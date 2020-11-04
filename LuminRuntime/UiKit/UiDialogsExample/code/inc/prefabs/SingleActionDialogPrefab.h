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

#include <SingleActionDialogPrefabBase.h>
#include <DialogsLayoutPrefab.h>

namespace prefabs {

  class SingleActionDialogPrefab : public SingleActionDialogPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <SingleActionDialogPrefab_EventOverrides.inc>

  protected:

    friend class SingleActionDialogPrefabBase;
    SingleActionDialogPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~SingleActionDialogPrefab() override;

  public:
    void setLayout(DialogsLayoutPrefab* layout);

  private:
    DialogsLayoutPrefab* layout_ = nullptr;;
  };
}
