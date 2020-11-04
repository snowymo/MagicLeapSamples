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
#include <lumin/ui/UiKit.h>
#include <lumin/PrismController.h>
/**
 * Creates a Scene displaying every System Icon.
 */
class SystemIcons final : public lumin::PrismController {
 public:
  /**
   * Constructs the System Icons Prism Controller.
   */
  SystemIcons();

  /**
   * Destroys the System Icons Prism Controller.
   */
  virtual ~SystemIcons();

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
   * Creates the System Icon layout, filled with each System Icon and its title.
   * @param[in] prism  - the prism to add the System Icon Layout.
   * @return           - the System Icon Layout.
   */
  lumin::ui::UiLinearLayout* createSystemIconLayout(lumin::Prism* prism);
};