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
#include <LabelFader.h>
#include <TogglesLayoutPrefab.h>
#include <BaseExample.h>
#include <SceneDescriptor.h>
#include <lumin/ui/UiKit.h>
#include <lumin/node/LineNode.h>
#include <lumin/PrismController.h>
/**
 * The Toggles Layout page; organizes the Eclipse and Standard Toggles
 * in UiLayouts.
 */
class TogglesLayout : public lumin::SDKExamples::BaseExample {
 public:
  /**
   * Constructs the TogglesLayout, with the name "Toggles".
   */
  TogglesLayout();

  /**
   * Destroys the TogglesLayout.
   */
  virtual ~TogglesLayout();

  /**
   * Creates the scene when it is attached to a prism.
   * @param prism - the prism the scene is attached to
   */
  void onAttachPrism(lumin::Prism* prism) override;

  /**
   * Deletes the scene when it is removed from a prism.
   * @param prism - the prism the scene will be detached from
   */
  void onDetachPrism(lumin::Prism* prism) override;

  /**
   * Updates the scene every frame, using the given delta time.
   * @param a_fDelta - the given delta time
   */
  void onUpdate(float a_fDelta) override;

 protected:
   /**
   * Loads the scene from the Lumin Runtime Editor.
   * @param[in] prism - the prism to load the scene in.
   * @return          - the UiGridLayout containing the scene.
   */
  lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) override;

  /**
   * Builds the scene.
   * @param[in] prism - the prism to build the scene in.
   * @return          - the UiGridLayout containing the scene.
   */
  lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) override;

 private:
  /**
   * Creates the title for the toggles.
   * @param[in] prism - the prism to add the title in.
   * @param[in] grid  - the UiGridLayout to add the title in.
   */
  void createTitle(lumin::Prism* prism, const std::string& title, lumin::ui::UiGridLayout* grid);

  /**
   * Creates a divider.
   * @param[in] prism     - the prism to add the divider in.
   * @param[in] lineWidth - width of the divider.
   * @return              - the LineNode divider.
   */
  lumin::LineNode* createDivider(lumin::Prism* prism, float lineWidth);

  /**
   * Adds the Standard Toggles to the grid.
   * @param[in] prism - the prism to add the toggles in.
   * @param[in] grid  - the UiGridLayout to add the toggles to.
   */
  void addStandardToggles(lumin::Prism* prism, lumin::ui::UiGridLayout* grid);

  /**
   * Adds the Eclipse Toggles to the grid.
   * @param[in] prism - the prism to add the toggles in.
   * @param[in] grid  - the UiGridLayout to add the toggles to.
   */
  void addEclipseToggles(lumin::Prism* prism, lumin::ui::UiGridLayout* grid);

  /**
   * Builds a toggle item.
   * @param[in] prism  - the prism to build the scene in.
   * @param[in] toggle - the toggle to add to the layout.
   * @return           - the created item.
   */
  lumin::ui::UiLinearLayout* buildItemLayout(lumin::Prism* prism, lumin::ui::UiToggle* toggle);

  /**
   * On Hover Enter Callback
   * Updates the toggle and label for the on hover enter callback.
   * @param[in] toggle - the updated toggle for the callback.
   * @param[in] label  - the label to update.
   * @parma[in] fader  - the fader to fade in the label.
   */
  void hoverEnterCallback(const lumin::ui::UiEventData& toggle, lumin::ui::UiText* label,
        LabelFader* fader);

  /**
   * On Hover Exit Callback
   * Updates the toggle and label for the on hover exit callback.
   * @param[in] toggle - the updated toggle for the callback.
   * @param[in] label  - the label to update.
   * @parma[in] fader  - the fader to fade out the label.
   */
  void hoverExitCallback(const lumin::ui::UiEventData& toggle, lumin::ui::UiText* label,
        LabelFader* fader);

  /**
   * On Long Press Callback
   * Updates the toggle and label for the on long press callback.
   * @param[in] toggle - the updated toggle for the callback.
   * @param[in] label  - the label to update.
   */
  void longPressCallback(const lumin::ui::UiEventData& toggle, lumin::ui::UiText* label);

  /**
   * On Toggle Changed Callback
   * Updates the toggle and label for the on toggle changed callback.
   * @param[in] toggle - the updated toggle for the callback.
   * @param[in] label  - the label to update.
   */
  void toggleChangedCallback(const lumin::ui::UiEventData& toggle, lumin::ui::UiText* label);

  /**
   * Creates user data used in the Loaded Scene Graph Toggle handlers.
   * @param[in] prefab - the given scene to add user data to.
   */
  void createData(prefabs::TogglesLayoutPrefab* prefab);

 private:
  float contentWidth_;
  float contentHeight_;
  std::vector<LabelFader*> faders_;
  prefabs::TogglesLayoutPrefab* prefab_;
};