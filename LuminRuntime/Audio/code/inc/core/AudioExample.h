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

// %SRC_VERSION%: 2

#pragma once
#include <lumin/LandscapeApp.h>
#include <BaseExampleController.h>

/**
 * AudioBaseApp is used to request and maintain prisms and audio resources.
 * Resources are deleted when the prism is deleted.
 */
class AudioBaseApp : public lumin::LandscapeApp {
 public:
  /**
   * Constructs the AudioBaseApp.
   */
  AudioBaseApp();

  /**
   * Destroys the AudioBaseApp.
   */
  virtual ~AudioBaseApp();

  /**
   * Returns true if an Audio Prism is in the application.
   */
  bool isAudioPrism() const;

  /**
   * Returns the Audio Prism. Only one Audio Prism is active in the application.
   * Audio Prisms do not participate in collisions, and have the UiCursor disabled.
   * @param size - optional size for the Audio Prism. Will only set the size of the prism if there
   *               is no other Audio Prism active in the application.
   * @return - the Audio Prism maintained by the AudioBaseApp.
   */
  std::weak_ptr<lumin::Prism> getAudioPrism(const glm::vec3& size = glm::vec3(1.0f, 0.4f, 1.0f));

  /**
   * Adds a callback to the Audio Prism that is executed when the Audio Prism is deleted.
   * @param callback - callback function with these parameters:
   *   @param Prism - the Audio Prism about to be deleted.
   * @return - the callback ID associated with the given callback function.
   */
  lumin::utils::CallbackID addPrismDeleter(const std::function<void(lumin::Prism*)>& callback);

  /**
   * Removes the callback function from the Audio Prism Deletion callback list.
   * @param callbackID - the callback ID of the callback function to remove.
   * @return - true if removed successfully, false otherwise.
   */
  bool removePrismDeleter(const lumin::utils::CallbackID& callbackID);

  /**
   * Deletes the Audio Prism if one is active in the application.
   * All audio resources are deleted when the Audio Prism is deleted.
   */
  void deleteAudioPrism();

  /**
   * Creates the given audio resource in the Audio Prism. If no Audio Prism is active, one will be created
   * with the given resource.
   * This will load the entire audio file in memory. If the audio file is large,
   * use createStreamedAudioResource() instead.
   * @param audioPath - relative path of the audio resource from the executable file.
   * @return - the ResourceIDType associated with the given resource.
   */
  lumin::ResourceIDType createAudioResource(const std::string& audioPath);

  /**
   * Creates the given audio resource in the Audio Prism. If no Audio Prism is active, one will be created
   * with the given resource.
   * This will load one chunk of the audio resource at a time in memory. For small files that should
   * be fully loaded into memory, use createAudioResource() instead.
   * @param audioPath - relative path of the streamed audio resource from the executable file.
   * @return - the ResourceIDType associated with the given resource.
   */
  lumin::ResourceIDType createStreamedAudioResource(const std::string& audioPath);

  /**
   * Gets all audio resources added to the Audio Prism if one is active.
   * These resources have all been fully loaded into memory, created with createAudioResource().
   * @return - vector of all audio resources added to the Audio Prism.
   */
  std::vector<lumin::ResourceIDType> getAudioResources() const;

  /**
   * Gets all audio resources added to the Audio Prism if one is active.
   * These resources have not been fully loaded into memory, created with createStreamedAudioResource().
   * @return - vector of all streamed audio resources added to the Audio Prism.
   */
  std::vector<lumin::ResourceIDType> getStreamedAudioResources() const;

  /**
   * Deletes all audio resources created with createAudioResource() and createStreamedAudioResource().
   */
  void deleteAllResources();

 protected:
  std::shared_ptr<lumin::Prism> audioPrism_;
  std::vector<std::pair<std::function<void(lumin::Prism*)>, lumin::utils::CallbackID>> customPrismDeleters_;
  std::vector<lumin::ResourceIDType> audioResources_;
  std::vector<lumin::ResourceIDType> streamedAudioResources_;
};

/**
 * This example app will demonstrate Lumin Runtime's AudioNode
 */
class AudioExample : public AudioBaseApp {
 public:
  /**
   * Constructs the Audio Example.
   */
  AudioExample();

  /**
   * Destroys the Audio Example.
   */
  virtual ~AudioExample();

  /**
   * Disallows the copy constructor.
   */
  AudioExample(const AudioExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  AudioExample(AudioExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  AudioExample& operator=(const AudioExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  AudioExample& operator=(AudioExample&&) = delete;

 protected:
  /**
   * Sets up our Audio Example.
   */
  int init() override;

  /**
   * Destroys our Audio Example.
   */
  int deInit() override;

  /**
   * Pauses our Audio Example.
   */
  void onAppPause() override;

  /**
   * Resumes our Audio Example.
   */
  void onAppResume() override;

 private:
  lumin::Prism* prism_ = nullptr;

  // Save our audio scene to play/pause audio.
  // The prism deletes this scene when it is destroyed.
  std::shared_ptr<lumin::SDKExamples::BaseExampleController> audioScene_ = nullptr;
};
