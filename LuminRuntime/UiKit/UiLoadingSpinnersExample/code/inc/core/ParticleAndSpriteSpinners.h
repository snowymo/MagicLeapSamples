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
#include <lumin/PrismController.h>
/**
 * UiLoadingSpinner Example's Prism Controller, displays every built-in loading spinner.
 */
class ParticleAndSpriteSpinners final : public lumin::SDKExamples::BaseExample {
 public:
 /**
  * Constructs the Particle and Sprite Spinners with the given name.
  */
  ParticleAndSpriteSpinners();

 /**
  * Destroys the Particle And Sprite Spinners Controller.
  */
  virtual ~ParticleAndSpriteSpinners();

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

 private:
 /**
  * Loads the scene graph from file.
  * @param[in] prism - the prism to associate the nodes with.
  * @return          - the root node of the scene.
  */
  lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) override;

 /**
  * Builds the scene graph programmatically.
  * @param[in] prism - the prism to associate the nodes with.
  * @return          - the root node of the scene.
  */
  lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) override;
};