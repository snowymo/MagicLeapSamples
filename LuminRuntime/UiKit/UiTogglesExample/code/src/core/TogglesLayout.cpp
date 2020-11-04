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
#include <TogglesLayout.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesDefines.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const uint32_t kColumns    = 2;
  const float kYOffset       = 0.2f;
  const float kLineWidth     = 0.37f;
  const float kLongLineWidth = 0.53f;
  const float kLayoutScale   = 0.3f;
  const float kItemScale     = 0.65f;
  const std::string kOn      = "On Toggle Changed [ON]";
  const std::string kOff     = "On Toggle Changed [OFF]";
  const glm::vec4 kLinePadding(0.02f, 0.0f, 0.02f, 0.0f);
  const glm::vec4 kNamePadding(0.04f, 0.05f, 0.04f, 0.01f);
  const glm::vec4 kFeedbackPadding(0.02f, 0.01f, 0.0f, 0.03f);
}

TogglesLayout::TogglesLayout()
: BaseExample("Toggles"),
  contentWidth_(0.0f),
  contentHeight_(0.0f),
  prefab_(nullptr) {
}

TogglesLayout::~TogglesLayout() {
}

void TogglesLayout::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "TogglesLayout::onAttachPrism() Initializing the Toggles Layout scene");
  lumin::SDKExamples::BaseExample::onAttachPrism(prism);
}

void TogglesLayout::onUpdate(float fDelta) {
  for (LabelFader* fader : faders_) {
    fader->update(fDelta);
  }
}

TransformNode* TogglesLayout::buildSceneGraph(Prism* prism) {
  const float baseLayoutWidth  = prism->getSize().x * kItemScale;
  const float baseLayoutHeight = (prism->getSize().y - kYOffset) * kItemScale;
  contentWidth_  = baseLayoutWidth / 1.5f;
  contentHeight_ = baseLayoutHeight / 4.0f;

  UiGridLayout* grid = SDKExamples::createUiGridLayout(prism);
  grid->setColumns(kColumns);
  grid->setAlignment(Alignment::CENTER_CENTER);
  grid->setDefaultItemAlignment(Alignment::TOP_CENTER);

  createTitle(prism, "Eclipse Toggles:", grid);
  addEclipseToggles(prism, grid);
  grid->addItem(createDivider(prism, kLineWidth), kLinePadding, Alignment::TOP_RIGHT);
  grid->addItem(createDivider(prism, kLongLineWidth), kLinePadding, Alignment::TOP_LEFT);
  createTitle(prism, "Standard Toggles:", grid);
  addStandardToggles(prism, grid);
  return grid;
}

TransformNode* TogglesLayout::loadSceneGraph(Prism* prism) {
  prefab_ = managers_->extendedPrefab_->spawn<prefabs::TogglesLayoutPrefab>();
  LUMIN_ASSERT(prefab_, "Failed to create TogglesLayoutPrefab");
  createData(prefab_);

  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab_->getRoot());
  return rootContainer;
}

void TogglesLayout::createData(prefabs::TogglesLayoutPrefab* prefab) {
  LabelFader* fader1 = new LabelFader(prefab->getBES_Label1());
  prefab->getBES_Label1()->setText("");
  prefab->addFader(prefabs::TogglesLayoutPrefab::Names::BES_Label1, fader1);

  LabelFader* fader2 = new LabelFader(prefab->getBES_Label2());
  prefab->getBES_Label2()->setText("");
  prefab->addFader(prefabs::TogglesLayoutPrefab::Names::BES_Label2, fader2);

  LabelFader* fader3 = new LabelFader(prefab->getBES_Label3());
  prefab->getBES_Label3()->setText("");
  prefab->addFader(prefabs::TogglesLayoutPrefab::Names::BES_Label3, fader3);

  LabelFader* fader4 = new LabelFader(prefab->getBES_Label4());
  prefab->getBES_Label4()->setText("");
  prefab->addFader(prefabs::TogglesLayoutPrefab::Names::BES_Label4, fader4);

  LabelFader* fader5 = new LabelFader(prefab->getBES_Label5());
  prefab->getBES_Label5()->setText("");
  prefab->addFader(prefabs::TogglesLayoutPrefab::Names::BES_Label5, fader5);

  LabelFader* fader6 = new LabelFader(prefab->getBES_Label6());
  prefab->getBES_Label6()->setText("");
  prefab->addFader(prefabs::TogglesLayoutPrefab::Names::BES_Label6, fader6);

  LabelFader* fader7 = new LabelFader(prefab->getBES_Label7());
  prefab->getBES_Label7()->setText("");
  prefab->addFader(prefabs::TogglesLayoutPrefab::Names::BES_Label7, fader7);

  LabelFader* fader8 = new LabelFader(prefab->getBES_Label8());
  prefab->getBES_Label8()->setText("");
  prefab->addFader(prefabs::TogglesLayoutPrefab::Names::BES_Label8, fader8);
}

