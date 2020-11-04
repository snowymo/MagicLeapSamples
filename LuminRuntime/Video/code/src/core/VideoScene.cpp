// %BANNER_BEGIN%
// ---------------------------------------------------------------------
// %COPYRIGHT_BEGIN%
//
// Copyright (c) 2018 Magic Leap, Inc. All Rights Reserved.
// Use of this file is governed by the Creator Agreement, located
// here: https://id.magicleap.com/creator-terms
//
// %COPYRIGHT_END%
// ---------------------------------------------------------------------
// %BANNER_END%
#include <VideoScene.h>
#include <VideoUI.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesHelpers.h>
#include <SceneManager.h>
#include <PrefabManager.h>

#include <lumin/event/VideoEventData.h>
#include <ml_logging.h>
#include <chrono>
#include <thread>

using namespace lumin;
using namespace lumin::ui;
using namespace lumin::utils;

namespace {
  const uint32_t kToolbarCols = 2;
  const float kVideoHeight    = 0.5f;
  const float kSliderMinVal   = 0.0f;
  const float kSliderMaxVal   = 1.0f;
  const float kSliderWidth    = 0.2f;
  const float kToolbarHeight  = 0.2f;
  const float kPlayIconSize   = 0.15f;
  const float kVideoYOffset   = 0.35f;
  const float kFadeInTime     = 0.5f;
  const float kFadeOutTime    = 0.5f;
  const float kPanelScale     = 0.7f;
  const float kHiddenYScale   = 0.1f;
  const float kErrorMsgScale  = 0.4f;
  const float kErrorMsgOffset = -0.2f;
  const glm::vec2 kSettingsMenuSize(0.2f, 0.1f);
  const glm::vec3 kSettingsOffset(-0.1f, 0.05f, 0.02f);
  const glm::vec3 kSliderTextOffset(-0.03f, 0.0f, 0.0f);
  const glm::vec4 kGreyedVideoColor = color::WHITE * 0.2f;
  const glm::vec4 kTransparentBlack(0.0f, 0.0f, 0.0f, 0.05f);  // invisible in scene, but able to be selected
  const glm::vec4 kResetButtonPadding(0.0f, 0.02f, 0.02f, 0.02f);
  const glm::vec4 kLoopTogglePadding(0.02f, 0.02f, 0.01f, 0.04f);
  const glm::vec4 kTitlePadding(0.0, 0.0f, 0.02f, 0.01f);
  const glm::vec4 kHiddenPanelPadding(-0.05f, 0.0f, 0.0f, 0.0f);
  const std::string kZeroTime      = "0:00";
  const std::string kTimeDelimeter = " / ";
};

VideoScene::VideoScene(const std::string& title, const std::string& videoLoc,
    const glm::vec2& videoRes, lumin::ViewMode viewMode, bool loadFromEditor, bool isPath)
  : BasePrismController("Video Example"),
  duration_(0),
  isPath_(isPath),
  isPrepared_(false),
  isSliding_(false),
  loadedFromEditor_(loadFromEditor),
  title_(title),
  videoLoc_(videoLoc),
  videoDuration_(""),
  viewMode_(viewMode),
  video_(nullptr),
  errorMsg_(nullptr),
  videoTime_(nullptr),
  videoSliderText_(nullptr),
  videoSlider_(nullptr),
  playButton_(nullptr),
  pauseButton_(nullptr),
  miniPlayButton_(nullptr),
  replayButton_(nullptr),
  resetButton_(nullptr),
  settingsList_(nullptr),
  videoUiNode_(nullptr),
  topLayout_(nullptr),
  cursorHiddenPanel_(nullptr),
  cursorVisiblePanel_(nullptr),
  loopToggle_(nullptr),
  videoMenuIcon_(nullptr),
  fullMenu_(nullptr),
  volumeButton_(nullptr),
  muteButton_(nullptr),
  volumeSlider_(nullptr),
  videoToolbar_(nullptr),
  videoResolution_(videoRes),
  videoSize_(glm::vec2(0.0f)),
  previousCursorPos_(glm::vec3(0.0f)),
  videoTitle_(nullptr) {
}

