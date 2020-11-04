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

#include <AudioModelBase.h>

namespace prefabs {

  class AudioModel : public AudioModelBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <AudioModel_EventOverrides.inc>

  protected:

    friend class AudioModelBase;
    AudioModel(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~AudioModel() override;

  };
}
