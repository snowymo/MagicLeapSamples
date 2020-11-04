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
#include <ButtonsLayout.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesDefines.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const uint32_t kColumns    = 2;
  const float kLineWidth     = 0.47f;
  const float kLayoutScale   = 0.3f;
  const float kItemScale     = 0.65f;
  const float kRoundedCorner = 0.5f;
  const float kSquare        = 0.0f;
  const glm::vec4 kLinePadding(0.02f, 0.0f, 0.02f, 0.0f);
  const glm::vec4 kNamePadding(0.02f, 0.03f, 0.02f, 0.02f);
  const glm::vec4 kContentLayoutPadding(0.01f, 0.02f, 0.01f, 0.02f);
  const glm::quat kScrollBarRotation(glm::vec3(0.0f, 0.0f, glm::half_pi<float>()));
}

ButtonsLayout::ButtonsLayout()
: BaseExample("Buttons"),
  contentWidth_(0.0f),
  contentHeight_(0.0f) {
}

ButtonsLayout::~ButtonsLayout() {
}

void ButtonsLayout::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "ButtonsLayout::onAttachPrism() Initializing the Buttons Layout scene");
  BaseExample::onAttachPrism(prism);
}

void ButtonsLayout::onUpdate(float fDelta) {
  for (LabelFader* fader : faders_) {
    fader->update(fDelta);
  }
}

TransformNode* ButtonsLayout::loadSceneGraph(Prism* prism) {
  prefab_ = managers_->extendedPrefab_->spawn<prefabs::ButtonsLayoutPrefab>();
  LUMIN_ASSERT(prefab_, "Failed to create ButtonsLayoutPrefab");
  createData(prefab_);

  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab_->getRoot());
  return rootContainer;
}

void ButtonsLayout::createData(prefabs::ButtonsLayoutPrefab* prefab) {
  LabelFader* fader1 = new LabelFader(prefab->getBES_Label1());
  prefab->getBES_Label1()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label1, fader1);

  LabelFader* fader2 = new LabelFader(prefab->getBES_Label2());
  prefab->getBES_Label2()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label2, fader2);

  LabelFader* fader3 = new LabelFader(prefab->getBES_Label3());
  prefab->getBES_Label3()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label3, fader3);

  LabelFader* fader4 = new LabelFader(prefab->getBES_Label4());
  prefab->getBES_Label4()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label4, fader4);

  LabelFader* fader5 = new LabelFader(prefab->getBES_Label5());
  prefab->getBES_Label5()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label5, fader5);

  LabelFader* fader6 = new LabelFader(prefab->getBES_Label6());
  prefab->getBES_Label6()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label6, fader6);

  LabelFader* fader7 = new LabelFader(prefab->getBES_Label7());
  prefab->getBES_Label7()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label7, fader7);

  LabelFader* fader8 = new LabelFader(prefab->getBES_Label8());
  prefab->getBES_Label8()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label8, fader8);

  LabelFader* fader9 = new LabelFader(prefab->getBES_Label9());
  prefab->getBES_Label9()->setText("");
  prefab->addLabelFader(prefabs::ButtonsLayoutPrefab::Names::BES_Label9, fader9);
}

TransformNode* ButtonsLayout::buildSceneGraph(Prism* prism) {
  const float baseLayoutWidth  = prism->getSize().x * kItemScale;
  const float baseLayoutHeight = prism->getSize().y * kItemScale;
  contentWidth_                = baseLayoutWidth / 1.5f;
  contentHeight_               = baseLayoutHeight / 6.0f;

  UiGridLayout* grid = SDKExamples::createUiGridLayout(prism);
  grid->setColumns(kColumns);
  grid->setAlignment(Alignment::CENTER_CENTER);
  grid->setDefaultItemAlignment(Alignment::TOP_CENTER);

  createTitle(prism, "Eclipse Buttons:", grid);
  addEclipseButtons(prism, grid);

  grid->addItem(createDivider(prism), kLinePadding, Alignment::TOP_RIGHT);
  grid->addItem(createDivider(prism), kLinePadding, Alignment::TOP_LEFT);
  createTitle(prism, "Standard Buttons:", grid);
  addStandardButtons(prism, grid);
  return grid;
}

