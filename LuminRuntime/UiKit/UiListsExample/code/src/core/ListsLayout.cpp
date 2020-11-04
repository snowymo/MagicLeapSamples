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
#include <ListsLayout.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesDefines.h>
#include <ListsLayoutPrefab.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const float kLayoutHeight       = 0.7f;
  const float kLayoutWidth        = 1.0f;
  const float kLayoutDepth        = 0.3f;
  const float kListTextSize       = 0.035f;
  const float kListMaxHeight      = 0.3f;
  const float kIconWidth          = 0.03f;
  const float kIconHeight         = 0.03f;
  const float kListWidth          = 0.25f;
  const float kListHeight         = 0.05f;
  const float kSmallListWidth     = 0.15f;
  const float kVerticalIconWidth  = 0.03f;
  const float kVerticalIconHeight = 0.03f;
  const float kVerticalListWidth  = 0.0f;   // width of 0.0f expands to fit items
  const float kVerticalListHeight = 0.3f;
  const glm::vec3 kLayoutLocalPos(0.15f, 0.0f, 0.0f);  // offset the layout
  const glm::vec3 kIconLocalPos(-0.13f, 0.03f, 0.0f);
  const glm::vec3 kOverlayLocalPos(0.125f, -0.025f, 0.0f);
  const glm::vec3 kSmallOverlayLocalPos(0.075f, -0.025f, 0.0f);
  const glm::vec3 kTitleLocalPos(-0.1f, 0.03f, render::MIN_ZDEPTH_OFFSET);
  const glm::vec3 kDescLocalPos(-0.1f, 0.01f, render::MIN_ZDEPTH_OFFSET);
  const glm::vec3 kLineLocalPos(0.0f, -0.01f, 0.0f);
  const glm::vec3 kLineLocalPosStart(-0.1f, 0.0f, 0.0f);
  const glm::vec3 kLineLocalPosEnd(0.19f, 0.0f, 0.0f);
  const glm::vec4 kTopLayoutItemPadding(0.01f, 0.01f, 0.01f, 0.01f);
  const glm::vec4 kItemPadding(0.01f, 0.05f, 0.01f, 0.05f);  // top, right, bottom, left (in meters)
  const glm::vec4 kItemBackgroundColorIdle(0.1f, 0.1f, 0.1f, 1.0f);  // (81, 81, 81)
  const glm::vec4 kItemBackgroundColorHovered(0.2f, 0.2f, 0.2f, 1.0f);  // (116, 116, 116)
  const glm::vec4 kLayoutItemPadding(0.03f, 0.0f, 0.0f, 0.0f);  // top, right, bottom, left
  const glm::vec4 kTitleTextColorIdle(0.7f, 0.7f, 0.7f, 1.0f);  // (216, 216, 216)
  const glm::vec4 kTitleTextColorHovered(1.0f);
  const glm::vec4 kDescTextColor(0.5f, 0.5f, 0.5f, 1.0f);  // (183, 183, 183)
  const glm::vec4 kLineColor(0.4f, 0.4f, 0.4f, 0.9f);  // (164, 164, 164)
  const std::vector<glm::vec2> kIconTextCoordsIdle =
      {{0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}};
  const std::vector<glm::vec2> kIconTextCoordsHovered =
      {{0.1f, 0.9f}, {0.9f, 0.9f}, {0.9f, 0.1f}, {0.1f, 0.1f}};
  const glm::quat kScrollBarRotation(glm::vec3(0.0f, 0.0f, glm::half_pi<float>()));
  const std::string kFirstIconPath   = "pipeline/Thumbnails/tn_1.png";
  const std::string kSecondIconPath  = "pipeline/Thumbnails/tn_2.png";
  const std::string kThirdIconPath   = "pipeline/Thumbnails/tn_3.png";
  const std::string kFourthIconPath  = "pipeline/Thumbnails/tn_4.png";
  const std::string kFifthIconPath   = "pipeline/Thumbnails/tn_5.png";
  const std::string kSixthIconPath   = "pipeline/Thumbnails/tn_6.png";
  const std::string kSeventhIconPath = "pipeline/Thumbnails/tn_7.png";
  const std::string kEighthIconPath  = "pipeline/Thumbnails/tn_8.png";
  const std::string kOverlayPath     = "pipeline/Thumbnails/TransparentOverlay.png";
}

