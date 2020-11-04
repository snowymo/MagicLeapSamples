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

#include <lumin/LandscapeApp.h>
#include <lumin/Prism.h>
#include <lumin/event/ServerEvent.h>
#include <SceneDescriptor.h>

// Forward declarations.
class GestureController;
class GestureVisualizer;

/**
 * Gestures Landscape Application
 */
class Gestures : public lumin::LandscapeApp {
public:
  /**
   * Constructs the Landscape Application.
   */
  Gestures();

  /**
   * Destroys the Landscape Application.
   */
  virtual ~Gestures();

  /**
   * Disallows the copy constructor.
   */
  Gestures(const Gestures&) = delete;

  /**
   * Disallows the move constructor.
   */
  Gestures(Gestures&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  Gestures& operator=(const Gestures&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  Gestures& operator=(Gestures&&) = delete;

protected:
  /**
   * Initializes the Landscape Application.
   * @return - 0 on success, error code on failure.
   */
  int init() override;

  /**
   * Deinitializes the Landscape Application.
   * @return - 0 on success, error code on failure.
   */
  int deInit() override;

  /**
   * Returns the initial size of the Prism
   * Used in createPrism().
   */
  const glm::vec3 getInitialPrismSize() const;

  /**
   * Creates the prism, updates the private variable prism_ with the created prism.
   */
  void createInitialPrism();

  /**
   * Run application login
   */
  virtual bool updateLoop(float fDelta) override;

  /**
   * Handle events from the server
   */
  virtual bool eventListener(lumin::ServerEvent* event) override;

private:
  lumin::Prism* prism_ = nullptr;
  std::shared_ptr<GestureVisualizer> gestureVisualizer_;
};
