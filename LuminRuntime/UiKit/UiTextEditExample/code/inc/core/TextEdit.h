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
#pragma once
#include <BaseExample.h>
#include <lumin/ui/UiKit.h>
#include <lumin/PrismController.h>
/**
 * Creates a Scene displaying the types of Text Entry.
 */
class TextEdit final : public lumin::SDKExamples::BaseExample {
 public:
 /**
  * Constructs the Text Edit Prism Controller.
  */
  TextEdit();

 /**
  * Destroys the Text Edit Prism Controller.
  */
  virtual ~TextEdit();

 /**
  * Creates the scene when it is attached to a prism.
  * @param[in] prism - the prism the scene is attached to.
  */
  void onAttachPrism(lumin::Prism* prism) override;

 /**
  * Deletes the scene when it is removed from a prism.
  * @param[in] prism - the prism the scene will be detached from.
  */
  void onDetachPrism(lumin::Prism* prism) override;

 private:
 /**
  * Loads the scene graph from file.
  * @param[in] prism - the prism to associate the nodes with.
  * @return          - the root node of the scene.
  */
  lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) override;

 /**
  * Builds the scene graph programmatically.
  * @param[in] prism - the prism to associate the nodes with.
  * @return          - the root node of the scene.
  */
  lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) override;

 /**
  * Creates a single line text entry box.
  * @param[in] prism     - prism to place the text entry box.
  * @param[in] topLayout - UiLayout to align the text entry box.
  */
  void createSingleLineEntry(lumin::Prism* prism, lumin::ui::UiLinearLayout* topLayout);

 /**
  * Creates a multiple line text entry box.
  * @param[in] prism     - prism to place the text entry box.
  * @param[in] topLayout - UiLayout to align the text entry box.
  */
  void createMultiLineEntry(lumin::Prism* prism, lumin::ui::UiLinearLayout* topLayout);

 /**
  * Creates a password text entry box.
  * @param[in] prism     - prism to place the text entry box.
  * @param[in] topLayout - UiLayout to align the text entry box.
  */
  void createPasswordEntry(lumin::Prism* prism, lumin::ui::UiLinearLayout* topLayout);

 /**
  * Creates a URL text entry box.
  * @param[in] prism     - prism to place the text entry box.
  * @param[in] topLayout - UiLayout to align the text entry box.
  */
  void createUrlEntry(lumin::Prism* prism, lumin::ui::UiLinearLayout* topLayout);

 /**
  * Creates a numeric text entry box.
  * @param[in] prism     - prism to place the text entry box.
  * @param[in] topLayout - UiLayout to align the text entry box.
  */
  void createNumericEntry(lumin::Prism* prism, lumin::ui::UiLinearLayout* topLayout);

 /**
  * Creates a title for the text entry box.
  * @param[in] prism     - prism to place the text entry box's title.
  * @param[in] topLayout - UiLayout to align the text entry box's title.
  * @param[in] title     - the title of the text entry box.
  */
  void createTitle(lumin::Prism* prism, lumin::ui::UiLinearLayout* topLayout, const std::string& title);

  /**
   * on Text Changed Callback for MultiLine Text Edits.
   * Changes the character ratio of the text edit.
   * @param[in] textEntry - the updated multi line text edit.
   * @param[in] charRatio - the character ratio to change.
   */
  void multiLineTextChangedCallback(const lumin::ui::UiEventData& textEntry,
    lumin::ui::UiText* charRatio);

  /**
   * on Keyboard Event Callback for MultiLine Text Edits.
   * Erases the text and character ratio when the clear key is activated.
   * @param[in] edit      - the updated multi line text edit.
   * @param[in] keyEvent  - the key activated.
   * @param[in] charRatio - the character ratio to change.
   */
  void multiLineKeyboardEventCallback(const lumin::ui::UiEventData& edit,
      const lumin::ui::KeyboardEvent::EventData& keyEvent, lumin::ui::UiText* charRatio);

  /**
   * on Hover Callbacks for Text Edits.
   * Changes the visibility of the UiText to the given value.
   * @param[in] UiEventData  - ignored.
   * @param[in] requirements - text to change the visibility of.
   * @param[in] visible      - true to set the text to visible, false to hide the text.
   */
  void hoverCallback(const lumin::ui::UiEventData&,
      lumin::ui::UiText* requirements, bool visible);

  /**
   * on Keyboard Event Callback for URL Text Edits.
   * Changes the color of the text on submit.
   * @param[in] edit - the updated URL text edit.
   * @param[in] key  - the key activated.
   */
  void urlKeyboardEventCallback(const lumin::ui::UiEventData& edit,
      const lumin::ui::KeyboardEvent::EventData& key);

  /**
   * on Text Changed Callback for Numeric Text Edits.
   * @param[in] textEntry - the updated text edit.
   */
  void numericTextChangedCallback(const lumin::ui::UiEventData& textEntry);

 /**
  * Sets properties that both built and loaded scene graphs would need to do.
  */
  void setCommonProperties();

 private:
  lumin::ui::KeyboardProperties keyboard_;
  lumin::ui::UiTextEdit* singleLineTextEdit_    = nullptr;
  lumin::ui::UiTextEdit* multiLineTextEdit_     = nullptr;
  lumin::ui::UiTextEdit* passwordTextEdit_      = nullptr;
  lumin::ui::UiTextEdit* urlTextEdit_           = nullptr;
  lumin::ui::UiTextEdit* numericTextEdit_       = nullptr;
};
