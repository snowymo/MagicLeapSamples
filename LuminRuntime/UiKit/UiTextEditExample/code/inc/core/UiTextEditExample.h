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
 * This Lumin Runtime UiTextEdit Example app will showcase the default text edit entries of
 * the Lumin Runtime UiKit.
 */
class UiTextEditExample : public lumin::LandscapeApp {
 public:
 /**
  * Constructs the UiTextEdit Example.
  */
  UiTextEditExample();

 /**
  * Destroys the UiTextEdit Example.
  */
  virtual ~UiTextEditExample();

 /**
  * Disallows the copy constructor.
  */
  UiTextEditExample(const UiTextEditExample&) = delete;

 /**
  * Disallows the move constructor.
  */
  UiTextEditExample(UiTextEditExample&&) = delete;

 /**
  * Disallows the copy assignment operator.
  */
  UiTextEditExample& operator=(const UiTextEditExample&) = delete;

 /**
  * Disallows the move assignment operator.
  */
  UiTextEditExample& operator=(UiTextEditExample&&) = delete;

 protected:
 /**
  * Sets up our UiTextEdit Example.
  */
  int init() override;

 /**
  * Destroys our UiTextEdit Example.
  */
  int deInit() override;

  /**
   * Creates an instance of our UiTextEdit Example.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
