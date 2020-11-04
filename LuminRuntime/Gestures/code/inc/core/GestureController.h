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

#include <lumin/PrismController.h>
#include <lumin/Consts.h>
#include <ExamplesConstants.h>

#include <map>
#include <functional>
/**
 * The hand index value, returned from GestureInputEventData.
 * The left hand corresponds to 0. The right hand corresponds to 1.
 */
namespace lumin {
  enum HandType : uint32_t {
    kLeftHand = 0,
    kRightHand = 1
  };

  enum HandEvent : uint32_t {
    kHandStart = 0,    // Hand Gesture event started this frame.
    kHandContinue = 1, // Hand Gesture event is a continuation of the previous gesture event.
    kHandEnd = 2       // Hand Gesture event has ended this frame.
  };
}

/**
 * Callback signature for all gesture types.
 * param[in] HandType - The hand index value. 0 left hand, 1 right hand.
 * param[in] float - The confidence value for the associated gesture, [0, 1].
 *                   Note: this returns the confidence for the current Gesture Type,
 *                   not the confidence of the hand itself.
 * param[in] glm::vec3 - The position of the tracked hand, in world or prism space.
 * param[in] std::map - The map of keypoint names to positions for the tracked hand, in world or prism space.
 * param[in] HandEvent - The status of the gesture event: start, continue, or end.
 */
using GestureCallback = std::function<void(lumin::HandType /* hand index */, float /* confidence value */,
    glm::vec3& /* position */,
    std::map<lumin::input::HandGestureKeypointName, glm::vec3>& /* keypoints */,
    lumin::HandEvent)>;

/**
 * This is a generic helper controller to simplify using hand gestures.
 * Add this controller to the prism and subscribe to the gestures you
 * want callbacks for. Make sure to remove your callbacks when done.
 */
class GestureController : public lumin::PrismController {
public:
  /**
   * Constructor.
   * param[in] confidenceFilter - the minimum threshold of a gesture's confidence value to accept.
   * param[in] pollRate - the rate at which to poll for hand gesture events, in Hz.
   * param[in] space - the coordinate space to use for the hand gesture events.
   */
  GestureController(float confidenceFilter = 0.0f, float pollRate = 20.0f,
      lumin::ExampleConsts::CoordinateSpace space = lumin::ExampleConsts::CoordinateSpace::kPrism);

  /**
   * Destructor.
   */
  virtual ~GestureController();

  /**
   * Adds the callback for the gesture type.
   * NOTE: This function will automatically register the given tracked gesture type.
   * param[in] key - Whatever unique key you want to provide in order to enable gesture callback removal.
   *                 Keys must be unique per gesture type.
   * param[in] gestureType - The type of hand gesture to register the callback for.
   * param[in] callback - The callback to register.
   */
  void addGestureCallback(int64_t key, lumin::input::GestureType gestureType, GestureCallback callback);

  /**
   * Removes the callback for the gesture type.
   * NOTE: This function will automatically deregister the given tracked gesture if it is the last callback
   * for that gesture.
   * param[in] key - Whatever unique key you want to provide in order to enable gesture callback removal.
   * param[in] gestureType - The type of hand gesture to de-register the callback for.
   * param[in] callback - The callback to de-register.
   */
  void removeGestureCallback(int64_t key, lumin::input::GestureType gestureType, GestureCallback callback);

  /**
   * Returns the current coordinate space used: World Space or Prism Space.
   */
  lumin::ExampleConsts::CoordinateSpace getSpace() const;

  /**
   * Sets the current coordinate space used: World Space or Prism space.
   * To move to a different prism space, attach this controller to another prism.
   * @param space - coordinate space to set to.
   */
  bool setSpace(lumin::ExampleConsts::CoordinateSpace space);

private:
  /**
   * Sets the hand gesture confidence filter and poll rate for the given prism.
   * param[in] prism - the prism this controller will be attached to.
   */
  void onAttachPrism(lumin::Prism* prism) override;

  /**
   * Override to intercept server events for hand gestures.
   * param[in] event - the server event to intercept.
   * returns true if the event was consumed.
   */
  bool onEvent(lumin::ServerEvent* event) override;

private:

  // Container for all callbacks registered.
  static constexpr uint32_t kNumGestures = static_cast<uint32_t>(lumin::input::GestureType::HAND_NO_POSE) -
                                           static_cast<uint32_t>(lumin::input::GestureType::HAND_FINGER) + 1;
  using GestureCallbacks = std::map<int64_t, GestureCallback>;
  GestureCallbacks gestureCallbacks_[kNumGestures];
  float confidenceFilter_;
  float pollRate_;
  lumin::ExampleConsts::CoordinateSpace space_;
};