void VideoScene::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "VideoExample::onAttachPrism() Initializing the Video scene");

  // Create the nodes that are only built via code. Must be done before creating the rest of the scene graph.
  createHiddenPanel(prism);
  createVideoNode(prism);
  BasePrismController::onAttachPrism(prism);
}

void VideoScene::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "VideoExample::onDetachPrism() Destroying the Video scene");
  deleteSceneGraph();
  delete videoTitle_;

  videoTitle_            = nullptr;
  errorMsg_              = nullptr;
  videoTime_             = nullptr;
  videoSliderText_       = nullptr;
  videoSlider_           = nullptr;
  playButton_            = nullptr;
  pauseButton_           = nullptr;
  miniPlayButton_        = nullptr;
  replayButton_          = nullptr;
  resetButton_           = nullptr;
  settingsList_          = nullptr;
  videoUiNode_           = nullptr;
  topLayout_             = nullptr;
  cursorHiddenPanel_     = nullptr;
  cursorVisiblePanel_    = nullptr;
  BasePrismController::onDetachPrism(prism);
}

void VideoScene::onUpdate(float a_fDelta) {
  videoTitle_->update(a_fDelta);
  if (isPrepared_) {
    if (!isSliding_) {
      int currentTime = 0;
      if (errorHandler(video_->getCurrentPosition(&currentTime),
        "unable to get the video's current time")) {
        videoSlider_->setValue(currentTime / static_cast<float>(duration_));
        std::string str_time = ExampleHelpers::msToString(currentTime);
        videoTime_->setText(str_time + " / " + videoDuration_);
        videoSliderText_->setText(str_time);
      }
    }
  }
}

bool VideoScene::onEvent(ServerEvent* an_Event) {
  // Create the Video UI when it is ready for playback, otherwise reset the UI when
  // the video has completed playback:
  ServerEventTypeValue eventType = an_Event->getServerEventTypeValue();
  bool consumedEvent = false;
  if (eventType == VideoEventData::GetServerEventTypeValue()) {
    VideoEventData* videoEventData = static_cast<VideoEventData*>(an_Event);
    VideoEventType videoEventType  = videoEventData->getVideoEventType();
    switch (videoEventType) {
    case VideoEventType::kPrepared: {
      if (!isPrepared_) {
        ML_LOG(Debug, "Video ready for playback.");
        onVideoReady();
        topLayout_->addItem(cursorHiddenPanel_, kHiddenPanelPadding);
        isPrepared_   = true;
        consumedEvent = true;
      }
      break;
    }
    case VideoEventType::kCompletion: {
      ML_LOG(Debug, "Video completed playback.");
      consumedEvent = true;
      if (!video_->isLooping()) {
        if (!isSliding_) {
          ExampleHelpers::enableUiNode(playButton_);
          ExampleHelpers::enableUiNode(replayButton_);
          ExampleHelpers::disableUiNode(pauseButton_);
          ExampleHelpers::disableUiNode(miniPlayButton_);
          videoTitle_->fadeIn();
        }
      }
      break;
    }
    default:
      break;
    }
  }
  return consumedEvent;
}

void VideoScene::play() {
  if (isPrepared_) {
    if (errorHandler(video_->start(), "failed to play video")) {
      toggleUIForPlaying();
    }
  }
}

void VideoScene::pause() {
  if (isPrepared_ && video_->isPlaying()) {
    if (errorHandler(video_->pause(), "failed to pause video")) {
      toggleUIForPausing();
    }
  }
}

void VideoScene::onAppPause() {
  pause();
}

void VideoScene::onAppResume() {
  pause();
}

void VideoScene::onToggleChanged(bool active) {
  pause();
}

