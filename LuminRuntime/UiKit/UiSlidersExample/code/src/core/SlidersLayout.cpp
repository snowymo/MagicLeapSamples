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
#include <SlidersLayout.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesHelpers.h>
#include <ExamplesDefines.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const uint32_t kColumns    = 2;
  const float kLineWidth     = 0.37f;
  const float kLongLineWidth = 0.53f;
  const float kLayoutScale   = 0.3f;
  const float kSliderWidth   = 0.2f;
  const float kSliderHeight  = 0.007f;
  const float kProgressMin   = 0.0f;
  const float kProgressMax   = 100.0f;
  const float kProgressSpeed = 1.0f;
  const float kRadialWidth   = 0.15f;
  const float kContentWidth  = 0.21666667f;
  const float kContentHeight = 0.05416667f;
  const glm::vec4 kLinePadding(0.02f, 0.0f, 0.02f, 0.0f);
  const glm::vec4 kNamePadding(0.02f, 0.03f, 0.02f, 0.02f);
  const glm::vec4 kContentLayoutPadding(0.01f, 0.02f, 0.01f, 0.02f);
  const std::string kSliderChangedText = "Slider Value: ";
}

SlidersLayout::SlidersLayout()
: BaseExample("Sliders"), prefab_(nullptr) {
}

SlidersLayout::~SlidersLayout() {
}

void SlidersLayout::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "SlidersLayout::onAttachPrism() Initializing the Sliders Layout scene");
  BaseExample::onAttachPrism(prism);
}

void SlidersLayout::onUpdate(float fDelta) {
  for (LabelFader* fader : faders_) {
    fader->update(fDelta);
  }
}

TransformNode* SlidersLayout::loadSceneGraph(Prism* prism) {
  prefab_ = managers_->extendedPrefab_->spawn<prefabs::SlidersLayoutPrefab>();
  LUMIN_ASSERT(prefab_, "Failed to create SlidersLayoutPrefab");
  createData(prefab_);

  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab_->getRoot());
  return rootContainer;
}

void SlidersLayout::createData(prefabs::SlidersLayoutPrefab* prefab) {
  LabelFader* fader1 = new LabelFader(prefab->getSE_Label1());
  prefab->getSE_Label1()->setText("");
  prefab->addFader(prefabs::SlidersLayoutPrefab::Names::SE_Label1, fader1);

  LabelFader* fader2 = new LabelFader(prefab->getSE_Label2());
  prefab->getSE_Label2()->setText("");
  prefab->addFader(prefabs::SlidersLayoutPrefab::Names::SE_Label2, fader2);

  LabelFader* fader3 = new LabelFader(prefab->getSE_Label3());
  prefab->getSE_Label3()->setText("");
  prefab->addFader(prefabs::SlidersLayoutPrefab::Names::SE_Label3, fader3);

  LabelFader* fader4 = new LabelFader(prefab->getSE_Label4());
  prefab->getSE_Label4()->setText("");
  prefab->addFader(prefabs::SlidersLayoutPrefab::Names::SE_Label4, fader4);

  LabelFader* fader5 = new LabelFader(prefab->getSE_Label5());
  prefab->getSE_Label5()->setText("");
  prefab->addFader(prefabs::SlidersLayoutPrefab::Names::SE_Label5, fader5);

  LabelFader* fader6 = new LabelFader(prefab->getSE_Label6());
  prefab->getSE_Label6()->setText("");
  prefab->addFader(prefabs::SlidersLayoutPrefab::Names::SE_Label6, fader6);
}


