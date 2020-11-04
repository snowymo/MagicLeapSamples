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
#include <ControllerScene.h>
#include <lumin/LandscapeApp.h>
/**
 * This example app will demonstrate how to use Lumin Runtime's Controller Events.
 */
class ControllerExample : public lumin::LandscapeApp {
 public:
  /**
   * Constructs the Controller Example.
   */
  ControllerExample();

  /**
   * Destroys the Controller Example.
   */
  virtual ~ControllerExample();

  /**
   * Disallows the copy constructor.
   */
  ControllerExample(const ControllerExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  ControllerExample(ControllerExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  ControllerExample& operator=(const ControllerExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  ControllerExample& operator=(ControllerExample&&) = delete;

 protected:
  /**
   * Sets up our Controller Example.
   */
  int init() override;

  /**
   * Destroys our Controller Example.
   */
  int deInit() override;

 private:
  lumin::Prism* prism_ = nullptr;
};
