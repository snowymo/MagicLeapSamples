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
 * The Lists Layout page; organizes DropDown Lists and List Views.
 */
class ListsLayout : public lumin::SDKExamples::BaseExample {
 public:
  /**
   * Constructs the ListsLayout, with the name "Lists".
   */
  ListsLayout();

  /**
   * Destroys the ListsLayout.
   */
  virtual ~ListsLayout();

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
   * Creates a transparent image overlay.
   * @param[in] prism      - the prism to create the overlay in.
   * @param[in] listWidth  - the width of the overlay.
   * @param[in] listHeight - the height of the overlay.
   * @param[in] overlayPos - the local position of the overlay.
   * @return               - the image overlay.
   */
  lumin::ui::UiImage* createOverlay(lumin::Prism* prism, float listWidth, float listHeight,
      const glm::vec3& overlayPos);

  /**
   * Builds the Single Select, Single Level List scene.
   * @param[in] prism - the prism to build the scene in
   */
  lumin::TransformNode* buildSceneGraphSSSL(lumin::Prism* prism);

  /**
   * Builds the MultiSelect, Single Level List scene.
   * @param[in] prism - the prism to build the scene in
   */
  lumin::TransformNode* buildSceneGraphMSSL(lumin::Prism* prism);

  /**
   * Builds the MultiSelect, MultiLevel List scene.
   * @param[in] prism - the prism to build the scene in
   */
  lumin::TransformNode* buildSceneGraphMSML(lumin::Prism* prism);

  /**
   * Builds the Horizontal List scene.
   * @param[in] prism - the prism to build the scene in
   */
  lumin::TransformNode* buildHorizontalSceneGraph(lumin::Prism* prism);

    /**
   * Builds the Vertical List scene.
   * @param[in] prism - the prism to build the scene in
   */
  lumin::TransformNode* buildVerticalSceneGraph(lumin::Prism* prism);

    /**
   * Builds the Dynamic List scene.
   * @param[in] prism - the prism to build the scene in
   */
  lumin::TransformNode* buildDynamicSceneGraph(lumin::Prism* prism);

  /**
   * Creates an item with an icon, used to add to a horizontal list.
   * @param[in] prism         - the prism to add the item to
   * @param[in] thumbnailPath - the path of the icon
   * @return                  - the created UiListViewItem
   */
  lumin::ui::UiListViewItem* createHorizontalItem(lumin::Prism* prism,
      const std::string& thumbnailPath);

  /**
   * Creates an item with a text description and an icon, used to add to a vertical list.
   * @param[in] prism         - the prism to add the item to
   * @param[in] titleString   - the title of the item
   * @param[in] descString    - the description of the icon
   * @param[in] thumbnailPath - the path of the icon
   * @return                  - the created UiListViewItem
   */
  lumin::ui::UiListViewItem* createVerticalItem(lumin::Prism* prism, const std::string& titleString,
    const std::string& descString, const std::string& thumbnailPath);

  /**
   * Creates an item with an icon, used to add to a dynamic list.
   * @param[in] prism     - the prism to add the item to
   * @param[in] currList  - the starting list of the item
   * @param[in] otherList - the list to switch to on activation
   * @param[in] iconPath  - the path of the item's icon
   * @return              - the created UiListViewItem
   */
  lumin::ui::UiListViewItem* createDynamicItem(lumin::Prism* prism,
      lumin::ui::UiListView* currList, lumin::ui::UiListView* otherList,
      const std::string& iconPath);

  /**
   * On Selection Changed Callback for Single Select, Single Level lists.
   * Changes the title color of the list.
   * @param[in] list      - updated list
   * @param[in] selection - selected items
   */
  void selectionChangedCallbackSSSL(const lumin::ui::UiEventData& list,
      const std::vector<const lumin::ui::DropDownListItem*>& selection);

  /**
   * On Selection Changed Callback for Multiselect, Single Level lists.
   * Changes the title color of the list.
   * @param[in] list      - updated list
   * @param[in] selection - selected items
   */
  void selectionChangedCallbackMSSL(const lumin::ui::UiEventData& list,
      const std::vector<const lumin::ui::DropDownListItem*>& selection);

  /**
   * On Selection Changed Callback for Multiselect, Multilevel lists.
   * Changes the title color of the list.
   * @param[in] list      - updated list
   * @param[in] selection - selected items
   */
  void selectionChangedCallbackMSML(const lumin::ui::UiEventData& list,
      const std::vector<const lumin::ui::DropDownListItem*>& selection);

  /**
   * On Hover Enter Callback.
   * Changes the color of the ListViewItem and zooms in on the thumbnail image.
   * @param[in] item      - updated ListViewItem
   * @param[in] thumbnail - image to zoom in
   * @param[in] title     - optional title to reset
   */
  void hoverEnterCallback(const lumin::ui::UiEventData& item, lumin::ui::UiImage* thumbnail,
      lumin::ui::UiText* title = nullptr);

  /**
   * On Hover Exit Callback.
   * Resets the color of the ListViewItem and the thumbnail image.
   * @param[in] item      - updated ListViewItem
   * @param[in] thumbnail - image to reset
   * @param[in] title     - optional title to reset
   */
  void hoverExitCallback(const lumin::ui::UiEventData& item, lumin::ui::UiImage* thumbnail,
      lumin::ui::UiText* title = nullptr);

  /**
   * On Activate Callback.
   * Changes the color of the thumbnail when clicked.
   * @param[in] UiEventData - ignored
   * @param[in] thumbnail   - image to change
   */
  void activateCallback(const lumin::ui::UiEventData&, lumin::ui::UiImage* thumbnail);

  /**
   * On Activate Callback for dynamic lists.
   * Moves the ListViewItem from one list to another.
   * @param[in] item        - updated ListViewItem
   * @param[in] currentList - list to remove the item from
   * @param[in] otherList   - list to add the new item to
   * @param[in] index       - index of the ListViewItem
   */
  void dynamicActivateCallback(const lumin::ui::UiEventData& item, lumin::ui::UiListView* currentList,
      lumin::ui::UiListView* otherList, uint32_t index);
};