void TogglesLayout::createTitle(Prism* prism, const std::string& title, UiGridLayout* grid) {
  UiText* titleLabel = SDKExamples::createEclipseLabel(prism, title, EclipseLabelType::kT1);
  titleLabel->setFont(resources::FontStyle::kItalic, resources::FontWeight::kBold);
  grid->addItem(titleLabel, ExampleConsts::kDefaultPadding);
  grid->addItem(SDKExamples::createTransformNode(prism)); // padding
}

LineNode* TogglesLayout::createDivider(Prism* prism, float lineWidth) {
  LineNode* divider = SDKExamples::createLineNode(prism);
  divider->setColor(color::WHITE * 0.9f);  // (243, 243, 243, 0.9)
  divider->addPoints(ExampleConsts::kDefaultLocalPos);
  divider->addPoints(glm::vec3(lineWidth, 0.0f, 0.0f));
  return divider;
}

void TogglesLayout::addEclipseToggles(Prism* prism, UiGridLayout* grid) {
  auto createToggle = [prism, grid, this](const std::string& name, EclipseToggleParams params) {
    UiToggle* toggle = SDKExamples::createEclipseToggle(prism, params);
    grid->addItem(SDKExamples::createEclipseLabel(prism, name,
        EclipseLabelType::kT3), kNamePadding, Alignment::TOP_RIGHT);
    grid->addItem(buildItemLayout(prism, toggle));
  };
  EclipseToggleParams params(EclipseToggleType::kIcon, SystemIcon::kStar);
  params.showBackground = false;
  createToggle("Icon Only", params);
  params = EclipseToggleParams(EclipseToggleType::kIcon, SystemIcon::kStar, SystemIcon::kHeart);
  params.showBackground = false;
  createToggle("Icon Only On/Off", params);
  params = EclipseToggleParams(EclipseToggleType::kIcon, SystemIcon::kStar);
  createToggle("Icon Only Outline", params);
  params = EclipseToggleParams(EclipseToggleType::kSwitchWithIcon, lumin::EMPTY_STRING, "Text");
  createToggle("Switch+Icon", params);
  params = EclipseToggleParams(
      EclipseToggleType::kSwitchWithLabel,
      lumin::EMPTY_STRING,
      lumin::EMPTY_STRING,
      "OFF",
      "ON");
  createToggle("Switch+Label", params);
}

void TogglesLayout::addStandardToggles(Prism* prism, UiGridLayout* grid) {
  auto addToggle = [prism, grid, this](const std::string& name, UiToggle* toggle) {
    grid->addItem(SDKExamples::createEclipseLabel(prism, name,
        EclipseLabelType::kT3), kNamePadding, Alignment::TOP_RIGHT);
    grid->addItem(buildItemLayout(prism, toggle));
  };
  UiToggle* toggle = SDKExamples::createUiToggle(prism, "Text");
  toggle->setTextSize(ExampleConsts::kTitleSize);
  addToggle("Default", toggle);
  addToggle("Radio", SDKExamples::createUiToggle(prism, "Text",
      ToggleType::kRadio, contentHeight_ * 0.3f));
  addToggle("Checkbox", SDKExamples::createUiToggle(prism, "Text",
      ToggleType::kCheckbox, contentHeight_ * 0.3f));
}

