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
#include <lumin/node/LineNode.h>
#include <lumin/PrismController.h>
/**
 * The Dialogs Layout page; organizes the UiKit's Dialogs.
 */
class DialogsLayout : public lumin::SDKExamples::BaseExample {
 public:
  /**
   * Constructs the DialogsLayout, with the name "Dialogs".
   */
  DialogsLayout();

  /**
   * Destroys the DialogsLayout.
   */
  virtual ~DialogsLayout();

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
   * On Activate Callback for the Modal Dual Action dialog Tab.
   * Spawns a Modal Dual Action Dialog.
   * @param[in] UiEventData - ignored.
   * @param[in] heartList   - spawns a heart icon in this list when user confirms.
   */
  void dualActionCallback(const lumin::ui::UiEventData&, lumin::ui::UiListView* heartList);

  /**
   * On Activate Callback for the Modal Single Action dialog Tab.
   * Spawns a Modal Single Action Dialog.
   * @param[in] UiEventData - ignored.
   * @param[in] heartList   - spawns a heart icon in this list when user confirms.
   */
  void singleActionCallback(const lumin::ui::UiEventData&, lumin::ui::UiListView* heartList);

  /**
   * On Activate Callback for the Modeless Timed dialog Tab.
   * Spawns a Modeless Timed Dialog.
   * @param[in] UiEventData - ignored.
   * @param[in] heartList   - spawns a heart icon in this list when user confirms.
   */
  void timedCallback(const lumin::ui::UiEventData&, lumin::ui::UiListView* heartList);

  /**
   * On Confirm Callback for Modal Dual Action Dialogs.
   * Adds a heart button to the heart list.
   * @param[in] dialog    - the updated Dual Action Dialog.
   * @param[in] heart     - the heart button to add.
   * @param[in] heartList - the list to add the heart button to.
   */
  void confirmCallback(const lumin::ui::UiEventData& dialog, lumin::ui::UiButton* heart,
      lumin::ui::UiListView* heartList);

  /**
   * On Confirm or On Cancel Callback for Dialogs.
   * Deletes the dialog, and brings the cursor panel to its default location.
   * @param[in] dialog    - dialog to be deleted.
   * @param[in] heartList - displays this list (visibility is true).
   */
  void dialogActivateCallback(const lumin::ui::UiEventData& dialog, lumin::ui::UiListView* heartList);

  /**
   * On Activate Callback for the Heart Button in Dual Action Dialogs.
   * @param[in] heart - changes the color of this button to red.
   */
  void dualActionHeartActivateCallback(const lumin::ui::UiEventData& heart);

  /**
   * On Activate Callback for the Heart Button in Single Action Dialogs.
   * Moves the heart button from the dialog to the list.
   * @param[in] heart     - the heart button to move.
   * @param[in] heartList - the list to add the heart to.
   */
  void singleActionHeartActivateCallback(const lumin::ui::UiEventData& heart,
      lumin::ui::UiListView* heartList);

  /**
   * On Time Expired Callback for Timed Dialogs.
   * Adds a heart button to the list.
   * @param[in] UiEventData - ignored.
   * @param[in] heartList   - list to add the heart button to.
   */
  void timeExpiredCallback(const lumin::ui::UiEventData&, lumin::ui::UiListView* heartList);

  /**
   * On Update Callback for Timed Dialogs.
   * Updates the status text and progress bar with the new time.
   * @param[in] dialog      - updated Timed Dialog.
   * @param[in] expireTime  - text to update.
   * @param[in] progressBar - slider to update.
   */
  void setExpireTime(const lumin::ui::UiEventData& dialog, float, lumin::ui::UiText* expireTime,
    lumin::ui::UiSlider* progressBar);
};