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
#include <TextEdit.h>
#include <TextEditPrefab.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesDefines.h>

#include <ml_logging.h>
#include <algorithm>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const float kIconSize           = 0.05f;
  const float kKeyboardOpacity    = 0.7f;
  const float kTextEditWidth      = 0.7f;
  const float kTextEditHeight     = 0.05f;
  const float kTextSmallSize      = 0.03f;
  const uint32_t kMultiCharLimit  = 140;          // multiline text entry character limit
  const uint32_t kNumerCharLimit  = 6;            // numeric text entry character limit
  const glm::vec2 kPasswordBounds(0.2f, 0.5f);    // password text bounds, enables text wrapping
  const glm::vec3 kPasswordPos(-0.3f, -0.08f, 0.0f);
  const glm::vec2 kNumericBounds(0.2f, 0.5f);     // numeric text bounds, enables text wrapping
  const glm::vec3 kNumericPos(-0.3f, -0.03f, 0.0f);
  const glm::vec4 kTitlePadding(0.0f, 0.0f, 0.01f, 0.0f);

  // Clear the UiTextEdit's text when the clear key is pressed:
  void clearEventCallback(const UiEventData& edit, const KeyboardEvent::EventData& keyEvent) {
    if (keyEvent.getEventType() == KeyboardEvent::EventType::KEY_PRESSED) {
      if (static_cast<const KeyboardEvent::KeyPressedData&>(keyEvent).getKeyType() == KeyType::kClear) {
        UiTextEdit::CastFrom(edit.getUiNode())->setText("");
      }
    }
  }
}

TextEdit::TextEdit() : BaseExample("UiKit Text Edit") {
  keyboard_.speechToTextEnabled = true;
}

TextEdit::~TextEdit() {
}

void TextEdit::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "TextEdit::onAttachPrism() Initializing the Text Edit scene");
  lumin::SDKExamples::BaseExample::onAttachPrism(prism);
}

void TextEdit::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "TextEdit::onDetachPrism() Destroying the Text Edit scene");
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}

TransformNode* TextEdit::loadSceneGraph(lumin::Prism* prism) {
  prefabs::TextEditPrefab* prefab = managers_->extendedPrefab_->spawn<prefabs::TextEditPrefab>();
  LUMIN_ASSERT(prefab, "Failed to create TextEditPrefab.");
  singleLineTextEdit_ = prefab->getSingleLineTextEdit();
  multiLineTextEdit_  = prefab->getMultiLineTextEdit();
  passwordTextEdit_   = prefab->getPasswordTextEdit();
  urlTextEdit_        = prefab->getURLTextEdit();
  numericTextEdit_    = prefab->getNumericTextEdit();

  // These will be supported in editor but until they are they need to manually set them.
  singleLineTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  multiLineTextEdit_->setText("Multiple Line Text Edit.\nLine 2.\nLine 3.");
  multiLineTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  passwordTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  urlTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  numericTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  setCommonProperties();

  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab->getRoot());
  return rootContainer;
}

TransformNode* TextEdit::buildSceneGraph(lumin::Prism* prism) {
  UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
  topLayout->setAlignment(Alignment::CENTER_CENTER);

  createSingleLineEntry(prism, topLayout);
  createMultiLineEntry(prism, topLayout);
  createPasswordEntry(prism, topLayout);
  createUrlEntry(prism, topLayout);
  createNumericEntry(prism, topLayout);
  setCommonProperties();
  return topLayout;
}

// Create a single line entry box:
void TextEdit::createSingleLineEntry(Prism* prism, UiLinearLayout* topLayout) {
  createTitle(prism, topLayout, "Single Line:");
  singleLineTextEdit_ = SDKExamples::createUiTextEdit(prism, "Single Line Text Edit.", kTextEditWidth, kTextEditHeight);
  singleLineTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  singleLineTextEdit_->setTextSize(ExampleConsts::kTextSize);
  singleLineTextEdit_->onKeyboardEventSub(std::bind(&clearEventCallback, std::placeholders::_1, std::placeholders::_2));
  topLayout->addItem(singleLineTextEdit_, ExampleConsts::kTitlePadding, Alignment::CENTER_LEFT);
}