ListsLayout::ListsLayout()
: BaseExample("Lists") {
}

ListsLayout::~ListsLayout() {
}

void ListsLayout::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "ListsLayout::onAttachPrism() Initializing the Buttons Layout scene");
  BaseExample::onAttachPrism(prism);
}

TransformNode* ListsLayout::loadSceneGraph(Prism* prism) {
  prefabs::ListsLayoutPrefab* prefab = managers_->extendedPrefab_->spawn<prefabs::ListsLayoutPrefab>();
  LUMIN_ASSERT(prefab, "Failed to create ListsLayoutPrefab");

  prefab->getHLVS_ListView1()->addChild(createOverlay(prism, kSmallListWidth, kListHeight, kSmallOverlayLocalPos));
  prefab->getHLVS_ListView2()->addChild(createOverlay(prism, kListWidth, kListHeight, kOverlayLocalPos));
  prefab->getMSML_DropDownList()->setList({
      {"reds", {{"red"}, {"pinks", {{"pink"}, {"hotpink"}}}, {"orange"}}},
      {"greens", {{"green"}, {"yellow"}}},
      {"blues",  {{"blue"}, {"cyan"}, {"purples", {{"magenta"}, {"indigo"}}}}},
  });
  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab->getRoot());
  return rootContainer;
}

UiImage* ListsLayout::createOverlay(Prism* prism, float listWidth,
    float listHeight, const glm::vec3& overlayPos) {
  UiImage* overlay = SDKExamples::createUiImage(prism, kOverlayPath, listWidth, listHeight);
  overlay->setIsOpaque(false);
  overlay->setIsUI(true);
  overlay->setSkipRaycast(true, true);  // prevent the cursor from activating events with this node.
  overlay->setEnabled(false);
  overlay->setLocalPosition(overlayPos);
  return overlay;
}

TransformNode* ListsLayout::buildSceneGraph(Prism* prism) {
  UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
  topLayout->setDefaultItemPadding(kTopLayoutItemPadding);
  topLayout->setAlignment(Alignment::TOP_CENTER);
  topLayout->setDefaultItemAlignment(Alignment::TOP_CENTER);

  auto createItem = [prism, this](const std::string& name, TransformNode* list) -> UiLinearLayout* {
    UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
    UiText* title          = SDKExamples::createEclipseLabel(prism, name, EclipseLabelType::kT3);
    layout->addItem(title);
    layout->addItem(list, ExampleConsts::kNoPadding, Alignment::CENTER_CENTER);
    return layout;
  };
  topLayout->addItem(createItem("Single Select, Single Level Dropdown List:",
      buildSceneGraphSSSL(prism)));
  topLayout->addItem(createItem("Multiselect, Single Level Dropdown List:",
      buildSceneGraphMSSL(prism)));
  topLayout->addItem(createItem("Multiselect, Multi Level Dropdown List:",
      buildSceneGraphMSML(prism)));
  topLayout->addItem(createItem("Vertical List View:",
      buildVerticalSceneGraph(prism)));
  topLayout->addItem(createItem("Horizontal List View:",
      buildHorizontalSceneGraph(prism)));
  topLayout->addItem(createItem("Dynamic List View:",
      buildDynamicSceneGraph(prism)));

  UiScrollView* scroll = SDKExamples::createUiScrollView(prism);
  scroll->setScrollBounds(math::AABB(
      glm::vec3(-kLayoutWidth / 2.01f, -kLayoutHeight / 2.01f, -kLayoutDepth / 2.01f),
      glm::vec3(kLayoutWidth / 2.01f, kLayoutHeight / 2.01f, kLayoutDepth / 2.01f)));
  scroll->setScrollContent(topLayout);
  return scroll;
}

