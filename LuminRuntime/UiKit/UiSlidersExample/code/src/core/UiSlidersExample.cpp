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
#include <UiSlidersExample.h>
#include <SlidersLayout.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

UiSlidersExample::UiSlidersExample() {
  ML_LOG(Debug, "UiSlidersExample constructor");
}

UiSlidersExample::~UiSlidersExample() {
  ML_LOG(Debug, "UiSlidersExample destructor");
}

int UiSlidersExample::init() {
  ML_LOG(Debug, "UiSlidersExample initializing");
  return 0;
}

void UiSlidersExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiSlidersExample creating instance");
  const glm::vec3 kPrismSize(1.0f, 1.0f, 0.1f);

  // Create a prism controller for the scene graph built in code and add to prism.
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<SlidersLayout>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiSlidersExample::deInit() {
  ML_LOG(Debug, "UiSlidersExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
