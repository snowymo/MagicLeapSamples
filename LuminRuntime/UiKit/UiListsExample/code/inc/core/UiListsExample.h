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
 * This Lumin Runtime UiLists example app will demonstrate the various list types
 * available in the Lumin Runtime UiKit: drop down lists, and list views.
 */
class UiListsExample : public lumin::LandscapeApp {
 public:
  /**
   * Constructs the UiListsExample.
   */
  UiListsExample();

  /**
   * Destroys the UiListsExample.
   */
  virtual ~UiListsExample();

  /**
   * Disallows the copy constructor.
   */
  UiListsExample(const UiListsExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiListsExample(UiListsExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiListsExample& operator=(const UiListsExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiListsExample& operator=(UiListsExample&&) = delete;

 protected:
  /**
   * Sets up our UiListsExample.
   */
  int init() override;

  /**
   * Destroys our UiListsExample.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiListsExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
