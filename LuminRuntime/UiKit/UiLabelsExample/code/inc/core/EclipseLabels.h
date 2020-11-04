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
#include <lumin/PrismController.h>
/**
 * Creates a Scene displaying the Eclipse Labels.
 */
class EclipseLabels final : public lumin::SDKExamples::BaseExample {
 public:
  /**
   * Constructs the Eclipse Labels Prism Controller.
   */
  EclipseLabels();

  /**
   * Destroys the Eclipse Labels Prism Controller.
   */
  virtual ~EclipseLabels();

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

  /**
   * Builds the scene.
   * @param[in] prism - the prism to build the scene in.
   * @return          - the root node of the scene.
   */
  lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) override;

  /**
   * Loads the scene from the Lumin Runtime Editor.
   * @param[in] prism - the prism to load the scene in.
   * @return          - the root node of the scene.
   */
  lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) override;

 private:
  /**
   * Makes an Eclipse Label and adds it to the scene. The Eclipse Label includes an
   * icon with its name, and a description formatted according to the Label.
   * @param[in] prism      - the prism to add the label to.
   * @param[in] type       - the type of Eclipse Label to create.
   * @param[in] typeLabel  - the name of the Eclipse Label.
   * @param[in] descrLabel - the description of the Eclipse Label.
   */
  void makeLabel(lumin::Prism* prism,
      lumin::ui::EclipseLabelType type, const std::string& typeLabel,
      const std::string& descrLabel);

 private:
  lumin::ui::UiGridLayout* labelLayout_;
};