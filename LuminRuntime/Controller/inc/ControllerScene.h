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
#include <ControllerEventWrapper.h>
#include <ControllerVisualizer.h>
#include <lumin/PrismController.h>
#include <lumin/ui/UiKit.h>
#include <lumin/utils/Status.h>
#include <lumin/event/ServerEvent.h>
/**
 * Controller Example's Prism Controller, displays the controller.
 */
class ControllerScene final : public lumin::PrismController {
 public:
  /**
   * Constructs the Scene's Controller.
   */
  ControllerScene();

  /**
   * Destroys the Scene's Controller.
   */
  virtual ~ControllerScene() {}

  /**
   * Creates the scene when it is attached to a prism.
   * @param prism - the prism the scene is attached to
   */
  void onAttachPrism(lumin::Prism* prism) override;

  /**
   * Destroys the scene when it is removed from a prism.
   * @param prism - the prism the scene will be removed from
   */
  void onDetachPrism(lumin::Prism* prism) override;

  /**
   * Indicates if the prism is selected.
   * @param fDelta - delta time since last frame
   */
  void onUpdate(float fDelta) override;

 private:
  std::shared_ptr<ControllerVisualizer> visualizer_ = nullptr;
  lumin::ui::UiText* prismSelected_ = nullptr;
};