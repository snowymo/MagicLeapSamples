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

// %SRC_VERSION%: 2

#include <AudioExample.h>
#include <AudioScene.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>

#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const uint32_t kChannels = 2; // sound used is stereo, and has 2 channels
  const glm::vec3 kPrismExtents(2.0f, 1.0f, 0.2f);
  const glm::vec3 kLayoutOffset(0.01f, -0.3f, 0.05f);
  const std::string kAudioPath  = "pipeline/SourceArt/ML_AUD_Example.wav";
  const std::string kAudioTitle = "MagicLeap Audio";
}

AudioBaseApp::AudioBaseApp() {

}

AudioBaseApp::~AudioBaseApp() {
  customPrismDeleters_.clear();
  audioResources_.clear();
  streamedAudioResources_.clear();
}

bool AudioBaseApp::isAudioPrism() const {
  return (audioPrism_ != nullptr);
}

std::weak_ptr<lumin::Prism> AudioBaseApp::getAudioPrism(const glm::vec3& size) {
  if (!audioPrism_) {
    auto prismDeletion = [this](Prism* prism) {
      for (auto functionHolder : customPrismDeleters_) {
        functionHolder.first(prism);
      }
      deleteAllResources();
    };
    audioPrism_.reset(requestNewPrism(size), prismDeletion);
    audioPrism_->onDestroyEventSub([this](Prism*) {
      audioPrism_.reset();
    });
    setCollisionsEnabled(audioPrism_.get(), false);
    Cursor::SetEnabled(audioPrism_.get(), false);
  }
  return audioPrism_;
}

lumin::utils::CallbackID AudioBaseApp::addPrismDeleter(const std::function<void(lumin::Prism*)>& callback) {
  lumin::utils::CallbackID callbackID;
  customPrismDeleters_.emplace_back(std::make_pair(callback, callbackID));
  return callbackID;
}

bool AudioBaseApp::removePrismDeleter(const lumin::utils::CallbackID& callbackID) {
  for (auto it = customPrismDeleters_.begin(); it != customPrismDeleters_.end(); ++it) {
    if ((*it).second == callbackID) {
      customPrismDeleters_.erase(it);
      return true;
    }
  }
  return false;
}

void AudioBaseApp::deleteAudioPrism() {
  deletePrism(audioPrism_.get());
}

ResourceIDType AudioBaseApp::createAudioResource(const std::string& audioPath) {
  if (!audioPrism_) {
    getAudioPrism();
  }
  ResourceIDType res = audioPrism_->createLoadedFileAudioResourceId(audioPath.c_str());
  audioResources_.push_back(res);
  return res;
}

ResourceIDType AudioBaseApp::createStreamedAudioResource(const std::string& audioPath) {
  if (!audioPrism_) {
    getAudioPrism();
  }
  ResourceIDType res = audioPrism_->createStreamedFileAudioResourceId(audioPath.c_str());
  streamedAudioResources_.push_back(res);
  return res;
}

std::vector<ResourceIDType> AudioBaseApp::getAudioResources() const {
  return audioResources_;
}
std::vector<ResourceIDType> AudioBaseApp::getStreamedAudioResources() const {
  return streamedAudioResources_;
}

void AudioBaseApp::deleteAllResources() {
  if (audioPrism_) {
    for (ResourceIDType res : audioResources_) {
      audioPrism_->destroyResource(res);
    }
    for (ResourceIDType res : streamedAudioResources_) {
      audioPrism_->destroyResource(res);
    }
  }
  audioResources_.clear();
  streamedAudioResources_.clear();
}

AudioExample::AudioExample() {
  ML_LOG(Debug, "AudioExample constructor");
}

AudioExample::~AudioExample() {
  ML_LOG(Debug, "AudioExample destructor");
}

int AudioExample::init() {
  ML_LOG(Debug, "AudioExample initializing");

  // create a new prism for the UI:
  prism_ = SDKExamples::assertPrism(requestNewPrism(kPrismExtents));
  glm::vec3 prismSize = prism_->getSize();

  // change the size to clamp to the UI.
  glm::vec3 position  = glm::vec3(0.0f, prismSize.y / 3.01f, -prismSize.z / 2.0f) + kLayoutOffset;  // set the UI in the back of the prism
  Cursor::SetScale(prism_, ExampleConsts::kCursorScale);
  Cursor::SetPlaneDepth(prism_, position.z);  // same depth as the Audio UI

  audioScene_ = std::make_shared<lumin::SDKExamples::BaseExampleController>("Audio Controller",
    position,
    std::make_shared<AudioScene>(*this, kAudioTitle, kAudioPath, kChannels),
    std::make_shared<AudioScene>(*this, kAudioTitle, kAudioPath, kChannels));
  prism_->setPrismController(audioScene_);
  return 0;
}

int AudioExample::deInit() {
  ML_LOG(Debug, "AudioExample uninitializing");

  // All prisms are deleted before deInit() is called
  prism_ = nullptr;
  return 0;
}

void AudioExample::onAppPause() {
  ML_LOG(Debug, "AudioExample pausing");
  if (audioScene_ && audioScene_->getActiveController()) {
    audioScene_->getActiveController()->onAppPause();
  }
}

void AudioExample::onAppResume() {
  ML_LOG(Debug, "AudioExample resuming");
  if (audioScene_ && audioScene_->getActiveController()) {
    audioScene_->getActiveController()->onAppResume();
  }
}