void VideoScene::toggleUIForPlaying() {
  ExampleHelpers::enableUiNode(pauseButton_);
  ExampleHelpers::disableUiNode(playButton_);
  ExampleHelpers::disableUiNode(miniPlayButton_);
  ExampleHelpers::disableUiNode(replayButton_);
  videoTitle_->fadeOut();
}

void VideoScene::toggleUIForPausing() {
  ExampleHelpers::enableUiNode(miniPlayButton_);
  ExampleHelpers::enableUiNode(playButton_);
  ExampleHelpers::disableUiNode(pauseButton_);
  ExampleHelpers::disableUiNode(replayButton_);
  videoTitle_->fadeIn();
}

void VideoScene::createHiddenPanel(Prism* prism) {
  glm::vec3 prismSize = prism->getSize();
  float videoWidth    = (videoResolution_.x / videoResolution_.y) * 0.5f;

  cursorHiddenPanel_ = SDKExamples::createUiPanel(prism);
  cursorHiddenPanel_->setCursorVisible(false);
  cursorHiddenPanel_->setLocalPosition(ExampleConsts::kDefaultForeground);
  cursorHiddenPanel_->setGravityWellEnabled(true);
  cursorHiddenPanel_->setPanelShape(BoundaryShape({ videoWidth, prismSize.y * kHiddenYScale }, 0.0f));
}

void VideoScene::createVideoNode(Prism* prism) {
  float videoWidth = (videoResolution_.x / videoResolution_.y) * 0.5f;
  video_ = SDKExamples::createVideoNode(prism, static_cast<uint32_t>(videoResolution_.x),
    static_cast<uint32_t>(videoResolution_.y));
  videoSize_ = { videoWidth, kVideoHeight };
  video_->setLocalScale(glm::vec3(videoWidth, kVideoHeight, 0.0f));
  video_->setViewMode(viewMode_);
  if (isPath_) {
    errorHandler(video_->setVideoPath(videoLoc_), "unable to set the path video file");
  } else {
    errorHandler(video_->setVideoUri(videoLoc_), "unable to set the uri video file");
  }
}

void VideoScene::hideUICallback(const UiEventData&, UiLinearLayout* videoUI, bool transition) {
  videoUI->setVisible(false);
  ExampleHelpers::disableUiNode(settingsList_);
  if (transition) {
    Cursor::TransitionToPanel(getPrism(), cursorHiddenPanel_);
  }
}

bool VideoScene::errorHandler(utils::StatusCode status, const std::string& errorMsg) {
  if (status == utils::NO_ERROR) {
    return true;
  } else {
    ML_LOG(Error, "VideoScene::errorHandler - Error:%s, status code: %d", errorMsg.c_str(), status);
    errorMsg_->setText("Error: " + errorMsg + " because " + ExampleHelpers::statusCodeToString(status));
    errorMsg_->setTextColor(color::RED);
    videoUiNode_->setEnabled(false);
    video_->setColor(kGreyedVideoColor);
  }
  return false;
}

