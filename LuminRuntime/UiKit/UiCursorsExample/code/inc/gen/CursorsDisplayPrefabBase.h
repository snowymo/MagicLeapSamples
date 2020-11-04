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
#include <lumin/ui/node/UiColorPicker.h>
#include <lumin/ui/node/UiGridLayout.h>
#include <lumin/ui/node/UiPanel.h>

class ExtendedPrefabManager;

namespace prefabs {

  class CursorsDisplayPrefab;

  class CursorsDisplayPrefabBase : public PrefabBase {
  public:

    static const PrefabDescriptor& getClassPrefabDescriptor();

  public:

    struct Names {
    public:

      static const std::string& CC_GridLayout;
      static const std::string& CC_Panel1;
      static const std::string& CC_Panel2;
      static const std::string& CC_Panel3;
      static const std::string& CC_Panel4;
      static const std::string& CC_Panel5;
      static const std::string& CC_Panel6;
      static const std::string& CC_Panel7;
      static const std::string& CC_ColorPicker;

    protected:
      Names() = delete;
      ~Names() = delete;
    };

  public:

    const PrefabDescriptor& getPrefabDescriptor() const override;
    const NodeReferences& getNodeReferences() const override;

    virtual lumin::ui::UiGridLayout* getCC_GridLayout();
    virtual lumin::ui::UiPanel* getCC_Panel1();
    virtual lumin::ui::UiPanel* getCC_Panel2();
    virtual lumin::ui::UiPanel* getCC_Panel3();
    virtual lumin::ui::UiPanel* getCC_Panel4();
    virtual lumin::ui::UiPanel* getCC_Panel5();
    virtual lumin::ui::UiPanel* getCC_Panel6();
    virtual lumin::ui::UiPanel* getCC_Panel7();
    virtual lumin::ui::UiColorPicker* getCC_ColorPicker();


  protected:

    lumin::ui::UiGridLayout* CC_GridLayout;
    lumin::ui::UiPanel* CC_Panel1;
    lumin::ui::UiPanel* CC_Panel2;
    lumin::ui::UiPanel* CC_Panel3;
    lumin::ui::UiPanel* CC_Panel4;
    lumin::ui::UiPanel* CC_Panel5;
    lumin::ui::UiPanel* CC_Panel6;
    lumin::ui::UiPanel* CC_Panel7;
    lumin::ui::UiColorPicker* CC_ColorPicker;

    virtual void CC_Panel1_ChangeCursorDefaultHandler(const lumin::ui::UiEventData& data) = 0;
    virtual void CC_Panel2_ChangeCursorBrowserDefault(const lumin::ui::UiEventData& data) = 0;
    virtual void CC_Panel3_ChangeCursorBrowserPointer(const lumin::ui::UiEventData& data) = 0;
    virtual void CC_Panel4_ChangeCursorTextInput(const lumin::ui::UiEventData& data) = 0;
    virtual void CC_Panel5_ChangeCursorCrosshair(const lumin::ui::UiEventData& data) = 0;
    virtual void CC_Panel6_ChangeCursorMove(const lumin::ui::UiEventData& data) = 0;
    virtual void CC_Panel7_ChangeCursorScroll(const lumin::ui::UiEventData& data) = 0;
    virtual void CC_ColorPicker_ColorChanged_onCancel(const lumin::ui::UiEventData& data, const glm::vec4& color) = 0;
    virtual void CC_ColorPicker_ColorChanged_onColorChanged(const lumin::ui::UiEventData& data, const glm::vec4& color) = 0;

  private:

    friend class ::ExtendedPrefabManager;
    friend class CursorsDisplayPrefab;

    static PrefabBase* createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);

    static const PrefabDescriptor classPrefabDescriptor_;
    static const NodeReferences classNodeReferences_;

    CursorsDisplayPrefabBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~CursorsDisplayPrefabBase() override;
  };
}
