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

#include <EclipseLabelsPrefabBase.h>
#include <EclipseLabelsPrefab.h>

namespace prefabs {

  const PrefabDescriptor& EclipseLabelsPrefabBase::getClassPrefabDescriptor() {
    return classPrefabDescriptor_;
  }

  PrefabBase* EclipseLabelsPrefabBase::createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root) {
    PrefabBase* const prefab = new EclipseLabelsPrefab(extendedPrefabManager, root);
    return prefab;
  }

  EclipseLabelsPrefabBase::EclipseLabelsPrefabBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : PrefabBase(extendedPrefabManager, root) {

  }

  EclipseLabelsPrefabBase::~EclipseLabelsPrefabBase() {
  }

  const PrefabDescriptor& EclipseLabelsPrefabBase::getPrefabDescriptor() const {
    return classPrefabDescriptor_;
  }

  const PrefabBase::NodeReferences& EclipseLabelsPrefabBase::getNodeReferences() const {
    return classNodeReferences_;
  }

}