UiLinearLayout* TogglesLayout::buildItemLayout(Prism* prism, UiToggle* toggle) {
  UiRectLayout* contentLayout = SDKExamples::createUiRectLayout(prism);
  contentLayout->setSize(glm::vec2(contentWidth_ * 0.35f, contentHeight_ / 2.0f));
  contentLayout->setContentAlignment(Alignment::CENTER_CENTER);
  contentLayout->setContent(toggle);

  UiText* eventLabel = SDKExamples::createEclipseLabel(prism, lumin::EMPTY_STRING,
      EclipseLabelType::kB4);
  eventLabel->setTextColor(color::WHITE);
  LabelFader* fader = new LabelFader(eventLabel);
  faders_.emplace_back(fader);

  UiRectLayout* feedbackLayout = SDKExamples::createUiRectLayout(prism);
  feedbackLayout->setSize(glm::vec2(contentWidth_ * 0.65f, contentHeight_ / 2.0f));
  feedbackLayout->setContentAlignment(Alignment::CENTER_LEFT);
  feedbackLayout->setContent(eventLabel);

  UiLinearLayout* baseLayout = SDKExamples::createUiLinearLayout(prism);
  baseLayout->setOrientation(Orientation::kHorizontal);
  baseLayout->setAlignment(Alignment::CENTER_CENTER);
  baseLayout->addItem(contentLayout, ExampleConsts::kDefaultPadding, Alignment::BOTTOM_LEFT);
  baseLayout->addItem(feedbackLayout, kFeedbackPadding, Alignment::BOTTOM_RIGHT);

  toggle->onHoverEnterSub(std::bind(&TogglesLayout::hoverEnterCallback, this,
      std::placeholders::_1, eventLabel, fader));
  toggle->onHoverExitSub(std::bind(&TogglesLayout::hoverExitCallback, this,
      std::placeholders::_1, eventLabel, fader));
  toggle->onToggleChangedSub(std::bind(&TogglesLayout::toggleChangedCallback, this,
      std::placeholders::_1, eventLabel));
  toggle->onLongPressSub(std::bind(&TogglesLayout::longPressCallback, this,
      std::placeholders::_1, eventLabel));
  return baseLayout;
}

void TogglesLayout::hoverEnterCallback(const UiEventData& toggle, UiText* label, LabelFader* fader) {
  label->setText(ExampleConsts::kHoverEnterText);
  fader->fadeIn();
  UiToggle::CastFrom(toggle.getUiNode())->setTextColor(color::CYAN);
}

void TogglesLayout::hoverExitCallback(const UiEventData& toggle, UiText* label, LabelFader* fader) {
  label->setText(ExampleConsts::kHoverExitText);
  fader->fadeOut();
  UiToggle::CastFrom(toggle.getUiNode())->setTextColor(color::WHITE);
}

void TogglesLayout::longPressCallback(const UiEventData& toggle, UiText* label) {
  label->setText(ExampleConsts::kLongPressText);
  UiToggle::CastFrom(toggle.getUiNode())->setTextColor(color::RED);
}

void TogglesLayout::toggleChangedCallback(const UiEventData& toggle, UiText* label) {
  if (UiToggle::CastFrom(toggle.getUiNode())->getOn()) {
    label->setText(kOn);
    UiToggle::CastFrom(toggle.getUiNode())->setTextColor(color::MAGENTA);
  } else {
    label->setText(kOff);
    UiToggle::CastFrom(toggle.getUiNode())->setTextColor(color::INDIGO);
  }
}

// Remove all nodes when detached from a prism:
void TogglesLayout::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "TogglesLayout::onDetachPrism() Destroying the Toggles Layout scene");
  for (LabelFader* fader : faders_) {
    delete fader;
    fader = nullptr;
  }
  faders_.clear();
  prefab_->deleteFaders();

  prefab_ = nullptr;
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}