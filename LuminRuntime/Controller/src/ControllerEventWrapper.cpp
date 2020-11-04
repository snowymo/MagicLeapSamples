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
#include <ControllerEventWrapper.h>
#include <ExamplesDefines.h>
#include <lumin/event/KeyInputEventData.h>
#include <lumin/event/InputDeviceEvent.h>
#include <lumin/event/ControlTouchPadInputEventData.h>
#include <lumin/event/ControlPose3DofInputEventData.h>
#include <lumin/event/ControlPose6DofInputEventData.h>
#include <lumin/event/GestureInputEventData.h>
#include <ml_logging.h>

using namespace lumin;

ControllerEventWrapper::ControllerEventWrapper()
: eventSource_(lumin::input::EventSource::UNKNOWN),
  deviceID_(-1) {
}

ControllerEventWrapper::~ControllerEventWrapper() {
}

// Resets the callback list for every event:
void ControllerEventWrapper::clearAll() {
  onConnectionChangedCallbacks_.clear();
  onTriggerCallbacks_.clear();
  on6DOFmoveCallbacks_.clear();
  on3DOFmoveCallbacks_.clear();
  onTouchpadCallbacks_.clear();
}

lumin::input::EventSource ControllerEventWrapper::getEventSource() {
  return eventSource_;
}

int32_t ControllerEventWrapper::getDeviceID() {
  return deviceID_;
}

