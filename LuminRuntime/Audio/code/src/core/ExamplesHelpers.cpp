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
#include <ExamplesHelpers.h>
#include <ml_logging.h>
#include <chrono>
#include <glm/gtc/matrix_inverse.hpp>

namespace lumin {
  /**
   * Functions that are shared among all the SDK Lumin Runtime UiKit Examples
   */
  namespace ExampleHelpers {
    void disableUiNode(lumin::ui::UiNode* node) {
      node->setVisible(false, true);
      node->setEnabled(false);
    }

    void enableUiNode(lumin::ui::UiNode* node) {
      node->setVisible(true, true);
      node->setEnabled(true);
    }

    const std::string statusCodeToString(lumin::utils::StatusCode status) {
      switch (status) {
        case lumin::utils::NO_ERROR:
          return "NO_ERROR";
        case lumin::utils::UNKNOWN_ERROR:
          return "UNKNOWN_ERROR";
        case lumin::utils::NO_MEMORY:
          return "NO_MEMORY";
        case lumin::utils::INVALID_OPERATION:
          return "INVALID_OPERATION";
        case lumin::utils::BAD_VALUE:
          return "BAD_VALUE";
        case lumin::utils::BAD_TYPE:
          return "BAD_TYPE";
        case lumin::utils::NAME_NOT_FOUND:
          return "NAME_NOT_FOUND";
        case lumin::utils::PERMISSION_DENIED:
          return "PERMISSION_DENIED";
        case lumin::utils::NO_INIT:
          return "NO_INIT";
        case lumin::utils::ALREADY_EXISTS:
          return "ALREADY_EXISTS";
        case lumin::utils::DEAD_OBJECT:
          return "DEAD_OBJECT";
        case lumin::utils::FAILED_TRANSACTION:
          return "FAILED_TRANSACTION";
        case lumin::utils::BAD_INDEX:
          return "BAD_INDEX";
        case lumin::utils::NOT_ENOUGH_DATA:
          return "NOT_ENOUGH_DATA";
        case lumin::utils::WOULD_BLOCK:
          return "WOULD_BLOCK";
        case lumin::utils::TIMED_OUT:
          return "TIMED_OUT";
        case lumin::utils::UNKNOWN_TRANSACTION:
          return "UNKNOWN_TRANSACTION";
        case lumin::utils::FDS_NOT_ALLOWED:
          return "FDS_NOT_ALLOWED";
        case lumin::utils::UNEXPECTED_NULL:
          return "UNEXPECTED_NULL";
      }
      return "UNKNOWN_STATUS_CODE";
    }

    const std::string gestureTypeToString(lumin::input::GestureType type) {
      switch (type) {
        case lumin::input::GestureType::NONE :
          return "NONE";
        case lumin::input::GestureType::Scroll :
          return "Scroll";
        case lumin::input::GestureType::Pinch :
          return "Pinch";
        case lumin::input::GestureType::Tap :
          return "Tap";
        case lumin::input::GestureType::ForceTapDown :
          return "ForceTapDown";
        case lumin::input::GestureType::ForceTapUp :
          return "ForceTapUp";
        case lumin::input::GestureType::ForceDwell :
          return "ForceDwell";
        case lumin::input::GestureType::SecondForceDown :
          return "SecondForceDown";
        case lumin::input::GestureType::LongHold :
          return "LongHold";
        case lumin::input::GestureType::RadialScroll :
          return "RadialScroll";
        case lumin::input::GestureType::Swipe :
          return "Swipe";
        case lumin::input::GestureType::TriggerDown :
          return "TriggerDown";
        case lumin::input::GestureType::TriggerUp :
          return "TriggerUp";
        case lumin::input::GestureType::TriggerClick :
          return "TriggerClick";
        case lumin::input::GestureType::TriggerHold :
          return "TriggerHold";
        case lumin::input::GestureType::HAND_FINGER :
          return "HAND_FINGER";
        case lumin::input::GestureType::HAND_FIST :
          return "HAND_FIST";
        case lumin::input::GestureType::HAND_PINCH :
          return "HAND_PINCH";
        case lumin::input::GestureType::HAND_THUMB :
          return "HAND_THUMB";
        case lumin::input::GestureType::HAND_L :
          return "HAND_L";
        case lumin::input::GestureType::HAND_OPENHANDBACK :
          return "HAND_OPENHANDBACK";
        case lumin::input::GestureType::HAND_OK :
          return "HAND_OK";
        case lumin::input::GestureType::HAND_C :
          return "HAND_C";
        case lumin::input::GestureType::HAND_NO_POSE :
          return "HAND_NO_POSE";
        default:
          return "NONE";
      }
      return "NONE";
    }

