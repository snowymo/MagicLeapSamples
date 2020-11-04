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
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesDefines.h>
#include <LoadingSpinners.h>

#include <lumin/node/LineNode.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

ParticleAndSpriteSpinners::ParticleAndSpriteSpinners()
  : BaseExample("Loading Spinners Example") {

}

ParticleAndSpriteSpinners::~ParticleAndSpriteSpinners() {
}

void ParticleAndSpriteSpinners::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "UiLoadingSpinnerExample::onAttachPrism() Initializing the Loading Spinner scene");
  lumin::SDKExamples::BaseExample::onAttachPrism(prism);
}

void ParticleAndSpriteSpinners::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "UiLoadingSpinnerExample::onDetachPrism() Destroying the Loading Spinner scene");
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}

TransformNode* ParticleAndSpriteSpinners::loadSceneGraph(Prism* prism) {
  prefabs::LoadingSpinners* prefab = managers_->extendedPrefab_->spawn<prefabs::LoadingSpinners>();
  LUMIN_ASSERT(prefab, "Failed to create LoadingSpinners prefab");

  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab->getRoot());
  return rootContainer;
}

TransformNode* ParticleAndSpriteSpinners::buildSceneGraph(Prism* prism) {
  const uint32_t kNumCols = 2;
  const glm::vec2 kLayoutSize(0.21f);
  const glm::vec2 kLoadingSpinnerSize(0.07f);
  const glm::vec3 kLineLocalPosStart(-0.4f, 0.0f, 0.0f);
  const glm::vec3 kLineLocalPosEnd(0.2f, 0.0f, 0.0f);
  const glm::vec4 kLineColor(0.6f, 0.6f, 0.6f, 1.0f);  // (200, 200, 200)
  const glm::vec4 kTitlePadding(0.0, 0.0f, 0.0f, 0.01f);
  const glm::vec4 kDefaultPadding(0.01, 0.1f, 0.01f, 0.04f);
  const glm::vec4 kItemTitlePadding(0.01, 0.1f, 0.0f, 0.04f);

  UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
  topLayout->setAlignment(Alignment::CENTER_CENTER);
  topLayout->setOrientation(Orientation::kVertical);
  topLayout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  topLayout->setDefaultItemAlignment(Alignment::TOP_CENTER);

  UiGridLayout* loadingSpinnerLayout = SDKExamples::createUiGridLayout(prism);
  loadingSpinnerLayout->setAlignment(Alignment::TOP_CENTER);
  loadingSpinnerLayout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  loadingSpinnerLayout->setColumns(kNumCols);

  UiText* particleTitle = SDKExamples::createEclipseLabel(prism, "Particle Spinner", EclipseLabelType::kT3);
  UiLoadingSpinner* particleSpinner = SDKExamples::createUiLoadingSpinner(prism, LoadingSpinnerType::kParticlePackage);
  UiRectLayout* particleLayout = SDKExamples::createUiRectLayout(prism);
  particleLayout->setSize(kLayoutSize);
  particleLayout->setContentAlignment(Alignment::CENTER_CENTER);
  particleLayout->setContent(particleSpinner);

  UiText* spriteTitle = SDKExamples::createEclipseLabel(prism, "Sprite Spinner", EclipseLabelType::kT3);
  UiLoadingSpinner* spriteSpinner = SDKExamples::createUiLoadingSpinner(prism, LoadingSpinnerType::k2dSpriteAnimation);
  spriteSpinner->setSize(kLoadingSpinnerSize);
  UiRectLayout* spriteLayout = SDKExamples::createUiRectLayout(prism);
  spriteLayout->setSize(kLayoutSize);
  spriteLayout->setContentAlignment(Alignment::CENTER_CENTER);
  spriteLayout->setContent(spriteSpinner);

  UiText* movePrismText = SDKExamples::createEclipseLabel(prism, "Try moving the prism!", EclipseLabelType::kT2);

  loadingSpinnerLayout->addItem(particleTitle, kDefaultPadding, Alignment::TOP_CENTER);
  loadingSpinnerLayout->addItem(spriteTitle, ExampleConsts::kDefaultPadding, Alignment::TOP_CENTER);
  loadingSpinnerLayout->addItem(particleLayout, kItemTitlePadding, Alignment::TOP_CENTER);
  loadingSpinnerLayout->addItem(spriteLayout, ExampleConsts::kTitlePadding, Alignment::TOP_CENTER);

  topLayout->addItem(loadingSpinnerLayout, ExampleConsts::kDefaultPadding, Alignment::TOP_LEFT);
  topLayout->addItem(movePrismText, ExampleConsts::kDefaultPadding, Alignment::TOP_CENTER);
  return topLayout;
}