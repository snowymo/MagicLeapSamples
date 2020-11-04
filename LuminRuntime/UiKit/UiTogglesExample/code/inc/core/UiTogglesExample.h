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
 * This Lumin Runtime UiToggles example app will demonstrate the
 * various toggle styles available in the Lumin Runtime UiKit.
 */
class UiTogglesExample : public lumin::LandscapeApp {
public:
  /**
   * Constructs the UiTogglesExample App.
   */
  UiTogglesExample();

  /**
   * Destroys the UiTogglesExample App.
   */
  virtual ~UiTogglesExample();

  /**
   * Disallows the copy constructor.
   */
  UiTogglesExample(const UiTogglesExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiTogglesExample(UiTogglesExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiTogglesExample& operator=(const UiTogglesExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiTogglesExample& operator=(UiTogglesExample&&) = delete;

protected:
  /**
   * Sets up our UiTogglesExample.
   */
  int init() override;

  /**
   * Destroys our UiTogglesExample.
   */
  int deInit() override;

  /**
   * Creates an instance of our UTogglesExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
