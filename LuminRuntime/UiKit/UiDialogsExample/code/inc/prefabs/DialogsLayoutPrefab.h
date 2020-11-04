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

#include <DialogsLayoutPrefabBase.h>
#include <lumin/Prism.h>
#include <lumin/node/Node.h>

namespace prefabs {

  class DialogsLayoutPrefab : public DialogsLayoutPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <DialogsLayoutPrefab_EventOverrides.inc>

  protected:

    friend class DialogsLayoutPrefabBase;
    DialogsLayoutPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~DialogsLayoutPrefab() override;

  public:
    void setPrism(lumin::Prism* prism);
    void reset();
    void addItem(lumin::Node* item);
    void setInteractions(bool enabled);

  private:
    lumin::Prism* prism_ = nullptr;
  };
}
