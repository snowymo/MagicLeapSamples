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
#include <UiSystemIconsExample.h>
#include <SystemIcons.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>

#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.1f, 0.75f, 0.3f);
}

UiSystemIconsExample::UiSystemIconsExample() {
  ML_LOG(Debug, "UiSystemIconsExample constructor");
}

UiSystemIconsExample::~UiSystemIconsExample() {
  ML_LOG(Debug, "UiSystemIconsExample destructor");
}

int UiSystemIconsExample::init() {
  ML_LOG(Debug, "UiSystemIconsExample initializing");
  return 0;
}

void UiSystemIconsExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiSystemIconsExample creating instance");

  // create a new client prism:
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<SystemIcons>());  // add a scene to the prism

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiSystemIconsExample::deInit() {
  ML_LOG(Debug, "UiSystemIconsExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
