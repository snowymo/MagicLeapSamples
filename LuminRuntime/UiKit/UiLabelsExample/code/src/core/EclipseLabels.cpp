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
#include <EclipseLabels.h>
#include <NodeCreationWrappers.h>
#include <EclipseLabelsPrefab.h>
#include <ExamplesConstants.h>
#include <ExamplesDefines.h>
#include <lumin/Prism.h>
#include <lumin/node/LineNode.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const float kCircleTextSize = 0.02f;
  const uint32_t kLabelRows   = 7;
  const uint32_t kLabelCols   = 2;
  const glm::vec2 kCircleSize(0.03f, 0.03f);
  const glm::vec2 kLabelSize(0.0f, 0.04f);
  const glm::vec3 kLayoutPos(0.0f, 0.0f, 0.0f);
  const glm::vec4 kCircleColor(0.1f, 0.3f, 1.0f, 1.0f);
  const glm::vec4 kCirclePadding(0.0f, 0.01f, 0.0f, 0.0f);
  const std::string kCirclePath = "pipeline/SourceArt/Circle.png";
}


// Construct a PrismController with the identifier 'UiKit Labels' to be used in diagnostics:
EclipseLabels::EclipseLabels()
  : BaseExample("UiKit Labels"),
    labelLayout_(nullptr) {
}

EclipseLabels::~EclipseLabels() {
}

// Create the scene when it is attached to a prism:
// Eclipse Labels are sorted into columns based on their type: Label Headers (T),
// Label Body (B), and Label All CAPS (C).
void EclipseLabels::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "EclipseLabels::onAttachPrism() Initializing the Eclipse Labels scene");
  lumin::SDKExamples::BaseExample::onAttachPrism(prism);
}

// Destroys all nodes when the scene is removed from a prism:
void EclipseLabels::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "EclipseLabels::onDetachPrism() Destroying the Eclipse Labels scene");
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}

TransformNode* EclipseLabels::loadSceneGraph(Prism* prism) {
  prefabs::EclipseLabelsPrefab* prefab = managers_->extendedPrefab_->spawn<prefabs::EclipseLabelsPrefab>();
  LUMIN_ASSERT(prefab, "Failed to create EclipseLabelsPrefab");

  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab->getRoot());
  return rootContainer;
}

TransformNode* EclipseLabels::buildSceneGraph(Prism* prism) {
  UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);

  labelLayout_ = SDKExamples::createUiGridLayout(prism);
  labelLayout_->setAlignment(Alignment::CENTER_CENTER);
  labelLayout_->setColumns(kLabelCols);
  labelLayout_->setRows(kLabelRows);
  labelLayout_->setSkipInvisibleItems(false);
  labelLayout_->setDefaultItemAlignment(Alignment::TOP_LEFT);
  labelLayout_->setDefaultItemPadding(ExampleConsts::kDefaultPadding);

  makeLabel(prism, EclipseLabelType::kT1, "T1", "Page Title (Top of screen)");
  makeLabel(prism, EclipseLabelType::kB1, "B1", "Label/Body - MEDIUM");
  makeLabel(prism, EclipseLabelType::kT2, "T2", "Title/Label - LARGE");
  makeLabel(prism, EclipseLabelType::kB2, "B2", "Label/Body - SMALL");
  makeLabel(prism, EclipseLabelType::kT3, "T3", "Title/Label - MEDIUM");
  makeLabel(prism, EclipseLabelType::kB3, "B3", "Label/Body - X-SMALL");
  makeLabel(prism, EclipseLabelType::kT4, "T4", "Title/Label - SMALL");
  makeLabel(prism, EclipseLabelType::kB4, "B4", "Label/Body - LARGE");
  makeLabel(prism, EclipseLabelType::kT5, "T5", "Title/Label - EXTRA SMALL");
  makeLabel(prism, EclipseLabelType::kC1, "C1", "CAPS Title - LARGE");
  makeLabel(prism, EclipseLabelType::kT6, "T6", "XX LARGE");
  makeLabel(prism, EclipseLabelType::kC2, "C2", "CAPS Title - MEDIUM");
  makeLabel(prism, EclipseLabelType::kT7, "T7", "X LARGE");
  makeLabel(prism, EclipseLabelType::kC3, "C3", "CAPS Title - SMALL");
  labelLayout_->addItem(SDKExamples::createTransformNode(prism));  // add empty items for alignment
  makeLabel(prism, EclipseLabelType::kC4, "C4", "CAPS Title - X-SMALL");

  topLayout->addItem(labelLayout_);
  return topLayout;
}

void EclipseLabels::makeLabel(Prism* prism, EclipseLabelType type, const std::string& typeLabel,
    const std::string& descrLabel) {
  UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
  layout->setOrientation(Orientation::kHorizontal);
  layout->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  layout->setAlignment(Alignment::TOP_LEFT);

  TransformNode* circle = SDKExamples::createTransformNode(prism);
  UiText* circleLabel   = SDKExamples::createEclipseLabel(prism, typeLabel, type);
  circleLabel->setTextSize(kCircleTextSize);
  circleLabel->setLocalPosition(ExampleConsts::kDefaultForeground);
  circleLabel->setAlignment(Alignment::CENTER_CENTER);
  circle->addChild(circleLabel);
  UiImage* circleImage = SDKExamples::createUiImage(prism, kCirclePath,
      kCircleSize.x, kCircleSize.y);
  circleImage->setIsOpaque(false);
  circleImage->setColor(kCircleColor);
  circle->addChild(circleImage);
  layout->addItem(circle, kCirclePadding);

  UiRectLayout* labelContainer = SDKExamples::createUiRectLayout(prism);
  labelContainer->setSize(kLabelSize);
  labelContainer->setContentAlignment(Alignment::CENTER_CENTER);
  UiText* label = SDKExamples::createEclipseLabel(prism, descrLabel, type);
  labelContainer->setContent(label);
  layout->addItem(labelContainer);
  labelLayout_->addItem(layout);
}