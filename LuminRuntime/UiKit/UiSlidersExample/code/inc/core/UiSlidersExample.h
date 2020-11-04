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
#include <lumin/LandscapeApp.h>
#include <lumin/InitArg.h>
/**
 * This Lumin Runtime UiSliders Example showcases the default sliders
 * and progress bar of the Lumin Runtime UiKit.
 */
class UiSlidersExample : public lumin::LandscapeApp {
 public:
  /**
   * Constructs the UiSlidersExample.
   */
  UiSlidersExample();

  /**
   * Destroys the UiSlidersExample.
   */
  virtual ~UiSlidersExample();

  /**
   * Disallows the copy constructor.
   */
  UiSlidersExample(const UiSlidersExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiSlidersExample(UiSlidersExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiSlidersExample& operator=(const UiSlidersExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiSlidersExample& operator=(UiSlidersExample&&) = delete;

 protected:
  /**
   * Sets up our UiSlidersExample.
   */
  int init() override;

  /**
   * Destroys our UiSlidersExample.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiSlidersExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
