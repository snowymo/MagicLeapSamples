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
#include <lumin/Prism.h>
#include <lumin/ui/UiKit.h>
#include <lumin/utils/Status.h>

namespace lumin {
  /**
   * Functions that are shared among all the SDK Lumin Runtime Examples
   */
  namespace ExampleHelpers {
    /**
     * Disables the given UiNode: visible -> false, enabled -> false.
     * @param node - the UiNode to disable
     */
    void disableUiNode(lumin::ui::UiNode* node);

    /**
     * Enables the given UiNode: visible -> true, enabled -> true.
     * @param node - the UiNode to enable
     */
    void enableUiNode(lumin::ui::UiNode* node);

    /**
     * Returns the string name of the given Status Code.
     * @param status - the status code to convert
     * @return       - the name of the status code
     */
    const std::string statusCodeToString(lumin::utils::StatusCode status);

    /**
     * Returns the string name of the given GestureType
     * @param type - the gesture type enum to convert
     * @return - the name of the gesture type
     */
    const std::string gestureTypeToString(lumin::input::GestureType type);

    /**
     * Returns the string name of the given HandGestureKeypointName
     * @param type - the hand gesture keypoint name enum to convert
     * @return - the name of the hand gesture keypoint
     */
    const std::string handKeypointToString(lumin::input::HandGestureKeypointName name);

    /**
     * Returns the time in h::mm::ss or m:ss format.
     * @param milliseconds - total milliseconds of the time
     * @return - a string with "h:mm:ss" or "m:ss" format
     */
    const std::string msToString(int milliseconds);

    /**
     * Converts a float to a string with %f.2 precision.
     * @param toConvert - float to convert
     * @return - string with "%f.2" precision
     */
    const std::string floatToString(float toConvert);

    /**
     * Converts a vector to a string, with %f.2 precision for each element.
     * @param toConvert - vector to convert
     * @return - string with "(%f.2, %f.2)" == (x, y) precision
     */
    const std::string vecToString(const glm::vec2& toConvert);

    /**
     * Converts a vector to a string, with %f.2 precision for each element.
     * @param toConvert - vector to convert
     * @return - string with "(%f.2, %f.2, %f.2)" == (x, y, z) precision
     */
    const std::string vecToString(const glm::vec3& toConvert);

    /**
     * Converts a vector in world space to prism space.
     * @param prism    - prism to use for conversion.
     * @param position - vector in world space to convert.
     */
    const glm::vec3 worldToPrismSpace(lumin::Prism* prism, const glm::vec3& position);

    /**
     * Converts a normal vector in world space to prism space.
     * @param prism  - prism to use for conversion.
     * @param normal - normal vector in world space to convert.
     */
    const glm::vec3 worldToPrismSpaceNormal(lumin::Prism* prism, const glm::vec3& normal);

    /**
     * Converts a vector in world space to prism space.
     * @param prism    - prism to use for conversion.
     * @param rotation - vector in world space to convert.
     */
    const glm::quat worldToPrismSpace(lumin::Prism* prism, const glm::quat& rotation);

  } // ExampleHelpers
}
