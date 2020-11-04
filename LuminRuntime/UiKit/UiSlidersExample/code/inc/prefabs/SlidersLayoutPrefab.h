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

#include <SlidersLayoutPrefabBase.h>
#include <LabelFader.h>
#include <unordered_map>

namespace prefabs {

  class SlidersLayoutPrefab : public SlidersLayoutPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <SlidersLayoutPrefab_EventOverrides.inc>

  protected:

    friend class SlidersLayoutPrefabBase;
    SlidersLayoutPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~SlidersLayoutPrefab() override;

  public:
    void addFader(const std::string& label, LabelFader* fader);
    void deleteFaders();

  private:
    std::unordered_map<std::string, LabelFader*> faders_;
  };
}
