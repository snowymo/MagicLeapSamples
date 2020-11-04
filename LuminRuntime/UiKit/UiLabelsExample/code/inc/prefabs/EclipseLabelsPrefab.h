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

#include <EclipseLabelsPrefabBase.h>

namespace prefabs {

  class EclipseLabelsPrefab : public EclipseLabelsPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <EclipseLabelsPrefab_EventOverrides.inc>

  protected:

    friend class EclipseLabelsPrefabBase;
    EclipseLabelsPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~EclipseLabelsPrefab() override;

  };
}
