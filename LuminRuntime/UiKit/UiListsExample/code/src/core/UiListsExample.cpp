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
#include <UiListsExample.h>
#include <ListsLayout.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>

#include <lumin/Prism.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.0f, 1.0f, 0.3f);
}

UiListsExample::UiListsExample() {
  ML_LOG(Debug, "UiListsExample constructor");
}

UiListsExample::~UiListsExample() {
  ML_LOG(Debug, "UiListsExample destructor");
}

int UiListsExample::init() {
  ML_LOG(Debug, "UiListsExample initializing");
  return 0;
}

void UiListsExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiListsExample creating instance");

  // Create a prism.
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<ListsLayout>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiListsExample::deInit() {
  ML_LOG(Debug, "UiListsExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
