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
#include <lumin/ui/UiKitConsts.h>
#include <cstdlib>
#include <map>

namespace lumin {
  /**
   * Constants that are shared among all the SDK Lumin Runtime Examples
   */
  namespace ExampleConsts {

    const float kTitleSize             = 0.05f;
    const float kTextSize              = 0.025f;
    const float kCursorScale           = 0.03f;
    const char* const kHoverEnterText  = "On Hover Enter";
    const char* const kHoverExitText   = "On Hover Exit";
    const char* const kActivateText    = "On Activate";
    const char* const kLongPressText   = "On Long Press";
    const glm::vec3 kDefaultLocalPos(0.0f);
    const glm::vec3 kDefaultForeground(0.0f, 0.0f, render::MIN_ZDEPTH_OFFSET);
    const glm::vec3 kDefaultBackground(0.0f, 0.0f, -render::MIN_ZDEPTH_OFFSET);
    const glm::vec3 kLayoutPos(0.0f, 0.3f, 0.0f);
    const glm::vec4 kTitlePadding(0.0f, 0.0f, 0.02f, 0.0f);
    const glm::vec4 kDefaultPadding(0.01f);
    const glm::vec4 kNoPadding(0.0f);
    const glm::quat kNoRotation(0.0f, 0.0f, 0.0f, 0.0f);
    extern std::map<lumin::ui::SystemIcon, std::string> systemIconsMap;

  } // ExampleConsts
}  // lumin