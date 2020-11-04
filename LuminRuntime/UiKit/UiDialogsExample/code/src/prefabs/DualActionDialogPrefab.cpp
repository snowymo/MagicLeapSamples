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
#include <DualActionDialogPrefab.h>
#include <DialogsLayoutPrefab.h>
#include <PrefabManager.h>

namespace prefabs {


  DualActionDialogPrefab::DualActionDialogPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : DualActionDialogPrefabBase(extendedPrefabManager, root) {
  }

  DualActionDialogPrefab::~DualActionDialogPrefab() {
    layout_ = nullptr;
  }

  void DualActionDialogPrefab::setLayout(DialogsLayoutPrefab* layout) {
    layout_ = layout;
  }

  // Handler methods are declared in the base class DualActionDialogPrefabBase and can be implemented here

  void DualActionDialogPrefab::DADN_Dialog_DualActionDialogHandlers_onCancel(const lumin::ui::UiEventData& data) {
    if (layout_) {
      layout_->reset();
    }
    extendedPrefabManager_->destroyPrefab(this);
  }

  void DualActionDialogPrefab::DADN_Dialog_DualActionDialogHandlers_onConfirm(const lumin::ui::UiEventData& data) {
    if (layout_) {
      layout_->addItem(getDADN_Button());
      layout_->reset();
    }
    extendedPrefabManager_->destroyPrefab(this);
  }

  void DualActionDialogPrefab::DADN_Button_HeartButtonHandlers(const lumin::ui::UiEventData& data) {
    getDADN_Button()->setIconColor(lumin::color::RED);
  }

}
