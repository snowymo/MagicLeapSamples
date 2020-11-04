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
 * This Lumin Runtime example app will demonstrate the various portal icons
 * available in the Lumin Runtime UiKit.
 */
class UiPortalIconsExample : public lumin::LandscapeApp {
public:
  /**
   * Constructs the UiPortalIcons Example.
   */
  UiPortalIconsExample();

  /**
   * Destroys the UiPortalIcons Example.
   */
  virtual ~UiPortalIconsExample();

  /**
   * Disallows the copy constructor.
   */
  UiPortalIconsExample(const UiPortalIconsExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiPortalIconsExample(UiPortalIconsExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiPortalIconsExample& operator=(const UiPortalIconsExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiPortalIconsExample& operator=(UiPortalIconsExample&&) = delete;

protected:
  /**
   * Sets up our UiPortalIcons Example.
   */
  int init() override;

  /**
   * Destroys our UiPortalIcons Example.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiPortalIcons Example.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
