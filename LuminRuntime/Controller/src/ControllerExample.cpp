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
#include <ControllerExample.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>
#include <lumin/node/RootNode.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(2.0f, 2.0f, 2.0f);
}

ControllerExample::ControllerExample() {
  ML_LOG(Debug, "ControllerExample constructor");
}

ControllerExample::~ControllerExample() {
  ML_LOG(Debug, "ControllerExample destructor");
}

int ControllerExample::init() {
  ML_LOG(Debug, "ControllerExample initializing");

  // create a new client prism:
  prism_ = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism_, ExampleConsts::kCursorScale);
  prism_->setPrismController(std::make_shared<ControllerScene>());
  return 0;
}

int ControllerExample::deInit() {
  ML_LOG(Debug, "ControllerExample uninitializing");

  // All prisms are deleted before deInit() is called.
  prism_ = nullptr;
  return 0;
}