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

#include <LoadingSpinnersBase.h>
#include <LoadingSpinners.h>

namespace prefabs {

  const PrefabDescriptor& LoadingSpinnersBase::getClassPrefabDescriptor() {
    return classPrefabDescriptor_;
  }

  PrefabBase* LoadingSpinnersBase::createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root) {
    PrefabBase* const prefab = new LoadingSpinners(extendedPrefabManager, root);
    return prefab;
  }

  LoadingSpinnersBase::LoadingSpinnersBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : PrefabBase(extendedPrefabManager, root) {

  }

  LoadingSpinnersBase::~LoadingSpinnersBase() {
  }

  const PrefabDescriptor& LoadingSpinnersBase::getPrefabDescriptor() const {
    return classPrefabDescriptor_;
  }

  const PrefabBase::NodeReferences& LoadingSpinnersBase::getNodeReferences() const {
    return classNodeReferences_;
  }

}
