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
#include <ButtonsLayoutPrefab.h>
#include <ExamplesConstants.h>
#include <lumin/ui/node/UiNode.h>
#include <lumin/ui/node/UiButton.h>
#include <lumin/ui/node/UiText.h>
#include <lumin/Consts.h>

using namespace lumin;
using namespace lumin::ui;

namespace prefabs {


  ButtonsLayoutPrefab::ButtonsLayoutPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : ButtonsLayoutPrefabBase(extendedPrefabManager, root) {
  }

  ButtonsLayoutPrefab::~ButtonsLayoutPrefab() {
  }

  void ButtonsLayoutPrefab::addLabelFader(const std::string& label, LabelFader* fader) {
    faders_.emplace(label, fader);
  }

  void ButtonsLayoutPrefab::deleteFaders() {
    for (auto fader : faders_) {
      delete fader.second;
      fader.second = nullptr;
    }
    faders_.clear();
  }

  void onHoverEnterBase(UiButton* button, UiText* label, LabelFader* fader) {
    label->setText(ExampleConsts::kHoverEnterText);
    if (fader) {
      fader->fadeIn();
    }
    button->setTextColor(color::CYAN);
    button->setIconColor(color::CYAN);
  }

  void onHoverExitBase(UiButton* button, UiText* label, LabelFader* fader) {
    label->setText(ExampleConsts::kHoverExitText);
    if (fader) {
      fader->fadeOut();
    }
    button->setTextColor(color::WHITE);
    button->setIconColor(color::WHITE);
  }

  void onActivateBase(UiButton* button, UiText* label) {
    label->setText(ExampleConsts::kActivateText);
    button->setTextColor(color::GREEN);
    button->setIconColor(color::GREEN);
  }

  void onLongPressBase(UiButton* button, UiText* label) {
    label->setText(ExampleConsts::kLongPressText);
    button->setTextColor(color::RED);
    button->setIconColor(color::RED);
  }

  void onUpdateLabelBase(LabelFader* fader, float delta) {
    if (fader) {
      fader->update(delta);
    }
  }

  // Handler methods are declared in the base class ButtonsLayoutPrefabBase and can be implemented here

