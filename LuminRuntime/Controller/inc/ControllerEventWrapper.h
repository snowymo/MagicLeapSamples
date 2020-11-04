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
#include <lumin/Consts.h>
#include <lumin/Prism.h>
#include <lumin/event/ServerEvent.h>
#include <lumin/event/RayCastEventData.h>
#include <lumin/utils/CallbackID.h>
/**
 * Parameters for the Event Wrapper Callback functions.
 */
namespace lumin {
  namespace EventWrappers {
    /**
     * Controller Touchpad Data returned as a parameter to Controller Touchpad Functions
     */
    struct ControllerTouchpadData {
      input::GestureType type;           // type of Controller Gesture, is NONE for Control Touchpad Events
      input::GestureDirection direction; // direction of Controller Gesture
      float speed;                       // speed of Controller Gesture
      float distance;                    // distance of Controller Gesture
      float fingerGap;                   // distance between two fingers
      float radius;                      // radius of Controller Gesture (for radial gestures)
      float angle;                       // angle from center of touchpad to finger
      float force;                       // force/pressure value of Controller gesture
      const glm::vec2 location;          // location of Controller gesture
      std::vector<glm::vec3> positions;  // vector of all touchpad positions
                                         // (x, y): position of touch, in [-1, 1]
                                         // z: force of touch, in [0, 1]
      uint32_t count;                    // total touch count
      bool isActive;                     // touch state, true if the touch is active
      bool isMulti;                      // true if the touch is multi touch, false if single touch
    };
    /**
     * Controller Trigger Data returned as a parameter to Controller Trigger Callback Functions
     */
    struct ControllerTriggerData {
      input::GestureType type;
      int32_t force;  // force/pressure value of Trigger gesture, in [0, 255]
    };
  }
}
/**
 * Controller Event Wrapper
 * Provides an interface for controller event callbacks. (MLMCA, Control)
 * Users may subscribe to an event by adding their callback function, this returns a callback ID
 * which may be used to unsubscribe their callback from the event.
 * Example Usage:
 *   // Subscribe myCallbackFunction to the onTrigger Event:
 *   // myCallbackFunction must have: (EventWrappers::ControllerTriggerData&) as a parameter.
 *   // When the onTrigger Event is returned, the subscribed callbacks are called.
 *   ControllerEventWrapper controllerEventWrapper;  // construct the controller event wrapper
 *   CallbackID myCallbackID = controllerEventWrapper.onTriggerSub(myCallbackFunction);
 *
 *   // Unsubscribe myCallbackFunction from the onTrigger Event:
 *   controllerEventWrapper.onTriggerUnsub(myCallbackID);
 *
 * NOTE: to trigger the event callbacks, the ControllerEventWrapper's eventDispatcher function
 * must called on the Client Thread's Event Listener:
 * (eventListener() for Landscape Apps, or onEvent() for Prism Controllers.)
 * Example usage:
 *   bool eventListener(ServerEvent* event) {
 *     return controllerEventWrapper.eventDispatcher(event);
 *   }
 * NOTE: the callback subscription functions are not thread safe.
 */
class ControllerEventWrapper final {
 public:
  /**
   * Initializes the Controller Event Wrapper.
   */
  ControllerEventWrapper();

  /**
   * Destroys the Controller Event Wrapper.
   */
  virtual ~ControllerEventWrapper();

  /**
   * Disallows the copy constructor.
   */
  ControllerEventWrapper(const ControllerEventWrapper&) = delete;

