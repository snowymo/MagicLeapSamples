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
#include <lumin/LandscapeApp.h>
#include <lumin/InitArg.h>
/**
 * This Lumin Runtime UiWebView example app will demonstrate
 * UiWebView node that renders webpages (html/css/js).
 */
class UiWebViewExample : public lumin::LandscapeApp {
public:
  /**
   * Constructs the UiWebViewExample App.
   */
  UiWebViewExample();

  /**
   * Destroys the UiWebViewExample App.
   */
  virtual ~UiWebViewExample();

  /**
   * Disallows the copy constructor.
   */
  UiWebViewExample(const UiWebViewExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiWebViewExample(UiWebViewExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiWebViewExample& operator=(const UiWebViewExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiWebViewExample& operator=(UiWebViewExample&&) = delete;

protected:
  /**
   * Creates an instance of our UiWebViewExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;

  int init() override { return 0; }

  int deInit() override { return 0; }

};