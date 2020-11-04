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

#include <CursorsDisplayPrefabBase.h>
#include <lumin/Prism.h>
#include <lumin/node/Node.h>

namespace prefabs {

  class CursorsDisplayPrefab : public CursorsDisplayPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <CursorsDisplayPrefab_EventOverrides.inc>

  protected:

    friend class CursorsDisplayPrefabBase;
    CursorsDisplayPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~CursorsDisplayPrefab() override;

  public:
    void setPrism(lumin::Prism* prism);

  private:
    lumin::Prism* prism_;
    std::vector<lumin::Node*> textNodes_;
    std::vector<lumin::Node*> circleNodes_;
  };
}
