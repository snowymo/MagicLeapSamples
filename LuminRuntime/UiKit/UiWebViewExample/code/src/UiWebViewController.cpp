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
#include <UiWebViewController.h>
#include <NodeCreationWrappers.h>
#include <lumin/ui/node/UiWebViewClient.h>
#include <lumin/ui/node/UiWebViewDataManager.h>


#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

/*
 * In this example we create a simple LinearLayout, add
 * two buttons 'Load Local' and 'Load Web'. Below them we
 * add a UiWebView element. Clicking 'Load Local'
 * will load a local html page from the file system.
 * Clicking 'Load Web' will open a page from the internet.
 * We also show how to receive events from UiWebView
 * via UiWebViewClient. This example also shows how to cleanup
 * user web data using UiWebViewDataManager interface.
 */
namespace lumin {

/*
 * This is a simple webview client that receives events
 * 'onBeforeResourceLoad' and 'onLoadEnd'. There are additional
 * events you can register for. See 'UiWebViewClient.h' for list
 * of all the events
 */
class SimpleUiWebViewClient : public lumin::ui::UiWebViewClient {
  public:
  SimpleUiWebViewClient() {}
  virtual ~SimpleUiWebViewClient() = default;
  // UiWebViewClient methods
  virtual void onBeforeResourceLoad(UiWebView* /* webview */, std::string resource_url) {
    ML_LOG(Debug, "onBeforeResource : %s", resource_url.c_str());
  };

  virtual void onLoadEnd(UiWebView* /* webview */, bool is_main_frame, int http_error_code) {
    ML_LOG(Debug, "onLoadEnd : is_main_frame: %d  http_error_code %d", is_main_frame, http_error_code);
  };
};

UiWebViewController::UiWebViewController(const std::string& name) :
  PrismController(name), ui_webview_(nullptr) {
}

UiWebViewController::~UiWebViewController() = default;

void UiWebViewController::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "UiWebViewController onAttachPrism");
  createLayout(prism);
}

void UiWebViewController::createLayout(Prism* prism) {
  ML_LOG(Debug, "UiWebViewController::createLayout");
  // Creates a simple LinearLayout and add two buttons
  // [Load Local]  [Load Web]
  UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
  topLayout->setOrientation(lumin::ui::Orientation::kVertical);
  UiLinearLayout* header_container = SDKExamples::createUiLinearLayout(prism);
  header_container->setOrientation(lumin::ui::Orientation::kHorizontal);
  header_container->setAlignment(lumin::ui::Alignment::CENTER_CENTER);
  header_container->setVisibilityInherited(true);
  header_container->setSkipInvisibleItems(true);

  // Adds 'Load Local' eclipse button
  EclipseButtonParams params_local = {EclipseButtonType::kText, "Load Local"};
  params_local.height = 0.06f;
  UiButton* button_load_local =
    SDKExamples::createEclipseButton(prism, params_local);
  header_container->addItem(button_load_local);
  button_load_local->onActivateSub(
    [this](const lumin::ui::UiEventData& /* eventData */) {
      if (ui_webview_) {
        ui_webview_->loadUrl("file:///package/res/local/index.html");
      }
    });

  // Add 'Load Web' eclipse button
  EclipseButtonParams params_web = {EclipseButtonType::kText, "Load Web"};
  params_web.height = 0.06f;
  UiButton* button_load_web =
  SDKExamples::createEclipseButton(prism, params_web);
  button_load_web->onActivateSub(
    [this](const lumin::ui::UiEventData& /* eventData */) {
      if (ui_webview_) {
        ui_webview_->loadUrl("https://www.magicleap.com/experiences/helio");
      }
    });

  // Add the buttons to the Linear Layout.
  header_container->addItem(button_load_local);
  header_container->addItem(button_load_web, {0, 0, 0, 0.05});

  topLayout->setAlignment(Alignment::CENTER_CENTER);
  topLayout->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  const glm::vec3 prism_size = prism->getSize();
  glm::vec2 web_node_size = glm::vec2(prism_size.x, prism_size.y - 0.1);

  ui_webview_ = UiWebView::Create(prism, web_node_size);
  LUMIN_ASSERT(ui_webview_ != nullptr, "Failed to create UiWebView");
  // There are a few reasons why a UiWebView creation can fail.
  // First, if the app doesn't have correct permission in the manifest.
  // Second, if the web engine did not initialize correctly.
  webview_client_ = std::make_unique<SimpleUiWebViewClient>();
  // Register a webview client
  ui_webview_->setWebViewClient(webview_client_.get());
  // Load a Url. Here we load https://www.magicleap.com
  ui_webview_->loadUrl("https://www.magicleap.com");
  topLayout->addItem(header_container, {0.01, 0, 0.02, 0});
  topLayout->addItem(ui_webview_);
  getRoot()->addChild(topLayout);
}

// Remove all nodes when detached from a prism:
void UiWebViewController::onDetachPrism(Prism*) {
  ML_LOG(Debug, "UiWebViewController::onDetachPrism");
  if (ui_webview_) {
    ML_LOG(Debug, "Cleaning up user web data");
    // Use UiWebViewDataManager to clean up user data if needed.
    // Prefer calling these APIs on Application Main Thread.
    ui_webview_->getDataManagerInstance()->clearCache();
    ui_webview_->getDataManagerInstance()->removeAllCookies();
  }
  deleteSceneGraph();
}

}  // namespace lumin