TransformNode* ListsLayout::buildSceneGraphSSSL(Prism* prism) {
  UiDropDownList* dropDownList = SDKExamples::createUiDropDownList(prism, "Color");
  dropDownList->setTextSize(ExampleConsts::kTextSize);
  dropDownList->setListMaxHeight(kListMaxHeight);
  dropDownList->setList({{"red"}, {"green"}, {"blue"}});
  dropDownList->onSelectionChangedSub(std::bind(
      &ListsLayout::selectionChangedCallbackSSSL, this,
      std::placeholders::_1, std::placeholders::_2));

  UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
  layout->setLocalPosition(kLayoutLocalPos);
  layout->setAlignment(Alignment::CENTER_CENTER);
  layout->setOrientation(Orientation::kHorizontal);

  // ensure you call the padding function before adding items,
  // otherwise you will have to manually call updateLayout for the changes to take effect:
  layout->setDefaultItemPadding(kItemPadding);
  layout->addItem(dropDownList);
  return layout;
}

TransformNode* ListsLayout::buildSceneGraphMSSL(Prism* prism) {
  UiDropDownList* dropDownList = SDKExamples::createUiDropDownList(prism, "Color");
  dropDownList->setTextSize(ExampleConsts::kTextSize);
  dropDownList->setListMaxHeight(kListMaxHeight);
  dropDownList->setMultiSelectMode(true);
  dropDownList->setList({{"red"}, {"green"}, {"blue"}});
  dropDownList->onSelectionChangedSub(std::bind(
      &ListsLayout::selectionChangedCallbackMSSL, this,
      std::placeholders::_1, std::placeholders::_2));

  UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
  layout->setLocalPosition(kLayoutLocalPos);
  layout->setAlignment(Alignment::CENTER_CENTER);
  layout->setOrientation(Orientation::kHorizontal);

  // ensure you call the padding function before adding items,
  // otherwise you will have to manually call updateLayout for the changes to take effect:
  layout->setDefaultItemPadding(kItemPadding);
  layout->addItem(dropDownList);
  return layout;
}

TransformNode* ListsLayout::buildSceneGraphMSML(Prism* prism) {
  UiDropDownList* dropDownList = SDKExamples::createUiDropDownList(prism, "Color");
  dropDownList->setTextSize(ExampleConsts::kTextSize);
  dropDownList->setListMaxHeight(kListMaxHeight);
  dropDownList->setMultiSelectMode(true);
  dropDownList->setList({
    {"reds", {{"red"}, {"pinks", {{"pink"}, {"hotpink"}}}, {"orange"}}},
    {"greens", {{"green"}, {"yellow"}}},
    {"blues",  {{"blue"}, {"cyan"}, {"purples", {{"magenta"}, {"indigo"}}}}},
  });
  dropDownList->onSelectionChangedSub(std::bind(
      &ListsLayout::selectionChangedCallbackMSML, this,
      std::placeholders::_1, std::placeholders::_2));

  UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
  layout->setLocalPosition(kLayoutLocalPos);
  layout->setAlignment(Alignment::CENTER_CENTER);
  layout->setOrientation(Orientation::kHorizontal);

  // ensure you call the padding function before adding items,
  // otherwise you will have to manually call updateLayout for the changes to take effect:
  layout->setDefaultItemPadding(kItemPadding);
  layout->addItem(dropDownList);
  return layout;
}

// Create an item with an icon, used to add to a list:
UiListViewItem* ListsLayout::createHorizontalItem(Prism* prism, const std::string& thumbnailPath) {
  UiImage* thumbnail = SDKExamples::createUiImage(prism, thumbnailPath, kIconWidth, kIconHeight);
  thumbnail->setLocalPosition(kIconLocalPos);

  UiListViewItem* listViewItem = SDKExamples::createUiListViewItem(prism);
  listViewItem->addChild(thumbnail);
  listViewItem->setBackgroundColor(kItemBackgroundColorIdle);
  listViewItem->onHoverEnterSub(std::bind(&ListsLayout::hoverEnterCallback, this,
      std::placeholders::_1, thumbnail, nullptr));
  listViewItem->onHoverExitSub(std::bind(&ListsLayout::hoverExitCallback, this,
      std::placeholders::_1, thumbnail, nullptr));
  listViewItem->onActivateSub(std::bind(&ListsLayout::activateCallback, this,
      std::placeholders::_1, thumbnail));
  return listViewItem;
}