  /**
   * Disallows the move constructor.
   */
  ControllerEventWrapper(ControllerEventWrapper&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  ControllerEventWrapper& operator=(const ControllerEventWrapper&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  ControllerEventWrapper& operator=(ControllerEventWrapper&&) = delete;

  /**
   * Dispatches the controller events returned from the given server event.
   * @param a_pEvent - returned Server Event
   */
  bool eventDispatcher(const lumin::ServerEvent* a_pEvent);

  /**
   * Resets the callback list for every event.
   */
  void clearAll();

  /**
   * Returns the Source of the Controller Event: Control, Companion App, etc.
   * NOTE: returns the most recent source of the controller events received.
   * @return - the enum value of the event source.
   */
  lumin::input::EventSource getEventSource();

  /**
   * Returns the device id of the controller event.
   * NOTE: returns the most recent device ID of the controller events received.
   *       a negative device id indicates no device id received.
   * @return - the device id
   */
  int32_t getDeviceID();

  /**
   * The on Connection Changed Event.
   * This event is dispatched when controller devices change connection.
   * @param callback - callback function
   *    @param int21_t         - the device id
   *    @param EventSource     - the source of the device: Control, Companion App, etc.
   *    @param DeviceEventType - describes the type of event that has occurred
   *    @param bool            - true if the device is connected, false otherwise
   * @return - the callback ID associated with the given callback function
   */
  lumin::utils::CallbackID onConnectionChangedSub(const std::function<void(
      int32_t, lumin::input::EventSource, lumin::input::DeviceEventType, bool)>& callback);

  /**
   * Unsubscribes the callback function from the on Connection Changed event.
   * @param callbackID - the callback ID of the callback function
   * @return - true if unsubscribed successfully, false otherwise
   */
  bool onConnectionChangedUnsub(const lumin::utils::CallbackID& callbackID);

  /**
   * The on Trigger Event.
   * This event is dispatched when the controller's trigger is used.
   * @param callback - callback function with these parameters:
   *   @param ControllerTriggerData - returned trigger data
   * @return - the callback ID associated with the given callback function
   */
  lumin::utils::CallbackID onTriggerSub(const std::function<void(
      const lumin::EventWrappers::ControllerTriggerData&)>& callback);

  /**
   * Unsubscribes the callback function from the on Trigger Event.
   * @param callbackID - the callback ID of the callback function
   * @return - true if unsubscribed successfully, false otherwise
   */
  bool onTriggerUnsub(const lumin::utils::CallbackID& callbackID);

  /**
   * The on 6DOF Move Event.
   * This event is dispatched when a 6DOF controller moves.
   * Subscribes the given callback function to this event.
   *
   * @param callback - callback function with these parameters:
   *    @param glm::quat - returned quaternion rotation
   *    @param glm::vec3 - returned position
   * @return - the callback ID associated with the given callback function
   */
  lumin::utils::CallbackID on6DOFmoveSub(const std::function<void(const glm::quat&,
      const glm::vec3&)>& callback);

  /**
   * Unsubscribes the callback function from the on 6DOF Move Event.
   * @param callbackID - the callback ID of the callback function
   * @return - true if unsubscribed successfully, false otherwise
   */
  bool on6DOFmoveUnsub(const lumin::utils::CallbackID& callbackID);

  /**
   * The on 3DOF Move Event.
   * This event is dispatched when a 3DOF controller moves.
   * Subscribes the given callback function to this event.
   *
   * @param callback - callback function with these parameters:
   *   @param glm::quat - returned quaternion rotation
   * @return - the callback ID associated with the given callback function
   */
  lumin::utils::CallbackID on3DOFmoveSub(const std::function<void(const glm::quat&)>& callback);

  /**
   * Unsubscribes the callback function from the on 3DOF Move Event.
   * @param callbackID - the callback ID of the callback function
   * @return - true if unsubscribed successfully, false otherwise
   */
  bool on3DOFmoveUnsub(const lumin::utils::CallbackID& callbackID);

  /**
   * The on Touch Pad Event.
   * This event is dispatched when the controller's touch pad is touched.
   * Subscribes the given callback function to this event.
   *
   * @param callback - callback function with these parameters:
   *   @param ControllerTouchpadData - returned touchpad data
   * @return - the callback ID associated with the given callback function
   */
  lumin::utils::CallbackID onTouchpadSub(const std::function<void(
      const lumin::EventWrappers::ControllerTouchpadData&)>& callback);

  /**
   * Unsubscribes the callback function from the on touch pad Event.
   * @param callbackID - the callback ID of the callback function
   * @return - true if unsubscribed successfully, false otherwise
   */
  bool onTouchpadUnsub(const lumin::utils::CallbackID& callbackID);

 private:
  // Controller callback lists:
  std::vector<std::pair<std::function<void(int32_t,
      lumin::input::EventSource, lumin::input::DeviceEventType, bool)>,
      lumin::utils::CallbackID>> onConnectionChangedCallbacks_;
  std::vector<std::pair<std::function<void(const lumin::EventWrappers::ControllerTriggerData&)>,
      lumin::utils::CallbackID>> onTriggerCallbacks_;
  std::vector<std::pair<std::function<void(const glm::quat&,
      const glm::vec3&)>, lumin::utils::CallbackID>> on6DOFmoveCallbacks_;
  std::vector<std::pair<std::function<void(const glm::quat&)>,
      lumin::utils::CallbackID>> on3DOFmoveCallbacks_;
  std::vector<std::pair<std::function<void(
      const lumin::EventWrappers::ControllerTouchpadData&)>,
      lumin::utils::CallbackID>> onTouchpadCallbacks_;

  lumin::input::EventSource eventSource_;
  int32_t deviceID_;
};