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
 * This Lumin Runtime UiCircleConfirmation Example app will showcase the Lumin Runtime UiKit.
 * This example displays the circle confirmation widget and the status of the widget
 * The UiCircleConfirmation node must be reset once it has completed a rotation.
 * This example uses nodes created with the Lumin Runtime Editor.
 */
class UiCircleConfirmationExample : public lumin::LandscapeApp {
public:
  /**
   * Constructs the UiCircleConfirmationExample.
   */
  UiCircleConfirmationExample();

  /**
   * Destroys the UiCircleConfirmationExample.
   */
  virtual ~UiCircleConfirmationExample();

  /**
   * Disallows the copy constructor.
   */
  UiCircleConfirmationExample(const UiCircleConfirmationExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiCircleConfirmationExample(UiCircleConfirmationExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiCircleConfirmationExample& operator=(const UiCircleConfirmationExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiCircleConfirmationExample& operator=(UiCircleConfirmationExample&&) = delete;

protected:
  /**
   * Sets up our UiCircleConfirmationExample.
   */
  int init() override;

  /**
   * Destroys our UiCircleConfirmationExample.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiCircleConfirmationExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
