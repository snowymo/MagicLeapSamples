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
#include <BaseExampleController.h>
#include <lumin/LandscapeApp.h>
/**
 * This example app will demonstrate Lumin Runtime's VideoNode
 */
class VideoExample : public lumin::LandscapeApp {
 public:
  /**
   * Constructs the Video Example.
   */
  VideoExample();

  /**
   * Destroys the Video Example.
   */
  virtual ~VideoExample();

  /**
   * Disallows the copy constructor.
   */
  VideoExample(const VideoExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  VideoExample(VideoExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  VideoExample& operator=(const VideoExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  VideoExample& operator=(VideoExample&&) = delete;

 protected:
  /**
   * Sets up our Video Example.
   */
  int init() override;

  /**
   * Destroys our Video Example.
   */
  int deInit() override;

  /**
   * Pauses our Video Example.
   */
  void onAppPause() override;

  /**
   * Resumes our Video Example.
   */
  void onAppResume() override;

 private:
  lumin::Prism* prism_ = nullptr;

  // Save our video scene to play/pause videos; the prism deletes this scene when it is destroyed.
  lumin::SDKExamples::BaseExampleController* videoScene_ = nullptr;
};
