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
#include <PortalIcons.h>
#include <UiPortalIconsExample.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>

#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.2f, 1.0f, 1.0f);
}

UiPortalIconsExample::UiPortalIconsExample() {
  ML_LOG(Debug, "UiPortalIconsExample constructor");
}

UiPortalIconsExample::~UiPortalIconsExample() {
  ML_LOG(Debug, "UiPortalIconsExample destructor");
}

int UiPortalIconsExample::init() {
  ML_LOG(Debug, "UiPortalIconsExample initializing");
  return 0;
}

void UiPortalIconsExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiPortalIconsExample creating instance");

  // create a new client prism:
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<PortalIcons>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiPortalIconsExample::deInit() {
  ML_LOG(Debug, "UiPortalIconsExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
