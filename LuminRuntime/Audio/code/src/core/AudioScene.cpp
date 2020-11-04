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
#include <AudioScene.h>
#include <AudioGizmos.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesHelpers.h>
#include <ExamplesDefines.h>

#include <lumin/event/AudioEvent.h>
#include <lumin/utils/RendererInterface.h>
#include <ml_logging.h>
#include <memory>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace lumin;
using namespace lumin::ui;
using namespace lumin::utils;

/**
 * Touchpad prism controls to pick up and move the audio model's prism.
 * Spawn more than one prism?
 */
namespace {
  const float kMaxPitchChange    = 1.0f;
  const float kRollOffFactor     = 0.5f;
  const float kMinDistMinVal     = 0.01f;
  const float kMinDistMaxVal     = 5.0f;
  const float kMaxDistMinVal     = 1.0f;
  const float kMaxDistMaxVal     = 20.0f;
  const float kPitchMinVal       = 0.5f;
  const float kPitchStartVal     = 1.0f;
  const float kPitchMaxVal       = 2.0f;
  const float kAudioMaxVal       = 1.0f;
  const float kAudioDefaultVal   = 0.125f;
  const float kOuterDefaultAngle = 60.0f;
  const float kInnerDefaultAngle = 30.0f;
  const float kMaxAngle          = 360.0f;
  const float kSliderWidth       = 0.2f;
  const float kMoveTime          = 1.0f;
  const float kTime              = 0.01f;
  const int32_t kSampleRate      = 44100;  // sample rate for audio stream in hertz
  const int32_t kChannels        = 2;      // number of audio channels for Raw PCM file
  const int32_t kBitDepth        = 16;     // number of bits per sample
  const glm::vec3 kSliderTextOffset(0.015f, 0.0f, 0.0f);
  const glm::vec3 kRadialSliderTextOffset(-0.01f, 0.0f, 0.0f);
  const glm::vec3 kBigRadialSliderTextOffset(-0.015f, 0.0f, 0.0f);
  const glm::vec3 kAudioPrismSize(1.0f, 0.4f, 1.0f);
  const glm::vec3 kAudioModelScale(10.0f);
  const glm::vec4 kTransparentBlack(0.0f, 0.0f, 0.0f, 0.05f);
  const glm::vec4 kTogglePadding(0.01f, 0.06f, 0.01f, 0.03f);
  const glm::vec4 kPitchSliderPadding(0.03, 0.01, 0.01, 0.06f);
  const glm::vec4 kGainPadding(0.02f, 0.02f, 0.02f, 0.0f);
  const glm::vec4 kDistancePadding(0.02f, 0.06f, 0.02f, 0.02f);
  const glm::quat kConeRotation  = glm::angleAxis(-glm::half_pi<float>(), VEC3_UP);
  const std::string kPlay        = "PLAY";
  const std::string kPause       = "PAUSE";
  const std::string kMute        = "MUTE";
  const std::string kUnmute      = "UNMUTE";
  const std::string kAnimation   = "Play";
  const std::string kOuterName   = "outerGain";
  const std::string kOuterHFName = "outerGainHF";
  const std::string kGainName    = "gain";
  const std::string kGainLFName  = "gainLf";
  const std::string kGainMFName  = "gainMf";
  const std::string kGainHFName  = "gainHf";
  const std::string kTitlePrefix = "NOW PLAYING: ";
}

AudioScene::AudioScene(AudioBaseApp& application, const std::string& audioTitle, const std::string& audioPath, uint32_t channelCount)
  : BasePrismController("Audio Scene"),
  basePitch_(0.0f),
  audioPlacer_(0.0f),
  moving_(false),
  noSound_(false),
  rotation_(true),
  firstPlay_(true),
  loaded_(false),
  audioPath_(audioPath),
  audioTitle_(audioTitle),
  application_(application),
  channelCount_(channelCount),
  prefab_(nullptr),
  modelPrefab_(nullptr),
  audioModelManagers_(nullptr),
  loadedAudio_(nullptr),
  streamedAudio_(nullptr),
  outputAudio_(nullptr),
  audioNode_(nullptr),
  audioHolder_(nullptr),
  audioUI_(nullptr),
  stopButton_(nullptr),
  pauseResumeButton_(nullptr),
  muteButton_(nullptr),
  loopToggle_(nullptr),
  spatialToggle_(nullptr),
  volume_(nullptr),
  pitch_(nullptr),
  outerAngle_(nullptr),
  innerAngle_(nullptr),
  gain_(nullptr),
  gainLf_(nullptr),
  gainMf_(nullptr),
  gainHf_(nullptr),
  outerGain_(nullptr),
  outerGainHf_(nullptr),
  minDistance_(nullptr),
  maxDistance_(nullptr),
  channelDistance_(nullptr),
  pitchText_(nullptr),
  outerLabel_(nullptr),
  innerLabel_(nullptr),
  minText_(nullptr),
  maxText_(nullptr),
  channelText_(nullptr),
  muteModel_(nullptr),
  offModel_(nullptr),
  onModel_(nullptr),
  playModel_(nullptr) {
    application_.addPrismDeleter([this](Prism* prism) {
      reset();
      removeAudioNodes();
      delete audioModelManagers_;
      audioModelManagers_ = nullptr;
    });
}

void createBackground(Prism* prism, bool skipFace = true) {
  // create transparent quadnodes of the prism extents:
  // this is to make focusing on the prism easier
  glm::vec3 prismSize = prism->getSize();
  auto createQuad = [prismSize, prism, root = prism->getRootNode()](const glm::vec3& pos, const glm::quat& rot) {
    QuadNode* face = SDKExamples::createQuadNode(prism);
    face->setSize(prismSize * 2.0f);
    face->setColor(kTransparentBlack);
    face->setLocalPosition(pos);
    face->setLocalRotation(rot);
    face->setBackFaceCulls(true);
    root->addChild(face);
  };
  if (!skipFace) {
    createQuad({-prismSize.x, -prismSize.y, prismSize.z}, ExampleConsts::kNoRotation);
  }
  createQuad({-prismSize.x, -prismSize.y, -prismSize.z}, ExampleConsts::kNoRotation);
  createQuad({-prismSize.x, -prismSize.y, prismSize.z},
      glm::angleAxis(glm::half_pi<float>(), lumin::VEC3_UP));
  createQuad({prismSize.x, -prismSize.y, prismSize.z},
      glm::angleAxis(glm::half_pi<float>(), lumin::VEC3_UP));
  createQuad({-prismSize.x, prismSize.y, prismSize.z},
      glm::angleAxis(glm::half_pi<float>(), lumin::VEC3_RIGHT));
  createQuad({-prismSize.x, -prismSize.y, prismSize.z},
      glm::angleAxis(glm::half_pi<float>(), lumin::VEC3_RIGHT));
}

