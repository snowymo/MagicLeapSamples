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
#include <CursorsDisplayPrefab.h>
#include <lumin/ui/Cursor.h>
#include <lumin/ui/node/UiText.h>
#include <lumin/ui/node/UiImage.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const float kColorOffset = 0.2f;
}

namespace prefabs {


  CursorsDisplayPrefab::CursorsDisplayPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : CursorsDisplayPrefabBase(extendedPrefabManager, root) {
    textNodes_   = root->findChildren(UiText::GetNodeTypeEnum());
    circleNodes_ = root->findChildren(UiImage::GetNodeTypeEnum());
  }

  CursorsDisplayPrefab::~CursorsDisplayPrefab() {
    prism_ = nullptr;
  }

  void CursorsDisplayPrefab::setPrism(Prism* prism) {
    prism_ = prism;
  }

  // Handler methods are declared in the base class CursorsDisplayPrefabBase and can be implemented here

  void CursorsDisplayPrefab::CC_Panel1_ChangeCursorDefaultHandler(const lumin::ui::UiEventData& data) {
    Cursor::SetState(prism_, EclipseCursorState::kDefault);
  }

  void CursorsDisplayPrefab::CC_Panel2_ChangeCursorBrowserDefault(const lumin::ui::UiEventData& data) {
    Cursor::SetState(prism_, EclipseCursorState::kBrowserDefault);
  }

  void CursorsDisplayPrefab::CC_Panel3_ChangeCursorBrowserPointer(const lumin::ui::UiEventData& data) {
    Cursor::SetState(prism_, EclipseCursorState::kBrowserPointer);
  }

  void CursorsDisplayPrefab::CC_Panel4_ChangeCursorTextInput(const lumin::ui::UiEventData& data) {
    Cursor::SetState(prism_, EclipseCursorState::kTextInput);
  }

  void CursorsDisplayPrefab::CC_Panel5_ChangeCursorCrosshair(const lumin::ui::UiEventData& data) {
    Cursor::SetState(prism_, EclipseCursorState::kCrosshair);
  }

  void CursorsDisplayPrefab::CC_Panel6_ChangeCursorMove(const lumin::ui::UiEventData& data) {
    Cursor::SetState(prism_, EclipseCursorState::kMove);
  }

  void CursorsDisplayPrefab::CC_Panel7_ChangeCursorScroll(const lumin::ui::UiEventData& data) {
    Cursor::SetState(prism_, EclipseCursorState::kScroll);
  }

  void colorChangedCallback(const glm::vec4 color, std::vector<Node*> textNodes, std::vector<Node*> circleNodes) {
    for (auto& node : textNodes) {
      UiText::CastFrom(node)->setTextColor(glm::vec4(fmax(0.0f, color.x - kColorOffset),
          fmax(0.0f, color.y - kColorOffset), fmax(0.0f, color.z - kColorOffset), 1.0f));
    }
    // Only change the color of the circles, not the shells:
    for (auto& node : circleNodes) {
      if (node->getName().find("CC_Image") != std::string::npos) {
        UiImage::CastFrom(node)->setColor(color);
      }
    }
  }

  void CursorsDisplayPrefab::CC_ColorPicker_ColorChanged_onCancel(const lumin::ui::UiEventData& data, const glm::vec4& color) {
    colorChangedCallback(color, textNodes_, circleNodes_);
  }

  void CursorsDisplayPrefab::CC_ColorPicker_ColorChanged_onColorChanged(const lumin::ui::UiEventData& data, const glm::vec4& color) {
    colorChangedCallback(color, textNodes_, circleNodes_);
  }

}
