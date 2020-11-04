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
#include <SlidersLayoutPrefab.h>
#include <LabelFader.h>
#include <lumin/ui/UiKit.h>
#include <lumin/node/LineNode.h>
#include <lumin/PrismController.h>
/**
 * The Sliders Layout page; organizes the Eclipse and Standard Sliders
 * in UiLayouts.
 */
class SlidersLayout : public lumin::SDKExamples::BaseExample {
 public:
  /**
   * Constructs the SlidersLayout, with the name "Sliders".
   */
  SlidersLayout();

  /**
   * Destroys the SlidersLayout.
   */
  virtual ~SlidersLayout();

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
   * Creates the title for the Sliders.
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
   * Builds a slider item.
   * @param[in] prism       - the prism to build the scene in.
   * @param[in] slider      - the slider to add to the layout.
   * @param[in] progressBar - true if the slider is a UiProgressBar, false if it is a UiSlider.
   * @return                - the created item.
   */
  lumin::ui::UiLinearLayout* buildItemLayout(lumin::Prism* prism,
      lumin::ui::UiNode* slider, bool progressBar);

  /**
   * On Hover Enter Callback
   * Updates the slider and label for the on hover enter callback.
   * @param[in] slider - the updated slider for the callback.
   * @param[in] label  - label to change.
   * @param[in] fader  - the fader to fade in the label.
   */
  void hoverEnterCallback(const lumin::ui::UiEventData& slider, lumin::ui::UiText* label, LabelFader* fader);

  /**
   * On Hover Exit Callback
   * Updates the slider and label for the on hover exit callback.
   * @param[in] slider - the updated slider for the callback.
   * @param[in] label  - label to change.
   * @param[in] fader  - the fader to fade out the label.
   */
  void hoverExitCallback(const lumin::ui::UiEventData& slider, lumin::ui::UiText* label, LabelFader* fader);

  /**
   * On Activate Callback
   * Updates the slider and label for the on activate callback.
   * @param[in] slider - the updated slider for the callback.
   * @param[in] label  - label to change.
   */
  void activateCallback(const lumin::ui::UiEventData& slider, lumin::ui::UiText* label);

  /**
   * On Long Press Callback
   * Updates the slider and label for the on long press callback.
   * @param[in] slider - the updated slider for the callback.
   * @param[in] label  - label to change.
   */
  void longPressCallback(const lumin::ui::UiEventData& slider, lumin::ui::UiText* label);

  /**
   * On Slider Changed Callback
   * Updates the label for the on slider changed callback.
   * @param[in] slider    - the updated node for the callback.
   * @param[in/out] label - label to change.
   */
  void sliderChangedCallback(const lumin::ui::UiEventData& slider, lumin::ui::UiText* label);

  /**
   * On Update Callback
   * Updates the UiProgressBar for the on update callback.
   * @param[in/out] bar - the progressbar to update.
   * @param[in] fDelta  - the delta time since the last frame.
   */
  void progressBarUpdateCallback(const lumin::ui::UiEventData& bar, float fDelta);

  /**
   * Creates user data used in the Loaded Scene Graph Slider handlers.
   * @param[in] prefab - the given scene to add user data to
   */
  void createData(prefabs::SlidersLayoutPrefab* prefab);

 private:
  std::vector<LabelFader*> faders_;
  prefabs::SlidersLayoutPrefab* prefab_;
};