TransformNode* SlidersLayout::buildSceneGraph(Prism* prism) {
  UiGridLayout* grid = SDKExamples::createUiGridLayout(prism);
  grid->setColumns(kColumns);
  grid->setAlignment(Alignment::CENTER_CENTER);
  grid->setDefaultItemAlignment(Alignment::TOP_CENTER);
  createTitle(prism, "Horizontal Sliders:", grid);

  auto addSlider = [prism, grid, this](const std::string& name, UiNode* slider, bool progressBar = false) {
    grid->addItem(SDKExamples::createEclipseLabel(prism, name,
        EclipseLabelType::kT3), kNamePadding, Alignment::TOP_RIGHT);
    grid->addItem(buildItemLayout(prism, slider, progressBar));
  };
  addSlider("Default", SDKExamples::createUiSlider(prism, kSliderWidth, kSliderHeight));
  addSlider("Horizontal+Labels", SDKExamples::createEclipseSlider(prism,
      EclipseSliderParams(EclipseSliderType::kHorizontalWithLabel, "Label1", "Label2",
      kSliderHeight, kSliderWidth)));
  addSlider("Horizontal+Icon", SDKExamples::createEclipseSlider(prism,
      EclipseSliderParams(EclipseSliderType::kHorizontalWithIcon, "", "", "", "", kSliderHeight,
      kSliderWidth, SystemIcon::kHeart, SystemIcon::kStar)));

  grid->addItem(createDivider(prism, kLineWidth), kLinePadding, Alignment::TOP_RIGHT);
  grid->addItem(createDivider(prism, kLongLineWidth), kLinePadding, Alignment::TOP_LEFT);
  createTitle(prism, "Radial Sliders:", grid);
  addSlider("Radial+Icon", SDKExamples::createEclipseSlider(prism,
      EclipseSliderParams(EclipseSliderType::kRadialWithIcon, "", "", "", "", 0.0f,
      0.0f, SystemIcon::kHeart, SystemIcon::kStar)));
  addSlider("Small Radial+Icon", SDKExamples::createEclipseSlider(prism,
      EclipseSliderParams(EclipseSliderType::kRadialWithIconSmall, "", "", "", "", 0.0f,
      0.0f, SystemIcon::kHeart, SystemIcon::kStar)));

  grid->addItem(createDivider(prism, kLineWidth), kLinePadding, Alignment::TOP_RIGHT);
  grid->addItem(createDivider(prism, kLongLineWidth), kLinePadding, Alignment::TOP_LEFT);
  createTitle(prism, "Progress Bar:", grid);
  UiProgressBar* progressBar = SDKExamples::createUiProgressBar(prism, kSliderWidth, kSliderHeight);
  progressBar->setMinMax(kProgressMin, kProgressMax);
  progressBar->setProgressColor(color::CYAN, color::GREEN);
  progressBar->onUpdateSub(std::bind(&SlidersLayout::progressBarUpdateCallback, this,
      std::placeholders::_1, std::placeholders::_2));
  addSlider("Default", progressBar, true);
  return grid;
}

void SlidersLayout::createTitle(Prism* prism, const std::string& title, UiGridLayout* grid) {
  UiText* titleLabel = SDKExamples::createEclipseLabel(prism, title, EclipseLabelType::kT1);
  titleLabel->setFont(resources::FontStyle::kItalic, resources::FontWeight::kBold);
  grid->addItem(titleLabel, ExampleConsts::kDefaultPadding);
  grid->addItem(SDKExamples::createTransformNode(prism)); // padding
}

LineNode* SlidersLayout::createDivider(Prism* prism, float lineWidth) {
  LineNode* divider = SDKExamples::createLineNode(prism);
  divider->setColor(color::WHITE * 0.9f);  // (243, 243, 243, 0.9)
  divider->addPoints(ExampleConsts::kDefaultLocalPos);
  divider->addPoints(glm::vec3(lineWidth, 0.0f, 0.0f));
  return divider;
}

UiLinearLayout* SlidersLayout::buildItemLayout(Prism* prism, UiNode* slider, bool progressBar) {
  UiRectLayout* contentLayout = SDKExamples::createUiRectLayout(prism);
  contentLayout->setSize(glm::vec2(kContentWidth, kContentHeight));
  contentLayout->setContentAlignment(Alignment::CENTER_CENTER);
  contentLayout->setContent(slider);

  UiText* eventLabel = SDKExamples::createEclipseLabel(prism, lumin::EMPTY_STRING,
      EclipseLabelType::kB4);
  eventLabel->setTextColor(color::WHITE);
  LabelFader* fader = new LabelFader(eventLabel);
  faders_.emplace_back(fader);

  UiRectLayout* feedbackLayout = SDKExamples::createUiRectLayout(prism);
  feedbackLayout->setSize(glm::vec2(kContentWidth, kContentHeight));
  feedbackLayout->setContentAlignment(Alignment::CENTER_LEFT);
  feedbackLayout->setContent(eventLabel);

  UiLinearLayout* baseLayout = SDKExamples::createUiLinearLayout(prism);
  baseLayout->setOrientation(Orientation::kHorizontal);
  baseLayout->setAlignment(Alignment::CENTER_CENTER);
  baseLayout->addItem(contentLayout, kContentLayoutPadding, Alignment::BOTTOM_LEFT);
  baseLayout->addItem(feedbackLayout, ExampleConsts::kDefaultPadding, Alignment::BOTTOM_LEFT);

  slider->onHoverEnterSub(std::bind(&SlidersLayout::hoverEnterCallback, this,
      std::placeholders::_1, eventLabel, fader));
  slider->onHoverExitSub(std::bind(&SlidersLayout::hoverExitCallback, this,
      std::placeholders::_1, eventLabel, fader));
  slider->onActivateSub(std::bind(&SlidersLayout::activateCallback, this,
      std::placeholders::_1, eventLabel));
  slider->onLongPressSub(std::bind(&SlidersLayout::longPressCallback, this,
      std::placeholders::_1, eventLabel));
  if (!progressBar) {
    UiSlider::CastFrom(slider)->onSliderChangedSub(std::bind(&SlidersLayout::sliderChangedCallback,
        this, std::placeholders::_1, eventLabel));
  }
  return baseLayout;
}

