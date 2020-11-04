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
 * Creates a Scene displaying a UiCircleConfirmation node and a UiToggle button.
 */
class CircleConfirmation final : public lumin::SDKExamples::BaseExample {
 public:
  /**
   * Constructs the Circle Confirmation Prism Controller.
   */
  CircleConfirmation();

  /**
   * Destroys the Circle Confirmation Prism Controller.
   */
  virtual ~CircleConfirmation();

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
   * Edits the Circle Confirmation Node.
   * @param[in] prism            - the prism to edit the node in.
   * @param[in] confirmationNode - the Circle Confirmation Node to edit.
   * @param[in] statusMessage    - the text to display the status of the Circle Confirmation.
   */
  void editCircleConfirmation(lumin::Prism* prism,
      lumin::ui::UiCircleConfirmation* confirmationNode, lumin::ui::UiText* statusMessage);

  /**
   * On Activate Callback.
   * Resets the scene when pressed.
   * @param[in] UiEventData   - the updated reset button, ignored.
   * @param[in] prism         - the prism to reset the scene in.
   * @param[in] placeholder   - the parent of the UiCircleConfirmation.
   * @param[in] statusMessage - the scene's status message.
   */
  void activateCallback(const lumin::ui::UiEventData&, lumin::Prism* prism,
      lumin::TransformNode* placeholder, lumin::ui::UiText* statusMessage);
};