void AudioScene::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "AudioExample::onAttachPrism() Initializing the Audio scene");
  lumin::SDKExamples::BasePrismController::onAttachPrism(prism);
  createBackground(prism);
  // Open our pcm file.
  std::ifstream fs;
  // Set the initial position at the end of the file for getting the file size.
  fs.open(audioPath_.c_str(), std::ios::binary | std::ios::ate);
  LUMIN_ASSERT(fs.is_open(), "AudioScene::createOutputStreamingBuffer: Error opening file: %s",
      audioPath_.c_str());
  streamedFileSize_ = fs.tellg();
  fs.seekg(0);
  streamedFileBuf_ = new char[streamedFileSize_];
  fs.read(streamedFileBuf_, streamedFileSize_);
  if (streamedFileSize_ != fs.gcount()) {
    delete[] streamedFileBuf_;
    LUMIN_ASSERT(false, "AudioScene::createOutputStreamingBuffer: Error reading file contents of file: %s",
        audioPath_.c_str());
  }
  fs.close();
}

// Load only the UI:
TransformNode* AudioScene::loadSceneGraph(Prism* prism) {
  loaded_ = true;
  prefab_  = managers_->extendedPrefab_->spawn<prefabs::AudioEditor>();
  LUMIN_ASSERT(prefab_, "Failed to create AudioEditor Prefab");

  audioUI_           = prefab_->getAudioUI();
  audioSwitcher_     = prefab_->getAudioSwitcher();
  stopButton_        = prefab_->getStopButton();
  pauseResumeButton_ = prefab_->getPauseResumeButton();
  muteButton_        = prefab_->getMuteButton();
  loopToggle_        = prefab_->getLoop();
  spatialToggle_     = prefab_->getSpatial();
  volume_            = prefab_->getVolume();
  pitch_             = prefab_->getPitch();
  outerAngle_        = prefab_->getOuterAngle();
  innerAngle_        = prefab_->getInnerAngle();
  gain_              = prefab_->getGain();
  gainHf_            = prefab_->getGainHf();
  gainLf_            = prefab_->getGainLf();
  gainMf_            = prefab_->getGainMf();
  outerGain_         = prefab_->getOuterGain();
  outerGainHf_       = prefab_->getOuterGainHF();
  minDistance_       = prefab_->getMinDistance();
  maxDistance_       = prefab_->getMaxDistance();
  channelDistance_   = prefab_->getChannelDistance();
  spatialLayout_     = prefab_->getSpatialLayout();
  createAllCustomLabels();
  prefab_->getAudioTitle()->setText(kTitlePrefix + audioTitle_);
  audioLabel_ = new LabelFader(prefab_->getAudioTitle());
  audioLabel_->fadeOut();
  spatialLayout_->setVisible(false);
  audioUI_->setVisible(false);
  prefab_->setAudioScene(this);

  UiLinearLayout* topLayout = prefab_->getTopLayout();
  topLayout->setLocalPosition(ExampleConsts::kDefaultLocalPos);
  getRoot()->addChild(topLayout);
  return getRoot();
}

// Build only the UI:
TransformNode* AudioScene::buildSceneGraph(Prism* prism) {
  UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
  topLayout->setOrientation(Orientation::kHorizontal);

  audioUI_ = createAudioUI();
  audioSwitcher_ = createAudioSwitcher();
  audioSwitcher_->onSelectionChangedSub(std::bind(&AudioScene::audioSwitcherCallback, this,
      std::placeholders::_1, std::placeholders::_2));
  topLayout->addItem(audioSwitcher_, {0.0f, 0.13f, 0.0f, 0.0f});
  topLayout->addItem(audioUI_);
  getRoot()->addChild(topLayout);
  return getRoot();
}

void AudioScene::buildAudio(Prism* prism) {
  audioHolder_   = createAudioModel(prism);
  loadedAudio_   = SDKExamples::createAudioNode(prism);  // pre-loaded sound
  streamedAudio_ = SDKExamples::createAudioNode(prism);  // streaming sound
  outputAudio_   = SDKExamples::createAudioNode(prism);  // output streaming sound
  loadedAudio_->getSoundPitch(basePitch_);
  createOutputStreamingBuffer();
  copyUi();
}

void AudioScene::loadAudio(Prism* prism) {
  modelPrefab_  = audioModelManagers_->extendedPrefab_->spawn<prefabs::AudioModel>();
  LUMIN_ASSERT(modelPrefab_, "Failed to create AudioModel Prefab");
  muteModel_     = modelPrefab_->getMuteModel();
  offModel_      = modelPrefab_->getOffModel();
  onModel_       = modelPrefab_->getOnModel();
  playModel_     = modelPrefab_->getPlayModel();
  loadedAudio_   = modelPrefab_->getLoadedAudio();
  streamedAudio_ = modelPrefab_->getStreamedAudio();
  outputAudio_   = modelPrefab_->getOutputAudio();
  audioHolder_   = modelPrefab_->getAudioHolder();
  audioParent_   = modelPrefab_->getAudioParent();
  loadedAudio_->getSoundPitch(basePitch_);
  prism->getRootNode()->addChild(audioParent_);
  auto setModel = [this](ModelNode* model) {
    model->setVisible(false);
    model->playAnimation(model->getModelResource(), kAnimation.c_str(), false);
    model->setSkipRaycast(true);
  };
  setModel(muteModel_);
  setModel(offModel_);
  setModel(onModel_);
  setModel(playModel_);
  playModel_->setLocalScale(kAudioModelScale);
  createOutputStreamingBuffer();
  copyUi();
}

void AudioScene::copyUi() {
  // copy the ui properties:
  audioNode_ = loadedAudio_;
  pitchCallback();
  volumeCallback();
  spatialCallback();
  audioNode_->setSoundMute(muteButton_->getText() == kUnmute);
  audioHolder_->setVisible(false, true);
  muteModel_->setVisible(muteButton_->getText() == kUnmute);
  offModel_->setVisible(muteButton_->getText() == kMute);
  audioNode_->setSoundLooping(loopToggle_->getOn());
  copyAudioProperties(audioNode_, streamedAudio_);
  copyAudioProperties(audioNode_, outputAudio_);
  audioNode_ = nullptr;
}

void AudioScene::createResources(UiDialog* loadingDialog) {
  ResourceIDType audioRes         = application_.createAudioResource(audioPath_);
  ResourceIDType audioStreamedRes = application_.createStreamedAudioResource(audioPath_);
  loadedAudio_->createSoundWithLoadedFile(audioRes);
  streamedAudio_->createSoundWithStreamedFile(audioStreamedRes);
  Cursor::SetEnabled(getPrism(), true);
  Node::Delete(loadingDialog);
}

/**
 * When I become inactive, delete my nodes from the prism if it exists.
 * When I become active, place my nodes in the prism if it exists.
 */
