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
#include <ParticleAndSpriteSpinners.h>
#include <UiLoadingSpinnersExample.h>
#include <ExamplesConstants.h>
#include <NodeCreationWrappers.h>

#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(0.9f, 0.6f, 0.2f);
}

UiLoadingSpinnersExample::UiLoadingSpinnersExample() {
  ML_LOG(Debug, "UiLoadingSpinnersExample constructor");
}

UiLoadingSpinnersExample::~UiLoadingSpinnersExample() {
  ML_LOG(Debug, "UiLoadingSpinnersExample destructor");
}

int UiLoadingSpinnersExample::init() {
  ML_LOG(Debug, "UiLoadingSpinnersExample initializing");
  return 0;
}

void UiLoadingSpinnersExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiLoadingSpinnerExample creating instance");
  // Create the prism for the code generated scene graph.
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<ParticleAndSpriteSpinners>());

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiLoadingSpinnersExample::deInit() {
  ML_LOG(Debug, "UiLoadingSpinnersExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
