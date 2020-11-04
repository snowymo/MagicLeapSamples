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
 * This example displays the types of dialogs offered in the UiKit: modal, modeless, single action,
 * dual action, and timed dialogs.
 */
class UiDialogsExample : public lumin::LandscapeApp {
public:
  /**
   * Constructs the UiDialogs Example.
   */
  UiDialogsExample();

  /**
   * Destroys the UiDialogs Example.
   */
  virtual ~UiDialogsExample();

  /**
   * Disallows the copy constructor.
   */
  UiDialogsExample(const UiDialogsExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiDialogsExample(UiDialogsExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiDialogsExample& operator=(const UiDialogsExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiDialogsExample& operator=(UiDialogsExample&&) = delete;

protected:
  /**
   * Sets up our UiDialogs Example.
   */
  int init() override;

  /**
   * Destroys our UiDialogs Example.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiDialogs Example.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