void AudioScene::onToggleChanged(bool active) {
  reset();
  audioLabel_->fadeOut();
  if (active) {
    // if an audio prism exists, use it:
    if (application_.isAudioPrism()) {
      if (audioPrism_.lock() != application_.getAudioPrism().lock()) {
        audioPrism_ = application_.getAudioPrism();
        audioModelManagers_ = new Managers(audioPrism_.lock().get());
      }
      (loaded_)? loadAudio(audioPrism_.lock().get()) : buildAudio(audioPrism_.lock().get());
      if (!audioPrism_.lock()->getResource(application_.getAudioResources()[0]) ||
          !audioPrism_.lock()->getResource(application_.getStreamedAudioResources()[0])) {
        application_.deleteAllResources();
        loadResources();
      }
      loadedAudio_->createSoundWithLoadedFile(application_.getAudioResources()[0]);
      streamedAudio_->createSoundWithStreamedFile(application_.getStreamedAudioResources()[0]);
    }
  } else {
    if (audioPrism_.lock()) {
      removeAudioNodes();
    }
  }
}

void AudioScene::removeAudioNodes() {
  if (modelPrefab_) {
    audioModelManagers_->extendedPrefab_->destroyPrefab(modelPrefab_);
  } else {
    Node::Delete(audioParent_);
    Node::Delete(loadedAudio_);
    Node::Delete(streamedAudio_);
    Node::Delete(outputAudio_);
  }

  modelPrefab_       = nullptr;
  audioNode_         = nullptr;
  loadedAudio_       = nullptr;
  streamedAudio_     = nullptr;
  outputAudio_       = nullptr;
  audioParent_       = nullptr;
  audioHolder_       = nullptr;
  playModel_         = nullptr;
  onModel_           = nullptr;
  offModel_          = nullptr;
  muteModel_         = nullptr;
  audioUI_->setVisible(false);
  audioSwitcher_->clearSelected();
}

void AudioScene::fillAndReleaseOutputBufferWrapper(AudioId id, void* context) {
  AudioScene* scene = static_cast<AudioScene*>(context);
  LUMIN_ASSERT(scene != nullptr, "AudioScene::fillOutputBufferWrapper: context is null");
  scene->fillAndReleaseOutputBuffer(id);
}

void AudioScene::fillAndReleaseOutputBuffer(AudioId id) {
  if (outputAudio_ && audioNode_) {
    bool isLooping;
    audioNode_->isSoundLooping(isLooping);
    AudioBuffer* buffer = static_cast<AudioBuffer*>(malloc(sizeof(AudioBuffer)));
    outputAudio_->getOutputStreamBuffer(buffer, id);
    if (streamedFileReadIndex_ + buffer->size < streamedFileSize_) {
      // single copy from middle of buffer
      memcpy(buffer->ptr, &streamedFileBuf_[streamedFileReadIndex_], buffer->size);
      streamedFileReadIndex_ += buffer->size;
      if (firstPlay_) {
        audioLabel_->fadeIn();
        firstPlay_ = false;
      }
    } else {
      // two copies from end then start of buffer
      uint32_t partial_size = streamedFileSize_ - streamedFileReadIndex_;
      memcpy(buffer->ptr, &streamedFileBuf_[streamedFileReadIndex_], partial_size);
      uint32_t remaining_size = buffer->size - partial_size;
      memcpy(&buffer->ptr[partial_size], streamedFileBuf_, remaining_size);
      streamedFileReadIndex_ = remaining_size;
      if (!isLooping) {
        BaseApp::RunOnMainThreadSync([this]() {
          AudioState state;
          audioNode_->getSoundState(state);
          if (state != AudioState::kInvalidAudioState) {
            audioNode_->stopSound();
            audioLabel_->fadeOut();
            stopButton_->setEnabled(false);
            firstPlay_ = true;
          }
          moving_ = false;
        });
      }
    }
    LUMIN_ASSERT(outputAudio_->releaseOutputStreamBuffer(id), "AudioNode::ReleaseOutputStreamBuffer failed.");
  }
}

void AudioScene::createOutputStreamingBuffer() {
  AudioBufferFormat outFormat;
  uint32_t outSize;
  uint32_t outMinSize; // ignored
  if (!AudioNode::GetOutputStreamDefaults(kChannels, kSampleRate, kMaxPitchChange, &outFormat,
      &outSize, &outMinSize)) {
    ML_LOG(Debug, "AudioNode::GetOuputStreamDefaults could not get recommended values.");
    outSize = (kSampleRate / 100) * (kChannels * sizeof(int16_t));
  }
  outFormat.channel_count         = kChannels;
  outFormat.samples_per_second    = kSampleRate;
  outFormat.bits_per_sample       = kBitDepth;
  outFormat.valid_bits_per_sample = kBitDepth;
  outFormat.sample_format         = AudioSampleFormat::Integer;
  outFormat.reserved              = 0;
  if (!outputAudio_->createSoundWithOutputStream(&outFormat, static_cast<size_t>(outSize),
      fillAndReleaseOutputBufferWrapper, static_cast<void*>(this))) {
        ML_LOG(Error, "AudioNode::createSoundWithOutputStream failed; cannot use with ML Remote.");
  }
  streamedFileReadIndex_ = 0;
}

UiDropDownList* AudioScene::createAudioSwitcher() {
  UiDropDownList* audioSwitcher = SDKExamples::createUiDropDownList(getPrism(), "Create Audio Type");
  audioSwitcher->setList({{"Pre-loaded Audio"}, {"Streamed Audio"}, {"Output Streamed Audio"}});
  audioSwitcher->setMultiSelectMode(false);
  return audioSwitcher;
}

void AudioScene::reset() {
  bool muted = false;
  firstPlay_ = true;
  moving_    = false;
  volume_->setVisible(true);
  pitch_->setVisible(true);
  stopButton_->setEnabled(false);
  pauseResumeButton_->setText(kPlay);

  if (audioNode_) {
    AudioState state;
    audioNode_->isSoundMuted(muted);
    audioNode_->getSoundState(state);
    if (state != AudioState::kInvalidAudioState) {
      audioNode_->stopSound();
    }
    audioParent_->removeChild(audioNode_);
    audioParent_->stopTransformAnimations();
    audioParent_->rotateTo(QUAT_IDENTITY, kMoveTime);
    audioPlacer_ = 0.0f;
    if (audioHolder_) {
      audioHolder_->setVisible(false, true);
      if (!muted && !noSound_) {
        offModel_->setVisible(true);
      } else {
        muteModel_->setVisible(true);
      }
    }
  }
}

void AudioScene::createAudioPrism() {
  audioPrism_ = application_.getAudioPrism(kAudioPrismSize);
  createBackground(audioPrism_.lock().get(), false);
  audioModelManagers_ = new Managers(audioPrism_.lock().get());
  (loaded_)? loadAudio(audioPrism_.lock().get()) : buildAudio(audioPrism_.lock().get());
  loadResources();
}