// Create an item with a text description and an icon, used to add to a list:
UiListViewItem* ListsLayout::createVerticalItem(Prism* prism, const std::string& titleString,
    const std::string& descString, const std::string& thumbnailPath) {
  UiText* title = SDKExamples::createEclipseLabel(prism, titleString, EclipseLabelType::kT4);
  title->setLocalPosition(kTitleLocalPos);
  title->setTextColor(kTitleTextColorIdle);
  title->setSkipRaycast(true, true);  // prevent the cursor from activating events with this node.

  UiText* desc      = SDKExamples::createUiText(prism, descString);
  FontParams params = UiText::GetEclipseFontParameters(EclipseLabelType::kT5);
  params.style      = resources::FontStyle::kItalic;
  desc->setFontParameters(params);
  desc->setTextColor(kDescTextColor);
  desc->setLocalPosition(kDescLocalPos);
  desc->setSkipRaycast(true, true);  // prevent the cursor from activating events with this node.

  UiImage* thumb = SDKExamples::createUiImage(prism, thumbnailPath, kVerticalIconWidth, kVerticalIconHeight);
  thumb->setLocalPosition(kIconLocalPos);

  LineNode* lineSeparator = SDKExamples::createLineNode(prism);
  lineSeparator->setLocalPosition(kLineLocalPos);
  lineSeparator->addPoints(kLineLocalPosStart);
  lineSeparator->addPoints(kLineLocalPosEnd);
  lineSeparator->setColor(kLineColor);

  UiListViewItem* listViewItem = SDKExamples::createUiListViewItem(prism);
  listViewItem->setBackgroundColor(kItemBackgroundColorIdle);
  listViewItem->addChild(title);
  listViewItem->addChild(desc);
  listViewItem->addChild(thumb);
  listViewItem->addChild(lineSeparator);
  listViewItem->onHoverEnterSub(std::bind(&ListsLayout::hoverEnterCallback, this,
        std::placeholders::_1, thumb, title));
  listViewItem->onHoverExitSub(std::bind(&ListsLayout::hoverExitCallback, this,
      std::placeholders::_1, thumb, title));
  listViewItem->onActivateSub(std::bind(&ListsLayout::activateCallback, this,
      std::placeholders::_1, thumb));
  return listViewItem;
}

// Create an item with an icon, used to dynamically add it to a list:
UiListViewItem* ListsLayout::createDynamicItem(Prism* prism, UiListView* currList,
    UiListView* otherList, const std::string& iconPath) {
  UiImage* thumb = SDKExamples::createUiImage(prism, iconPath, kIconWidth, kIconHeight);
  thumb->setLocalPosition(kIconLocalPos);

  UiListViewItem* listViewItem = SDKExamples::createUiListViewItem(prism);
  listViewItem->addChild(thumb);
  listViewItem->setBackgroundColor(kItemBackgroundColorIdle);
  listViewItem->onHoverEnterSub(std::bind(&ListsLayout::hoverEnterCallback,
      this, std::placeholders::_1, thumb, nullptr));
  listViewItem->onHoverExitSub(std::bind(&ListsLayout::hoverExitCallback,
      this, std::placeholders::_1, thumb, nullptr));
  listViewItem->onActivateSub([=](const UiEventData&) {
    if (listViewItem->isInSubtree(currList)) {
      currList->removeItem(listViewItem);
      otherList->addItem(listViewItem);
    } else if (listViewItem->isInSubtree(otherList)) {
      otherList->removeItem(listViewItem);
      currList->addItem(listViewItem);
    }
  });
  return listViewItem;
}