// Create a multiple line text entry box, with a 140 character limit,
// Display the current character count:
void TextEdit::createMultiLineEntry(Prism* prism, UiLinearLayout* topLayout) {
  createTitle(prism, topLayout, "Multiple Line:");
  multiLineTextEdit_ = SDKExamples::createUiTextEdit(prism, "Multiple Line Text Edit.",
      kTextEditWidth, kTextEditHeight * 2.0f);
  multiLineTextEdit_->setMultilineMode(true);
  multiLineTextEdit_->setScrollBarVisibilityMode(ScrollBarVisibility::kAlways);
  multiLineTextEdit_->setCharacterLimit(kMultiCharLimit);
  multiLineTextEdit_->setText("Multiple Line Text Edit.\nLine 2.\nLine 3.");
  multiLineTextEdit_->setTextSize(ExampleConsts::kTextSize);
  multiLineTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  UiText* charRatio = SDKExamples::createUiText(prism, "40/" + std::to_string(kMultiCharLimit));
  charRatio->setTextSize(kTextSmallSize);
  topLayout->addItem(multiLineTextEdit_, ExampleConsts::kTitlePadding, Alignment::CENTER_LEFT);
  topLayout->addItem(charRatio, ExampleConsts::kNoPadding, Alignment::BOTTOM_RIGHT);
  multiLineTextEdit_->onTextChangedSub(std::bind(&TextEdit::multiLineTextChangedCallback, this,
      std::placeholders::_1, charRatio));
  multiLineTextEdit_->onKeyboardEventSub(std::bind(&TextEdit::multiLineKeyboardEventCallback, this,
      std::placeholders::_1, std::placeholders::_2, charRatio));
}

// Create a password text edit, indicating valid password entries:
void TextEdit::createPasswordEntry(Prism* prism, UiLinearLayout* topLayout) {
  createTitle(prism, topLayout, "Password Mode:");
  passwordTextEdit_ = SDKExamples::createUiTextEdit(prism, "Password", kTextEditWidth, kTextEditHeight);
  passwordTextEdit_->setPasswordMode(true);
  passwordTextEdit_->setTextSize(ExampleConsts::kTextSize);
  passwordTextEdit_->setText("");
  passwordTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  UiText* passwordRequirements = SDKExamples::createUiText(prism,
    "Password Requirements:  8-14 characters.  Must include at least one number and one special character.");
  passwordRequirements->setBoundsSize(kPasswordBounds);
  passwordRequirements->setTextSize(kTextSmallSize);
  passwordRequirements->setVisible(false);
  passwordRequirements->setLocalPosition(kPasswordPos);
  passwordTextEdit_->addChild(passwordRequirements);
  topLayout->addItem(passwordTextEdit_, ExampleConsts::kTitlePadding, Alignment::CENTER_LEFT);
  passwordTextEdit_->onHoverEnterSub(std::bind(&TextEdit::hoverCallback, this, std::placeholders::_1,
      passwordRequirements, true));
  passwordTextEdit_->onHoverExitSub(std::bind(&TextEdit::hoverCallback, this, std::placeholders::_1,
      passwordRequirements, false));
}

// Create a URL text entry box, indicating when the user clicks 'submit':
void TextEdit::createUrlEntry(Prism* prism, UiLinearLayout* topLayout) {
  createTitle(prism, topLayout, "URL Mode:");
  urlTextEdit_ = SDKExamples::createUiTextEdit(prism, "http://creator.magicleap.com", kTextEditWidth, kTextEditHeight);
  urlTextEdit_->setTextEntryMode(TextEntryMode::kURL);
  urlTextEdit_->setTextSize(ExampleConsts::kTextSize);
  urlTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  topLayout->addItem(urlTextEdit_, ExampleConsts::kTitlePadding, Alignment::CENTER_LEFT);
  urlTextEdit_->onKeyboardEventSub(std::bind(&TextEdit::urlKeyboardEventCallback, this, std::placeholders::_1,
      std::placeholders::_2));
  urlTextEdit_->onKeyboardEventSub(std::bind(&clearEventCallback, std::placeholders::_1, std::placeholders::_2));
}

// Create a numeric text entry, with a six character limit:
void TextEdit::createNumericEntry(Prism* prism, UiLinearLayout* topLayout) {
  createTitle(prism, topLayout, "Numeric Mode:");
  numericTextEdit_ = SDKExamples::createUiTextEdit(prism, "1234", kTextEditWidth, kTextEditHeight);
  numericTextEdit_->setTextEntryMode(TextEntryMode::kNumeric);
  numericTextEdit_->setFont(resources::FontStyle::kNormal, resources::FontWeight::kBold);
  numericTextEdit_->setTextSize(ExampleConsts::kTextSize);
  numericTextEdit_->setCharacterLimit(kNumerCharLimit);
  UiText* numericRequirements = SDKExamples::createUiText(prism, "Enter " +
      std::to_string(kNumerCharLimit) + " digit pin code:");
  numericRequirements->setTextSize(kTextSmallSize);
  numericRequirements->setBoundsSize(kNumericBounds);
  numericRequirements->setVisible(false);
  numericRequirements->setLocalPosition(kNumericPos);
  numericTextEdit_->addChild(numericRequirements);
  topLayout->addItem(numericTextEdit_, ExampleConsts::kTitlePadding, Alignment::CENTER_LEFT);
  numericTextEdit_->onHoverEnterSub(std::bind(&TextEdit::hoverCallback, this, std::placeholders::_1,
      numericRequirements, true));
  numericTextEdit_->onHoverExitSub(std::bind(&TextEdit::hoverCallback, this, std::placeholders::_1,
      numericRequirements, false));
  numericTextEdit_->onTextChangedSub(std::bind(&TextEdit::numericTextChangedCallback, this, std::placeholders::_1));
  numericTextEdit_->onKeyboardEventSub(std::bind(&clearEventCallback, std::placeholders::_1, std::placeholders::_2));
}