void AudioScene::loadResources() {
  Cursor::SetEnabled(getPrism(), false);
  UiDialog* loadingDialog = SDKExamples::createUiDialog(getPrism(), DialogType::kNoAction);
  UiLinearLayout* content = SDKExamples::createUiLinearLayout(getPrism());
  content->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  content->setAlignment(Alignment::CENTER_CENTER);
  content->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  UiText* title = SDKExamples::createEclipseLabel(getPrism(), "Loading Audio Resources ...", EclipseLabelType::kT3);
  content->addItem(title);
  loadingDialog->setLocalPosition({0.0f, 0.0f, 0.1f});
  loadingDialog->setDialogContent(content);
  loadingDialog->setRenderingLayer(render::RenderingLayer::kPostObjectLayer);
  spatialToggle_->addChild(loadingDialog);
  loadingDialog->init();
  BaseApp::RunOnMainThread(std::bind(&AudioScene::createResources, this, loadingDialog));
}

void AudioScene::audioSwitcherCallback(const UiEventData&,
    const std::vector<const DropDownListItem*>& list) {

  std::function<void(UiNode* node, bool enabled)> setChildrenEnabled;
  setChildrenEnabled = [&setChildrenEnabled](UiNode* node, bool enabled) {
    if (node) {
      node->setEnabled(enabled);
      for (auto child : node->findChildren(UiNode::GetNodeTypeEnum(), false, false)) {
        setChildrenEnabled(static_cast<UiNode*>(child), enabled);
      }
    }
  };

  if (!audioPrism_.lock()) {
    createAudioPrism();
  }

  for (const DropDownListItem* item : list) {
    if (item->getSelected()) {
      if (item->label == "Pre-loaded Audio") {
        if (!audioUI_->getEnabled()) {
          setChildrenEnabled(audioUI_, true);
        }
        if (audioNode_) {
          reset();
          copyAudioProperties(audioNode_, loadedAudio_);
        }
        audioNode_ = loadedAudio_;
        spatialCallback();
      } else if (item->label == "Streamed Audio") {
        if (!audioUI_->getEnabled()) {
          setChildrenEnabled(audioUI_, true);
        }
        if (audioNode_) {
          reset();
          copyAudioProperties(audioNode_, streamedAudio_);
        }
        audioNode_ = streamedAudio_;
        spatialCallback();
      } else if (item->label == "Output Streamed Audio") {
        if (audioNode_) {
          reset();
          copyAudioProperties(audioNode_, outputAudio_);
        }
        setChildrenEnabled(audioUI_, false);
        pauseResumeButton_->setEnabled(true);
        muteButton_->setEnabled(true);
        loopToggle_->setEnabled(true);
        volume_->setVisible(false);
        pitch_->setVisible(false);
        audioNode_ = outputAudio_;
        spatialLayout_->setVisible(false);
        removeAudioGizmos(audioPrism_, audioNode_);
      }
      audioUI_->setVisible(true);
      audioParent_->addChild(audioNode_);
      audioLabel_->fadeIn();
    }
  }
}

void AudioScene::copyAudioProperties(AudioNode* copyFrom, AudioNode* copyTo) {
  float tempF;
  bool tempB;
  glm::vec3 channelPosition;
  glm::quat channelDirection;
  SpatialSoundDistanceProperties channelDistance;
  SpatialSoundRadiationProperties channelRadiation;
  SpatialSoundSendLevels channelSendLevels;

  copyFrom->getSoundVolumeLinear(tempF);
  copyTo->setSoundVolumeLinear(tempF);
  copyFrom->getSoundPitch(tempF);
  copyTo->setSoundPitch(tempF);
  copyFrom->isSoundMuted(tempB);
  copyTo->setSoundMute(tempB);
  copyFrom->isSoundLooping(tempB);
  copyTo->setSoundLooping(tempB);
  copyFrom->getSpatialSoundEnable(tempB);
  copyTo->setSpatialSoundEnable(tempB);

  for (uint32_t i = 0; i < channelCount_; ++i) {
    copyFrom->getSpatialSoundPosition(i, channelPosition);
    copyTo->setSpatialSoundPosition(i, channelPosition);
    copyFrom->getSpatialSoundDirection(i, channelDirection);
    copyTo->setSpatialSoundDirection(i, channelDirection);
    copyFrom->getSpatialSoundDistanceProperties(i, channelDistance);
    copyTo->setSpatialSoundDistanceProperties(i, channelDistance);
    copyFrom->getSpatialSoundRadiationProperties(i, channelRadiation);
    copyTo->setSpatialSoundRadiationProperties(i, channelRadiation);
    copyFrom->getSpatialSoundDirectSendLevels(i, channelSendLevels);
    copyTo->setSpatialSoundDirectSendLevels(i, channelSendLevels);
    copyFrom->getSpatialSoundRoomSendLevels(i, channelSendLevels);
    copyTo->setSpatialSoundRoomSendLevels(i, channelSendLevels);
  }
  if (tempB) {
    constructAudioGizmos(audioPrism_, copyTo, channelCount_);
  }
}

// set in the back of the prism
TransformNode* AudioScene::createAudioModel(Prism* prism) {
  audioParent_               = SDKExamples::createTransformNode(prism);  // holds the cones and models
  TransformNode* audioHolder = SDKExamples::createTransformNode(prism);  // holds the models
  audioParent_->addChild(audioHolder);
  prism->getRootNode()->addChild(audioParent_);

  auto createModel = [prism, parent = audioHolder, this](const std::string& path,
      const glm::vec4& color = color::WHITE, const glm::vec3& scale = kAudioModelScale) {
    ResourceIDType res = prism->createModelResourceId(path.c_str(), 1.0f);
    ModelNode* model   = SDKExamples::createModelNode(prism, res);
    model->setLocalScale(scale);
    model->setShader(utils::ShaderType::kPbr);
    model->setColor(color);
    model->setVisible(false);
    model->playAnimation(res, kAnimation.c_str(), false);
    model->setSkipRaycast(true);
    model->setLocalRotation(kConeRotation);
    parent->addChild(model);
    return model;
  };

  muteModel_ = createModel("pipeline/SourceArt/ML_SoundIcon_Mute.fbx");
  offModel_  = createModel("pipeline/SourceArt/ML_SoundIcon_Off.fbx");
  onModel_   = createModel("pipeline/SourceArt/ML_SoundIcon_On.fbx");
  playModel_ = createModel("pipeline/SourceArt/ML_SoundIcon_Play.fbx");
  return audioHolder;
}

