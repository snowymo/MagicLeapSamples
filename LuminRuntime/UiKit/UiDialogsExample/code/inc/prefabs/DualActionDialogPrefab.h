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

#include <DualActionDialogPrefabBase.h>
#include <DialogsLayoutPrefab.h>

namespace prefabs {

  class DualActionDialogPrefab : public DualActionDialogPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <DualActionDialogPrefab_EventOverrides.inc>

  protected:

    friend class DualActionDialogPrefabBase;
    DualActionDialogPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~DualActionDialogPrefab() override;

  public:
    void setLayout(DialogsLayoutPrefab* layout);

  private:
    DialogsLayoutPrefab* layout_ = nullptr;
  };
}
