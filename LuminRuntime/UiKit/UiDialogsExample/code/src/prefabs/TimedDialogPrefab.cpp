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

#include <PrefabDescriptor.h>
#include <TimedDialogPrefab.h>
#include <TimedDialogHeartPrefab.h>
#include <DialogsLayoutPrefab.h>
#include <PrefabManager.h>

#include <ExamplesHelpers.h>
#include <ExamplesDefines.h>
#include <lumin/ui/Cursor.h>
#include <lumin/node/RootNode.h>

using namespace lumin::ui;
using namespace lumin;

namespace prefabs {


  TimedDialogPrefab::TimedDialogPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : TimedDialogPrefabBase(extendedPrefabManager, root) {
  }

  TimedDialogPrefab::~TimedDialogPrefab() {
  }

  void TimedDialogPrefab::setLayout(DialogsLayoutPrefab* layout) {
    layout_ = layout;
  }

  // Handler methods are declared in the base class TimedDialogPrefabBase and can be implemented here

  void TimedDialogPrefab::TDN_Dialog_TimedDialogHandlers_onTimeExpired(const lumin::ui::UiEventData& data) {
    TimedDialogHeartPrefab* prefab = extendedPrefabManager_->spawn<TimedDialogHeartPrefab>();
    LUMIN_ASSERT(prefab, "Failed to create TimedDialogHeartPrefab");
    if (layout_) {
      layout_->setInteractions(true);  // enable ui interactions
      layout_->addItem(prefab->getRoot());
      layout_->reset();
    }
    extendedPrefabManager_->destroyPrefab(this);
  }

  void TimedDialogPrefab::TDN_Dialog_TimedDialogHandlers_onUpdate(const lumin::ui::UiEventData& data, const float dTime) {
    float currentTime = getTDN_Dialog()->getCurrentExpireTime();
    getTDN_Label3()->setText(lumin::ExampleHelpers::floatToString(currentTime));
    getTDN_Slider()->setValue(currentTime);
  }
}
