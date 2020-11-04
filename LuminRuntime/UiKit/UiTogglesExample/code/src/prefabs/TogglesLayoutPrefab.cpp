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
#include <TogglesLayoutPrefab.h>
#include <ExamplesConstants.h>
#include <lumin/Consts.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const std::string kOn  = "On Toggle Changed [ON]";
  const std::string kOff = "On Toggle Changed [OFF]";
}

namespace prefabs {


  TogglesLayoutPrefab::TogglesLayoutPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : TogglesLayoutPrefabBase(extendedPrefabManager, root) {
  }

  TogglesLayoutPrefab::~TogglesLayoutPrefab() {
  }

  void TogglesLayoutPrefab::addFader(const std::string& label, LabelFader* fader) {
    faders_.emplace(label, fader);
  }

  void TogglesLayoutPrefab::deleteFaders() {
    for (auto fader : faders_) {
      delete fader.second;
      fader.second = nullptr;
    }
    faders_.clear();
  }

  void onHoverEnterBase(UiToggle* toggle, UiText* label, LabelFader* fader) {
    label->setText(ExampleConsts::kHoverEnterText);
    if (fader) {
      fader->fadeIn();
    }
    toggle->setTextColor(color::CYAN);
  }

  void onHoverExitBase(UiToggle* toggle, UiText* label, LabelFader* fader) {
    label->setText(ExampleConsts::kHoverExitText);
    if (fader) {
      fader->fadeOut();
    }
    toggle->setTextColor(color::WHITE);
  }

  void onLongPressBase(UiToggle* toggle, UiText* label) {
    label->setText(ExampleConsts::kLongPressText);
    toggle->setTextColor(color::RED);
  }

  void onToggleChangedBase(UiToggle* toggle, UiText* label) {
    if (toggle->getOn()) {
      label->setText(kOn);
      toggle->setTextColor(color::MAGENTA);
    } else {
      label->setText(kOff);
      toggle->setTextColor(color::INDIGO);
    }
  }

  void onUpdateLabelBase(LabelFader* fader, float delta) {
    if (fader) {
      fader->update(delta);
    }
  }

  // Handler methods are declared in the base class TogglesLayoutPrefabBase and can be implemented here

