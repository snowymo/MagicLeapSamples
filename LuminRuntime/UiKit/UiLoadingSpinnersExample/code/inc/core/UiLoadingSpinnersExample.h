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
 * This example app will demonstrate the two loading spinners available in
 * the Lumin Runtime UiKit: the default Particle Spinner and Sprite Animation Spinner
 */
class UiLoadingSpinnersExample : public lumin::LandscapeApp {
 public:
 /**
  * Constructs the UiLoadingSpinners Example.
  */
  UiLoadingSpinnersExample();

 /**
  * Destroys the UiLoadingSpinners Example.
  */
  virtual ~UiLoadingSpinnersExample();

 /**
  * Disallows the copy constructor.
  */
  UiLoadingSpinnersExample(const UiLoadingSpinnersExample&) = delete;

 /**
  * Disallows the move constructor.
  */
  UiLoadingSpinnersExample(UiLoadingSpinnersExample&&) = delete;

 /**
  * Disallows the copy assignment operator.
  */
  UiLoadingSpinnersExample& operator=(const UiLoadingSpinnersExample&) = delete;

 /**
  * Disallows the move assignment operator.
  */
  UiLoadingSpinnersExample& operator=(UiLoadingSpinnersExample&&) = delete;

 protected:
 /**
  * Sets up our UiLoadingSpinners Example.
  */
  int init() override;

 /**
  * Destroys our UiLoadingSpinners Example.
  */
  int deInit() override;

  /**
   * Creates an instance of our UiLoadingSpinners Example.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
