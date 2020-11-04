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
#include <LabelFader.h>
#include <ButtonsLayoutPrefab.h>
#include <lumin/ui/UiKit.h>
#include <lumin/node/LineNode.h>
#include <lumin/PrismController.h>
/**
 * The Buttons Layout page; organizes the Eclipse and Standard Buttons
 * in UiLayouts.
 */
class ButtonsLayout : public lumin::SDKExamples::BaseExample {
 public:
  /**
   * Constructs the ButtonsLayout, with the name "Buttons".
   */
  ButtonsLayout();

  /**
   * Destroys the ButtonsLayout.
   */
  virtual ~ButtonsLayout();

  /**
   * Creates the scene when it is attached to a prism.
   * @param[in] prism - the prism the scene is attached to
   */
  void onAttachPrism(lumin::Prism* prism) override;

  /**
   * Deletes the scene when it is removed from a prism.
   * @param[in] prism - the prism the scene will be detached from
   */
  void onDetachPrism(lumin::Prism* prism) override;

  /**
   * Updates the Label Faders.
   * @param[in] fDelta - delta time since last frame.
   */
  void onUpdate(float fDelta) override;

 protected:
  /**
   * Loads the scene from the Lumin Runtime Editor.
   * @param[in] prism - the prism to load the scene in.
   * @return          - the root node of the scene, to be added.
   */
  lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) override;

  /**
   * Builds the scene.
   * @param[in] prism - the prism to build the scene in.
   * @return          - the root node of the scene, to be added.
   */
  lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) override;

 private:
  /**
   * Creates the title for the buttons.
   * @param[in] prism - the prism to add the title in.
   * @param[in] grid  - the UiGridLayout to add the title in.
   */
  void createTitle(lumin::Prism* prism, const std::string& title, lumin::ui::UiGridLayout* grid);

  /**
   * Creates a divider.
   * @param[in] prism - the prism to add the divider in.
   * @return          - the LineNode divider.
   */
  lumin::LineNode* createDivider(lumin::Prism* prism);

  /**
   * Adds the Standard Buttons to the grid.
   * @param[in] prism - the prism to add the buttons in.
   * @param[in] grid  - the UiGridLayout to add the buttons to.
   */
  void addStandardButtons(lumin::Prism* prism, lumin::ui::UiGridLayout* grid);

  /**
   * Adds the Eclipse Buttons to the grid.
   * @param[in] prism - the prism to add the buttons in.
   * @param[in] grid  - the UiGridLayout to add the buttons to.
   */
  void addEclipseButtons(lumin::Prism* prism, lumin::ui::UiGridLayout* grid);

  /**
   * Builds a button item.
   * @param[in] prism  - the prism to build the scene in.
   * @param[in] button - the button to add to the layout.
   * @return           - the created item.
   */
  lumin::ui::UiLinearLayout* buildItemLayout(lumin::Prism* prism, lumin::ui::UiButton* button);

  /**
   * On Hover Enter Callback
   * Updates the button and label for the on hover enter callback.
   * @param[in] button - the updated button for the callback.
   * @param[in] label  - label to change.
   * @param[in] fader  - the fader to fade in the label.
   */
  void hoverEnterCallback(const lumin::ui::UiEventData& button, lumin::ui::UiText* label, LabelFader* fader);

  /**
   * On Hover Exit Callback
   * Updates the button and label for the on hover exit callback.
   * @param[in] button - the updated button for the callback.
   * @param[in] label  - label to change.
   * @param[in] fader  - the fader to fade out the label.
   */
  void hoverExitCallback(const lumin::ui::UiEventData& button, lumin::ui::UiText* label, LabelFader* fader);

  /**
   * On Activate Callback
   * Updates the button and label for the on activate callback.
   * @param[in] button - the updated button for the callback.
   * @param[in] label  - label to change.
   */
  void activateCallback(const lumin::ui::UiEventData& button, lumin::ui::UiText* label);

  /**
   * On Long Press Callback
   * Updates the button and label for the on long press callback.
   * @param[in] button - the updated button for the callback.
   * @param[in] label  - label to change.
   */
  void longPressCallback(const lumin::ui::UiEventData& button, lumin::ui::UiText* label);

  /**
   * Creates and loads user data used in the Loaded Scene Graph Button handlers.
   * @param[in] prefab - the given scene to add user data to
   */
  void createData(prefabs::ButtonsLayoutPrefab* prefab);

 private:
  float contentWidth_;
  float contentHeight_;
  std::vector<LabelFader*> faders_;
  prefabs::ButtonsLayoutPrefab* prefab_;
};