// Create a title for the text entry box:
void TextEdit::createTitle(Prism* prism, UiLinearLayout* topLayout,
    const std::string& title) {
  UiText* label = SDKExamples::createUiText(prism, title,
      resources::FontStyle::kItalic, resources::FontWeight::kBold);
  label->setTextSize(ExampleConsts::kTitleSize);
  topLayout->addItem(label, kTitlePadding, Alignment::CENTER_LEFT);
}

void TextEdit::multiLineTextChangedCallback(const UiEventData& textEntry, UiText* charRatio) {
  uint32_t charCount = UiTextEdit::CastFrom(textEntry.getUiNode())->getCharacterCount();
  charRatio->setText(std::to_string(charCount) + "/" + std::to_string(kMultiCharLimit));
}

void TextEdit::multiLineKeyboardEventCallback(const UiEventData& edit,
    const KeyboardEvent::EventData& keyEvent, UiText* charRatio) {
  if (keyEvent.getEventType() == KeyboardEvent::EventType::KEY_PRESSED) {
    if (static_cast<const KeyboardEvent::KeyPressedData&>(keyEvent).getKeyType() == KeyType::kClear) {
      UiTextEdit::CastFrom(edit.getUiNode())->setText("");
      charRatio->setText("0/" + std::to_string(kMultiCharLimit));
    }
  }
}

void TextEdit::hoverCallback(const UiEventData&, UiText* requirements, bool visible) {
  requirements->setVisible(visible);
}

void TextEdit::urlKeyboardEventCallback(const UiEventData& edit, const KeyboardEvent::EventData& key) {
  if (key.getEventType() == KeyboardEvent::EventType::KEY_PRESSED) {
    if (static_cast<const KeyboardEvent::KeyPressedData&>(key).getKeyType() == KeyType::kSubmit) {
      UiTextEdit::CastFrom(edit.getUiNode())->setTextColor(color::GREEN);
    }
    else {
      UiTextEdit::CastFrom(edit.getUiNode())->setTextColor(color::WHITE);
    }
  }
}

void TextEdit::numericTextChangedCallback(const UiEventData& textEntry) {
  if (UiTextEdit::CastFrom(textEntry.getUiNode())->getCharacterCount() == kNumerCharLimit) {
    UiTextEdit::CastFrom(textEntry.getUiNode())->setTextColor(color::GREEN);
  } else {
    UiTextEdit::CastFrom(textEntry.getUiNode())->setTextColor(color::WHITE);
  }
}

void TextEdit::setCommonProperties() {
  // Single Line.
  keyboard_.enterIsSubmit = true;
  keyboard_.formMode = KeyboardProperties::FormMode::kOff;
  singleLineTextEdit_->setKeyboardProperties(keyboard_);

  // Multi Line.
  keyboard_.enterIsSubmit = false;
  keyboard_.formMode = KeyboardProperties::FormMode::kClearCloseSubmit;
  multiLineTextEdit_->setKeyboardProperties(keyboard_);

  // Password.
  keyboard_.enterIsSubmit = true;
  keyboard_.formMode = KeyboardProperties::FormMode::kOff;
  passwordTextEdit_->setKeyboardProperties(keyboard_);

  // URL.
  keyboard_.enterIsSubmit = true;
  keyboard_.formMode = KeyboardProperties::FormMode::kClearCloseSubmit;
  keyboard_.submitLabel = KeyboardProperties::SubmitLabel::kSearchIcon;
  urlTextEdit_->setKeyboardProperties(keyboard_);

  // Numeric.
  keyboard_.enterIsSubmit = false;
  keyboard_.submitLabel = KeyboardProperties::SubmitLabel::kSubmit;
  numericTextEdit_->setKeyboardProperties(keyboard_);
}