UiLinearLayout* AudioScene::createAudioUI() {
  UiLinearLayout* fullUI = SDKExamples::createUiLinearLayout(getPrism());

  auto createLayout = [prism = getPrism()]() {
    UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
    layout->setOrientation(Orientation::kHorizontal);
    layout->setDefaultItemPadding(2.0f * ExampleConsts::kDefaultPadding);
    return layout;
  };

  UiLinearLayout* stateButtons = createLayout();
  createAudioPlayerButtons(stateButtons);

  UiLinearLayout* toggles = createLayout();
  createAudioPlayerToggles(toggles);

  UiLinearLayout* soundSliders = createLayout();
  createAudioPlayerSliders(soundSliders);

  spatialLayout_                 = SDKExamples::createUiLinearLayout(getPrism());
  UiLinearLayout* angleLayout    = createLayout();
  UiLinearLayout* gainLayout     = createLayout();
  UiLinearLayout* distanceLayout = createLayout();
  createSpatialAngleSliders(angleLayout);
  createSpatialDistanceSliders(distanceLayout);
  createSpatialGainSliders(gainLayout);
  spatialLayout_->addItem(angleLayout);
  spatialLayout_->addItem(distanceLayout);
  spatialLayout_->addItem(gainLayout, kGainPadding);
  spatialLayout_->setVisible(false);
  createAllCustomLabels();

  UiText* audioTitle = SDKExamples::createEclipseLabel(getPrism(), kTitlePrefix + audioTitle_, EclipseLabelType::kB4);
  audioLabel_ = new LabelFader(audioTitle);
  audioLabel_->fadeOut();

  fullUI->addItem(audioTitle, {0.0, 0.0, 0.0, 0.02});
  fullUI->addItem(stateButtons);
  fullUI->addItem(toggles);
  fullUI->addItem(soundSliders);
  fullUI->addItem(spatialLayout_);
  fullUI->setVisible(false);
  fullUI->setRenderingLayer(lumin::render::RenderingLayer::kPostObjectLayer);
  return fullUI;
}

void AudioScene::createAllCustomLabels() {
  auto addCustomSliderText = [](UiSlider* slider, UiText* customLabel, glm::vec3 offset = kSliderTextOffset,
      Alignment alignment = Alignment::BOTTOM_CENTER) {
    if (slider->getUiTextLabel()) {
      customLabel->setLocalPosition(offset);
      customLabel->setRenderingLayer(render::RenderingLayer::kPostObjectLayer);
      customLabel->setAlignment(alignment);
      customLabel->setVisibilityInherited(true);  // The label is normally invisible and only shows up OnHover.
      slider->getUiTextLabel()->setTextColor(kTransparentBlack);
      slider->getUiTextLabel()->addChild(customLabel);
      slider->getUiTextLabel()->setSkipRaycast(true, true);
    }
  };
  pitchText_  = SDKExamples::createEclipseLabel(getPrism(), "0.00%", EclipseLabelType::kB4);
  outerLabel_ = SDKExamples::createEclipseLabel(getPrism(), "60°", EclipseLabelType::kT4);
  innerLabel_ = SDKExamples::createEclipseLabel(getPrism(), "30°", EclipseLabelType::kT4);
  minText_    = SDKExamples::createEclipseLabel(getPrism(),
      ExampleHelpers::floatToString((kMinDistMinVal + kMinDistMaxVal) / 2.0f) + " m", EclipseLabelType::kB4);
  maxText_ = SDKExamples::createEclipseLabel(getPrism(),
    ExampleHelpers::floatToString((kMaxDistMinVal + kMaxDistMaxVal) / 2.0f) + " m", EclipseLabelType::kB4);
  channelText_ = SDKExamples::createEclipseLabel(getPrism(),
    ExampleHelpers::floatToString(0.5f) + " m", EclipseLabelType::kB4);
  addCustomSliderText(channelDistance_, channelText_);
  addCustomSliderText(maxDistance_, maxText_);
  addCustomSliderText(minDistance_, minText_);
  addCustomSliderText(pitch_, pitchText_);
  addCustomSliderText(outerAngle_, outerLabel_, kRadialSliderTextOffset, Alignment::CENTER_CENTER);
  addCustomSliderText(innerAngle_, innerLabel_, kRadialSliderTextOffset, Alignment::CENTER_CENTER);
}

void AudioScene::createAudioPlayerButtons(UiLinearLayout* layout) {
  pauseResumeButton_ = SDKExamples::createEclipseButton(getPrism(),
      EclipseButtonParams(EclipseButtonType::kText, kPlay));
  stopButton_ = SDKExamples::createEclipseButton(getPrism(),
      EclipseButtonParams(EclipseButtonType::kText, "STOP"));
  muteButton_ = SDKExamples::createEclipseButton(getPrism(),
      EclipseButtonParams(EclipseButtonType::kText, kMute));
  stopButton_->setEnabled(false);
  stopButton_->onActivateSub(std::bind(&AudioScene::stopCallback, this, std::placeholders::_1));
  pauseResumeButton_->onActivateSub(std::bind(&AudioScene::pauseResumeCallback, this, std::placeholders::_1));
  muteButton_->onActivateSub([this](const UiEventData&) { muteCallback();} );

  layout->addItem(pauseResumeButton_);
  layout->addItem(stopButton_);
  layout->addItem(muteButton_);
}

void AudioScene::stopCallback(const UiEventData&) {
  AudioState state;
  audioNode_->getSoundState(state);
  if (state != AudioState::kInvalidAudioState) {
    audioNode_->stopSound();
    audioLabel_->fadeOut();
    stopButton_->setEnabled(false);
  };
  moving_ = false;
}

void AudioScene::pauseResumeCallback(const UiEventData&) {
  if (pauseResumeButton_->getText() == kPlay) {
    moving_ = true;
    if (firstPlay_) {
      audioNode_->startSound();
      audioLabel_->fadeIn();
      stopButton_->setEnabled(true);
      firstPlay_ = false;
    } else {
      audioNode_->resumeSound();
      audioLabel_->fadeIn();
    }
  } else {
    audioNode_->pauseSound();
    moving_ = false;
  }
}

void AudioScene::muteCallback() {
  if (muteButton_->getText() == kMute) {
    audioNode_->setSoundMute(true);
    muteButton_->setText(kUnmute);
    audioHolder_->setVisible(false, true);
    muteModel_->setVisible(true);
  } else {
    audioNode_->setSoundMute(false);
    muteButton_->setText(kMute);
    audioHolder_->setVisible(false, true);
    offModel_->setVisible(true);
  }
}

void AudioScene::createAudioPlayerToggles(UiLinearLayout* layout) {
  loopToggle_ = SDKExamples::createEclipseToggle(getPrism(),
      EclipseToggleParams(EclipseToggleType::kSwitchWithIcon, SystemIcon::kSettings, "LOOP"));
  spatialToggle_ = SDKExamples::createEclipseToggle(getPrism(),
      EclipseToggleParams(EclipseToggleType::kSwitchWithIcon, SystemIcon::kSettings, "SPATIAL SOUND"));
  UiToggle* rotate = SDKExamples::createEclipseToggle(getPrism(),
      EclipseToggleParams(EclipseToggleType::kSwitchWithIcon, SystemIcon::kSettings, "ROTATE"));
  rotate->setOn(true);
  loopToggle_->onActivateSub(std::bind(&AudioScene::loopCallback, this, std::placeholders::_1));
  spatialToggle_->onActivateSub([this](const UiEventData&) { spatialCallback(); });
  rotate->onActivateSub(std::bind(&AudioScene::rotateCallback, this, std::placeholders::_1));
  layout->addItem(loopToggle_, kTogglePadding);
  layout->addItem(spatialToggle_, kTogglePadding);
  layout->addItem(rotate, kTogglePadding);
}

