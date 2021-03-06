// -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING --
//
// THE CONTENTS OF THIS FILE IS GENERATED BY CODE AND
// ANY MODIFICATIONS WILL BE OVERWRITTEN
//
// -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING --

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

#include <DualActionDialogPrefabBase.h>
#include <DualActionDialogPrefab.h>

namespace prefabs {

  const PrefabDescriptor& DualActionDialogPrefabBase::getClassPrefabDescriptor() {
    return classPrefabDescriptor_;
  }

  PrefabBase* DualActionDialogPrefabBase::createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root) {
    PrefabBase* const prefab = new DualActionDialogPrefab(extendedPrefabManager, root);
    return prefab;
  }

  DualActionDialogPrefabBase::DualActionDialogPrefabBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : PrefabBase(extendedPrefabManager, root) {

    DADN_Dialog = lumin::ui::UiDialog::CastFrom(root->findChild(Names::DADN_Dialog));
    DADN_Button = lumin::ui::UiButton::CastFrom(root->findChild(Names::DADN_Button));

    DADN_Dialog->onCancelSub(std::bind(&DualActionDialogPrefabBase::DADN_Dialog_DualActionDialogHandlers_onCancel, this, std::placeholders::_1));
    DADN_Dialog->onConfirmSub(std::bind(&DualActionDialogPrefabBase::DADN_Dialog_DualActionDialogHandlers_onConfirm, this, std::placeholders::_1));
    DADN_Button->onActivateSub(std::bind(&DualActionDialogPrefabBase::DADN_Button_HeartButtonHandlers, this, std::placeholders::_1));
  }

  DualActionDialogPrefabBase::~DualActionDialogPrefabBase() {
  }

  const PrefabDescriptor& DualActionDialogPrefabBase::getPrefabDescriptor() const {
    return classPrefabDescriptor_;
  }

  const PrefabBase::NodeReferences& DualActionDialogPrefabBase::getNodeReferences() const {
    return classNodeReferences_;
  }

  lumin::ui::UiDialog* DualActionDialogPrefabBase::getDADN_Dialog() {
    return DADN_Dialog;
  }

  lumin::ui::UiButton* DualActionDialogPrefabBase::getDADN_Button() {
    return DADN_Button;
  }

}
