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

#include <TimedDialogHeartPrefabBase.h>
#include <SceneManager.h>

namespace prefabs {

  class TimedDialogHeartPrefab : public TimedDialogHeartPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <TimedDialogHeartPrefab_EventOverrides.inc>

  protected:

    friend class TimedDialogHeartPrefabBase;
    TimedDialogHeartPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~TimedDialogHeartPrefab() override;
  };
}
