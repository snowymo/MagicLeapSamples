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
#include <UiWebViewExample.h>

#include <NodeCreationWrappers.h>
#include <lumin/ui/UiKit.h>
#include <lumin/ui/node/UiWebView.h>
#include <UiWebViewController.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kPrismSize(1.0f, 1.0f, 0.3f);
}

UiWebViewExample::UiWebViewExample() {}

UiWebViewExample::~UiWebViewExample() = default;

void UiWebViewExample::onAppStart(const InitArg&) {
  ML_LOG(Debug, "UiWebViewExample creating instance");
  // Creates a prism.
  Prism* prism = SDKExamples::assertPrism(requestNewPrism(kPrismSize));
  Cursor::SetScale(prism, 0.03f);
  prism->setPrismController(std::make_shared<UiWebViewController>("WebViewController"));
  // Rotate the prism towards the user.
  setBodyDynamic(prism, BodyDynamicType::kEdgeBillboard);
}
