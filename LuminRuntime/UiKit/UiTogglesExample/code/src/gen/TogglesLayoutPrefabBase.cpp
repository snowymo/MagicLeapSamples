// -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING --
//
// THE CONTENTS OF THIS FILE IS GENERATED BY CODE AND
// ANY MODIFICATIONS WILL BE OVERWRITTEN
//
// -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING --

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

#include <TogglesLayoutPrefabBase.h>
#include <TogglesLayoutPrefab.h>

namespace prefabs {

  const PrefabDescriptor& TogglesLayoutPrefabBase::getClassPrefabDescriptor() {
    return classPrefabDescriptor_;
  }

  PrefabBase* TogglesLayoutPrefabBase::createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root) {
    PrefabBase* const prefab = new TogglesLayoutPrefab(extendedPrefabManager, root);
    return prefab;
  }

  TogglesLayoutPrefabBase::TogglesLayoutPrefabBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : PrefabBase(extendedPrefabManager, root) {

    TLS_Label1 = lumin::ui::UiText::CastFrom(root->findChild(Names::TLS_Label1));
    IOTS_Toggle = lumin::ui::UiToggle::CastFrom(root->findChild(Names::IOTS_Toggle));
    BES_Label1 = lumin::ui::UiText::CastFrom(root->findChild(Names::BES_Label1));
    IOSTS_Toggle = lumin::ui::UiToggle::CastFrom(root->findChild(Names::IOSTS_Toggle));
    BES_Label2 = lumin::ui::UiText::CastFrom(root->findChild(Names::BES_Label2));
    IOOTS_Toggle = lumin::ui::UiToggle::CastFrom(root->findChild(Names::IOOTS_Toggle));
    BES_Label3 = lumin::ui::UiText::CastFrom(root->findChild(Names::BES_Label3));
    SWITS_Toggle = lumin::ui::UiToggle::CastFrom(root->findChild(Names::SWITS_Toggle));
    BES_Label4 = lumin::ui::UiText::CastFrom(root->findChild(Names::BES_Label4));
    SWLTS_Toggle = lumin::ui::UiToggle::CastFrom(root->findChild(Names::SWLTS_Toggle));
    BES_Label5 = lumin::ui::UiText::CastFrom(root->findChild(Names::BES_Label5));
    TLS_Label7 = lumin::ui::UiText::CastFrom(root->findChild(Names::TLS_Label7));
    DTS_Toggle = lumin::ui::UiToggle::CastFrom(root->findChild(Names::DTS_Toggle));
    BES_Label6 = lumin::ui::UiText::CastFrom(root->findChild(Names::BES_Label6));
    RTS_Toggle = lumin::ui::UiToggle::CastFrom(root->findChild(Names::RTS_Toggle));
    BES_Label7 = lumin::ui::UiText::CastFrom(root->findChild(Names::BES_Label7));
    CTS_Toggle = lumin::ui::UiToggle::CastFrom(root->findChild(Names::CTS_Toggle));
    BES_Label8 = lumin::ui::UiText::CastFrom(root->findChild(Names::BES_Label8));

    IOTS_Toggle->onToggleChangedSub(std::bind(&TogglesLayoutPrefabBase::IOTS_Toggle_IconOnlyToggleHandlers_onToggleChanged, this, std::placeholders::_1));
    IOTS_Toggle->onHoverEnterSub(std::bind(&TogglesLayoutPrefabBase::IOTS_Toggle_IconOnlyToggleHandlers_onHoverEnter, this, std::placeholders::_1));
    IOTS_Toggle->onHoverExitSub(std::bind(&TogglesLayoutPrefabBase::IOTS_Toggle_IconOnlyToggleHandlers_onHoverExit, this, std::placeholders::_1));
    IOTS_Toggle->onLongPressSub(std::bind(&TogglesLayoutPrefabBase::IOTS_Toggle_IconOnlyToggleHandlers_onLongPress, this, std::placeholders::_1));
    BES_Label1->onUpdateSub(std::bind(&TogglesLayoutPrefabBase::BES_Label1_IconOnlyLabelHandler, this, std::placeholders::_1, std::placeholders::_2));
    IOSTS_Toggle->onToggleChangedSub(std::bind(&TogglesLayoutPrefabBase::IOSTS_Toggle_IconOnlySwitchToggleHandlers_onToggleChanged, this, std::placeholders::_1));
    IOSTS_Toggle->onHoverEnterSub(std::bind(&TogglesLayoutPrefabBase::IOSTS_Toggle_IconOnlySwitchToggleHandlers_onHoverEnter, this, std::placeholders::_1));
    IOSTS_Toggle->onHoverExitSub(std::bind(&TogglesLayoutPrefabBase::IOSTS_Toggle_IconOnlySwitchToggleHandlers_onHoverExit, this, std::placeholders::_1));
    IOSTS_Toggle->onLongPressSub(std::bind(&TogglesLayoutPrefabBase::IOSTS_Toggle_IconOnlySwitchToggleHandlers_onLongPress, this, std::placeholders::_1));
    BES_Label2->onUpdateSub(std::bind(&TogglesLayoutPrefabBase::BES_Label2_IconOnlySwitchLabelHandler, this, std::placeholders::_1, std::placeholders::_2));
    IOOTS_Toggle->onToggleChangedSub(std::bind(&TogglesLayoutPrefabBase::IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onToggleChanged, this, std::placeholders::_1));
    IOOTS_Toggle->onHoverEnterSub(std::bind(&TogglesLayoutPrefabBase::IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onHoverEnter, this, std::placeholders::_1));
    IOOTS_Toggle->onHoverExitSub(std::bind(&TogglesLayoutPrefabBase::IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onHoverExit, this, std::placeholders::_1));
    IOOTS_Toggle->onLongPressSub(std::bind(&TogglesLayoutPrefabBase::IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onLongPress, this, std::placeholders::_1));
    BES_Label3->onUpdateSub(std::bind(&TogglesLayoutPrefabBase::BES_Label3_IconOnlyOutlineLabelHandler, this, std::placeholders::_1, std::placeholders::_2));
    SWITS_Toggle->onToggleChangedSub(std::bind(&TogglesLayoutPrefabBase::SWITS_Toggle_SwitchIconToggleHandlers_onToggleChanged, this, std::placeholders::_1));
    SWITS_Toggle->onHoverEnterSub(std::bind(&TogglesLayoutPrefabBase::SWITS_Toggle_SwitchIconToggleHandlers_onHoverEnter, this, std::placeholders::_1));
    SWITS_Toggle->onHoverExitSub(std::bind(&TogglesLayoutPrefabBase::SWITS_Toggle_SwitchIconToggleHandlers_onHoverExit, this, std::placeholders::_1));
    SWITS_Toggle->onLongPressSub(std::bind(&TogglesLayoutPrefabBase::SWITS_Toggle_SwitchIconToggleHandlers_onLongPress, this, std::placeholders::_1));
    BES_Label4->onUpdateSub(std::bind(&TogglesLayoutPrefabBase::BES_Label4_SwitchIconLabelHandler, this, std::placeholders::_1, std::placeholders::_2));
    SWLTS_Toggle->onToggleChangedSub(std::bind(&TogglesLayoutPrefabBase::SWLTS_Toggle_SwitchLabelToggleHandlers_onToggleChanged, this, std::placeholders::_1));
    SWLTS_Toggle->onHoverEnterSub(std::bind(&TogglesLayoutPrefabBase::SWLTS_Toggle_SwitchLabelToggleHandlers_onHoverEnter, this, std::placeholders::_1));
    SWLTS_Toggle->onHoverExitSub(std::bind(&TogglesLayoutPrefabBase::SWLTS_Toggle_SwitchLabelToggleHandlers_onHoverExit, this, std::placeholders::_1));
    SWLTS_Toggle->onLongPressSub(std::bind(&TogglesLayoutPrefabBase::SWLTS_Toggle_SwitchLabelToggleHandlers_onLongPress, this, std::placeholders::_1));
    BES_Label5->onUpdateSub(std::bind(&TogglesLayoutPrefabBase::BES_Label5_SwitchLabelHandler, this, std::placeholders::_1, std::placeholders::_2));
    DTS_Toggle->onToggleChangedSub(std::bind(&TogglesLayoutPrefabBase::DTS_Toggle_DefaultToggleHandlers_onToggleChanged, this, std::placeholders::_1));
    DTS_Toggle->onHoverEnterSub(std::bind(&TogglesLayoutPrefabBase::DTS_Toggle_DefaultToggleHandlers_onHoverEnter, this, std::placeholders::_1));
    DTS_Toggle->onHoverExitSub(std::bind(&TogglesLayoutPrefabBase::DTS_Toggle_DefaultToggleHandlers_onHoverExit, this, std::placeholders::_1));
    DTS_Toggle->onLongPressSub(std::bind(&TogglesLayoutPrefabBase::DTS_Toggle_DefaultToggleHandlers_onLongPress, this, std::placeholders::_1));
    BES_Label6->onUpdateSub(std::bind(&TogglesLayoutPrefabBase::BES_Label6_DefaultLabelHandler, this, std::placeholders::_1, std::placeholders::_2));
    RTS_Toggle->onToggleChangedSub(std::bind(&TogglesLayoutPrefabBase::RTS_Toggle_RadioToggleHandlers_onToggleChanged, this, std::placeholders::_1));
    RTS_Toggle->onHoverEnterSub(std::bind(&TogglesLayoutPrefabBase::RTS_Toggle_RadioToggleHandlers_onHoverEnter, this, std::placeholders::_1));
    RTS_Toggle->onHoverExitSub(std::bind(&TogglesLayoutPrefabBase::RTS_Toggle_RadioToggleHandlers_onHoverExit, this, std::placeholders::_1));
    RTS_Toggle->onLongPressSub(std::bind(&TogglesLayoutPrefabBase::RTS_Toggle_RadioToggleHandlers_onLongPress, this, std::placeholders::_1));
    BES_Label7->onUpdateSub(std::bind(&TogglesLayoutPrefabBase::BES_Label7_RadioLabelHandler, this, std::placeholders::_1, std::placeholders::_2));
    CTS_Toggle->onToggleChangedSub(std::bind(&TogglesLayoutPrefabBase::CTS_Toggle_CheckboxToggleHandlers_onToggleChanged, this, std::placeholders::_1));
    CTS_Toggle->onHoverEnterSub(std::bind(&TogglesLayoutPrefabBase::CTS_Toggle_CheckboxToggleHandlers_onHoverEnter, this, std::placeholders::_1));
    CTS_Toggle->onHoverExitSub(std::bind(&TogglesLayoutPrefabBase::CTS_Toggle_CheckboxToggleHandlers_onHoverExit, this, std::placeholders::_1));
    CTS_Toggle->onLongPressSub(std::bind(&TogglesLayoutPrefabBase::CTS_Toggle_CheckboxToggleHandlers_onLongPress, this, std::placeholders::_1));
    BES_Label8->onUpdateSub(std::bind(&TogglesLayoutPrefabBase::BES_Label8_CheckboxLabelHandler, this, std::placeholders::_1, std::placeholders::_2));
  }

  TogglesLayoutPrefabBase::~TogglesLayoutPrefabBase() {
  }

  const PrefabDescriptor& TogglesLayoutPrefabBase::getPrefabDescriptor() const {
    return classPrefabDescriptor_;
  }

  const PrefabBase::NodeReferences& TogglesLayoutPrefabBase::getNodeReferences() const {
    return classNodeReferences_;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getTLS_Label1() {
    return TLS_Label1;
  }

  lumin::ui::UiToggle* TogglesLayoutPrefabBase::getIOTS_Toggle() {
    return IOTS_Toggle;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getBES_Label1() {
    return BES_Label1;
  }

  lumin::ui::UiToggle* TogglesLayoutPrefabBase::getIOSTS_Toggle() {
    return IOSTS_Toggle;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getBES_Label2() {
    return BES_Label2;
  }

  lumin::ui::UiToggle* TogglesLayoutPrefabBase::getIOOTS_Toggle() {
    return IOOTS_Toggle;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getBES_Label3() {
    return BES_Label3;
  }

  lumin::ui::UiToggle* TogglesLayoutPrefabBase::getSWITS_Toggle() {
    return SWITS_Toggle;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getBES_Label4() {
    return BES_Label4;
  }

  lumin::ui::UiToggle* TogglesLayoutPrefabBase::getSWLTS_Toggle() {
    return SWLTS_Toggle;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getBES_Label5() {
    return BES_Label5;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getTLS_Label7() {
    return TLS_Label7;
  }

  lumin::ui::UiToggle* TogglesLayoutPrefabBase::getDTS_Toggle() {
    return DTS_Toggle;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getBES_Label6() {
    return BES_Label6;
  }

  lumin::ui::UiToggle* TogglesLayoutPrefabBase::getRTS_Toggle() {
    return RTS_Toggle;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getBES_Label7() {
    return BES_Label7;
  }

  lumin::ui::UiToggle* TogglesLayoutPrefabBase::getCTS_Toggle() {
    return CTS_Toggle;
  }

  lumin::ui::UiText* TogglesLayoutPrefabBase::getBES_Label8() {
    return BES_Label8;
  }

}