TransformNode* VideoScene::loadSceneGraph(Prism* prism) {
  // Load the nodes created in the editor:
  prefabs::VideoUI* prefab = managers_->extendedPrefab_->spawn<prefabs::VideoUI>();
  LUMIN_ASSERT(prefab, "Failed to create VideoUI scene");

  cursorVisiblePanel_ = prefab->getCursorVisiblePanel();
  topLayout_          = prefab->getTopLayout();
  errorMsg_           = prefab->getErrorMsg();
  videoUiNode_        = prefab->getVideoUI();
  videoTitle_         = new LabelFader(prefab->getTitle(), kFadeInTime, kFadeOutTime);

  settingsList_  = prefab->getSettingsList();
  loopToggle_    = prefab->getLoopToggle();
  resetButton_   = prefab->getResetButton();
  videoMenuIcon_ = prefab->getVideoMenuIcon();
  settingsList_->setItemPadding(prefab->getLoopItem(), kLoopTogglePadding);
  settingsList_->setItemPadding(prefab->getResetItem(), kResetButtonPadding);

  playButton_ = prefab->getPlayButton();
  playButton_->setLocalPosition(ExampleConsts::kDefaultForeground +
    glm::vec3(0.5f * videoSize_.x, -0.5f * videoSize_.y, 0.0f));
  videoUiNode_->addChild(playButton_);  // re-parent the play button since it can't be exported as a
                                        // child to a UiRectLayout.

  Node::Delete(videoUiNode_->detachContent());  // delete the placeholder content.
  videoUiNode_->setContent(video_);

  fullMenu_    = prefab->getFullMenu();
  videoSlider_ = prefab->getVideoSlider();

  videoToolbar_   = prefab->getVideoToolbar();
  videoTime_      = prefab->getVideoTime();
  pauseButton_    = prefab->getPauseButton();
  miniPlayButton_ = prefab->getMiniPlayButton();
  replayButton_   = prefab->getReplayButton();

  volumeButton_ = prefab->getVolumeButton();
  muteButton_   = prefab->getMuteButton();
  volumeSlider_ = prefab->getVolumeSlider();

  UiGridLayout* fullToolbar = prefab->getFullToolbar();
  fullToolbar->setItemAlignment(0, 0, Alignment::TOP_LEFT);
  fullToolbar->setItemAlignment(0, 1, Alignment::TOP_RIGHT);

  getRoot()->addChild(prefab->getRoot());
  setCommonProperties();
  return getRoot();
}

