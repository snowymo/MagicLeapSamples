// %COPYRIGHT_BEGIN%
//
// Copyright (c) 2018 Magic Leap, Inc. All Rights Reserved.
// Use of this file is governed by the Creator Agreement, located
// here: https://id.magicleap.com/creator-terms
//
// %COPYRIGHT_END%
// ---------------------------------------------------------------------
// %BANNER_END%

// %SRC_VERSION%: 2

#include <lumin/LandscapeApp.h>
#include <lumin/InitArg.h>
/**
 * This Lumin Runtime UiButtons example app will demonstrate the
 * various button styles available in the Lumin Runtime UiKit.
 */
class UiButtonsExample : public lumin::LandscapeApp {
public:
  /**
   * Constructs the UiButtonsExample App.
   */
  UiButtonsExample();

  /**
   * Destroys the UiButtonsExample App.
   */
  virtual ~UiButtonsExample();

  /**
   * Disallows the copy constructor.
   */
  UiButtonsExample(const UiButtonsExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiButtonsExample(UiButtonsExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiButtonsExample& operator=(const UiButtonsExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiButtonsExample& operator=(UiButtonsExample&&) = delete;

protected:
  /**
   * Sets up our UiButtonsExample.
   */
  int init() override;

  /**
   * Destroys our UiButtonsExample.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiButtonsExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
