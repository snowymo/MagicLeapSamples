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
 * This example displays every default Eclipse Label Type. These label types are
 * used with UiText nodes to change the size, boldness, and case. A brief description
 * of each label type is displayed next to the name of each type.
 */
class UiLabelsExample : public lumin::LandscapeApp {
 public:
  /**
   * Constructs the UiLabels Example.
   */
  UiLabelsExample();

  /**
   * Destroys the UiLabels Example.
   */
  virtual ~UiLabelsExample();

  /**
   * Disallows the copy constructor.
   */
  UiLabelsExample(const UiLabelsExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiLabelsExample(UiLabelsExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiLabelsExample& operator=(const UiLabelsExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiLabelsExample& operator=(UiLabelsExample&&) = delete;

 protected:
  /**
   * Sets up our UiLabelsExample.
   */
  int init() override;

  /**
   * Destroys our UiLabelsExample.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiLabelsExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
