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
#include <UiTextEditExample.h>
#include <TextEdit.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>

#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.3f, 0.9f, 0.1f);
}

UiTextEditExample::UiTextEditExample() {
  ML_LOG(Debug, "UiTextEditExample constructor");
}

UiTextEditExample::~UiTextEditExample() {
  ML_LOG(Debug, "UiTextEditExample destructor");
}

int UiTextEditExample::init() {
  ML_LOG(Debug, "UiTextEditExample initializing");
  return 0;
}

void UiTextEditExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiTextEditExample creating instance");

  // Create a prism controller for the scene graph built in code and add to prism.
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<TextEdit>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiTextEditExample::deInit() {
  ML_LOG(Debug, "UiTextEditExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