  void TogglesLayoutPrefab::IOTS_Toggle_IconOnlyToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) {
    onToggleChangedBase(getIOTS_Toggle(), getBES_Label1());
  }

  void TogglesLayoutPrefab::IOTS_Toggle_IconOnlyToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getIOTS_Toggle(), getBES_Label1(), faders_[Names::BES_Label1]);
  }

  void TogglesLayoutPrefab::IOTS_Toggle_IconOnlyToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getIOTS_Toggle(), getBES_Label1(), faders_[Names::BES_Label1]);
  }

  void TogglesLayoutPrefab::IOTS_Toggle_IconOnlyToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getIOTS_Toggle(), getBES_Label1());
  }

  void TogglesLayoutPrefab::BES_Label1_IconOnlyLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label1], dTime);
  }

  void TogglesLayoutPrefab::IOSTS_Toggle_IconOnlySwitchToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) {
    onToggleChangedBase(getIOSTS_Toggle(), getBES_Label2());
  }

  void TogglesLayoutPrefab::IOSTS_Toggle_IconOnlySwitchToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getIOSTS_Toggle(), getBES_Label2(), faders_[Names::BES_Label2]);
  }

  void TogglesLayoutPrefab::IOSTS_Toggle_IconOnlySwitchToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getIOSTS_Toggle(), getBES_Label2(), faders_[Names::BES_Label2]);
  }

  void TogglesLayoutPrefab::IOSTS_Toggle_IconOnlySwitchToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getIOSTS_Toggle(), getBES_Label2());
  }

  void TogglesLayoutPrefab::BES_Label2_IconOnlySwitchLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label2], dTime);
  }

  void TogglesLayoutPrefab::IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) {
    onToggleChangedBase(getIOOTS_Toggle(), getBES_Label3());
  }

  void TogglesLayoutPrefab::IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getIOOTS_Toggle(), getBES_Label3(), faders_[Names::BES_Label3]);
  }

  void TogglesLayoutPrefab::IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getIOOTS_Toggle(), getBES_Label3(), faders_[Names::BES_Label3]);
  }

  void TogglesLayoutPrefab::IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getIOOTS_Toggle(), getBES_Label3());
  }

  void TogglesLayoutPrefab::BES_Label3_IconOnlyOutlineLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label3], dTime);
  }

  void TogglesLayoutPrefab::SWITS_Toggle_SwitchIconToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) {
    onToggleChangedBase(getSWITS_Toggle(), getBES_Label4());
  }

  void TogglesLayoutPrefab::SWITS_Toggle_SwitchIconToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getSWITS_Toggle(), getBES_Label4(), faders_[Names::BES_Label4]);
  }

  void TogglesLayoutPrefab::SWITS_Toggle_SwitchIconToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getSWITS_Toggle(), getBES_Label4(), faders_[Names::BES_Label4]);
  }

  void TogglesLayoutPrefab::SWITS_Toggle_SwitchIconToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getSWITS_Toggle(), getBES_Label4());
  }

  void TogglesLayoutPrefab::BES_Label4_SwitchIconLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label4], dTime);
  }

  void TogglesLayoutPrefab::SWLTS_Toggle_SwitchLabelToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) {
    onToggleChangedBase(getSWLTS_Toggle(), getBES_Label5());
  }

  void TogglesLayoutPrefab::SWLTS_Toggle_SwitchLabelToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getSWLTS_Toggle(), getBES_Label5(), faders_[Names::BES_Label5]);
  }

  void TogglesLayoutPrefab::SWLTS_Toggle_SwitchLabelToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getSWLTS_Toggle(), getBES_Label5(), faders_[Names::BES_Label5]);
  }

  void TogglesLayoutPrefab::SWLTS_Toggle_SwitchLabelToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getSWLTS_Toggle(), getBES_Label5());
  }

  void TogglesLayoutPrefab::BES_Label5_SwitchLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label5], dTime);
  }

  void TogglesLayoutPrefab::DTS_Toggle_DefaultToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) {
    onToggleChangedBase(getDTS_Toggle(), getBES_Label6());
  }

  void TogglesLayoutPrefab::DTS_Toggle_DefaultToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDTS_Toggle(), getBES_Label6(), faders_[Names::BES_Label6]);
  }

  void TogglesLayoutPrefab::DTS_Toggle_DefaultToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDTS_Toggle(), getBES_Label6(), faders_[Names::BES_Label6]);
  }

  void TogglesLayoutPrefab::DTS_Toggle_DefaultToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getDTS_Toggle(), getBES_Label6());
  }

  void TogglesLayoutPrefab::BES_Label6_DefaultLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label6], dTime);
  }

  void TogglesLayoutPrefab::RTS_Toggle_RadioToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) {
    onToggleChangedBase(getRTS_Toggle(), getBES_Label7());
  }

  void TogglesLayoutPrefab::RTS_Toggle_RadioToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getRTS_Toggle(), getBES_Label7(), faders_[Names::BES_Label7]);
  }

  void TogglesLayoutPrefab::RTS_Toggle_RadioToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getRTS_Toggle(), getBES_Label7(), faders_[Names::BES_Label7]);
  }

  void TogglesLayoutPrefab::RTS_Toggle_RadioToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getRTS_Toggle(), getBES_Label7());
  }

  void TogglesLayoutPrefab::BES_Label7_RadioLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label7], dTime);
  }

  void TogglesLayoutPrefab::CTS_Toggle_CheckboxToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) {
    onToggleChangedBase(getCTS_Toggle(), getBES_Label8());
  }

  void TogglesLayoutPrefab::CTS_Toggle_CheckboxToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getCTS_Toggle(), getBES_Label8(), faders_[Names::BES_Label8]);
  }

  void TogglesLayoutPrefab::CTS_Toggle_CheckboxToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getCTS_Toggle(), getBES_Label8(), faders_[Names::BES_Label8]);
  }

  void TogglesLayoutPrefab::CTS_Toggle_CheckboxToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(getCTS_Toggle(), getBES_Label8());
  }

  void TogglesLayoutPrefab::BES_Label8_CheckboxLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label8], dTime);
  }
}