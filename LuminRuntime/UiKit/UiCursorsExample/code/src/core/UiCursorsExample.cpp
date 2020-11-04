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
#include <UiCursorsExample.h>
#include <CursorsDisplay.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>

#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.3f, 0.9f, 0.1f);
}

UiCursorsExample::UiCursorsExample() {
  ML_LOG(Debug, "UiCursorsExample constructor");
}

UiCursorsExample::~UiCursorsExample() {
  ML_LOG(Debug, "UiCursorsExample destructor");
}

int UiCursorsExample::init() {
  ML_LOG(Debug, "UiCursorsExample initializing");
  return 0;
}

void UiCursorsExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiCursorsExample creating instance");
  // create a new client prism:
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));

  Cursor::SetScale(prism, ExampleConsts::kCursorScale);
  prism->setPrismController(std::make_shared<CursorsDisplay>());  // add the cursor scene to this prism

  // Have the prism rotate towards the user:
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}

int UiCursorsExample::deInit() {
  ML_LOG(Debug, "UiCursorsExample uninitializing");
  // All prisms are deleted before deInit() is called.
  return 0;
}