TransformNode* VideoScene::buildSceneGraph(Prism* prism) {
  glm::vec3 prismSize = prism->getSize();
  float videoWidth    = (videoResolution_.x / videoResolution_.y) * 0.5f;
  cursorVisiblePanel_ = SDKExamples::createUiPanel(prism);
  cursorVisiblePanel_->setPanelShape(BoundaryShape({prismSize.x * kPanelScale,
      prismSize.y * kPanelScale}, 0.0f));
  cursorVisiblePanel_->setLocalPosition(ExampleConsts::kDefaultLocalPos);

  topLayout_ = SDKExamples::createUiLinearLayout(prism);
  topLayout_->setAlignment(Alignment::TOP_CENTER);
  topLayout_->setOrientation(Orientation::kVertical);
  topLayout_->setDefaultItemPadding(ExampleConsts::kNoPadding);
  topLayout_->setDefaultItemAlignment(Alignment::TOP_CENTER);
  topLayout_->setLocalPosition(glm::vec3(0.0f, kVideoYOffset, 0.0f));
  cursorVisiblePanel_->addChild(topLayout_);

  UiText* title = SDKExamples::createEclipseLabel(prism, title_, EclipseLabelType::kT1);
  topLayout_->addItem(title, kTitlePadding, Alignment::CENTER_CENTER);
  videoTitle_ = new LabelFader(title, kFadeInTime, kFadeOutTime);

  errorMsg_ = SDKExamples::createEclipseLabel(prism, "", EclipseLabelType::kT6);
  errorMsg_->setBoundsSize(glm::vec2(prismSize.x, prismSize.y) * kErrorMsgScale);
  errorMsg_->setLocalPosition(glm::vec3(prismSize.x, prismSize.y, 0.0f) * kErrorMsgOffset);
  getRoot()->addChild(errorMsg_);

  videoUiNode_ = SDKExamples::createUiRectLayout(prism);
  videoUiNode_->setPadding(ExampleConsts::kDefaultPadding);
  videoUiNode_->setContentAlignment(Alignment::CENTER_CENTER);
  videoUiNode_->setContent(video_);
  getRoot()->addChild(cursorVisiblePanel_);

  topLayout_->addItem(videoUiNode_);

  // loop toggle:
  UiListViewItem* loopItem = SDKExamples::createUiListViewItem(prism);
  loopToggle_ = SDKExamples::createEclipseToggle(prism,
    EclipseToggleParams(EclipseToggleType::kSwitchWithIcon, SystemIcon::kSettings, "Loop"));
  loopItem->addChild(loopToggle_);
  loopItem->setBackgroundColor(color::BLACK);

  // reset button:
  UiListViewItem* resetItem = SDKExamples::createUiListViewItem(prism);
  resetButton_ = SDKExamples::createEclipseButton(prism,
    EclipseButtonParams(EclipseButtonType::kText, "Restart"));
  resetItem->addChild(resetButton_);
  resetItem->setBackgroundColor(color::BLACK);

  // settings icon and list:
  videoMenuIcon_ = SDKExamples::createEclipseButton(prism,
    EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kSettings));
  settingsList_ = SDKExamples::createUiListView(prism);
  settingsList_->setLocalPosition(glm::vec3(videoSize_.x / 2.01f, kVideoYOffset - videoSize_.y,
    0.0f) + kSettingsOffset);
  settingsList_->setAlignment(Alignment::TOP_CENTER);
  settingsList_->addItem(loopItem, kLoopTogglePadding);
  settingsList_->addItem(resetItem, kResetButtonPadding);
  getRoot()->addChild(settingsList_);

  // play button:
  playButton_ = SDKExamples::createEclipseButton(prism,
    EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kPlay));
  playButton_->setIconSize(glm::vec2(kPlayIconSize, kPlayIconSize));
  playButton_->setLocalPosition(ExampleConsts::kDefaultForeground +
    glm::vec3(0.5f * videoSize_.x, -0.5f * videoSize_.y, 0.0f));
  videoUiNode_->addChild(playButton_);

  // bottom menu:
  fullMenu_ = SDKExamples::createUiLinearLayout(prism);
  fullMenu_->setOrientation(Orientation::kVertical);
  fullMenu_->setDefaultItemAlignment(Alignment::TOP_LEFT);
  videoSlider_ = SDKExamples::createEclipseSlider(prism,
    EclipseSliderParams(EclipseSliderType::kHorizontalWithLabel, "", "", 0.0f, videoSize_.x));
  videoSlider_->setGravityWellEnabled(false);
  fullMenu_->addItem(videoSlider_);

  // Player buttons:
  UiNode* playerButton = SDKExamples::createUiNode(prism);
  pauseButton_ = SDKExamples::createEclipseButton(prism,
    EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kPause));
  miniPlayButton_ = SDKExamples::createEclipseButton(prism,
    EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kPlay));
  replayButton_ = SDKExamples::createEclipseButton(prism,
    EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kReplay));
  playerButton->addChild(pauseButton_);
  playerButton->addChild(miniPlayButton_);
  playerButton->addChild(replayButton_);

  // video toolbar:
  UiGridLayout* fullToolbar = SDKExamples::createUiGridLayout(prism);
  fullToolbar->setColumns(kToolbarCols);
  fullToolbar->setSize(glm::vec2(videoSize_.x, kToolbarHeight));
  videoToolbar_ = SDKExamples::createUiLinearLayout(prism);
  videoToolbar_->setOrientation(Orientation::kHorizontal);
  videoToolbar_->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  videoToolbar_->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  videoToolbar_->setSkipInvisibleItems(true);
  videoToolbar_->addItem(playerButton);

  // volume switcher and slider:
  UiNode* volumeSwitcher = SDKExamples::createUiNode(prism);
  volumeButton_ = SDKExamples::createEclipseButton(prism,
    EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kVolume));
  muteButton_ = SDKExamples::createEclipseButton(prism,
    EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kVolumeMute));
  volumeSlider_ = SDKExamples::createUiSlider(prism, kSliderWidth);
  volumeSlider_->setValue(kSliderMaxVal);  // videos are set at maximum volume by default
  volumeSwitcher->addChild(volumeButton_);
  volumeSwitcher->addChild(muteButton_);
  videoToolbar_->addItem(volumeSwitcher);
  videoToolbar_->addItem(volumeSlider_);

  videoTime_ = SDKExamples::createEclipseLabel(prism, kZeroTime + kTimeDelimeter + kZeroTime,
    EclipseLabelType::kB2);
  videoToolbar_->addItem(videoTime_);

  fullToolbar->addItem(videoToolbar_, ExampleConsts::kNoPadding, Alignment::TOP_LEFT);
  fullToolbar->addItem(videoMenuIcon_, ExampleConsts::kNoPadding, Alignment::TOP_RIGHT);
  fullMenu_->addItem(fullToolbar);
  topLayout_->addItem(fullMenu_);
  setCommonProperties();
  return getRoot();
}