void AudioScene::loopCallback(const UiEventData& toggle) {
  audioNode_->setSoundLooping(UiToggle::CastFrom(toggle.getUiNode())->getOn());
}

void AudioScene::spatialCallback() {
  SpatialSoundDistanceProperties distProps;
  SpatialSoundRadiationProperties radProps;
  SpatialSoundSendLevels sendProps;

  bool isSpatial           = spatialToggle_->getOn();
  float outerAngle         = outerAngle_->getValue() * kMaxAngle;
  float innerAngle         = innerAngle_->getValue() * kMaxAngle;
  distProps.min_distance   = minDistance_->getValue();
  distProps.max_distance   = maxDistance_->getValue();
  float channelDistance    = channelDistance_->getValue();
  distProps.rolloff_factor = kRollOffFactor;
  radProps.outer_angle     = outerAngle;
  radProps.inner_angle     = innerAngle;
  radProps.outer_gain      = outerGain_->getValue();
  radProps.outer_gain_hf   = outerGainHf_->getValue();
  sendProps.gain           = gain_->getValue();
  sendProps.gain_lf        = gainLf_->getValue();
  sendProps.gain_mf        = gainMf_->getValue();
  sendProps.gain_hf        = gainHf_->getValue();

  spatialLayout_->setVisible(isSpatial);
  audioUI_->updateLayout();
  if (audioNode_) {
    audioNode_->setSpatialSoundEnable(isSpatial);
    for (uint32_t i = 0; i < channelCount_; ++i) {
      if (i % 2 == 0) {
        audioNode_->setSpatialSoundPosition(i, {channelDistance / -2.0f, 0.0f, 0.0f});
      } else {
        audioNode_->setSpatialSoundPosition(i, {channelDistance / 2.0f, 0.0f, 0.0f});
      }
      audioNode_->setSpatialSoundRadiationProperties(i, radProps);
      audioNode_->setSpatialSoundDistanceProperties(i, distProps);
      audioNode_->setSpatialSoundDirectSendLevels(i, sendProps);
      audioNode_->setSpatialSoundRoomSendLevels(i, sendProps);
    }
    if (isSpatial) {
      constructAudioGizmos(audioPrism_, audioNode_, channelCount_);
    } else {
      removeAudioGizmos(audioPrism_, audioNode_);
    }
  }
}

void AudioScene::rotateCallback(const UiEventData& toggle) {
  rotation_ = UiToggle::CastFrom(toggle.getUiNode())->getOn();
}

void AudioScene::createAudioPlayerSliders(UiLinearLayout* layout) {
  volume_ = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kRadialWithIcon,"", "", "", "",
          0.0f, 0.0f, SystemIcon::kVolume, SystemIcon::kVolumeMute));
  volume_->setValue(kAudioDefaultVal); // AudioNodes are set at 1.0f by default
  volume_->onSliderChangedSub([this](const UiEventData&) { volumeCallback(); });

  pitch_ = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kHorizontalWithLabel, "PITCH:    -1 OCTAVE", "+1 OCTAVE"));
  pitch_->setMinMax(kPitchMinVal, kPitchMaxVal);
  pitch_->setValue(kPitchStartVal);
  pitch_->onSliderChangedSub([this](const UiEventData&) { pitchCallback(); });
  layout->addItem(volume_);
  layout->addItem(pitch_, kPitchSliderPadding);
}

void AudioScene::volumeCallback() {
  float newVolume = volume_->getValue();
  audioNode_->setSoundVolumeLinear(newVolume * 8.0f); // volume is on a 0 to 8 scale
  bool muted = false;
  AudioState state;
  audioNode_->getSoundState(state);
  audioNode_->isSoundMuted(muted);
  if (newVolume == 0.0f) {
    noSound_ = true;
    audioHolder_->setVisible(false, true);
    muteModel_->setVisible(true);
  } else {
    noSound_ = false;
    if (state == AudioState::kStopped && !muted) {
      audioHolder_->setVisible(false, true);
      onModel_->setVisible(true);
    }
  }
}

void AudioScene::pitchCallback() {
  float pitchChange = pitch_->getValue();
  audioNode_->setSoundPitch(pitchChange);
  pitchText_->setText(ExampleHelpers::floatToString((pitchChange - kPitchStartVal) * 100.00f) + "%");
}

void AudioScene::createSpatialAngleSliders(UiLinearLayout* layout) {
  UiText* outerText    = SDKExamples::createEclipseLabel(getPrism(), "OUTER ANGLE:", EclipseLabelType::kB4);
  UiText* innerText    = SDKExamples::createEclipseLabel(getPrism(), "INNER ANGLE:", EclipseLabelType::kB4);
  UiText* outerGText   = SDKExamples::createEclipseLabel(getPrism(), "OUTER GAIN:", EclipseLabelType::kB4);
  UiText* outerHFGText = SDKExamples::createEclipseLabel(getPrism(), "OUTER HF GAIN:", EclipseLabelType::kB4);
  outerAngle_          = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kRadialWithIcon, SystemIcon::kWifi));
  float outerAngle = kOuterDefaultAngle / kMaxAngle;
  outerAngle_->setValue(outerAngle);
  outerAngle_->onSliderChangedSub(std::bind(&AudioScene::outerAngleCallback, this, std::placeholders::_1));

  innerAngle_ = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kRadialWithIcon, SystemIcon::kWifiOneBar));
  float innerAngle = kInnerDefaultAngle / kMaxAngle;
  innerAngle_->setValue(innerAngle);
  innerAngle_->onSliderChangedSub(std::bind(&AudioScene::innerAngleCallback, this, std::placeholders::_1));

  outerGain_ = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kRadialWithIconSmall, SystemIcon::kVolume));
  outerGain_->setValue(kAudioMaxVal);  // AudioNodes are set to maximum outer gain by default
  outerGain_->onSliderChangedSub(std::bind(&AudioScene::outerGainCallback, this, std::placeholders::_1));
  outerGain_->setName(kOuterName);

  outerGainHf_ = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kRadialWithIconSmall, SystemIcon::kVolume));
  outerGainHf_->setValue(kAudioMaxVal);  // AudioNodes are set to maximum inner gain by default
  outerGainHf_->onSliderChangedSub(std::bind(&AudioScene::outerGainCallback, this, std::placeholders::_1));
  outerGainHf_->setName(kOuterHFName);

  layout->addItem(innerText, 2.0f * ExampleConsts::kDefaultPadding, Alignment::CENTER_CENTER);
  layout->addItem(innerAngle_);
  layout->addItem(outerText, 2.0f * ExampleConsts::kDefaultPadding, Alignment::CENTER_CENTER);
  layout->addItem(outerAngle_);
  layout->addItem(outerGText, 2.0f * ExampleConsts::kDefaultPadding, Alignment::CENTER_CENTER);
  layout->addItem(outerGain_, 2.0f * ExampleConsts::kDefaultPadding, Alignment::CENTER_CENTER);
  layout->addItem(outerHFGText, 2.0f * ExampleConsts::kDefaultPadding, Alignment::CENTER_CENTER);
  layout->addItem(outerGainHf_, 2.0f * ExampleConsts::kDefaultPadding, Alignment::CENTER_CENTER);
}

