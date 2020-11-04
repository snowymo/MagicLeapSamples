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
#include <CircleConfirmation.h>
#include <CircleConfirmationLayout.h>
#include <CircleConfirmationPrefab.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesDefines.h>
#include <scenes.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kStartLine(-0.3f, 0.0f, 0.0f);
  const glm::vec3 kEndLine(0.3f, 0.0f, 0.0f);
  const glm::vec4 kGrey(0.403f, 0.403f, 0.403f, 1.0f);  // (165, 165, 165)
}

// Create a Prism Controller with the identifier 'UiKit Circle Confirmation' to be used in diagnostics:
CircleConfirmation::CircleConfirmation() : BaseExample("UiKit Circle Confirmation") {
}

CircleConfirmation::~CircleConfirmation() {

}

// Create and display the UiKit's Circle Confirmation widget.
// Add a reset button which resets the Circle Confirmation widget.
void CircleConfirmation::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "CircleConfirmation::onAttachPrism() Initializing the Circle Confirmation scene");
  lumin::SDKExamples::BaseExample::onAttachPrism(prism);
}

void CircleConfirmation::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "CircleConfirmation::onDetachPrism() Destroying the Circle Confirmation scene");
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}

TransformNode* CircleConfirmation::loadSceneGraph(Prism* prism) {
  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  prefabs::CircleConfirmationLayout* layout = managers_->extendedPrefab_->spawn<prefabs::CircleConfirmationLayout>();
  prefabs::CircleConfirmationPrefab* prefab = managers_->extendedPrefab_->spawn<prefabs::CircleConfirmationPrefab>();
  LUMIN_ASSERT(layout, "Failed to create CircleConfirmationLayout");
  LUMIN_ASSERT(prefab, "Failed to create CircleConfirmationPrefab");

  prefab->setLayout(layout);
  layout->setCircleConfirmationPrefab(prefab);
  layout->getCCM_Placeholder()->addChild(prefab->getRoot());
  prefab->getCCM_CircleConfirmation()->updateLayout();
  rootContainer->addChild(layout->getRoot());
  return rootContainer;
}

TransformNode* CircleConfirmation::buildSceneGraph(Prism* prism) {
  UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
  topLayout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  topLayout->setDefaultItemAlignment(Alignment::TOP_CENTER);
  topLayout->setAlignment(Alignment::CENTER_CENTER);

  TransformNode* placeholder = SDKExamples::createTransformNode(prism);
  UiCircleConfirmation* conf = SDKExamples::createUiCircleConfirmation(prism);
  placeholder->addChild(conf);
  topLayout->addItem(placeholder);

  UiText* statusMessage = SDKExamples::createUiText(prism, "Complete the Circle Confirmation");
  statusMessage->setTextSize(ExampleConsts::kTextSize);
  topLayout->addItem(statusMessage);

  UiTab* resetButton = SDKExamples::createUiTab(prism, "Click to Reset Circle Confirmation");
  resetButton->setTextSize(ExampleConsts::kTextSize);
  resetButton->onActivateSub(std::bind(&CircleConfirmation::activateCallback, this, std::placeholders::_1,
      prism, placeholder, statusMessage));
  topLayout->addItem(resetButton);

  editCircleConfirmation(prism, conf, statusMessage);
  return topLayout;
}

void CircleConfirmation::editCircleConfirmation(Prism* prism,
    UiCircleConfirmation* confirmationNode, UiText* statusMessage) {
  confirmationNode->onActivateSub([statusMessage, this](const UiEventData&) {
    statusMessage->setText("Press the home button to cancel");
  });
  confirmationNode->onConfirmationCompleteSub([statusMessage, this](const UiEventData&) {
    statusMessage->setText("Completed confirmation");
  });
  confirmationNode->onConfirmationCanceledSub([statusMessage](const UiEventData&) {
    statusMessage->setText("Confirmation canceled");
  });
  confirmationNode->onConfirmationUpdateSub([statusMessage](const UiEventData&,
      const float ratioTowardConfirmation) {
    statusMessage->setText(std::to_string(static_cast<int>(ratioTowardConfirmation * 100)) +
    "% away from confirming");
  });
}

void CircleConfirmation::activateCallback(const UiEventData&, Prism* prism, TransformNode* placeholder,
    UiText* statusMessage) {
  Node::Delete(placeholder->getChild(0));
  UiCircleConfirmation* confirmationNode = SDKExamples::createUiCircleConfirmation(prism);
  placeholder->addChild(confirmationNode);
  editCircleConfirmation(prism, confirmationNode, statusMessage);
  statusMessage->setText("Complete the Circle Confirmation");
}