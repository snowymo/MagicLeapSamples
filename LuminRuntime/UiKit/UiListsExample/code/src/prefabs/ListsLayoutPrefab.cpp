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

// %SRC_VERSION%: 2

#include <PrefabDescriptor.h>
#include <ListsLayoutPrefab.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec4 kItemBackgroundColorIdle(0.1f, 0.1f, 0.1f, 1.0f);  // (81, 81, 81)
  const glm::vec4 kItemBackgroundColorHovered(0.2f, 0.2f, 0.2f, 1.0f);  // (116, 116, 116)
  const glm::vec4 kTitleTextColorIdle(0.7f, 0.7f, 0.7f, 1.0f);  // (216, 216, 216)
  const glm::vec4 kTitleTextColorHovered(1.0f);
  const std::vector<glm::vec2> kIconTextCoordsIdle =
      {{0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}};
  const std::vector<glm::vec2> kIconTextCoordsHovered =
      {{0.1f, 0.9f}, {0.9f, 0.9f}, {0.9f, 0.1f}, {0.1f, 0.1f}};
}

namespace prefabs {


  ListsLayoutPrefab::ListsLayoutPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : ListsLayoutPrefabBase(extendedPrefabManager, root) {
  }

  ListsLayoutPrefab::~ListsLayoutPrefab() {
  }

  void onHoverEnterBase(UiListViewItem* item, UiImage* thumbnail, UiText* title = nullptr) {
    item->setBackgroundColor(kItemBackgroundColorHovered);
    thumbnail->setTexCoords(kIconTextCoordsHovered);
    if (title) {
      title->setTextColor(kTitleTextColorHovered);
    }
  }

  void onHoverExitBase(UiListViewItem* item, UiImage* thumbnail, UiText* title = nullptr) {
    item->setBackgroundColor(kItemBackgroundColorIdle);
    thumbnail->setTexCoords(kIconTextCoordsIdle);
    if (title) {
      title->setTextColor(kTitleTextColorIdle);
    }
  }

  void onActivateBase(UiImage* thumbnail) {
    if (thumbnail->getColor() == color::WHITE) {
      thumbnail->setColor(color::HOTPINK);
    } else {
      thumbnail->setColor(color::WHITE);
    }
  }

  void onDynamicItemActivate(UiListViewItem* item, UiListView* list1, UiListView* list2) {
    if (item->isInSubtree(list1)) {
      list1->removeItem(item);
      list2->addItem(item);
    } else if (item->isInSubtree(list2)) {
      list2->removeItem(item);
      list1->addItem(item);
    }
  }

  // Handler methods are declared in the base class ListsLayoutPrefabBase and can be implemented here

  void ListsLayoutPrefab::SSSL_DropDownList_SingleSelectSingleLevelHandlers(const lumin::ui::UiEventData& data, const std::vector<const lumin::ui::DropDownListItem*>& selection) {
    glm::vec4 color = color::BLACK;
    if (!selection.empty()) {
      const std::string itemLabel = selection[0]->label;
      if (itemLabel == "red") {
        color = color::RED;
      } else if (itemLabel == "green") {
        color = color::GREEN;
      } else if (itemLabel == "blue") {
        color = color::BLUE;
      }
    } else {
      color = color::WHITE;
    }
    UiDropDownList::CastFrom(data.getUiNode())->setTextColor(color);
  }