void SlidersLayout::hoverEnterCallback(const UiEventData& slider, UiText* label, LabelFader* fader) {
  label->setText(ExampleConsts::kHoverEnterText);
  fader->fadeIn();
  if (slider.getUiNode()->isNodeType(UiSlider::GetNodeTypeEnum())) {
    UiSlider* sliderNode = UiSlider::CastFrom(slider.getUiNode());
    if (sliderNode->getUiImageIcon()) {
      sliderNode->getUiImageIcon()->setColor(color::CYAN);
    }
    if (sliderNode->getUiTextLabel()) {
      sliderNode->getUiTextLabel()->setTextColor(color::CYAN);
    }
  }
}

void SlidersLayout::hoverExitCallback(const UiEventData& slider, UiText* label, LabelFader* fader) {
  label->setText(ExampleConsts::kHoverExitText);
  fader->fadeOut();
  if (slider.getUiNode()->isNodeType(UiSlider::GetNodeTypeEnum())) {
    UiSlider* sliderNode = UiSlider::CastFrom(slider.getUiNode());
    if (sliderNode->getUiImageIcon()) {
      sliderNode->getUiImageIcon()->setColor(color::WHITE);
    }
    if (sliderNode->getUiTextLabel()) {
      sliderNode->getUiTextLabel()->setTextColor(color::WHITE);
    }
  }
}

void SlidersLayout::activateCallback(const UiEventData& slider, UiText* label) {
  label->setText(ExampleConsts::kActivateText);
  if (slider.getUiNode()->isNodeType(UiSlider::GetNodeTypeEnum())) {
    UiSlider* sliderNode = UiSlider::CastFrom(slider.getUiNode());
    if (sliderNode->getUiImageIcon()) {
      sliderNode->getUiImageIcon()->setColor(color::GREEN);
    }
    if (sliderNode->getUiTextLabel()) {
      sliderNode->getUiTextLabel()->setTextColor(color::GREEN);
    }
  }
}

void SlidersLayout::progressBarUpdateCallback(const UiEventData& bar, float fDelta) {
  UiProgressBar* progressBar = UiProgressBar::CastFrom(bar.getUiNode());
  float value = glm::min(FLT_MAX, progressBar->getValue() + kProgressSpeed);
  (value >= kProgressMax)? progressBar->setValue(kProgressMin) : progressBar->setValue(value);
}

void SlidersLayout::longPressCallback(const UiEventData& slider, UiText* label) {
  label->setText(ExampleConsts::kLongPressText);
  if (slider.getUiNode()->isNodeType(UiSlider::GetNodeTypeEnum())) {
    UiSlider* sliderNode = UiSlider::CastFrom(slider.getUiNode());
    if (sliderNode->getUiImageIcon()) {
      sliderNode->getUiImageIcon()->setColor(color::RED);
    }
    if (sliderNode->getUiTextLabel()) {
      sliderNode->getUiTextLabel()->setTextColor(color::RED);
    }
  }
}

void SlidersLayout::sliderChangedCallback(const UiEventData& slider, UiText* label) {
  label->setText(kSliderChangedText +
        ExampleHelpers::floatToString(UiSlider::CastFrom(slider.getUiNode())->getValue()));
  label->setTextColor(color::WHITE);
}

// Remove all nodes when detached from a prism:
void SlidersLayout::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "SlidersLayout::onDetachPrism() Destroying the Sliders Layout scene");
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