    const std::string handKeypointToString(lumin::input::HandGestureKeypointName name) {
      switch (name) {
        case lumin::input::HandGestureKeypointName::NONE :
          return "NONE";
        case lumin::input::HandGestureKeypointName::THUMB_TIP :
          return "THUMB_TIP";
        case lumin::input::HandGestureKeypointName::THUMB_FIRST_JOINT :
          return "THUMB_FIRST_JOINT";
        case lumin::input::HandGestureKeypointName::THUMB_BASE :
          return "THUMB_BASE";
        case lumin::input::HandGestureKeypointName::THUMB_CARPAL_JOINT :
          return "THUMB_CARPAL_JOINT";
        case lumin::input::HandGestureKeypointName::INDEX_FINGER_TIP :
          return "INDEX_FINGER_TIP";
        case lumin::input::HandGestureKeypointName::INDEX_FINGER_FIRST_JOINT :
          return "INDEX_FINGER_FIRST_JOINT";
        case lumin::input::HandGestureKeypointName::INDEX_FINGER_SECOND_JOINT :
          return "INDEX_FINGER_SECOND_JOINT";
        case lumin::input::HandGestureKeypointName::INDEX_FINGER_BASE :
          return "INDEX_FINGER_BASE";
        case lumin::input::HandGestureKeypointName::MIDDLE_FINGER_TIP :
          return "MIDDLE_FINGER_TIP";
        case lumin::input::HandGestureKeypointName::MIDDLE_FINGER_FIRST_JOINT :
          return "MIDDLE_FINGER_FIRST_JOINT";
        case lumin::input::HandGestureKeypointName::MIDDLE_FINGER_SECOND_JOINT :
          return "MIDDLE_FINGER_SECOND_JOINT";
        case lumin::input::HandGestureKeypointName::MIDDLE_FINGER_BASE :
          return "MIDDLE_FINGER_BASE";
        case lumin::input::HandGestureKeypointName::RING_FINGER_TIP :
          return "RING_FINGER_TIP";
        case lumin::input::HandGestureKeypointName::RING_FINGER_FIRST_JOINT :
          return "RING_FINGER_FIRST_JOINT";
        case lumin::input::HandGestureKeypointName::RING_FINGER_SECOND_JOINT :
          return "RING_FINGER_SECOND_JOINT";
        case lumin::input::HandGestureKeypointName::RING_FINGER_BASE :
          return "RING_FINGER_BASE";
        case lumin::input::HandGestureKeypointName::PINKY_FINGER_TIP :
          return "PINKY_FINGER_TIP";
        case lumin::input::HandGestureKeypointName::PINKY_FINGER_FIRST_JOINT :
          return "PINKY_FINGER_FIRST_JOINT";
        case lumin::input::HandGestureKeypointName::PINKY_FINGER_SECOND_JOINT :
          return "PINKY_FINGER_SECOND_JOINT";
        case lumin::input::HandGestureKeypointName::PINKY_FINGER_BASE :
          return "PINKY_FINGER_BASE";
        case lumin::input::HandGestureKeypointName::HAND_CENTER :
          return "HAND_CENTER";
        case lumin::input::HandGestureKeypointName::WRIST_CENTER :
          return "WRIST_CENTER";
        case lumin::input::HandGestureKeypointName::WRIST_PINKY_SIDE :
          return "WRIST_PINKY_SIDE";
        case lumin::input::HandGestureKeypointName::WRIST_THUMB_SIDE :
          return "WRIST_THUMB_SIDE";
      }
      return "NONE";
    }

    const std::string msToString(int milliseconds) {
      long hours   = std::chrono::duration_cast<std::chrono::hours>(
          std::chrono::milliseconds(milliseconds)).count();
      long minutes = (std::chrono::duration_cast<std::chrono::minutes>(
          std::chrono::milliseconds(milliseconds)) % std::chrono::hours(1)).count();
      long seconds = (std::chrono::duration_cast<std::chrono::seconds>(
          std::chrono::milliseconds(milliseconds)) % std::chrono::minutes(1)).count();

      std::string time = "";
      if (hours > 0) {
        time += std::to_string(hours) + ":";
        if (minutes < 10) {
          time += "0";
        }
      }
      time += std::to_string(minutes) + ":";
      if (seconds < 10) {
        time += "0";
      }
      time += std::to_string(seconds);
      return time;
    }

    const std::string floatToString(float toConvert) {
      std::string converted    = std::to_string(toConvert);
      std::size_t decimalPlace = converted.find(".");
      if (decimalPlace != std::string::npos) {
        converted = converted.erase(decimalPlace + 3); // default precision is 6 characters
      }
      return converted;
    }

    const std::string vecToString(const glm::vec2& toConvert) {
      return "(" + floatToString(toConvert.x) + ", " + floatToString(toConvert.y) + ")";
    }

    const std::string vecToString(const glm::vec3& toConvert) {
      return "(" + floatToString(toConvert.x) + ", " + floatToString(toConvert.y) + ", " +
          floatToString(toConvert.z) + ")";
    }

    const glm::vec3 worldToPrismSpace(lumin::Prism* prism, const glm::vec3& position) {
      glm::mat4 prism_inverse_matrix = glm::inverse(prism->getTransform());
      return prism_inverse_matrix * glm::vec4(position, 1.0f);
    }

    const glm::vec3 worldToPrismSpaceNormal(lumin::Prism* prism, const glm::vec3& normal) {
      glm::mat3 prism_transpose_matrix = glm::transpose(glm::mat3(prism->getTransform()));
      return prism_transpose_matrix * normal;
    }

    const glm::quat worldToPrismSpace(lumin::Prism* prism, const glm::quat& rotation) {
      return glm::inverse(prism->getRotation()) * rotation;
    }

  } // ExampleHelpers
} // lumin