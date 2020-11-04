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

#include <GestureController.h>
#include <ExamplesDefines.h>
#include <ExamplesHelpers.h>
#include <lumin/Prism.h>
#include <lumin/event/GestureInputEventData.h>
#include <lumin/node/TransformNode.h>
#include <lumin/ui/node/UiImage.h>
#include <lumin/ui/node/UiText.h>

using namespace lumin;
using namespace lumin::input;

namespace {
  uint32_t handGestureTypeToFlag(GestureType type) {
    if (GestureType::HAND_FINGER <= type && GestureType::HAND_C >= type) {
      switch (type) {
        case GestureType::HAND_FINGER: {
          return static_cast<uint32_t>(HandGestureFlags::kHandFinger);
        }
        case GestureType::HAND_FIST: {
          return static_cast<uint32_t>(HandGestureFlags::kHandFist);
        }
        case GestureType::HAND_PINCH: {
          return static_cast<uint32_t>(HandGestureFlags::kHandPinch);
        }
        case GestureType::HAND_THUMB: {
          return static_cast<uint32_t>(HandGestureFlags::kHandThumb);
        }
        case GestureType::HAND_L: {
          return static_cast<uint32_t>(HandGestureFlags::kHandL);
        }
        case GestureType::HAND_OPENHANDBACK: {
          return static_cast<uint32_t>(HandGestureFlags::kHandOpenHandBack);
        }
        case GestureType::HAND_OK: {
          return static_cast<uint32_t>(HandGestureFlags::kHandOk);
        }
        case GestureType::HAND_C: {
          return static_cast<uint32_t>(HandGestureFlags::kHandC);
        }
        default: {
          return 0; // ignore other hand gestures
        }
      }
    }
    return 0;
  }
}

GestureController::GestureController(float confidenceFilter, float pollRate, ExampleConsts::CoordinateSpace space)
: PrismController("GestureController"),
  confidenceFilter_(confidenceFilter),
  pollRate_(pollRate),
  space_(space) {

}

GestureController::~GestureController() {

}

void GestureController::onAttachPrism(Prism* prism) {
  prism->setHandGestureFilterConfidenceLevel(confidenceFilter_);
  prism->setHandGestureFilterPollRate(pollRate_);
  prism->setHandGestureTouchDistance(0.1f);
  prism->setHandGestureHoverDistance(0.1f);
}

void GestureController::addGestureCallback(int64_t key, GestureType gestureType, GestureCallback callback) {

  // Assert this is a hand gesture and then map into array space and add it.
  // The first time this gesture type is registered enable tracking.
  if (GestureType::HAND_FINGER <= gestureType && GestureType::HAND_NO_POSE >= gestureType) {
    uint32_t gestureIndex = static_cast<uint32_t>(gestureType) - static_cast<uint32_t>(GestureType::HAND_FINGER);
    gestureCallbacks_[gestureIndex][key] = callback;
    if (gestureType != GestureType::HAND_NO_POSE) {
      if (gestureCallbacks_[gestureIndex].size() == 1) {
        Prism* prism = getPrism();
        LUMIN_ASSERT(prism, "GestureController::addGestureCallback(): GestureController must be added to prism to call this.");
        uint32_t tracked = prism->getUserHandGesture();
        prism->startTrackHandGesture(tracked | handGestureTypeToFlag(gestureType));
      }
    }
  } else {
    LUMIN_ASSERT(false, "GestureController::addGestureCallack(): GestureType unsupported.");
  }
}

void GestureController::removeGestureCallback(int64_t key, GestureType gestureType, GestureCallback callback) {
  // Deregister hand gestures if they are the last callback:
  if (GestureType::HAND_FINGER <= gestureType && GestureType::HAND_NO_POSE >= gestureType) {
    uint32_t gestureIndex = static_cast<uint32_t>(gestureType) - static_cast<uint32_t>(GestureType::HAND_FINGER);
    LUMIN_ASSERT(gestureCallbacks_[gestureIndex].find(key) != gestureCallbacks_[gestureIndex].end(),
        "GestureController::removeGestureCallback(): Can't find context key to remove callback.");
    gestureCallbacks_[gestureIndex].erase(key);

   // Remove gesture no pose events without deregistering hand gestures:
    if (gestureType != GestureType::HAND_NO_POSE) {
      if (gestureCallbacks_[gestureIndex].size() == 0) {
        Prism* prism = getPrism();
        LUMIN_ASSERT(prism, "GestureController::removeGestureCallback(): GestureController must be added to prism to call this.");
        prism->stopTrackHandGesture(handGestureTypeToFlag(gestureType));
      }
    }
  }
}

ExampleConsts::CoordinateSpace GestureController::getSpace() const {
  return space_;
}

bool GestureController::setSpace(ExampleConsts::CoordinateSpace space) {
  space_ = space;
  return true;
}

bool GestureController::onEvent(lumin::ServerEvent* event) {

  // Extract out the event data and ensure it's a hand gesture event we care to handle.
  LUMIN_ASSERT(event, "GestureController::onEvent(): Invalid event.");
  lumin::ServerEventTypeValue serverEventType = event->getServerEventTypeValue();

  if (lumin::GestureInputEventData::GetServerEventTypeValue() == serverEventType) {
    const GestureInputEventData* gestureEventData = static_cast<lumin::GestureInputEventData*>(event);
    const GestureType gestureType = gestureEventData->getGesture();

    // Handle hand gestures and make all callbacks for that gesture type.
    if (GestureType::HAND_FINGER <= gestureType && gestureType <= GestureType::HAND_NO_POSE ) {
      int32_t gestureTypeIndex = (int32_t)gestureType - (int32_t)GestureType::HAND_FINGER;
      HandType handIndex       = (gestureEventData->getHandGestureIndex())? HandType::kRightHand : HandType::kLeftHand;
      HandEvent handEvent      = HandEvent::kHandStart;
      EventType eventType      = static_cast<lumin::InputEventData*>(event)->getEventType();
      glm::vec3 handPosition, keypoint;
      if (eventType == lumin::input::EventType::EVENT_GESTURE_CONTINUE) {
        handEvent = HandEvent::kHandContinue;
      } else if (eventType == lumin::input::EventType::EVENT_GESTURE_END) {
        handEvent = HandEvent::kHandEnd;
      }

      gestureEventData->getHandGestureLocation(handPosition.x, handPosition.y, handPosition.z);
      if (space_ == ExampleConsts::CoordinateSpace::kPrism) {
        handPosition = ExampleHelpers::worldToPrismSpace(getPrism(), handPosition);
      }
      std::map<HandGestureKeypointName, glm::vec3> keypoints;
      for (uint32_t i = (uint32_t)HandGestureKeypointName::NONE; i
          <= (uint32_t)HandGestureKeypointName::WRIST_THUMB_SIDE; ++i) {
        HandGestureKeypointName keypointName = static_cast<HandGestureKeypointName>(i);
        gestureEventData->getHandGestureKeypoint(keypointName, keypoint.x, keypoint.y, keypoint.z);
        if (space_ == ExampleConsts::CoordinateSpace::kPrism) {
          keypoint = ExampleHelpers::worldToPrismSpace(getPrism(), keypoint);
        }
        if (keypoint != lumin::VEC3_ZERO) {
          keypoints[keypointName] = keypoint;
        }
      }

      for (auto it = gestureCallbacks_[gestureTypeIndex].begin(); it != gestureCallbacks_[gestureTypeIndex].end(); ++it) {
        it->second(handIndex, gestureEventData->getGestureKeyPoseConfidence(gestureType), handPosition, keypoints, handEvent);
      }

      return true;
    }
  }
  return false;
}
