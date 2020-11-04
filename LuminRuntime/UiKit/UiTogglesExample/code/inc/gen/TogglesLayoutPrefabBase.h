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

#pragma once

#include <PrefabBase.h>
#include <PrefabDescriptor.h>
#include <lumin/ui/node/UiText.h>
#include <lumin/ui/node/UiToggle.h>

class ExtendedPrefabManager;

namespace prefabs {

  class TogglesLayoutPrefab;

  class TogglesLayoutPrefabBase : public PrefabBase {
  public:

    static const PrefabDescriptor& getClassPrefabDescriptor();

  public:

    struct Names {
    public:

      static const std::string& TLS_Label1;
      static const std::string& IOTS_Toggle;
      static const std::string& BES_Label1;
      static const std::string& IOSTS_Toggle;
      static const std::string& BES_Label2;
      static const std::string& IOOTS_Toggle;
      static const std::string& BES_Label3;
      static const std::string& SWITS_Toggle;
      static const std::string& BES_Label4;
      static const std::string& SWLTS_Toggle;
      static const std::string& BES_Label5;
      static const std::string& TLS_Label7;
      static const std::string& DTS_Toggle;
      static const std::string& BES_Label6;
      static const std::string& RTS_Toggle;
      static const std::string& BES_Label7;
      static const std::string& CTS_Toggle;
      static const std::string& BES_Label8;

    protected:
      Names() = delete;
      ~Names() = delete;
    };

  public:

    const PrefabDescriptor& getPrefabDescriptor() const override;
    const NodeReferences& getNodeReferences() const override;

    virtual lumin::ui::UiText* getTLS_Label1();
    virtual lumin::ui::UiToggle* getIOTS_Toggle();
    virtual lumin::ui::UiText* getBES_Label1();
    virtual lumin::ui::UiToggle* getIOSTS_Toggle();
    virtual lumin::ui::UiText* getBES_Label2();
    virtual lumin::ui::UiToggle* getIOOTS_Toggle();
    virtual lumin::ui::UiText* getBES_Label3();
    virtual lumin::ui::UiToggle* getSWITS_Toggle();
    virtual lumin::ui::UiText* getBES_Label4();
    virtual lumin::ui::UiToggle* getSWLTS_Toggle();
    virtual lumin::ui::UiText* getBES_Label5();
    virtual lumin::ui::UiText* getTLS_Label7();
    virtual lumin::ui::UiToggle* getDTS_Toggle();
    virtual lumin::ui::UiText* getBES_Label6();
    virtual lumin::ui::UiToggle* getRTS_Toggle();
    virtual lumin::ui::UiText* getBES_Label7();
    virtual lumin::ui::UiToggle* getCTS_Toggle();
    virtual lumin::ui::UiText* getBES_Label8();


  protected:

    lumin::ui::UiText* TLS_Label1;
    lumin::ui::UiToggle* IOTS_Toggle;
    lumin::ui::UiText* BES_Label1;
    lumin::ui::UiToggle* IOSTS_Toggle;
    lumin::ui::UiText* BES_Label2;
    lumin::ui::UiToggle* IOOTS_Toggle;
    lumin::ui::UiText* BES_Label3;
    lumin::ui::UiToggle* SWITS_Toggle;
    lumin::ui::UiText* BES_Label4;
    lumin::ui::UiToggle* SWLTS_Toggle;
    lumin::ui::UiText* BES_Label5;
    lumin::ui::UiText* TLS_Label7;
    lumin::ui::UiToggle* DTS_Toggle;
    lumin::ui::UiText* BES_Label6;
    lumin::ui::UiToggle* RTS_Toggle;
    lumin::ui::UiText* BES_Label7;
    lumin::ui::UiToggle* CTS_Toggle;
    lumin::ui::UiText* BES_Label8;

    virtual void IOTS_Toggle_IconOnlyToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void IOTS_Toggle_IconOnlyToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void IOTS_Toggle_IconOnlyToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void IOTS_Toggle_IconOnlyToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) = 0;
    virtual void BES_Label1_IconOnlyLabelHandler(const lumin::ui::UiEventData& data, const float dTime) = 0;
    virtual void IOSTS_Toggle_IconOnlySwitchToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void IOSTS_Toggle_IconOnlySwitchToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void IOSTS_Toggle_IconOnlySwitchToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void IOSTS_Toggle_IconOnlySwitchToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) = 0;
    virtual void BES_Label2_IconOnlySwitchLabelHandler(const lumin::ui::UiEventData& data, const float dTime) = 0;
    virtual void IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void IOOTS_Toggle_IconOnlyOutlineToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) = 0;
    virtual void BES_Label3_IconOnlyOutlineLabelHandler(const lumin::ui::UiEventData& data, const float dTime) = 0;
    virtual void SWITS_Toggle_SwitchIconToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void SWITS_Toggle_SwitchIconToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void SWITS_Toggle_SwitchIconToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void SWITS_Toggle_SwitchIconToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) = 0;
    virtual void BES_Label4_SwitchIconLabelHandler(const lumin::ui::UiEventData& data, const float dTime) = 0;
    virtual void SWLTS_Toggle_SwitchLabelToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void SWLTS_Toggle_SwitchLabelToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void SWLTS_Toggle_SwitchLabelToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void SWLTS_Toggle_SwitchLabelToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) = 0;
    virtual void BES_Label5_SwitchLabelHandler(const lumin::ui::UiEventData& data, const float dTime) = 0;
    virtual void DTS_Toggle_DefaultToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void DTS_Toggle_DefaultToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void DTS_Toggle_DefaultToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void DTS_Toggle_DefaultToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) = 0;
    virtual void BES_Label6_DefaultLabelHandler(const lumin::ui::UiEventData& data, const float dTime) = 0;
    virtual void RTS_Toggle_RadioToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void RTS_Toggle_RadioToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void RTS_Toggle_RadioToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void RTS_Toggle_RadioToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) = 0;
    virtual void BES_Label7_RadioLabelHandler(const lumin::ui::UiEventData& data, const float dTime) = 0;
    virtual void CTS_Toggle_CheckboxToggleHandlers_onToggleChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void CTS_Toggle_CheckboxToggleHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void CTS_Toggle_CheckboxToggleHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void CTS_Toggle_CheckboxToggleHandlers_onLongPress(const lumin::ui::UiEventData& data) = 0;
    virtual void BES_Label8_CheckboxLabelHandler(const lumin::ui::UiEventData& data, const float dTime) = 0;

  private:

    friend class ::ExtendedPrefabManager;
    friend class TogglesLayoutPrefab;

    static PrefabBase* createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);

    static const PrefabDescriptor classPrefabDescriptor_;
    static const NodeReferences classNodeReferences_;

    TogglesLayoutPrefabBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~TogglesLayoutPrefabBase() override;
  };
}