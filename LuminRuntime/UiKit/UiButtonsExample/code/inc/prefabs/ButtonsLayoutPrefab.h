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

#include <ButtonsLayoutPrefabBase.h>
#include <LabelFader.h>
#include <unordered_map>

namespace prefabs {

  class ButtonsLayoutPrefab : public ButtonsLayoutPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <ButtonsLayoutPrefab_EventOverrides.inc>

  protected:

    friend class ButtonsLayoutPrefabBase;
    ButtonsLayoutPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~ButtonsLayoutPrefab() override;

  public:
    void addLabelFader(const std::string& label, LabelFader* fader);
    void deleteFaders();

  private:
    std::unordered_map<std::string, LabelFader*> faders_;
  };
}