  void ListsLayoutPrefab::MSSL_DropDownList_MultiSelectSingleLevelHandlers(const lumin::ui::UiEventData& data, const std::vector<const lumin::ui::DropDownListItem*>& selection) {
    glm::vec4 color(0.0f);
    for (auto item : selection) {
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
    UiDropDownList::CastFrom(data.getUiNode())->setTextColor(color);
  }

  void ListsLayoutPrefab::MSML_DropDownList_MultiSelectMultiLevelHandlers(const lumin::ui::UiEventData& data, const std::vector<const lumin::ui::DropDownListItem*>& selection) {
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
    UiDropDownList::CastFrom(data.getUiNode())->setTextColor(color);
  }

  void ListsLayoutPrefab::VLVS_ListViewItem1_VerticalListViewItem1Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getVLVS_ListViewItem1(), getVLVS_Image1(), getVLVS_Label1());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem1_VerticalListViewItem1Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getVLVS_ListViewItem1(), getVLVS_Image1(), getVLVS_Label1());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem1_VerticalListViewItem1Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getVLVS_Image1());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem2_VerticalListViewItem2Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getVLVS_ListViewItem2(), getVLVS_Image2(), getVLVS_Label3());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem2_VerticalListViewItem2Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getVLVS_ListViewItem2(), getVLVS_Image2(), getVLVS_Label3());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem2_VerticalListViewItem2Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getVLVS_Image2());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem3_VerticalListViewItem3Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getVLVS_ListViewItem3(), getVLVS_Image3(), getVLVS_Label5());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem3_VerticalListViewItem3Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getVLVS_ListViewItem3(), getVLVS_Image3(), getVLVS_Label5());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem3_VerticalListViewItem3Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getVLVS_Image3());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem4_VerticalListViewItem4Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getVLVS_ListViewItem4(), getVLVS_Image4(), getVLVS_Label7());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem4_VerticalListViewItem4Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getVLVS_ListViewItem4(), getVLVS_Image4(), getVLVS_Label7());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem4_VerticalListViewItem4Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getVLVS_Image4());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem5_VerticalListViewItem5Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getVLVS_ListViewItem5(), getVLVS_Image5(), getVLVS_Label9());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem5_VerticalListViewItem5Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getVLVS_ListViewItem5(), getVLVS_Image5(), getVLVS_Label9());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem5_VerticalListViewItem5Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getVLVS_Image5());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem6_VerticalListViewItem6Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getVLVS_ListViewItem6(), getVLVS_Image6(), getVLVS_Label11());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem6_VerticalListViewItem6Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getVLVS_ListViewItem6(), getVLVS_Image6(), getVLVS_Label11());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem6_VerticalListViewItem6Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getVLVS_Image6());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem7_VerticalListViewItem7Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getVLVS_ListViewItem7(), getVLVS_Image7(), getVLVS_Label13());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem7_VerticalListViewItem7Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getVLVS_ListViewItem7(), getVLVS_Image7(), getVLVS_Label13());
  }

  void ListsLayoutPrefab::VLVS_ListViewItem7_VerticalListViewItem7Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getVLVS_Image7());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem1_HorizontalListViewItem1Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem1(), getHLVS_Image1());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem1_HorizontalListViewItem1Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem1(), getHLVS_Image1());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem1_HorizontalListViewItem1Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image1());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem2_HorizontalListViewItem2Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem2(), getHLVS_Image2());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem2_HorizontalListViewItem2Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image2());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem2_HorizontalListViewItem2Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem2(), getHLVS_Image2());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem3_HorizontalListViewItem3Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem3(), getHLVS_Image3());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem3_HorizontalListViewItem3Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem3(), getHLVS_Image3());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem3_HorizontalListViewItem3Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image3());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem4_HorizontalListViewItem4Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem4(), getHLVS_Image4());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem4_HorizontalListViewItem4Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem4(), getHLVS_Image4());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem4_HorizontalListViewItem4Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image4());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem5_HorizontalListViewItem5Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem5(), getHLVS_Image5());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem5_HorizontalListViewItem5Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem5(), getHLVS_Image5());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem5_HorizontalListViewItem5Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image5());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem6_HorizontalListViewItem6Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem6(), getHLVS_Image6());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem6_HorizontalListViewItem6Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem6(), getHLVS_Image6());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem6_HorizontalListViewItem6Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image6());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem7_HorizontalListViewItem7Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem7(), getHLVS_Image7());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem7_HorizontalListViewItem7Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem7(), getHLVS_Image7());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem7_HorizontalListViewItem7Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image7());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem8_HorizontalListViewItem8Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem8(), getHLVS_Image8());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem8_HorizontalListViewItem8Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem8(), getHLVS_Image8());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem8_HorizontalListViewItem8Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image8());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem9_HorizontalListViewItem9Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem9(), getHLVS_Image9());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem9_HorizontalListViewItem9Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem9(), getHLVS_Image9());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem9_HorizontalListViewItem9Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image9());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem10_HorizontalListViewItem10Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem10(), getHLVS_Image10());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem10_HorizontalListViewItem10Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem10(), getHLVS_Image10());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem10_HorizontalListViewItem10Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image10());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem11_HorizontalListViewItem11Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem11(), getHLVS_Image11());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem11_HorizontalListViewItem11Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem11(), getHLVS_Image11());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem11_HorizontalListViewItem11Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image11());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem12_HorizontalListViewItem12Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem12(), getHLVS_Image12());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem12_HorizontalListViewItem12Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem12(), getHLVS_Image12());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem12_HorizontalListViewItem12Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image12());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem13_HorizontalListViewItem13Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem13(), getHLVS_Image13());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem13_HorizontalListViewItem13Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem13(), getHLVS_Image13());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem13_HorizontalListViewItem13Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image13());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem14_HorizontalListViewItem14Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getHLVS_ListViewItem14(), getHLVS_Image14());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem14_HorizontalListViewItem14Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getHLVS_ListViewItem14(), getHLVS_Image14());
  }

  void ListsLayoutPrefab::HLVS_ListViewItem14_HorizontalListViewItem14Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onActivateBase(getHLVS_Image14());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem1_DynamicListViewItem1Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDLVS_ListViewItem1(), getDLVS_Image1());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem1_DynamicListViewItem1Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDLVS_ListViewItem1(), getDLVS_Image1());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem1_DynamicListViewItem1Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onDynamicItemActivate(getDLVS_ListViewItem1(), getDLVS_ListView1(), getDLVS_ListView2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem2_DynamicListViewItem2Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDLVS_ListViewItem2(), getDLVS_Image2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem2_DynamicListViewItem2Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDLVS_ListViewItem2(), getDLVS_Image2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem2_DynamicListViewItem2Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onDynamicItemActivate(getDLVS_ListViewItem2(), getDLVS_ListView1(), getDLVS_ListView2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem3_DynamicListViewItem3Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDLVS_ListViewItem3(), getDLVS_Image3());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem3_DynamicListViewItem3Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDLVS_ListViewItem3(), getDLVS_Image3());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem3_DynamicListViewItem3Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onDynamicItemActivate(getDLVS_ListViewItem3(), getDLVS_ListView1(), getDLVS_ListView2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem4_DynamicListViewItem4Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDLVS_ListViewItem4(), getDLVS_Image4());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem4_DynamicListViewItem4Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDLVS_ListViewItem4(), getDLVS_Image4());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem4_DynamicListViewItem4Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onDynamicItemActivate(getDLVS_ListViewItem4(), getDLVS_ListView1(), getDLVS_ListView2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem5_DynamicListViewItem5Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDLVS_ListViewItem5(), getDLVS_Image5());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem5_DynamicListViewItem5Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDLVS_ListViewItem5(), getDLVS_Image5());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem5_DynamicListViewItem5Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onDynamicItemActivate(getDLVS_ListViewItem5(), getDLVS_ListView1(), getDLVS_ListView2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem6_DynamicListViewItem6Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDLVS_ListViewItem6(), getDLVS_Image6());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem6_DynamicListViewItem6Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDLVS_ListViewItem6(), getDLVS_Image6());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem6_DynamicListViewItem6Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onDynamicItemActivate(getDLVS_ListViewItem6(), getDLVS_ListView1(), getDLVS_ListView2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem7_DynamicListViewItem7Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDLVS_ListViewItem7(), getDLVS_Image7());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem7_DynamicListViewItem7Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDLVS_ListViewItem7(), getDLVS_Image7());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem7_DynamicListViewItem7Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onDynamicItemActivate(getDLVS_ListViewItem7(), getDLVS_ListView1(), getDLVS_ListView2());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem8_DynamicListViewItem8Handlers_onHoverEnter(const lumin::ui::UiEventData& data) {
    onHoverEnterBase(getDLVS_ListViewItem8(), getDLVS_Image8());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem8_DynamicListViewItem8Handlers_onHoverExit(const lumin::ui::UiEventData& data) {
    onHoverExitBase(getDLVS_ListViewItem8(), getDLVS_Image8());
  }

  void ListsLayoutPrefab::DLVS_ListViewItem8_DynamicListViewItem8Handlers_onActivate(const lumin::ui::UiEventData& data) {
    onDynamicItemActivate(getDLVS_ListViewItem8(), getDLVS_ListView2(), getDLVS_ListView1());
  }
}