TransformNode* ListsLayout::buildHorizontalSceneGraph(Prism* prism) {
  UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
  layout->setAlignment(Alignment::CENTER_CENTER);
  layout->setDefaultItemAlignment(Alignment::CENTER_CENTER);

  // ensure you call the padding function before adding items,
  // otherwise you will have to manually call updateLayout for the changes to take effect:
  layout->setDefaultItemPadding(kLayoutItemPadding);

  auto createList = [this, prism](float listWidth, float listHeight, const glm::vec3 overlayPos) {
    UiImage* overlay     = createOverlay(prism, listWidth, listHeight, overlayPos);
    UiListView* listView = SDKExamples::createUiListView(prism, listWidth, listHeight);
    listView->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
    listView->setOrientation(Orientation::kHorizontal);
    listView->setCursorEdgeScrollMode(CursorEdgeScrollMode::kAlways);
    listView->addItem(createHorizontalItem(prism, kFirstIconPath));
    listView->addItem(createHorizontalItem(prism, kSecondIconPath));
    listView->addItem(createHorizontalItem(prism, kThirdIconPath));
    listView->addItem(createHorizontalItem(prism, kFourthIconPath));
    listView->addItem(createHorizontalItem(prism, kFifthIconPath));
    listView->addItemAt(0, createHorizontalItem(prism, kSixthIconPath));
    listView->addItemAt(1, createHorizontalItem(prism, kSeventhIconPath));
    listView->addChild(overlay);
    return listView;
  };
  layout->addItem(createList(kSmallListWidth, kListHeight, kSmallOverlayLocalPos));
  layout->addItem(createList(kListWidth, kListHeight, kOverlayLocalPos));
  return layout;
}

TransformNode* ListsLayout::buildVerticalSceneGraph(Prism* prism) {
  UiListView* listView = SDKExamples::createUiListView(prism, kVerticalListWidth, kVerticalListHeight);
  listView->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  listView->addItem(createVerticalItem(prism,
      "1. One Circle", "Green * No Background", kFirstIconPath));
  listView->addItem(createVerticalItem(prism,
      "2. Two Circles", "Indigo * No Background", kSecondIconPath));
  listView->addItem(createVerticalItem(prism,
      "3. Three Circles", "Hot Pink * No Background", kThirdIconPath));
  listView->addItem(createVerticalItem(prism,
      "4. Four Circles", "Orange * No Background", kFourthIconPath));
  listView->addItem(createVerticalItem(prism,
      "5. Five Circles", "Yellow * Blue Background", kFifthIconPath));
  listView->addItem(createVerticalItem(prism,
      "6. Six Circles", "Magenta * Blue Background", kSixthIconPath));
  listView->addItem(createVerticalItem(prism,
      "7. Seven Circles", "Cyan * Blue Background", kSeventhIconPath));

  UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
  layout->setAlignment(Alignment::CENTER_CENTER);

  // ensure you call the padding function before adding items,
  // otherwise you will have to manually call updateLayout for the changes to take effect:
  layout->setDefaultItemPadding(kLayoutItemPadding);
  layout->addItem(listView);
  return layout;
}

TransformNode* ListsLayout::buildDynamicSceneGraph(Prism* prism) {
  UiListView* listA = SDKExamples::createUiListView(prism, kListWidth, kListHeight);
  listA->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  listA->setOrientation(Orientation::kHorizontal);

  UiListView* listB = SDKExamples::createUiListView(prism, kListWidth, kListHeight);
  listB->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  listB->setOrientation(Orientation::kHorizontal);

  listA->addItem(createDynamicItem(prism, listA, listB, kFirstIconPath));
  listA->addItem(createDynamicItem(prism, listA, listB, kSecondIconPath));
  listA->addItem(createDynamicItem(prism, listA, listB, kThirdIconPath));
  listA->addItem(createDynamicItem(prism, listA, listB, kFourthIconPath));
  listA->addItem(createDynamicItem(prism, listA, listB, kFifthIconPath));
  listA->addItem(createDynamicItem(prism, listA, listB, kSixthIconPath));
  listA->addItem(createDynamicItem(prism, listA, listB, kSeventhIconPath));
  listB->addItem(createDynamicItem(prism, listB, listA, kEighthIconPath));

  UiLinearLayout* layout = SDKExamples::createUiLinearLayout(prism);
  layout->setAlignment(Alignment::CENTER_CENTER);
  layout->setDefaultItemAlignment(Alignment::CENTER_CENTER);

  // ensure you call the padding function before adding items,
  // otherwise you will have to manually call updateLayout for the changes to take effect:
  layout->setDefaultItemPadding(kLayoutItemPadding);
  layout->addItem(listA);
  layout->addItem(listB);
  return layout;
}

