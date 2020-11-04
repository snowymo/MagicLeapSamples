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
#include <lumin/ui/node/UiWebView.h>

namespace lumin {
  class SimpleUiWebViewClient;
  /**
   * Extends PrismController to create UiWebView based scene graph.
   */
  class UiWebViewController : public lumin::PrismController {
  public:
    /**
     * Constructs the UiWebViewController.
     * @param[in] name - name of Prism Controller.
     */
    UiWebViewController(const std::string& name);

    /**
     * Destroys the UiWebViewController.
     */
    virtual ~UiWebViewController();

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
  private:
   void createLayout(lumin::Prism* prism);
   lumin::ui::UiWebView* ui_webview_;
   std::unique_ptr<SimpleUiWebViewClient> webview_client_;
  };
} // lumin