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

#include <DialogsLayoutPrefabBase.h>
#include <DialogsLayoutPrefab.h>

namespace prefabs {

  const PrefabDescriptor& DialogsLayoutPrefabBase::getClassPrefabDescriptor() {
    return classPrefabDescriptor_;
  }

  PrefabBase* DialogsLayoutPrefabBase::createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root) {
    PrefabBase* const prefab = new DialogsLayoutPrefab(extendedPrefabManager, root);
    return prefab;
  }

  DialogsLayoutPrefabBase::DialogsLayoutPrefabBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : PrefabBase(extendedPrefabManager, root) {

    SADS_Tab = lumin::ui::UiTab::CastFrom(root->findChild(Names::SADS_Tab));
    DADS_Tab = lumin::ui::UiTab::CastFrom(root->findChild(Names::DADS_Tab));
    TDS_Tab = lumin::ui::UiTab::CastFrom(root->findChild(Names::TDS_Tab));
    DS_ListView = lumin::ui::UiListView::CastFrom(root->findChild(Names::DS_ListView));

    SADS_Tab->onActivateSub(std::bind(&DialogsLayoutPrefabBase::SADS_Tab_SingleActionDialogTabHandlers, this, std::placeholders::_1));
    DADS_Tab->onActivateSub(std::bind(&DialogsLayoutPrefabBase::DADS_Tab_DualActionDialogTabHandlers, this, std::placeholders::_1));
    TDS_Tab->onActivateSub(std::bind(&DialogsLayoutPrefabBase::TDS_Tab_TimedDialogTabHandlers, this, std::placeholders::_1));
  }

  DialogsLayoutPrefabBase::~DialogsLayoutPrefabBase() {
  }

  const PrefabDescriptor& DialogsLayoutPrefabBase::getPrefabDescriptor() const {
    return classPrefabDescriptor_;
  }

  const PrefabBase::NodeReferences& DialogsLayoutPrefabBase::getNodeReferences() const {
    return classNodeReferences_;
  }

  lumin::ui::UiTab* DialogsLayoutPrefabBase::getSADS_Tab() {
    return SADS_Tab;
  }

  lumin::ui::UiTab* DialogsLayoutPrefabBase::getDADS_Tab() {
    return DADS_Tab;
  }

  lumin::ui::UiTab* DialogsLayoutPrefabBase::getTDS_Tab() {
    return TDS_Tab;
  }

  lumin::ui::UiListView* DialogsLayoutPrefabBase::getDS_ListView() {
    return DS_ListView;
  }

}
