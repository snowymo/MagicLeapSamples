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
#include <BasePrismController.h>

namespace lumin {
  namespace SDKExamples {
  /**
   * Provides an interface to use for Prism Controllers generated programmatically and
   * loaded from an external file generated by the Lumin Runtime Editor.
   * Provides a page layout to toggle between the two scene graphs.
   */
  class BaseExampleController : public lumin::PrismController {
  public:
    /**
     * Constructs the BaseExampleController.
     * @param[in] name                      - name of Prism Controller.
     * @param[in] position                  - position of the page content switcher.
     * @param[in] generatedProgrammatically - the Prism Controller built in code.
     * @param[in] generatedExternally       - the Prism Controller loaded from a file.
     */
    BaseExampleController(const std::string& name, const glm::vec3& position,
        const std::shared_ptr<BasePrismController> generatedProgrammatically,
        const std::shared_ptr<BasePrismController> generatedExternally);

    /**
     * Destroys the BaseExampleController.
     */
    virtual ~BaseExampleController();

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

    /**
     * Returns the active child prism controller displayed.
     */
    std::shared_ptr<BasePrismController> getActiveController();

  private:
    /**
     * Creates a Page Layout that toggles between the scene graphs generated in code
     * and using an external file.
     * @param[in] prism - the prism to build the layout in.
     */
    void createLayout(lumin::Prism* prism);

  private:
    const glm::vec3 position_;
    std::shared_ptr<BasePrismController> generatedProgrammatically_;
    std::shared_ptr<BasePrismController> generatedExternally_;
    std::shared_ptr<BasePrismController> activeController_;
  };

  } // SDKExamples
} // lumin