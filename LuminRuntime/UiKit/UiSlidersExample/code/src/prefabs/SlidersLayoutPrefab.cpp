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

// %SRC_VERSION%: 2

#include <PrefabDescriptor.h>
#include <SlidersLayoutPrefab.h>
#include <ExamplesConstants.h>
#include <ExamplesHelpers.h>
#include <lumin/Consts.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const float kProgressMin   = 0.0f;
  const float kProgressMax   = 100.0f;
  const float kProgressSpeed = 1.0f;
  const std::string kSliderChangedText = "Slider Value: ";
}

namespace prefabs {


  SlidersLayoutPrefab::SlidersLayoutPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : SlidersLayoutPrefabBase(extendedPrefabManager, root) {
  }

  SlidersLayoutPrefab::~SlidersLayoutPrefab() {
  }

  void SlidersLayoutPrefab::addFader(const std::string& label, LabelFader* fader) {
    faders_.emplace(label, fader);
  }

  void SlidersLayoutPrefab::deleteFaders() {
    for (auto fader : faders_) {
      delete fader.second;
      fader.second = nullptr;
    }
    faders_.clear();
  }

  // Handler methods are declared in the base class SlidersLayoutPrefabBase and can be implemented here

  void onHoverEnterBase(UiSlider* slider, UiText* label, LabelFader* fader) {
    label->setText(ExampleConsts::kHoverEnterText);
    if (fader) {
      fader->fadeIn();
    }
    if (slider->getUiImageIcon()) {
      slider->getUiImageIcon()->setColor(color::CYAN);
    }
    if (slider->getUiTextLabel()) {
      slider->getUiTextLabel()->setTextColor(color::CYAN);
    }
  }

  void onHoverExitBase(UiSlider* slider, UiText* label, LabelFader* fader) {
    label->setText(ExampleConsts::kHoverExitText);
    if (fader) {
      fader->fadeOut();
    }
    if (slider->getUiImageIcon()) {
      slider->getUiImageIcon()->setColor(color::WHITE);
    }
    if (slider->getUiTextLabel()) {
      slider->getUiTextLabel()->setTextColor(color::WHITE);
    }
  }

  void onActivateBase(UiSlider* slider, UiText* label) {
    label->setText(ExampleConsts::kActivateText);
    if (slider->getUiImageIcon()) {
      slider->getUiImageIcon()->setColor(color::GREEN);
    }
    if (slider->getUiTextLabel()) {
      slider->getUiTextLabel()->setTextColor(color::GREEN);
    }
  }

  void onLongPressBase(UiSlider* slider, UiText* label) {
    label->setText(ExampleConsts::kLongPressText);
    if (slider->getUiImageIcon()) {
      slider->getUiImageIcon()->setColor(color::RED);
    }
    if (slider->getUiTextLabel()) {
      slider->getUiTextLabel()->setTextColor(color::RED);
    }
  }

  void onSliderChangedBase(UiSlider* slider, UiText* label) {
    label->setText(kSliderChangedText + ExampleHelpers::floatToString(slider->getValue()));
    label->setTextColor(color::WHITE);
  }

  void onUpdateLabelBase(LabelFader* fader, float delta) {
    if (fader) {
      fader->update(delta);
    }
  }


  void SlidersLayoutPrefab::SL_Slider1_DefaultSliderHandlers_onSliderChanged(const lumin::ui::UiEventData& data) {
    onSliderChangedBase(getSL_Slider1(), getSE_Label1());
  }

