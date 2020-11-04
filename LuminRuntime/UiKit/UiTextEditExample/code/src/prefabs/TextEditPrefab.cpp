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
#include <TextEditPrefab.h>
#include <lumin/ui/node/UiTextEdit.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const uint32_t kMultiCharLimit  = 140;  // multiline text entry character limit
  const uint32_t kNumerCharLimit  = 6;

  // Clear the UiTextEdit's text when the clear key is pressed:
  void clearEventCallback(const UiEventData& edit, const KeyboardEvent::EventData& keyEvent) {
    if (keyEvent.getEventType() == KeyboardEvent::EventType::KEY_PRESSED) {
      if (static_cast<const KeyboardEvent::KeyPressedData&>(keyEvent).getKeyType() == KeyType::kClear) {
        UiTextEdit::CastFrom(edit.getUiNode())->setText("");
      }
    }
  }
}

namespace prefabs {


  TextEditPrefab::TextEditPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : TextEditPrefabBase(extendedPrefabManager, root) {
  }

  TextEditPrefab::~TextEditPrefab() {
  }

  // Handler methods are declared in the base class TextEditPrefabBase and can be implemented here

  void TextEditPrefab::SingleLineTextEdit_SingleLineHandlers(const lumin::ui::UiEventData& data, const lumin::ui::KeyboardEvent::EventData& event) {
    clearEventCallback(data, event);
  }

  void TextEditPrefab::MultiLineTextEdit_MultiLineHandlers_onKeyboardEvent(const lumin::ui::UiEventData& data, const lumin::ui::KeyboardEvent::EventData& event) {
    if (event.getEventType() == KeyboardEvent::EventType::KEY_PRESSED) {
      if (static_cast<const KeyboardEvent::KeyPressedData&>(event).getKeyType() == KeyType::kClear) {
        UiTextEdit::CastFrom(data.getUiNode())->setText("");
        getCharRatio()->setText("0/" + std::to_string(kMultiCharLimit));
      }
    }
  }

  void TextEditPrefab::MultiLineTextEdit_MultiLineHandlers_onTextChanged(const lumin::ui::UiEventData& data) {
    uint32_t charCount = UiTextEdit::CastFrom(data.getUiNode())->getCharacterCount();
    getCharRatio()->setText(std::to_string(charCount) + "/" + std::to_string(kMultiCharLimit));
  }

  void TextEditPrefab::PasswordTextEdit_PasswordHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    getPasswordRequirements()->setVisible(true);
  }

  void TextEditPrefab::PasswordTextEdit_PasswordHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    getPasswordRequirements()->setVisible(false);
  }

  void TextEditPrefab::URLTextEdit_UrlHandlers(const lumin::ui::UiEventData& data, const lumin::ui::KeyboardEvent::EventData& event) {
    clearEventCallback(data, event);
    if (event.getEventType() == KeyboardEvent::EventType::KEY_PRESSED) {
      if (static_cast<const KeyboardEvent::KeyPressedData&>(event).getKeyType() == KeyType::kSubmit) {
        UiTextEdit::CastFrom(data.getUiNode())->setTextColor(color::GREEN);
      }
      else {
        UiTextEdit::CastFrom(data.getUiNode())->setTextColor(color::WHITE);
      }
    }
  }

  void TextEditPrefab::NumericTextEdit_NumericHandlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    getNumericRequirements()->setVisible(true);
  }

  void TextEditPrefab::NumericTextEdit_NumericHandlers_onHoverExit(const lumin::ui::UiEventData& data) {
    getNumericRequirements()->setVisible(false);
  }

  void TextEditPrefab::NumericTextEdit_NumericHandlers_onTextChanged(const lumin::ui::UiEventData& data) {
    if (UiTextEdit::CastFrom(data.getUiNode())->getCharacterCount() == kNumerCharLimit) {
      UiTextEdit::CastFrom(data.getUiNode())->setTextColor(color::GREEN);
    } else {
      UiTextEdit::CastFrom(data.getUiNode())->setTextColor(color::WHITE);
    }
  }

  void TextEditPrefab::NumericTextEdit_NumericHandlers_onKeyboardEvent(const lumin::ui::UiEventData& data, const lumin::ui::KeyboardEvent::EventData& event) {
    clearEventCallback(data, event);
  }
}