// make sure outer angle is greater than or equal to the inner angle
void AudioScene::outerAngleCallback(const UiEventData&) {
  SpatialSoundRadiationProperties props;
  if (outerAngle_->getValue() < innerAngle_->getValue()) {
    outerAngle_->setValue(innerAngle_->getValue());
  }
  float angle = outerAngle_->getValue() * kMaxAngle;
  for (uint32_t i = 0; i < channelCount_; ++i) {
    if (audioNode_) {
      audioNode_->getSpatialSoundRadiationProperties(i, props);
      props.outer_angle = angle;
      audioNode_->setSpatialSoundRadiationProperties(i, props);
    }
  }
  outerLabel_->setText(std::to_string(static_cast<int>(angle)) + "°");
  if (angle > 100.0f) {
    outerLabel_->setLocalPosition(kBigRadialSliderTextOffset);
  } else {
    outerLabel_->setLocalPosition(kRadialSliderTextOffset);
  }
  constructAudioGizmos(audioPrism_, audioNode_, channelCount_);
}

// make sure the inner angle is less than or equal to the outer angle
void AudioScene::innerAngleCallback(const UiEventData&) {
  SpatialSoundRadiationProperties props;
  if (innerAngle_->getValue() > outerAngle_->getValue()) {
    innerAngle_->setValue(outerAngle_->getValue());
  }
  float angle = innerAngle_->getValue() * kMaxAngle;
  for (uint32_t i = 0; i < channelCount_; ++i) {
    if (audioNode_) {
      audioNode_->getSpatialSoundRadiationProperties(i, props);
      props.inner_angle = angle;
      audioNode_->setSpatialSoundRadiationProperties(i, props);
    }
  }
  innerLabel_->setText(std::to_string(static_cast<int>(angle)) + "°");
  if (angle > 100.0f) {
    innerLabel_->setLocalPosition(kBigRadialSliderTextOffset);
  } else {
    innerLabel_->setLocalPosition(kRadialSliderTextOffset);
  }
  constructAudioGizmos(audioPrism_, audioNode_, channelCount_);
}

void AudioScene::createSpatialGainSliders(UiLinearLayout* layout) {
  auto setupGain = [this, layout](const std::string& title, const std::string& name) -> UiSlider* {
    UiText* text   = SDKExamples::createEclipseLabel(getPrism(), title, EclipseLabelType::kB4);
    UiSlider* gain = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kRadialWithIconSmall, SystemIcon::kVolume));
    gain->setValue(kAudioMaxVal);  // AudioNodes are set to maximum outer gain by default
    gain->onSliderChangedSub(std::bind(&AudioScene::gainCallback, this, std::placeholders::_1));
    gain->setName(name);
    layout->addItem(text, 2.0f * ExampleConsts::kDefaultPadding, Alignment::CENTER_CENTER);
    layout->addItem(gain);
    return gain;
  };
  gain_   = setupGain("GAIN:", kGainName);
  gainLf_ = setupGain("LF GAIN:", kGainLFName);
  gainMf_ = setupGain("MF GAIN:", kGainMFName);
  gainHf_ = setupGain("HF GAIN:", kGainHFName);
}

void AudioScene::outerGainCallback(const UiEventData& slider) {
  SpatialSoundRadiationProperties props;
  bool hf    = UiSlider::CastFrom(slider.getUiNode())->getName() == kOuterHFName;
  float gain = UiSlider::CastFrom(slider.getUiNode())->getValue();

  for (uint32_t i = 0; i < channelCount_; ++i) {
    audioNode_->getSpatialSoundRadiationProperties(i, props);
    if (hf) {
      props.outer_gain_hf = gain;
    } else {
      props.outer_gain = gain;
    }
    audioNode_->setSpatialSoundRadiationProperties(i, props);
  }
}

void AudioScene::gainCallback(const UiEventData& slider) {
  SpatialSoundSendLevels levels;
  float gain = UiSlider::CastFrom(slider.getUiNode())->getValue();

  for (uint32_t i = 0; i < channelCount_; ++i) {
    audioNode_->getSpatialSoundDirectSendLevels(i, levels);
    if (UiSlider::CastFrom(slider.getUiNode())->getName() == kGainName) {
      levels.gain = gain;
    } else if (UiSlider::CastFrom(slider.getUiNode())->getName() == kGainLFName) {
      levels.gain_lf = gain;
    } else if (UiSlider::CastFrom(slider.getUiNode())->getName() == kGainMFName) {
      levels.gain_mf = gain;
    } else if (UiSlider::CastFrom(slider.getUiNode())->getName() == kGainHFName) {
      levels.gain_hf = gain;
    }
    audioNode_->setSpatialSoundDirectSendLevels(i, levels);
    audioNode_->setSpatialSoundRoomSendLevels(i, levels);
  }
}

void AudioScene::createSpatialDistanceSliders(UiLinearLayout* layout) {
  minDistance_ = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kHorizontalWithLabel, "MIN DISTANCE:", "", 0.0f, kSliderWidth));
  minDistance_->setMinMax(kMinDistMinVal, kMinDistMaxVal);
  minDistance_->setValue((kMinDistMinVal + kMinDistMaxVal) / 2.0f);
  minDistance_->onSliderChangedSub(std::bind(&AudioScene::minDistanceCallback, this,
      std::placeholders::_1));

  maxDistance_ = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kHorizontalWithLabel, "MAX DISTANCE:", "", 0.0f, kSliderWidth));
  maxDistance_->setMinMax(kMaxDistMinVal, kMaxDistMaxVal);
  maxDistance_->setValue((kMaxDistMinVal + kMaxDistMaxVal) / 2.0f);
  maxDistance_->onSliderChangedSub(std::bind(&AudioScene::maxDistanceCallback, this,
      std::placeholders::_1));

  channelDistance_ = SDKExamples::createEclipseSlider(getPrism(),
      EclipseSliderParams(EclipseSliderType::kHorizontalWithLabel, "CHANNEL DISTANCE:", "", 0.0f, kSliderWidth));
  channelDistance_->setValue(0.5f);
  channelDistance_->onSliderChangedSub(std::bind(&AudioScene::channelDistanceCallback, this,
      std::placeholders::_1));

  layout->addItem(minDistance_, kDistancePadding);
  layout->addItem(maxDistance_, kDistancePadding);
  layout->addItem(channelDistance_);
}

