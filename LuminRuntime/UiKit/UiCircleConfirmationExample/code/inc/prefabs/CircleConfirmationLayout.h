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

#include <CircleConfirmationLayoutBase.h>
#include <CircleConfirmationPrefab.h>

namespace prefabs {

  class CircleConfirmationLayout : public CircleConfirmationLayoutBase {
  public:

    void setCircleConfirmationPrefab(CircleConfirmationPrefab* prefab);

  protected:

    #define EVENT_OVERRIDES_INC
    #include <CircleConfirmationLayout_EventOverrides.inc>

  protected:

    friend class CircleConfirmationLayoutBase;
    CircleConfirmationLayout(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~CircleConfirmationLayout() override;

  private:
    CircleConfirmationPrefab* prefab_ = nullptr;
  };
}
