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
#include <ExamplesConstants.h>

#include <lumin/PrismController.h>
#include <lumin/node/MoveData.h>
#include <lumin/ui/UiKit.h>
/**
 * UiPortalIcons Example's Prism Controller, displays static and animated portal icons.
 * Icons on the boundary, when activated, swap places with the icon in the center.
 */
class PortalIcons final : public lumin::PrismController {
 public:
  /**
   * Constructs the Portal Icons Prism Controller with the given name.
   */
  PortalIcons() : PrismController("Portal Icons Example") {}

  /**
   * Destroys the Portal Icons Prism Controller.
   */
  virtual ~PortalIcons() {}

  /**
   * Creates the scene when it is attached to a prism.
   * @param[in] prism - the prism the scene is attached to.
   */
  void onAttachPrism(lumin::Prism* prism) override;

  /**
   * Destroys the scene when it is removed from a prism.
   * @param[in] prism - the prism the scene will be removed from.
   */
  void onDetachPrism(lumin::Prism* prism) override;

  /**
   * Disables portal icons while moving.
   * @param[in] anEvent - the received Server Event.
   */
  bool onEvent(lumin::ServerEvent* anEvent) override;

 private:
  /**
   * Creates the default UiPortalIcon.
   * @param[in] title    - the title of the UiPortalIcon
   * @param[in] position - the local position of the UiPortalIcon
   * @param[in] size     - the size of the UiPortalIcon
   * @return - UiRectLayout containing the created UiPortalIcon
   */
  lumin::ui::UiRectLayout* createPortalIcon(const std::string& title,
      const glm::vec3& position,
      const lumin::ui::PortalIconSize size = lumin::ui::PortalIconSize::kMedium);

  /**
   * Creates a UiPortalIcon with a ModelNode* icon and Node* background.
   * @param[in] title      - the title of the UiPortalIcon
   * @param[in] icon       - the ModelNode* icon overlay of the UiPortalIcon
   * @param[in] bg         - the Node* background of the UiPortalIcon
   * @param[in] position   - the local position of the UiPortalIcon
   * @param[in] iconOffset - the offset of the icon overlay
   * @param[in] bgOffset   - the offset of the background
   * @param[in] hoverAni   - the name of the animation track to use when hovered
   * @param[in] idleAni    - the name of the animation track to use when idle
   * @param[in] size       - the size of the UiPortalIcon
   * @return - UiRectLayout containing the created UiPortalIcon
   */
  lumin::ui::UiRectLayout* createPortalIcon(const std::string& title,
      lumin::ModelNode* icon, lumin::Node* bg, const glm::vec3& position,
      const glm::vec3& iconOffset = lumin::ExampleConsts::kDefaultForeground,
      const glm::vec3& bgOffset   = lumin::ExampleConsts::kDefaultBackground,
      const std::string& hoverAni = "",
      const std::string& idleAni  = "",
      const lumin::ui::PortalIconSize size = lumin::ui::PortalIconSize::kMedium);

  /**
   * Creates a UiRectLayout to be used as a container for a portal icon.
   * @param[in] position - the local position to place the UiRectLayout
   * @return             - the created UiRectLayout
   */
  lumin::ui::UiRectLayout* createLayout(const glm::vec3& position);

  /**
   * Switches the activated portal icon with the center portal icon.
   * @param[in] portal - the activated portal icon data
   * @param[in] layout - the activated UiRectLayout containing the portal icon
   */
  void onPortalIconActivate(const lumin::ui::UiEventData& portal,
      lumin::ui::UiRectLayout* layout);

 private:
  lumin::ui::UiRectLayout* centerIcon_ = nullptr;
  lumin::ui::UiRectLayout* prevIcon_   = nullptr;
  lumin::TimeMod* scaleIn_             = nullptr;
  lumin::TimeMod* scaleOut_            = nullptr;
  bool isMoving_                       = false;
};