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
#include <VideoExample.h>
#include <VideoScene.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>

#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const float kGravityWellDistance = 0.01f;
  const glm::vec2 kVideoResolution(1280u, 720u);  // resolution is in unsigned integers
  const glm::vec3 kPrismSize(1.3f, 1.1f, 0.3f);
  const std::string kVideoPath  = "res/ML_VID_Example.mp4";
  const std::string kVideoTitle = "Magic Leap Video";
}

VideoExample::VideoExample() {
  ML_LOG(Debug, "VideoExample constructor");
}

VideoExample::~VideoExample() {
  ML_LOG(Debug, "VideoExample destructor");
}

int VideoExample::init() {
  ML_LOG(Debug, "VideoExample initializing");

  // create a new prism:
  prism_ = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism_, ExampleConsts::kCursorScale);
  Cursor::SetGravityWellMaxDistance(prism_, kGravityWellDistance);
  prism_->setPrismController(std::make_shared<lumin::SDKExamples::BaseExampleController>("Video Controller",
      glm::vec3(0.0f),  // use the default position
      std::make_shared<VideoScene>(kVideoTitle, kVideoPath, kVideoResolution,
        ViewMode::kFullArea, false),
      std::make_shared<VideoScene>(kVideoTitle, kVideoPath, kVideoResolution,
        ViewMode::kFullArea, true)));
  videoScene_ = static_cast<lumin::SDKExamples::BaseExampleController*>(prism_->getPrismController());
  return 0;
}

int VideoExample::deInit() {
  ML_LOG(Debug, "VideoExample uninitializing");

  // All prisms are deleted before deInit() is called.
  prism_ = nullptr;
  return 0;
}

void VideoExample::onAppPause() {
  ML_LOG(Debug, "VideoExample pausing");
  if (videoScene_ && videoScene_->getActiveController()) {
    videoScene_->getActiveController()->onAppPause();
  }
}

void VideoExample::onAppResume() {
  ML_LOG(Debug, "VideoExample resuming");
  if (videoScene_ && videoScene_->getActiveController()) {
    videoScene_->getActiveController()->onAppResume();
  }
}