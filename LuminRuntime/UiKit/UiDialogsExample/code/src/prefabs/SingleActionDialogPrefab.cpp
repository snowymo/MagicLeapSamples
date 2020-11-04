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
#include <SingleActionDialogPrefab.h>
#include <DialogsLayoutPrefab.h>
#include <PrefabManager.h>

namespace prefabs {


  SingleActionDialogPrefab::SingleActionDialogPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : SingleActionDialogPrefabBase(extendedPrefabManager, root) {
  }

  SingleActionDialogPrefab::~SingleActionDialogPrefab() {
    layout_ = nullptr;
  }

  void SingleActionDialogPrefab::setLayout(DialogsLayoutPrefab* layout) {
    layout_ = layout;
  }

  // Handler methods are declared in the base class SingleActionDialogPrefabBase and can be implemented here

  void SingleActionDialogPrefab::SADN_Dialog_SingleActionDialogHandlers(const lumin::ui::UiEventData& data) {
    if (layout_) {
      layout_->reset();
    }
    extendedPrefabManager_->destroyPrefab(this);
  }

  void SingleActionDialogPrefab::SADN_Button_HeartButtonHandlers(const lumin::ui::UiEventData& data) {
    if (layout_) {
      layout_->addItem(getSADN_Button());
    }
    getSADN_Button()->setIconColor(lumin::color::RED);
    getSADN_Button()->setEnabled(false);
  }

}
