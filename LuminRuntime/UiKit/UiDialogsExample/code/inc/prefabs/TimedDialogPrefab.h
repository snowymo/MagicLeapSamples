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

#include <TimedDialogPrefabBase.h>
#include <DialogsLayoutPrefab.h>

namespace prefabs {

  class TimedDialogPrefab : public TimedDialogPrefabBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <TimedDialogPrefab_EventOverrides.inc>

  protected:

    friend class TimedDialogPrefabBase;
    TimedDialogPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~TimedDialogPrefab() override;

  public:
    void setLayout(DialogsLayoutPrefab* layout);

  private:
    DialogsLayoutPrefab* layout_ = nullptr;
  };
}
