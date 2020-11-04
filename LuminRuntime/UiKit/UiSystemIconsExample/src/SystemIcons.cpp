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
#include <SystemIcons.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>

#include <lumin/Prism.h>
#include <lumin/node/LineNode.h>
#include <lumin/ui/UiKit.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  float kScrollHeight  = 0.55f;
  float kScrollWidth   = 0.95f;
  float kScrollDepth   = 0.3f;
  float kIconSize      = 0.05f;
  const uint32_t kCols = 5;
  const glm::vec3 kLineLocalPosStart(-0.4f, 0.0f, 0.0f);
  const glm::vec3 kLineLocalPosEnd(0.57f, 0.0f, 0.0f);
  const glm::vec4 kLineColor(0.6, 0.6f, 0.6f, 1.0f);
  const glm::vec4 kLayoutPadding(0.06f, 0.0f, 0.06f, 0.1f);
  const glm::vec4 kIconPadding(0.02f, 0.01f, 0.01f, 0.01f);
  const glm::vec4 kIconTitlePadding(0.0f, 0.01f, 0.01f, 0.01f);
  const glm::quat kScrollBarRotation(glm::vec3(0.0f, 0.0f, -(glm::half_pi<float>())));
}

// Constructs a PrismController with the identifier 'UiKit System Icons' to be used in diagnostics:
SystemIcons::SystemIcons() : PrismController("UiKit System Icons") {
}

SystemIcons::~SystemIcons() {
}

void SystemIcons::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "SystemIcons::onAttachPrism() Initializing the Eclipse Labels scene");
  UiLinearLayout* pageLayout = SDKExamples::createUiLinearLayout(prism);
  pageLayout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  pageLayout->setAlignment(Alignment::TOP_CENTER);
  pageLayout->setLocalPosition(ExampleConsts::kLayoutPos);

  UiText* systemIconsTitle = SDKExamples::createUiText(prism, "System Icons",
      resources::FontStyle::kItalic, resources::FontWeight::kBold);
  systemIconsTitle->setTextSize(ExampleConsts::kTitleSize);
  pageLayout->addItem(systemIconsTitle, ExampleConsts::kTitlePadding);

  LineNode* divider = SDKExamples::createLineNode(prism);
  divider->addPoints(kLineLocalPosStart);
  divider->addPoints(kLineLocalPosEnd);
  divider->setColor(kLineColor);

  pageLayout->addItem(divider, ExampleConsts::kNoPadding);
  pageLayout->addItem(createSystemIconLayout(prism));
  getRoot()->addChild(pageLayout);
}

UiLinearLayout* SystemIcons::createSystemIconLayout(Prism* prism) {
  UiGridLayout* grid = SDKExamples::createUiGridLayout(prism);
  grid->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  grid->setColumns(kCols);

  for(uint32_t i = 0; i <= static_cast<int>(SystemIcon::kZoomOut); ++i) {
    UiImage* icon = SDKExamples::createUiImage(prism, static_cast<SystemIcon>(i), kIconSize);
    UiText* title = SDKExamples::createEclipseLabel(prism,
        ExampleConsts::systemIconsMap[static_cast<SystemIcon>(i)], EclipseLabelType::kB3);
    UiLinearLayout* iconLayout = SDKExamples::createUiLinearLayout(prism);
    iconLayout->setAlignment(Alignment::TOP_CENTER);
    iconLayout->addItem(icon, kIconPadding, Alignment::TOP_CENTER);
    iconLayout->addItem(title, kIconTitlePadding, Alignment::TOP_CENTER);
    grid->addItem(iconLayout);
  }

  UiScrollView* pageScroll = SDKExamples::createUiScrollView(prism);
  pageScroll->setScrollBounds(
      math::AABB(glm::vec3(-kScrollWidth, -kScrollHeight, -kScrollDepth) * 0.5f,
      glm::vec3(kScrollWidth, kScrollHeight, kScrollDepth) * 0.5f));
  pageScroll->setScrollContent(grid);
  UiScrollBar* scrollBar = SDKExamples::createUiScrollBar(prism, kScrollHeight);
  scrollBar->setLocalRotation(kScrollBarRotation);
  pageScroll->setScrollBar(Orientation::kVertical, scrollBar);
  pageScroll->setScrollBarVisibilityMode(ScrollBarVisibility::kAuto);
  pageScroll->setCursorEdgeScrollMode(CursorEdgeScrollMode::kAlways);

  UiLinearLayout* scrollLayout = SDKExamples::createUiLinearLayout(prism);
  scrollLayout->setAlignment(Alignment::CENTER_CENTER);
  scrollLayout->setOrientation(Orientation::kHorizontal);
  scrollLayout->addItem(pageScroll);
  scrollLayout->addItem(scrollBar);
  return scrollLayout;
}

// Destroys all nodes when the scene is removed from a prism:
void SystemIcons::onDetachPrism(Prism*) {
  ML_LOG(Debug, "SystemIcons::onDetachPrism() Destroying the Eclipse Labels scene");
  deleteSceneGraph();
}
