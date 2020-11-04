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
 * This example displays every default System Icon in the Lumin Runtime UiKit.
 */
class UiSystemIconsExample : public lumin::LandscapeApp {
 public:
  /**
   * Constructs the UiSystemIcons Example.
   */
  UiSystemIconsExample();

  /**
   * Destroys the UiSystemIcons Example.
   */
  virtual ~UiSystemIconsExample();

  /**
   * Disallows the copy constructor.
   */
  UiSystemIconsExample(const UiSystemIconsExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiSystemIconsExample(UiSystemIconsExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiSystemIconsExample& operator=(const UiSystemIconsExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiSystemIconsExample& operator=(UiSystemIconsExample&&) = delete;

 protected:
  /**
   * Sets up our UiSystemIconsExample.
   */
  int init() override;

  /**
   * Destroys our UiSystemIconsExample.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiSystemIconsExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