// Update the controller data given the server event, and call the corresponding callback functions.
// Return true if the controller data was updated:
bool ControllerEventWrapper::eventDispatcher(const lumin::ServerEvent* a_pEvent) {
  LUMIN_ASSERT(a_pEvent != nullptr, "ControllerEventWrapper::eventDispatcher - received invalid Server Event");
  bool updated = false;

  if (a_pEvent->isServerEventTypeValue(InputDeviceEvent::GetServerEventTypeValue())) {
    const InputDeviceEvent* inputDeviceEvent = InputDeviceEvent::CastFrom(a_pEvent);
    input::DeviceEventType type              = inputDeviceEvent->getEventType();
    if (type != input::DeviceEventType::STATE_CHANGE) {
      deviceID_    = inputDeviceEvent->getDeviceId();
      eventSource_ = inputDeviceEvent->getSource();
      updated      = true;
      for (auto functionHolder : onConnectionChangedCallbacks_) {
        functionHolder.first(deviceID_, eventSource_, type, inputDeviceEvent->isConnected());
      }
    }
  }

  // look for controller input events:
  if (a_pEvent->isInputEventType()) {
    const InputEventData* inputEventData = InputEventData::CastFrom(a_pEvent);
    const input::EventType eventType     = inputEventData->getEventType();
    eventSource_                         = inputEventData->getEventSource();
    deviceID_                            = inputEventData->getDeviceId();

    if (inputEventData->isServerEventTypeValue(KeyInputEventData::GetServerEventTypeValue())) {
      const KeyInputEventData* keyEventData = KeyInputEventData::CastFrom(inputEventData);

      if (keyEventData->keyCode() == input::KeyCodes::AKEYCODE_EX_TRIGGER) {
        updated = true;
        EventWrappers::ControllerTriggerData&& data = {
            lumin::input::GestureType::NONE,
            keyEventData->keyVal()};  // get the force value of the trigger event
        if (eventType == lumin::input::EventType::EVENT_KEY_DOWN) {
          data.type = lumin::input::GestureType::TriggerDown;
        } else if (eventType == lumin::input::EventType::EVENT_KEY_UP) {
          data.type = lumin::input::GestureType::TriggerUp;
        } else if (eventType == lumin::input::EventType::EVENT_KEY_LONG_DOWN) {
          data.type = lumin::input::GestureType::TriggerHold;
        }
        for (auto functionHolder : onTriggerCallbacks_) {
          functionHolder.first(data);
        }
      }
    }

    // call all the callbacks for the returned controller event:
    switch (eventType) {
      case lumin::input::EventType::EVENT_POSE_6DOF: {
        const ControlPose6DofInputEventData* controllerPose6DofInputEventData =
            static_cast<const ControlPose6DofInputEventData*>(inputEventData);
        glm::quat rotation;
        glm::vec3 position;
        controllerPose6DofInputEventData->getQuaternion(rotation.w, rotation.x, rotation.y, rotation.z);
        controllerPose6DofInputEventData->get6DofPosition(position.x, position.y, position.z);
        updated = true;
        for (auto functionHolder : on6DOFmoveCallbacks_) {
          functionHolder.first(rotation, position);
        }
        break;
      }
      case lumin::input::EventType::EVENT_POSE_3DOF: {
        const ControlPose3DofInputEventData* controllerPose3DofInputEventData =
            static_cast<const ControlPose3DofInputEventData*>(inputEventData);
        glm::quat rotation;
        controllerPose3DofInputEventData->getQuaternion(rotation.w, rotation.x, rotation.y, rotation.z);
        updated = true;
        for (auto functionHolder : on3DOFmoveCallbacks_) {
          functionHolder.first(rotation);
        }
        break;
      }
      case lumin::input::EventType::EVENT_CONTROL_TOUCHPAD: {
        const ControlTouchPadInputEventData* touchpadInputEventData =
            static_cast<const ControlTouchPadInputEventData*>(inputEventData);
        uint32_t touchCount = touchpadInputEventData->getTouchCount();
        std::vector<glm::vec3> touchPositions(touchCount);
        for (uint32_t i = 0; i < touchCount; ++i) {
          touchpadInputEventData->getTouch(touchPositions[i].x,
            touchPositions[i].y, touchPositions[i].z, i);
        }
        EventWrappers::ControllerTouchpadData data;
        data.type      = lumin::input::GestureType::NONE;
        data.positions = touchPositions;
        data.count     = touchCount;
        data.isActive  = touchpadInputEventData->getTouchState();
        data.isMulti   = touchpadInputEventData->isMultiTouch();
        updated        = true;
        for (auto functionHolder : onTouchpadCallbacks_) {
          functionHolder.first(data);
        }
        break;
      }
      case lumin::input::EventType::EVENT_CONTROL_GESTURE: {
        const GestureInputEventData* gestureInputEventData =
            static_cast<const GestureInputEventData*>(inputEventData);
        input::GestureType type = gestureInputEventData->getGesture();
        glm::vec2 location;
        gestureInputEventData->getGestureLocation(location.x, location.y);
        uint32_t touchCount = gestureInputEventData->getTouchCount();
        std::vector<glm::vec3> touchPositions(touchCount);
        for (uint32_t i = 0; i < touchCount; ++i) {
          gestureInputEventData->getTouch(touchPositions[i].x,
            touchPositions[i].y, touchPositions[i].z, i);
        }
        EventWrappers::ControllerTouchpadData&& data = {
            type,
            gestureInputEventData->getGestureDirection(),
            gestureInputEventData->getGestureSpeed(),
            gestureInputEventData->getGestureDistance(),
            gestureInputEventData->getGestureFingerGap(),
            gestureInputEventData->getGestureRadius(),
            gestureInputEventData->getGestureAngle(),
            gestureInputEventData->getGestureForceValue(),
            location, touchPositions, touchCount,
            gestureInputEventData->getTouchState(),
            gestureInputEventData->isMultiTouch()};
        if (type >= input::GestureType::Scroll && type <= input::GestureType::Swipe) {
          updated = true;
          for (auto functionHolder : onTouchpadCallbacks_) {
            functionHolder.first(data);
          }
        } else if (type >= input::GestureType::TriggerDown && type <= input::GestureType::TriggerHold) {
          updated = true;
          EventWrappers::ControllerTriggerData&& triggerData = {
              type, static_cast<int32_t>(gestureInputEventData->getGestureForceValue())};
          for (auto functionHolder : onTriggerCallbacks_) {
            functionHolder.first(triggerData);
          }
        }
        break;
      }
      // ignore input events from a source other than a controller:
      default: {
        break;
      }
    }
  }
  return updated;
}

