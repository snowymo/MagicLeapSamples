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
#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>
#include <lumin/PrismController.h>
/**
 * Creates a Scene displaying each type of Eclipse Cursor inside a circular panel.
 * The circular panel restricts the cursor's movement until a breakthrough threshold is achieved.
 * A Color Picker is added to the scene, allowing the user to change the color of the panels and titles.
 * A comparison image of a white shell is displayed behind each circle at 50% opacity.
 */
class CursorsDisplay final : public lumin::SDKExamples::BaseExample {
public:
  /**
   * Constructs the Cursor Prism Controller.
   */
  CursorsDisplay();

  /**
   * Destroys the Cursor Prism Controller.
   */
  virtual ~CursorsDisplay();

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

  /**
   * Creates a panel which when hovered, changes the cursor to the
   * given cursor state.
   * @param[in] cursorState - the Eclipse Cursor State to change to.
   * @param[in] node_index  - the index of the cursor panel nodes.
   * @param[in] root        - the parent node to search under.
   */
  void editCursorDisplay(lumin::ui::EclipseCursorState cursorState, uint32_t node_index, lumin::Node* root);

  /**
   * Edits the color picker to allow the user to change
   * the color of the cursor panels.
   * @param[in] root  - the parent node to search under.
   */
  void editColorPicker(lumin::Node* root);

  /**
   * On Panel Enter Callback.
   * Changes the state of the cursor depending on the panel entered.
   * @param[in] UiEventData - ignored.
   * @param[in] prism       - prism to change the cursor in.
   * @param[in] state       - the new cursor state.
   */
  void panelEnterCallback(const lumin::ui::UiEventData&, lumin::Prism* prism,
      lumin::ui::EclipseCursorState state);

  /**
   * On Color Changed Callback.
   * Changes the color of the titles and the circles.
   * Title colors are a shade 'darker' than the circles.
   * @param[in] UiEventData - ignored.
   * @param[in] color       - color to change to, chosen from the UiColorPicker.
   * @param[in] textNodes   - vector of titles to change.
   * @param[in] circleNodes - vector of cicles to change.
   */
  void colorChangedCallback(const lumin::ui::UiEventData&, const glm::vec4 color,
      std::vector<lumin::Node*> textNodes, std::vector<lumin::Node*> circleNodes);
};