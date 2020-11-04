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
#include <UiCircleConfirmationExample.h>
#include <CircleConfirmation.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>

#include <lumin/Prism.h>
#include <lumin/node/RootNode.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(0.7f, 0.5f, 0.1f);
}

UiCircleConfirmationExample::UiCircleConfirmationExample() {
  ML_LOG(Debug, "UiCircleConfirmationExample constructor");
}

UiCircleConfirmationExample::~UiCircleConfirmationExample() {
  ML_LOG(Debug, "UiCircleConfirmationExample destructor");
}

int UiCircleConfirmationExample::init() {
  ML_LOG(Debug, "UiCircleConfirmationExample initializing");
  return 0;
}

void UiCircleConfirmationExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiCircleConfirmationExample creating instance");
  // create a new client prism:
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);

  // add the circle confirmation scene to this prism:
  prism->setPrismController(std::make_shared<CircleConfirmation>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiCircleConfirmationExample::deInit() {
  ML_LOG(Debug, "UiCircleConfirmationExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
