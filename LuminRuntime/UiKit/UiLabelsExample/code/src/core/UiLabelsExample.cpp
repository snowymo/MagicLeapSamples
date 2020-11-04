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
#include <UiLabelsExample.h>
#include <EclipseLabels.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>

#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.0f, 0.6f, 0.1f);
}

UiLabelsExample::UiLabelsExample() {
  ML_LOG(Debug, "UiLabelsExample constructor");
}

UiLabelsExample::~UiLabelsExample() {
  ML_LOG(Debug, "UiLabelsExample destructor");
}

int UiLabelsExample::init() {
  ML_LOG(Debug, "UiLabelsExample initializing");
  return 0;
}

void UiLabelsExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiLabelsExample creating instance");
  // Create a prism.
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<EclipseLabels>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiLabelsExample::deInit() {
  ML_LOG(Debug, "UiLabelsExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
