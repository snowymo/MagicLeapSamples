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

#include <CircleConfirmationPrefabBase.h>
#include <CircleConfirmationLayout.h>

namespace prefabs {

  class CircleConfirmationPrefab : public CircleConfirmationPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <CircleConfirmationPrefab_EventOverrides.inc>

  protected:

    friend class CircleConfirmationPrefabBase;
    CircleConfirmationPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~CircleConfirmationPrefab() override;

  public:
    void setLayout(CircleConfirmationLayout* layout);

  private:
    CircleConfirmationLayout* layout_ = nullptr;
  };
}
