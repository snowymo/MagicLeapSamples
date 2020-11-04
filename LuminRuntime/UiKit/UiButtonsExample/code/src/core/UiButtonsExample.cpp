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

#include <UiButtonsExample.h>
#include <BaseExample.h>
#include <ButtonsLayout.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>
#include <glm/gtx/string_cast.hpp>
#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.0f, 1.0f, 0.3f);
}

UiButtonsExample::UiButtonsExample() {
  ML_LOG(Debug, "UiButtonsExample constructor");
}

UiButtonsExample::~UiButtonsExample() {
  ML_LOG(Debug, "UiButtonsExample destructor");
}

int UiButtonsExample::init() {
  ML_LOG(Debug, "UiButtonsExample initializing");
  return 0;
}

void UiButtonsExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiButtonsExample creating instance");
  // Create a prism:
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<ButtonsLayout>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiButtonsExample::deInit() {
  ML_LOG(Debug, "UiButtonsExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
