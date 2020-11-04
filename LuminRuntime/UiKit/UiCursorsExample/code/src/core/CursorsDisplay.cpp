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
#include <CursorsDisplay.h>
#include <CursorsDisplayPrefab.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesDefines.h>
#include <scenes.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const uint32_t kColumns        = 4;
  const float kRoundness         = 1.0f;
  const float kColorPickerHeight = 0.3f;
  const float kEdgeConstraint    = 0.5f;
  const float kColorOffset       = 0.2f;
  const glm::vec2 kBounds(0.2f, 0.1f);
  const glm::vec2 kCircleSize(0.2f, 0.2f);
  const glm::vec4 kTransparentWhite(1.0f, 1.0f, 1.0f, 0.5f);
  const std::string kCirclePath = "pipeline/SourceArt/Circle.png";
  const std::string kShellPath  = "pipeline/SourceArt/Shell.png";
}

CursorsDisplay::CursorsDisplay() : BaseExample("Cursors Example") {

}

CursorsDisplay::~CursorsDisplay() {

}

// Create the scene when it is attached to a prism,
// display the seven Eclipse Cursor types:
void CursorsDisplay::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "CursorsDisplay::onAttachPrism() Initializing the Cursors scene");
  lumin::SDKExamples::BaseExample::onAttachPrism(prism);
}

// Remove all nodes when detached from a prism:
void CursorsDisplay::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "CursorsDisplay::onDetachPrism() Destroying the Cursors scene");
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}

TransformNode* CursorsDisplay::buildSceneGraph(Prism* prism) {
  uint32_t index = 0;
  auto createCircle = [prism, &index, this] (const std::string& name,
      EclipseCursorState state) -> UiLinearLayout* {
    UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
    layout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
    layout->setDefaultItemAlignment(Alignment::BOTTOM_CENTER);

    UiText* title = SDKExamples::createUiText(prism, name, resources::FontStyle::kItalic,
        resources::FontWeight::kBold);
    title->setTextSize(ExampleConsts::kTitleSize);
    title->setBoundsSize(kBounds);
    title->setAlignment(Alignment::TOP_CENTER);
    layout->addItem(title);

    UiPanel* panel = SDKExamples::createUiPanel(prism);
    panel->setPanelShape(BoundaryShape(kCircleSize, kRoundness));
    panel->setCursorConstrained(true);
    panel->setCursorVisible(true);
    panel->setEdgeConstraint(Side::kTop, kEdgeConstraint);
    panel->setEdgeConstraint(Side::kRight, kEdgeConstraint);
    panel->setEdgeConstraint(Side::kBottom, kEdgeConstraint);
    panel->setEdgeConstraint(Side::kLeft, kEdgeConstraint);
    panel->onPanelEnterSub(std::bind(&CursorsDisplay::panelEnterCallback, this,
        std::placeholders::_1, prism, state));

    UiImage* circle = SDKExamples::createUiImage(prism, kCirclePath, kCircleSize.x, kCircleSize.y);
    circle->setIsOpaque(false);
    circle->setColor(kTransparentWhite);
    circle->setAlignment(Alignment::CENTER_CENTER);
    circle->setName("CC_Image" + std::to_string(++index));

    UiImage* shell = SDKExamples::createUiImage(prism, kShellPath, kCircleSize.x, kCircleSize.y);
    shell->setIsOpaque(false);
    shell->setAlignment(Alignment::CENTER_CENTER);
    shell->setLocalPosition(ExampleConsts::kDefaultBackground);

    circle->addChild(shell);
    panel->addChild(circle);
    layout->addItem(panel);
    return layout;
  };

  UiGridLayout* cursorGrid = SDKExamples::createUiGridLayout(prism);
  cursorGrid->setColumns(kColumns);
  cursorGrid->setDefaultItemAlignment(Alignment::BOTTOM_CENTER);
  cursorGrid->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  cursorGrid->addItem(createCircle("Default", EclipseCursorState::kDefault));
  cursorGrid->addItem(createCircle("Browser Default", EclipseCursorState::kBrowserDefault));
  cursorGrid->addItem(createCircle("Browser Pointer", EclipseCursorState::kBrowserPointer));
  cursorGrid->addItem(createCircle("Text Input", EclipseCursorState::kTextInput));
  cursorGrid->addItem(createCircle("Crosshair", EclipseCursorState::kCrosshair));
  cursorGrid->addItem(createCircle("Move", EclipseCursorState::kMove));
  cursorGrid->addItem(createCircle("Scroll", EclipseCursorState::kScroll));

  UiColorPicker* colorPicker = SDKExamples::createUiColorPicker(prism, kTransparentWhite, kColorPickerHeight);
  cursorGrid->addItem(colorPicker);

  std::vector<Node*> textNodes   = cursorGrid->findChildren(UiText::GetNodeTypeEnum());
  std::vector<Node*> circleNodes = cursorGrid->findChildren(UiImage::GetNodeTypeEnum());
  colorPicker->onColorChangedSub(std::bind(&CursorsDisplay::colorChangedCallback, this,
      std::placeholders::_1, std::placeholders::_2, textNodes, circleNodes));
  colorPicker->onCancelSub(std::bind(&CursorsDisplay::colorChangedCallback, this,
      std::placeholders::_1, std::placeholders::_2, textNodes, circleNodes));
  return cursorGrid;
}

TransformNode* CursorsDisplay::loadSceneGraph(Prism* prism) {
  prefabs::CursorsDisplayPrefab* prefab = managers_->extendedPrefab_->spawn<prefabs::CursorsDisplayPrefab>();
  LUMIN_ASSERT(prefab, "Failed to create CursorsDisplayPrefab");
  prefab->setPrism(prism);
  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab->getRoot());
  return rootContainer;
}

void CursorsDisplay::panelEnterCallback(const UiEventData&, Prism* prism, EclipseCursorState state) {
    Cursor::SetState(prism, state);
}

void CursorsDisplay::colorChangedCallback(const UiEventData&, const glm::vec4 color,
    std::vector<Node*> textNodes, std::vector<Node*> circleNodes) {
  for (auto& node : textNodes) {
    UiText::CastFrom(node)->setTextColor(glm::vec4(fmax(0.0f, color.x - kColorOffset),
        fmax(0.0f, color.y - kColorOffset), fmax(0.0f, color.z - kColorOffset), 1.0f));
  }
  // Only change the color of the circles, not the shells:
  for (auto& node : circleNodes) {
    if (node->getName().find("CC_Image") != std::string::npos) {
      UiImage::CastFrom(node)->setColor(color);
    }
  }
}