void ListsLayout::selectionChangedCallbackSSSL(const UiEventData& list,
    const std::vector<const DropDownListItem*>& selection) {
  glm::vec4 color = color::BLACK;
  if (!selection.empty()) {
    const std::string itemLabel = selection[0]->label;
    if (itemLabel == "red") {
      color = color::RED;
    }
    else if (itemLabel == "green") {
      color = color::GREEN;
    }
    else if (itemLabel == "blue") {
      color = color::BLUE;
    }
  } else {
    color = color::WHITE;
  }
  UiDropDownList::CastFrom(list.getUiNode())->setTextColor(color);
}

void ListsLayout::selectionChangedCallbackMSSL(const UiEventData& list,
    const std::vector<const DropDownListItem*>& selection) {
  glm::vec4 color(0.0f);
  for(auto item : selection) {
    const std::string itemLabel = item->label;
    if (itemLabel == "red") {
      color += color::RED;
    } else if (itemLabel == "green") {
      color += color::GREEN;
    } else if (itemLabel == "blue") {
      color += color::BLUE;
    }
  }

  if (!selection.empty()) {
    color /= static_cast<float>(selection.size());
  } else {
    color = color::WHITE;
  }
  UiDropDownList::CastFrom(list.getUiNode())->setTextColor(color);
}

void ListsLayout::selectionChangedCallbackMSML(const UiEventData& list,
    const std::vector<const DropDownListItem*>& selection) {
  glm::vec4 color(0.0f);
  for(auto item : selection) {
    const std::string itemLabel = item->label;
    if (itemLabel == "red") {
      color += color::RED;
    } else if (itemLabel == "pink") {
      color += color::PINK;
    } else if (itemLabel == "hotpink") {
      color += color::HOTPINK;
    } else if (itemLabel == "green") {
      color += color::GREEN;
    } else if (itemLabel == "yellow") {
      color += color::YELLOW;
    } else if (itemLabel == "orange") {
      color += color::ORANGE;
    } else if (itemLabel == "blue") {
      color += color::BLUE;
    } else if (itemLabel == "magenta") {
      color += color::MAGENTA;
    } else if (itemLabel == "cyan") {
      color += color::CYAN;
    } else if (itemLabel == "indigo") {
      color += color::INDIGO;
    }
  }

  if (!selection.empty()) {
    color /= static_cast<float>(selection.size());
  } else {
    color = color::WHITE;
  }
  UiDropDownList::CastFrom(list.getUiNode())->setTextColor(color);
}


void ListsLayout::hoverEnterCallback(const UiEventData& item, UiImage* thumbnail, UiText* title) {
  UiListViewItem::CastFrom(item.getUiNode())->setBackgroundColor(kItemBackgroundColorHovered);
  thumbnail->setTexCoords(kIconTextCoordsHovered);
  if (title) {
    title->setTextColor(kTitleTextColorHovered);
  }
}

void ListsLayout::hoverExitCallback(const UiEventData& item, UiImage* thumbnail, UiText* title) {
  UiListViewItem::CastFrom(item.getUiNode())->setBackgroundColor(kItemBackgroundColorIdle);
  thumbnail->setTexCoords(kIconTextCoordsIdle);
  if (title) {
    title->setTextColor(kTitleTextColorIdle);
  }
}

void ListsLayout::activateCallback(const UiEventData&, UiImage* thumbnail) {
  if (thumbnail->getColor() == color::WHITE) {
    thumbnail->setColor(color::HOTPINK);
  } else {
    thumbnail->setColor(color::WHITE);
  }
}

// Remove all nodes when detached from a prism:
void ListsLayout::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "ListsLayout::onDetachPrism() Destroying the Buttons Layout scene");
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}