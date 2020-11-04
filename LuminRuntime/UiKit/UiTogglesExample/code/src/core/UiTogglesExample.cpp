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
#include <UiTogglesExample.h>
#include <BaseExample.h>
#include <TogglesLayout.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>

#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.2f, 1.2f, 0.3f);
}

UiTogglesExample::UiTogglesExample() {
  ML_LOG(Debug, "UiTogglesExample constructor");
}

UiTogglesExample::~UiTogglesExample() {
  ML_LOG(Debug, "UiTogglesExample destructor");
}

int UiTogglesExample::init() {
  ML_LOG(Debug, "UiTogglesExample initializing");
  return 0;
}

void UiTogglesExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiTogglesExample creating instance");

  // create a new client prism:
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<TogglesLayout>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiTogglesExample::deInit() {
  ML_LOG(Debug, "UiTogglesExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
