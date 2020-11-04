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
#include <UiDialogsExample.h>
#include <DialogsLayout.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>

#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

namespace {
  const glm::vec3 kPrismSize(1.0f, 0.7f, 1.0f);
}

using namespace lumin;
using namespace lumin::ui;

UiDialogsExample::UiDialogsExample() {
  ML_LOG(Debug, "UiDialogsExample constructor");
}

UiDialogsExample::~UiDialogsExample() {
  ML_LOG(Debug, "UiDialogsExample destructor");
}

int UiDialogsExample::init() {
  ML_LOG(Debug, "UiDialogsExample initializing");
  return 0;
}

void UiDialogsExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiDialogsExample creating instance");

  // Create a prism.
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<DialogsLayout>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiDialogsExample::deInit() {
  ML_LOG(Debug, "UiDialogsExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
