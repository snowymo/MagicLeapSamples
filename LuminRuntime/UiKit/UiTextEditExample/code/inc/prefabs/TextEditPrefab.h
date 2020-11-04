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

#include <TextEditPrefabBase.h>

namespace prefabs {

  class TextEditPrefab : public TextEditPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <TextEditPrefab_EventOverrides.inc>

  protected:

    friend class TextEditPrefabBase;
    TextEditPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~TextEditPrefab() override;

  };
}