lumin::utils::CallbackID ControllerEventWrapper::onConnectionChangedSub(const std::function<void(int32_t,
    lumin::input::EventSource, lumin::input::DeviceEventType, bool)>& callback) {
  lumin::utils::CallbackID callbackID;
  onConnectionChangedCallbacks_.emplace_back(std::make_pair(callback, callbackID));
  return callbackID;
}

bool ControllerEventWrapper::onConnectionChangedUnsub(const lumin::utils::CallbackID& callbackID) {
  for (auto it = onConnectionChangedCallbacks_.begin(); it != onConnectionChangedCallbacks_.end(); ++it) {
    if ((*it).second == callbackID) {
      onConnectionChangedCallbacks_.erase(it);
      return true;
    }
  }
  return false;
}

lumin::utils::CallbackID ControllerEventWrapper::onTriggerSub(const std::function<void(
    const lumin::EventWrappers::ControllerTriggerData&)>& callback) {
  lumin::utils::CallbackID callbackID;
  onTriggerCallbacks_.emplace_back(std::make_pair(callback, callbackID));
  return callbackID;
}

bool ControllerEventWrapper::onTriggerUnsub(const lumin::utils::CallbackID& callbackID) {
  for (auto it = onTriggerCallbacks_.begin(); it != onTriggerCallbacks_.end(); ++it) {
    if ((*it).second == callbackID) {
      onTriggerCallbacks_.erase(it);
      return true;
    }
  }
  return false;
}

lumin::utils::CallbackID ControllerEventWrapper::on6DOFmoveSub(const std::function<void(
    const glm::quat&, const glm::vec3&)>& callback) {
  lumin::utils::CallbackID callbackID;
  on6DOFmoveCallbacks_.emplace_back(std::make_pair(callback, callbackID));
  return callbackID;
}

bool ControllerEventWrapper::on6DOFmoveUnsub(const lumin::utils::CallbackID& callbackID) {
  for (auto it = on6DOFmoveCallbacks_.begin(); it != on6DOFmoveCallbacks_.end(); ++it) {
    if ((*it).second == callbackID) {
      on6DOFmoveCallbacks_.erase(it);
      return true;
    }
  }
  return false;
}

lumin::utils::CallbackID ControllerEventWrapper::on3DOFmoveSub(const std::function<void(
    const glm::quat&)>& callback) {
  lumin::utils::CallbackID callbackID;
  on3DOFmoveCallbacks_.emplace_back(std::make_pair(callback, callbackID));
  return callbackID;
}

bool ControllerEventWrapper::on3DOFmoveUnsub(const lumin::utils::CallbackID& callbackID) {
  for (auto it = on3DOFmoveCallbacks_.begin(); it != on3DOFmoveCallbacks_.end(); ++it) {
    if ((*it).second == callbackID) {
      on3DOFmoveCallbacks_.erase(it);
      return true;
    }
  }
  return false;
}

lumin::utils::CallbackID ControllerEventWrapper::onTouchpadSub(const std::function<void(
    const lumin::EventWrappers::ControllerTouchpadData&)>& callback) {
  lumin::utils::CallbackID callbackID;
  onTouchpadCallbacks_.emplace_back(std::make_pair(callback, callbackID));
  return callbackID;
}

bool ControllerEventWrapper::onTouchpadUnsub(const lumin::utils::CallbackID& callbackID) {
  for (auto it = onTouchpadCallbacks_.begin(); it != onTouchpadCallbacks_.end(); ++it) {
    if ((*it).second == callbackID) {
      onTouchpadCallbacks_.erase(it);
      return true;
    }
  }
  return false;
}