void ButtonsLayout::createTitle(Prism* prism, const std::string& title, UiGridLayout* grid) {
  UiText* titleLabel = SDKExamples::createEclipseLabel(prism, title, EclipseLabelType::kT1);
  titleLabel->setFont(resources::FontStyle::kItalic, resources::FontWeight::kBold);
  grid->addItem(titleLabel, ExampleConsts::kDefaultPadding);
  grid->addItem(SDKExamples::createTransformNode(prism)); // padding
}

LineNode* ButtonsLayout::createDivider(Prism* prism) {
  LineNode* divider = SDKExamples::createLineNode(prism);
  divider->setColor(color::WHITE * 0.9f);  // (243, 243, 243, 0.9)
  divider->addPoints(ExampleConsts::kDefaultLocalPos);
  divider->addPoints(glm::vec3(kLineWidth, 0.0f, 0.0f));
  return divider;
}

void ButtonsLayout::addEclipseButtons(Prism* prism, UiGridLayout* grid) {
  auto createButton = [prism, grid, this](const std::string& name, EclipseButtonParams params) {
    UiButton* button = SDKExamples::createEclipseButton(prism, params);
    grid->addItem(SDKExamples::createEclipseLabel(prism, name,
        EclipseLabelType::kT3), kNamePadding, Alignment::TOP_RIGHT);
    grid->addItem(buildItemLayout(prism, button));
  };
  EclipseButtonParams params(EclipseButtonType::kIcon, SystemIcon::kStar);
  params.width  = contentHeight_;
  params.height = contentHeight_;
  createButton("Icon Only", params);
  params = EclipseButtonParams(EclipseButtonType::kText, "Text Only");
  params.width  = contentWidth_;
  params.height = contentHeight_;
  createButton("Text Only", params);
  params = EclipseButtonParams(EclipseButtonType::kIconWithLabel, SystemIcon::kStar);
  params.labelText = "Label";
  params.width     = contentWidth_;
  params.height    = contentHeight_;
  createButton("Icon + Label", params);
  params = EclipseButtonParams(EclipseButtonType::kTextWithIcon, SystemIcon::kStar);
  params.labelText = "Text";
  params.width     = contentWidth_;
  params.height    = contentHeight_;
  createButton("Text + Icon", params);
  params = EclipseButtonParams(EclipseButtonType::kText, "Outline");
  params.width         = contentWidth_;
  params.height        = contentHeight_;
  params.outlineButton = true;
  createButton("Text Only Outlined", params);
  params = EclipseButtonParams(EclipseButtonType::kTextWithIcon, SystemIcon::kStar);
  params.labelText     = "Outline";
  params.width         = contentWidth_;
  params.height        = contentHeight_;
  params.outlineButton = true;
  createButton("Text + Icon Outlined", params);
}

void ButtonsLayout::addStandardButtons(Prism* prism, UiGridLayout* grid) {
  auto addButton = [prism, grid, this](const std::string& name, UiButton* button) {
    grid->addItem(SDKExamples::createEclipseLabel(prism, name,
        EclipseLabelType::kT3), kNamePadding, Alignment::TOP_RIGHT);
    grid->addItem(buildItemLayout(prism, button));
  };
  addButton("Capsule", SDKExamples::createUiButton(prism, "Capsule", contentWidth_,
      contentHeight_));
  addButton("Rounded Corner", SDKExamples::createUiButton(prism, "Rounded Corner", contentWidth_,
      contentHeight_, kRoundedCorner));
  addButton("Square", SDKExamples::createUiButton(prism, "Square Corner", contentWidth_,
      contentHeight_, kSquare));
}

