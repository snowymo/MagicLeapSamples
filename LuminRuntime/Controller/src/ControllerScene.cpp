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
#include <ControllerScene.h>
#include <ControllerExample.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesHelpers.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;
using namespace lumin::utils;

namespace {
  const glm::vec2 kDirectionsSize(0.8f, 0.0f);
  const glm::vec3 kDirectionsOffset(0.0f, -0.1f, 0.1f);
}

ControllerScene::ControllerScene(): PrismController("Controller Example") {
}

void ControllerScene::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "ControllerScene::onAttachPrism() Initializing the Controller Scene");
  glm::vec3 prismSize = prism->getSize() * 0.95f;
  visualizer_ = std::make_shared<ControllerVisualizer>();
  addChildController(visualizer_);  // add the visualizer
  getRoot()->addChild(visualizer_->getRoot());

  UiLinearLayout* directionsLayout = SDKExamples::createUiLinearLayout(prism);
  directionsLayout->setAlignment(Alignment::CENTER_CENTER);
  directionsLayout->setOrientation(Orientation::kVertical);
  directionsLayout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  UiText* directions = SDKExamples::createEclipseLabel(prism, "", EclipseLabelType::kT2);
  directions->setBoundsSize(kDirectionsSize);
  directions->setText(R"(Controller model will follow the physical controller while it is in this Prism.

                          Press the trigger to enter and exit calibration for Mobile App Devices.)");
  prismSelected_ = SDKExamples::createEclipseLabel(prism, "", EclipseLabelType::kT2);
  prismSelected_->setBoundsSize(kDirectionsSize);
  prismSelected_->setTextColor(color::RED);
  directionsLayout->addItem(directions);
  directionsLayout->addItem(prismSelected_);
  directionsLayout->setLocalPosition(glm::vec3(0.0f, 0.0f, -prismSize.z / 2.01f) + kDirectionsOffset);
  getRoot()->addChild(directionsLayout);
}

void ControllerScene::onUpdate(float fDelta) {
  if (!getPrism()->isPrismSelected()) {
    prismSelected_->setText("Prism is not selected; please focus on this prism to interact with it.");
    LineNode* outline = visualizer_->getPrismOutline();
    outline->setColor(color::WHITE * 0.5f);
  } else if (prismSelected_->getText() != "") {
    prismSelected_->setText("");
    LineNode* outline = visualizer_->getPrismOutline();
    outline->setColor(color::MAGENTA);
  }
}

void ControllerScene::onDetachPrism(Prism*) {
  ML_LOG(Debug, "ControllerExample::onDetachPrism() Destroying the Controller Scene");
  deleteSceneGraph();
  visualizer_    = nullptr;
  prismSelected_ = nullptr;
}