void AudioScene::minDistanceCallback(const UiEventData&) {
  SpatialSoundDistanceProperties props;
  if (minDistance_->getValue() > maxDistance_->getValue()) {
    minDistance_->setValue(maxDistance_->getValue());
  }
  float min_distance = minDistance_->getValue();
  for (uint32_t i = 0; i < channelCount_; ++i) {
    audioNode_->getSpatialSoundDistanceProperties(i, props);
    props.min_distance = min_distance;
    audioNode_->setSpatialSoundDistanceProperties(i, props);
  }
  minText_->setText(ExampleHelpers::floatToString(min_distance) + " m");
  constructAudioGizmos(audioPrism_, audioNode_, channelCount_);
}

void AudioScene::maxDistanceCallback(const UiEventData&) {
  SpatialSoundDistanceProperties props;
  if (maxDistance_->getValue() < minDistance_->getValue()) {
    maxDistance_->setValue(minDistance_->getValue());
  }
  float max_distance = maxDistance_->getValue();
  for (uint32_t i = 0; i < channelCount_; ++i) {
    audioNode_->getSpatialSoundDistanceProperties(i, props);
    props.max_distance = max_distance;
    audioNode_->setSpatialSoundDistanceProperties(i, props);
  }
  maxText_->setText(ExampleHelpers::floatToString(max_distance) + " m");
  constructAudioGizmos(audioPrism_, audioNode_, channelCount_);
}

void AudioScene::channelDistanceCallback(const UiEventData&) {
  float channelDistance = channelDistance_->getValue();
  for (uint32_t i = 0; i < channelCount_; ++i) {
    if (i % 2 == 0) {
      audioNode_->setSpatialSoundPosition(i, {channelDistance / -2.0f, 0.0f, 0.0f});
    } else {
      audioNode_->setSpatialSoundPosition(i, {channelDistance / 2.0f, 0.0f, 0.0f});
    }
  }
  channelText_->setText(ExampleHelpers::floatToString(channelDistance) + " m");
  constructAudioGizmos(audioPrism_, audioNode_, channelCount_);
}

void AudioScene::pause() {
  if (audioNode_) {
    if (moving_) {
      audioNode_->pauseSound();
      moving_ = false;
    }
  }
  if (audioLabel_) {
    audioLabel_->fadeOut();
  }
}

void AudioScene::play() {
  if (audioNode_) {
    if (firstPlay_) {
      audioNode_->startSound();
      stopButton_->setEnabled(true);
      firstPlay_ = false;
    } else if (!moving_) {
      audioNode_->resumeSound();
    }
  }
  if (audioLabel_) {
    audioLabel_->fadeIn();
  }
}

void AudioScene::onUpdate(float a_fDelta) {
  if (moving_ && rotation_ && audioParent_) {
    audioPlacer_+= kTime;
    if (audioPlacer_ >= 12.0f) {
      audioPlacer_ -= 12.0f;
    }
    glm::quat rotation = glm::angleAxis(audioPlacer_ * glm::half_pi<float>() / 3.0f, lumin::VEC3_UP);
    audioParent_->setLocalRotation(rotation);
  }
  if (audioLabel_) {
    audioLabel_->update(a_fDelta);
  }
}

bool AudioScene::onEvent(ServerEvent* an_Event) {
  ServerEventTypeValue eventType = an_Event->getServerEventTypeValue();
  bool consumedEvent = false;
  if (eventType == AudioEvent::GetServerEventTypeValue()) {
    AudioEvent* audioEvent        = static_cast<AudioEvent*>(an_Event);
    AudioEventType audioEventType = audioEvent->getAudioEventType();
    AudioState state;
    if (audioNode_ && audioEventType == AudioEventType::kPlayEnd) {
      consumedEvent = true;
      bool muted    = false;
      audioNode_->getSoundState(state);
      audioNode_->isSoundMuted(muted);
      if (state == AudioState::kStopped) {
        moving_ = false;
        audioParent_->stopTransformAnimations();
        audioParent_->rotateTo(QUAT_IDENTITY, kMoveTime);
        audioPlacer_ = 0.0f;
        pauseResumeButton_->setText(kPlay);
        if (!muted && !noSound_) {
          audioHolder_->setVisible(false, true);
          offModel_->setVisible(true);
        }
        if (!firstPlay_) {
          firstPlay_ = true;
        }
      } else if (state == AudioState::kPlaying) {
        pauseResumeButton_->setText(kPause);
        if (!muted && !noSound_) {
          audioHolder_->setVisible(false, true);
          playModel_->setVisible(true);
        }
      } else if (state == AudioState::kPaused) {
        pauseResumeButton_->setText(kPlay);
        if (!muted && !noSound_) {
          audioHolder_->setVisible(false, true);
          onModel_->setVisible(true);
        }
      }
    }
  }
  return consumedEvent;
}

void AudioScene::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "AudioExample::onDetachPrism() Destroying the Audio scene");

  // delete these nodes first, since they may not be added to the scene graph:
  Node::Delete(outputAudio_);
  Node::Delete(streamedAudio_);
  Node::Delete(loadedAudio_);

  delete[] streamedFileBuf_;
  delete audioLabel_;
  deleteSceneGraph();

  // delete the audio prism:
  application_.deleteAudioPrism();

  audioLabel_        = nullptr;
  prefab_            = nullptr;
  modelPrefab_       = nullptr;
  spatialLayout_     = nullptr;
  playModel_         = nullptr;
  onModel_           = nullptr;
  offModel_          = nullptr;
  muteModel_         = nullptr;
  channelText_       = nullptr;
  maxText_           = nullptr;
  minText_           = nullptr;
  innerLabel_        = nullptr;
  outerLabel_        = nullptr;
  pitchText_         = nullptr;
  channelDistance_   = nullptr;
  maxDistance_       = nullptr;
  minDistance_       = nullptr;
  outerGain_         = nullptr;
  outerGainHf_       = nullptr;
  gain_              = nullptr;
  gainLf_            = nullptr;
  gainMf_            = nullptr;
  gainHf_            = nullptr;
  innerAngle_        = nullptr;
  outerAngle_        = nullptr;
  pitch_             = nullptr;
  volume_            = nullptr;
  spatialToggle_     = nullptr;
  loopToggle_        = nullptr;
  muteButton_        = nullptr;
  pauseResumeButton_ = nullptr;
  stopButton_        = nullptr;
  audioSwitcher_     = nullptr;
  audioUI_           = nullptr;
  audioHolder_       = nullptr;
  audioNode_         = nullptr;
  outputAudio_       = nullptr;
  streamedAudio_     = nullptr;
  loadedAudio_       = nullptr;
  lumin::SDKExamples::BasePrismController::onDetachPrism(prism);
}