void VideoScene::setCommonProperties() {
  fullMenu_->setVisible(false);
  ExampleHelpers::disableUiNode(pauseButton_);
  ExampleHelpers::disableUiNode(replayButton_);
  ExampleHelpers::disableUiNode(muteButton_);
  ExampleHelpers::disableUiNode(volumeSlider_);

  videoSliderText_ = SDKExamples::createEclipseLabel(getPrism(), kZeroTime, EclipseLabelType::kB4);
  videoSliderText_->setLocalPosition(kSliderTextOffset);
  videoSliderText_->setText(kZeroTime);
  videoSlider_->getUiTextLabel()->addChild(videoSliderText_);
  videoSlider_->getUiTextLabel()->setTextColor(kTransparentBlack);
  videoSlider_->setRenderingLayer(lumin::render::RenderingLayer::kPostObjectLayer);
  videoToolbar_->updateLayout();

  errorMsg_->setRenderingLayer(lumin::render::RenderingLayer::kPostObjectLayer);
  settingsList_->setRenderingLayer(lumin::render::RenderingLayer::kPostObjectLayer);
  ExampleHelpers::disableUiNode(settingsList_);
}

void VideoScene::onVideoReady() {

  // Get the video duration and handle the error with a visual message.
  // Workaround an issue by retrying for a couple of seconds before displaying the error.
  const int maxTimeMs = 2000;
  const int intervalMs = 200;
  int elapsedTimeMs = 0;
  utils::StatusCode status = video_->getDuration(&duration_);
  while (status != utils::OK && elapsedTimeMs < maxTimeMs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
    elapsedTimeMs += intervalMs;
    status = video_->getDuration(&duration_);
  }

  if (status != utils::OK) {
    errorHandler(status, "unable to get the video's duration");
  }

  videoDuration_ = ExampleHelpers::msToString(duration_);

  // Play or pause the video when the appropriate buttons are activated.
  playButton_->onActivateSub([this](const UiEventData&) {
    play();
  });
  videoUiNode_->onActivateSub([this](const UiEventData& data) {
    if (video_->isPlaying()) {
      pause();
    } else {
      play();
      hideUICallback(data, fullMenu_);
    }
  });

  // Show the full menu controls when cursor enters.
  videoUiNode_->onHoverEnterSub([this](const UiEventData&) {
    fullMenu_->setVisible(true);
  });

  // Hide the UI when playing the video or leaving the cursor leaving the Video panel.
  cursorVisiblePanel_->onPanelExitSub(std::bind(&VideoScene::hideUICallback, this,
      std::placeholders::_1, fullMenu_, false));
  cursorVisiblePanel_->setCursorConstrained(true);
  cursorVisiblePanel_->setEdgeConstraint(Side::kTop, 0.1f);
  cursorVisiblePanel_->setEdgeConstraint(Side::kBottom, 0.1f, cursorHiddenPanel_);
  cursorVisiblePanel_->setEdgeConstraint(Side::kLeft, 0.1f, cursorHiddenPanel_);
  cursorVisiblePanel_->setEdgeConstraint(Side::kRight, 0.1f, cursorHiddenPanel_);
  playButton_->onActivateSub(std::bind(&VideoScene::hideUICallback, this,
      std::placeholders::_1, fullMenu_, true));

  // Handle enabling/disabling the appropriate nodes based on video slider activation.
  videoSlider_->onActivateSub([this](const UiEventData&) {
    if (!isSliding_) {
      isSliding_ = true;
      ExampleHelpers::disableUiNode(playButton_);
      if (video_->isPlaying()) {
        errorHandler(video_->pause(), "failed to pause video for seeking");
      }
      if (replayButton_->getEnabled()) {
        ExampleHelpers::disableUiNode(replayButton_);
        ExampleHelpers::enableUiNode(pauseButton_);
      }
    }
    else {
      isSliding_ = false;
      if (pauseButton_->getEnabled() || videoSlider_->getValue() == kSliderMaxVal) {
        errorHandler(video_->start(), "failed to play video after seeking");
        videoTitle_->fadeOut();
      }
    }
  });

  videoSlider_->onFocusLostSub([this](const UiEventData&) {
    isSliding_ = false;
  });

  // Handle video seeking and textual changes during video slider scrubbing.
  videoSlider_->onSliderChangedSub([this](const UiEventData&) {
    if (isSliding_) {
      if (errorHandler(video_->seekTo(static_cast<int>(videoSlider_->getValue() * duration_)),
        "unable to seek to new position")) {
        std::string str_time = ExampleHelpers::msToString(static_cast<int>(videoSlider_->getValue()
          * duration_));
        videoTime_->setText(str_time + kTimeDelimeter + videoDuration_);
        videoSliderText_->setText(str_time);
      }
    }
  });

  // Handle looping toggle.
  loopToggle_->onActivateSub([this](const UiEventData&) {
    errorHandler(video_->setLooping(loopToggle_->getOn()), "failed to set video loop behavior");
  });

  // Handle video restart button.
  resetButton_->onActivateSub([this](const UiEventData&) {
    errorHandler(video_->seekTo(0), "failed to restart video");
    play();
  });

  // Handle toggling on the settings UI.
  videoMenuIcon_->onActivateSub([this](const UiEventData&) {
    settingsList_->getEnabled() ?
      ExampleHelpers::disableUiNode(settingsList_) :
      ExampleHelpers::enableUiNode(settingsList_);
  });

  // Handle pause activation.
  pauseButton_->onActivateSub([this](const UiEventData&) {
    if (errorHandler(video_->pause(), "failed to pause video from mini pause button")) {
      ExampleHelpers::disableUiNode(pauseButton_);
      ExampleHelpers::enableUiNode(miniPlayButton_);
      videoTitle_->fadeIn();
    }
  });

  // Handle playing the video.
  miniPlayButton_->onActivateSub([this](const UiEventData&) {
    play();
  });
  replayButton_->onActivateSub([this](const UiEventData&) {
    play();
  });

  // Handle volume button and slider activation
  auto setupVolumeButton = [this](UiButton* button) {
    button->onHoverEnterSub([this](const UiEventData&) {
      ExampleHelpers::enableUiNode(volumeSlider_);
      videoToolbar_->updateLayout();  // call updateLayout to dynamically change the positions of the items
    });
    button->onActivateSub([this](const UiEventData&) {
      volumeSlider_->getEnabled() ?
        ExampleHelpers::disableUiNode(volumeSlider_) :
        ExampleHelpers::enableUiNode(volumeSlider_);
      videoToolbar_->updateLayout();
    });
  };
  setupVolumeButton(volumeButton_);
  setupVolumeButton(muteButton_);

  // Handle changing the volume via the slider.
  volumeSlider_->onSliderChangedSub([this](const UiEventData&) {
    if (errorHandler(video_->setVolume(volumeSlider_->getValue()), "unable to set the video's volume")) {
      if (volumeSlider_->getValue() == kSliderMinVal) {
        ExampleHelpers::disableUiNode(volumeButton_);
        ExampleHelpers::enableUiNode(muteButton_);
      }
      else {
        ExampleHelpers::enableUiNode(volumeButton_);
        ExampleHelpers::disableUiNode(muteButton_);
      }
    }
  });
}