  void SlidersLayoutPrefab::SL_Slider1_DefaultSliderHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getSL_Slider1(), getSE_Label1(), faders_[Names::SE_Label1]);
  }

  void SlidersLayoutPrefab::SL_Slider1_DefaultSliderHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getSL_Slider1(), getSE_Label1(), faders_[Names::SE_Label1]);
  }

  void SlidersLayoutPrefab::SL_Slider1_DefaultSliderHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getSL_Slider1(), getSE_Label1());
  }

  void SlidersLayoutPrefab::SL_Slider1_DefaultSliderHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getSL_Slider1(), getSE_Label1());
  }

  void SlidersLayoutPrefab::SE_Label1_DefaultSliderLabelHandlers(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::SE_Label1], dTime);
  }

  void SlidersLayoutPrefab::SL_Slider2_HorizontalLabelSliderHandlers_onSliderChanged(const lumin::ui::UiEventData& data) {
    onSliderChangedBase(getSL_Slider2(), getSE_Label2());
  }

  void SlidersLayoutPrefab::SL_Slider2_HorizontalLabelSliderHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getSL_Slider2(), getSE_Label2(), faders_[Names::SE_Label2]);
  }

  void SlidersLayoutPrefab::SL_Slider2_HorizontalLabelSliderHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getSL_Slider2(), getSE_Label2(), faders_[Names::SE_Label2]);
  }

  void SlidersLayoutPrefab::SL_Slider2_HorizontalLabelSliderHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getSL_Slider2(), getSE_Label2());
  }

  void SlidersLayoutPrefab::SL_Slider2_HorizontalLabelSliderHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getSL_Slider2(), getSE_Label2());
  }

  void SlidersLayoutPrefab::SE_Label2_HorizontalLabelSliderLabelHandlers(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::SE_Label2], dTime);
  }

  void SlidersLayoutPrefab::SL_Slider3_HorizontalIconSliderHandlers_onSliderChanged(const lumin::ui::UiEventData& data) {
    onSliderChangedBase(getSL_Slider3(), getSE_Label3());
  }

  void SlidersLayoutPrefab::SL_Slider3_HorizontalIconSliderHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getSL_Slider3(), getSE_Label3(), faders_[Names::SE_Label3]);
  }

  void SlidersLayoutPrefab::SL_Slider3_HorizontalIconSliderHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getSL_Slider3(), getSE_Label3(), faders_[Names::SE_Label3]);
  }

  void SlidersLayoutPrefab::SL_Slider3_HorizontalIconSliderHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getSL_Slider3(), getSE_Label3());
  }

  void SlidersLayoutPrefab::SL_Slider3_HorizontalIconSliderHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getSL_Slider3(), getSE_Label3());
  }

  void SlidersLayoutPrefab::SE_Label3_HorizontalIconSliderLabelHandlers(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::SE_Label3], dTime);
  }

  void SlidersLayoutPrefab::SL_Slider4_RadialIconSliderHandlers_onSliderChanged(const lumin::ui::UiEventData& data) {
    onSliderChangedBase(getSL_Slider4(), getSE_Label4());
  }

  void SlidersLayoutPrefab::SL_Slider4_RadialIconSliderHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getSL_Slider4(), getSE_Label4(), faders_[Names::SE_Label4]);
  }

  void SlidersLayoutPrefab::SL_Slider4_RadialIconSliderHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getSL_Slider4(), getSE_Label4(), faders_[Names::SE_Label4]);
  }

  void SlidersLayoutPrefab::SL_Slider4_RadialIconSliderHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getSL_Slider4(), getSE_Label4());
  }

  void SlidersLayoutPrefab::SL_Slider4_RadialIconSliderHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getSL_Slider4(), getSE_Label4());
  }

  void SlidersLayoutPrefab::SE_Label4_RadialSliderIconLabelHandlers(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::SE_Label4], dTime);
  }

  void SlidersLayoutPrefab::SL_Slider5_SmallRadialIconSliderHandlers_onSliderChanged(const lumin::ui::UiEventData& data) {
    onSliderChangedBase(getSL_Slider5(), getSE_Label5());
  }

  void SlidersLayoutPrefab::SL_Slider5_SmallRadialIconSliderHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getSL_Slider5(), getSE_Label5(), faders_[Names::SE_Label5]);
  }

  void SlidersLayoutPrefab::SL_Slider5_SmallRadialIconSliderHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getSL_Slider5(), getSE_Label5(), faders_[Names::SE_Label5]);
  }

  void SlidersLayoutPrefab::SL_Slider5_SmallRadialIconSliderHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getSL_Slider5(), getSE_Label5());
  }

  void SlidersLayoutPrefab::SL_Slider5_SmallRadialIconSliderHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getSL_Slider5(), getSE_Label5());
  }

  void SlidersLayoutPrefab::SE_Label5_SmallRadialIconSliderLabelHandlers(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::SE_Label5], dTime);
  }

  void SlidersLayoutPrefab::SL_ProgressBar_DefaultProgressBarHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    getSE_Label6()->setText(ExampleConsts::kHoverEnterText);
    if (faders_[Names::SE_Label6]) {
      faders_[Names::SE_Label6]->fadeIn();
    };
  }

  void SlidersLayoutPrefab::SL_ProgressBar_DefaultProgressBarHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    getSE_Label6()->setText(ExampleConsts::kHoverExitText);
    if (faders_[Names::SE_Label6]) {
      faders_[Names::SE_Label6]->fadeOut();
    };
  }

  void SlidersLayoutPrefab::SL_ProgressBar_DefaultProgressBarHandlers_onActivate(const lumin::ui::UiEventData& data) {
    getSE_Label6()->setText(lumin::ExampleConsts::kActivateText);
  }

  void SlidersLayoutPrefab::SL_ProgressBar_DefaultProgressBarHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    getSE_Label6()->setText(lumin::ExampleConsts::kLongPressText);
  }

  void SlidersLayoutPrefab::SL_ProgressBar_DefaultProgressBarHandlers_onUpdate(const lumin::ui::UiEventData& data, const float dTime) {
    float value = glm::min(kProgressMax, getSL_ProgressBar()->getValue() + kProgressSpeed);
    (value >= kProgressMax)?
        getSL_ProgressBar()->setValue(kProgressMin) :
        getSL_ProgressBar()->setValue(value);
  }

  void SlidersLayoutPrefab::SE_Label6_DefaultProgressBarLabelHandlers(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::SE_Label6], dTime);
  }

}
