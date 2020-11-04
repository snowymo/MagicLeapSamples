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

#include <GestureBase.h>

namespace prefabs {

  class Gesture : public GestureBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <Gesture_EventOverrides.inc>

  protected:

    friend class GestureBase;
    Gesture(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~Gesture() override;

  };
}