  void ButtonsLayoutPrefab::BLS_Button1_IconOnlyButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label1(), faders_[Names::BES_Label1]);
  }

  void ButtonsLayoutPrefab::BLS_Button1_IconOnlyButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label1(), faders_[Names::BES_Label1]);
  }

  void ButtonsLayoutPrefab::BLS_Button1_IconOnlyButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label1());
  }

  void ButtonsLayoutPrefab::BLS_Button1_IconOnlyButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label1());
  }

  void ButtonsLayoutPrefab::BES_Label1_IconOnlyLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label1], dTime);
  }

  void ButtonsLayoutPrefab::BLS_Button2_TextOnlyButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label2(), faders_[Names::BES_Label2]);
  }

  void ButtonsLayoutPrefab::BLS_Button2_TextOnlyButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label2(), faders_[Names::BES_Label2]);
  }

  void ButtonsLayoutPrefab::BLS_Button2_TextOnlyButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label2());
  }

  void ButtonsLayoutPrefab::BLS_Button2_TextOnlyButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label2());
  }

  void ButtonsLayoutPrefab::BES_Label2_TextOnlyLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label2], dTime);
  }

  void ButtonsLayoutPrefab::BLS_Button3_IconWithLabelButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label3(), faders_[Names::BES_Label3]);
  }

  void ButtonsLayoutPrefab::BLS_Button3_IconWithLabelButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label3(), faders_[Names::BES_Label3]);
  }

  void ButtonsLayoutPrefab::BLS_Button3_IconWithLabelButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label3());
  }

  void ButtonsLayoutPrefab::BLS_Button3_IconWithLabelButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label3());
  }

  void ButtonsLayoutPrefab::BES_Label3_IconWithLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label3], dTime);
  }

  void ButtonsLayoutPrefab::BLS_Button4_TextWithIconButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label4(), faders_[Names::BES_Label4]);
  }

  void ButtonsLayoutPrefab::BLS_Button4_TextWithIconButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label4(), faders_[Names::BES_Label4]);
  }

  void ButtonsLayoutPrefab::BLS_Button4_TextWithIconButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label4());
  }

  void ButtonsLayoutPrefab::BLS_Button4_TextWithIconButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label4());
  }

  void ButtonsLayoutPrefab::BES_Label4_TextWithIconLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label4], dTime);
  }

  void ButtonsLayoutPrefab::BLS_Button5_TextOnlyOutlinedButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label5(), faders_[Names::BES_Label5]);
  }

  void ButtonsLayoutPrefab::BLS_Button5_TextOnlyOutlinedButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label5(), faders_[Names::BES_Label5]);
  }

  void ButtonsLayoutPrefab::BLS_Button5_TextOnlyOutlinedButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label5());
  }

  void ButtonsLayoutPrefab::BLS_Button5_TextOnlyOutlinedButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label5());
  }

  void ButtonsLayoutPrefab::BES_Label5_TextOnlyOutlinedLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label5], dTime);
  }

  void ButtonsLayoutPrefab::BLS_Button6_TextWithIconOutlinedButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label6(), faders_[Names::BES_Label6]);
  }

  void ButtonsLayoutPrefab::BLS_Button6_TextWithIconOutlinedButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label6(), faders_[Names::BES_Label6]);
  }

  void ButtonsLayoutPrefab::BLS_Button6_TextWithIconOutlinedButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label6());
  }

  void ButtonsLayoutPrefab::BLS_Button6_TextWithIconOutlinedButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label6());
  }

  void ButtonsLayoutPrefab::BES_Label6_TextWithIconOutlinedLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label6], dTime);
  }

  void ButtonsLayoutPrefab::CBS_Button_CapsuleButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label7(), faders_[Names::BES_Label7]);
  }

  void ButtonsLayoutPrefab::CBS_Button_CapsuleButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label7(), faders_[Names::BES_Label7]);
  }

  void ButtonsLayoutPrefab::CBS_Button_CapsuleButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label7());
  }

  void ButtonsLayoutPrefab::CBS_Button_CapsuleButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label7());
  }

  void ButtonsLayoutPrefab::BES_Label7_CapsuleLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label7], dTime);
  }

  void ButtonsLayoutPrefab::RCB_Button_RoundedCornerButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label8(), faders_[Names::BES_Label8]);
  }

  void ButtonsLayoutPrefab::RCB_Button_RoundedCornerButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label8(), faders_[Names::BES_Label8]);
  }

  void ButtonsLayoutPrefab::RCB_Button_RoundedCornerButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label8());
  }

  void ButtonsLayoutPrefab::RCB_Button_RoundedCornerButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label8());
  }

  void ButtonsLayoutPrefab::BES_Label8_RoundedCornerLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label8], dTime);
  }

  void ButtonsLayoutPrefab::SB_Button_SquareButtonHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(UiButton::CastFrom(data.getUiNode()), getBES_Label9(), faders_[Names::BES_Label9]);
  }

  void ButtonsLayoutPrefab::SB_Button_SquareButtonHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(UiButton::CastFrom(data.getUiNode()), getBES_Label9(), faders_[Names::BES_Label9]);
  }

  void ButtonsLayoutPrefab::SB_Button_SquareButtonHandlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(UiButton::CastFrom(data.getUiNode()), getBES_Label9());
  }

  void ButtonsLayoutPrefab::SB_Button_SquareButtonHandlers_onLongPress(const lumin::ui::UiEventData& data) {
    onLongPressBase(UiButton::CastFrom(data.getUiNode()), getBES_Label9());
  }

  void ButtonsLayoutPrefab::BES_Label9_SquareLabelHandler(const lumin::ui::UiEventData& data, const float dTime) {
    onUpdateLabelBase(faders_[Names::BES_Label9], dTime);
  }
}