UiLinearLayout* ButtonsLayout::buildItemLayout(Prism* prism, UiButton* button) {
  UiRectLayout* contentLayout = SDKExamples::createUiRectLayout(prism);
  contentLayout->setSize(glm::vec2(contentWidth_ / 2.0f, contentHeight_ / 2.0f));
  contentLayout->setContentAlignment(Alignment::CENTER_CENTER);
  contentLayout->setContent(button);

  UiText* eventLabel = SDKExamples::createEclipseLabel(prism, lumin::EMPTY_STRING,
      EclipseLabelType::kB4);
  eventLabel->setTextColor(color::WHITE);
  LabelFader* fader = new LabelFader(eventLabel);
  faders_.emplace_back(fader);

  UiRectLayout* feedbackLayout = SDKExamples::createUiRectLayout(prism);
  feedbackLayout->setSize(glm::vec2(contentWidth_ / 2.0f, contentHeight_ / 2.0f));
  feedbackLayout->setContentAlignment(Alignment::CENTER_CENTER);
  feedbackLayout->setContent(eventLabel);

  UiLinearLayout* baseLayout = SDKExamples::createUiLinearLayout(prism);
  baseLayout->setOrientation(Orientation::kHorizontal);
  baseLayout->setAlignment(Alignment::CENTER_CENTER);
  baseLayout->addItem(contentLayout, kContentLayoutPadding, Alignment::BOTTOM_CENTER);
  baseLayout->addItem(feedbackLayout, ExampleConsts::kDefaultPadding, Alignment::BOTTOM_CENTER);

  button->onHoverEnterSub(std::bind(&ButtonsLayout::hoverEnterCallback, this,
      std::placeholders::_1, eventLabel, fader));
  button->onHoverExitSub(std::bind(&ButtonsLayout::hoverExitCallback, this,
      std::placeholders::_1, eventLabel, fader));
  button->onActivateSub(std::bind(&ButtonsLayout::activateCallback, this,
      std::placeholders::_1, eventLabel));
  button->onLongPressSub(std::bind(&ButtonsLayout::longPressCallback, this,
      std::placeholders::_1, eventLabel));
  return baseLayout;
}

void ButtonsLayout::hoverEnterCallback(const UiEventData& button, UiText* label, LabelFader* fader) {
  label->setText(ExampleConsts::kHoverEnterText);
  fader->fadeIn();
  UiButton::CastFrom(button.getUiNode())->setTextColor(color::CYAN);
  UiButton::CastFrom(button.getUiNode())->setIconColor(color::CYAN);
}

void ButtonsLayout::hoverExitCallback(const UiEventData& button, UiText* label, LabelFader* fader) {
  label->setText(ExampleConsts::kHoverExitText);
  fader->fadeOut();
  UiButton::CastFrom(button.getUiNode())->setTextColor(color::WHITE);
  UiButton::CastFrom(button.getUiNode())->setIconColor(color::WHITE);
}

void ButtonsLayout::activateCallback(const UiEventData& button, UiText* label) {
  label->setText(ExampleConsts::kActivateText);
  UiButton::CastFrom(button.getUiNode())->setTextColor(color::GREEN);
  UiButton::CastFrom(button.getUiNode())->setIconColor(color::GREEN);
}

void ButtonsLayout::longPressCallback(const UiEventData& button, UiText* label) {
  label->setText(ExampleConsts::kLongPressText);
  UiButton::CastFrom(button.getUiNode())->setTextColor(color::RED);
  UiButton::CastFrom(button.getUiNode())->setIconColor(color::RED);
}

// Remove all nodes when detached from a prism:
void ButtonsLayout::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "ButtonsLayout::onDetachPrism() Destroying the Buttons Layout scene");
  for (LabelFader* fader : faders_) {
    delete fader;
    fader = nullptr;
  }
  prefab_->deleteFaders();
  managers_->extendedPrefab_->destroyPrefab(prefab_);
  prefab_ = nullptr;
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}