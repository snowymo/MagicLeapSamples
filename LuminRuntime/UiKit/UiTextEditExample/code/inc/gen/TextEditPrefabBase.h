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
#include <lumin/ui/node/UiTextEdit.h>

class ExtendedPrefabManager;

namespace prefabs {

  class TextEditPrefab;

  class TextEditPrefabBase : public PrefabBase {
  public:

    static const PrefabDescriptor& getClassPrefabDescriptor();

  public:

    struct Names {
    public:

      static const std::string& SingleLineTextEdit;
      static const std::string& MultiLineTextEdit;
      static const std::string& CharRatio;
      static const std::string& PasswordTextEdit;
      static const std::string& PasswordRequirements;
      static const std::string& URLTextEdit;
      static const std::string& NumericTextEdit;
      static const std::string& NumericRequirements;

    protected:
      Names() = delete;
      ~Names() = delete;
    };

  public:

    const PrefabDescriptor& getPrefabDescriptor() const override;
    const NodeReferences& getNodeReferences() const override;

    virtual lumin::ui::UiTextEdit* getSingleLineTextEdit();
    virtual lumin::ui::UiTextEdit* getMultiLineTextEdit();
    virtual lumin::ui::UiText* getCharRatio();
    virtual lumin::ui::UiTextEdit* getPasswordTextEdit();
    virtual lumin::ui::UiText* getPasswordRequirements();
    virtual lumin::ui::UiTextEdit* getURLTextEdit();
    virtual lumin::ui::UiTextEdit* getNumericTextEdit();
    virtual lumin::ui::UiText* getNumericRequirements();


  protected:

    lumin::ui::UiTextEdit* SingleLineTextEdit;
    lumin::ui::UiTextEdit* MultiLineTextEdit;
    lumin::ui::UiText* CharRatio;
    lumin::ui::UiTextEdit* PasswordTextEdit;
    lumin::ui::UiText* PasswordRequirements;
    lumin::ui::UiTextEdit* URLTextEdit;
    lumin::ui::UiTextEdit* NumericTextEdit;
    lumin::ui::UiText* NumericRequirements;

    virtual void SingleLineTextEdit_SingleLineHandlers(const lumin::ui::UiEventData& data, const lumin::ui::KeyboardEvent::EventData& event) = 0;
    virtual void MultiLineTextEdit_MultiLineHandlers_onKeyboardEvent(const lumin::ui::UiEventData& data, const lumin::ui::KeyboardEvent::EventData& event) = 0;
    virtual void MultiLineTextEdit_MultiLineHandlers_onTextChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void PasswordTextEdit_PasswordHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void PasswordTextEdit_PasswordHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void URLTextEdit_UrlHandlers(const lumin::ui::UiEventData& data, const lumin::ui::KeyboardEvent::EventData& event) = 0;
    virtual void NumericTextEdit_NumericHandlers_onHoverEnter(const lumin::ui::UiEventData& data) = 0;
    virtual void NumericTextEdit_NumericHandlers_onHoverExit(const lumin::ui::UiEventData& data) = 0;
    virtual void NumericTextEdit_NumericHandlers_onTextChanged(const lumin::ui::UiEventData& data) = 0;
    virtual void NumericTextEdit_NumericHandlers_onKeyboardEvent(const lumin::ui::UiEventData& data, const lumin::ui::KeyboardEvent::EventData& event) = 0;

  private:

    friend class ::ExtendedPrefabManager;
    friend class TextEditPrefab;

    static PrefabBase* createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);

    static const PrefabDescriptor classPrefabDescriptor_;
    static const NodeReferences classNodeReferences_;

    TextEditPrefabBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~TextEditPrefabBase() override;
  };
}
