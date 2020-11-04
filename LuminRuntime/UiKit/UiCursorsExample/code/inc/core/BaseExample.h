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
#include <SceneManager.h>
#include <PrefabManager.h>

namespace lumin {
  namespace SDKExamples {
  /**
   * Provides an interface to use for Prism Controllers generated programmatically and
   * loaded from an external file generated by the Lumin Runtime Editor.
   * Provides a page layout to toggle between the two scene graphs.
   */
  class BaseExample : public lumin::PrismController {
  public:
    /**
     * Managers used to load scene graphs from the Lumin Runtime Editor.
     */
    struct Managers {
      Managers(lumin::Prism* prism);
      ~Managers();
      ExtendedSceneManager* extendedScene_ = nullptr;
      ExtendedPrefabManager* extendedPrefab_ = nullptr;
    };
    /**
     * Constructs the BaseExample.
     * @param[in] name - name of Prism Controller.
     */
    BaseExample(const std::string& name);

    /**
     * Destroys the BaseExample.
     */
    virtual ~BaseExample();

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
    virtual lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) = 0;

    /**
     * Builds the scene.
     * @param[in] prism - the prism to build the scene in.
     * @return          - the root node of the scene, to be added.
     */
    virtual lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) = 0;

  private:
    /**
     * Creates a Page Layout that toggles between the scene graphs generated in code
     * and using an external file.
     * @param[in] prism - the prism to build the layout in.
     */
    void createLayout(lumin::Prism* prism);

  protected:
    Managers* managers_;
  };

  } // SDKExamples
} // lumin