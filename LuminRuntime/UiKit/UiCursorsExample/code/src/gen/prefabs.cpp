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

#include <prefabs.h>
#include <PrefabManager.h>
#include <CursorsDisplayPrefab.h>

namespace prefabs {

  const PrefabBase::NodeReferences CursorsDisplayPrefabBase::classNodeReferences_ = {
    "CC_GridLayout",
    "CC_Panel1",
    "CC_Panel2",
    "CC_Panel3",
    "CC_Panel4",
    "CC_Panel5",
    "CC_Panel6",
    "CC_Panel7",
    "CC_ColorPicker"
  };

  const std::string& CursorsDisplayPrefabBase::Names::CC_GridLayout = CursorsDisplayPrefabBase::classNodeReferences_[0];
  const std::string& CursorsDisplayPrefabBase::Names::CC_Panel1 = CursorsDisplayPrefabBase::classNodeReferences_[1];
  const std::string& CursorsDisplayPrefabBase::Names::CC_Panel2 = CursorsDisplayPrefabBase::classNodeReferences_[2];
  const std::string& CursorsDisplayPrefabBase::Names::CC_Panel3 = CursorsDisplayPrefabBase::classNodeReferences_[3];
  const std::string& CursorsDisplayPrefabBase::Names::CC_Panel4 = CursorsDisplayPrefabBase::classNodeReferences_[4];
  const std::string& CursorsDisplayPrefabBase::Names::CC_Panel5 = CursorsDisplayPrefabBase::classNodeReferences_[5];
  const std::string& CursorsDisplayPrefabBase::Names::CC_Panel6 = CursorsDisplayPrefabBase::classNodeReferences_[6];
  const std::string& CursorsDisplayPrefabBase::Names::CC_Panel7 = CursorsDisplayPrefabBase::classNodeReferences_[7];
  const std::string& CursorsDisplayPrefabBase::Names::CC_ColorPicker = CursorsDisplayPrefabBase::classNodeReferences_[8];

  const PrefabDescriptor CursorsDisplayPrefabBase::classPrefabDescriptor_(
    0,
    "CursorsDisplayPrefab",
    "root",
    "/assets/scenes/CursorsDisplayPrefab.scene.xml",
    "/assets/scenes/CursorsDisplayPrefab.scene.res.xml");

  const PrefabDescriptorMap prefabDescriptorMap = {
    { CursorsDisplayPrefab::getClassPrefabDescriptor().getName(), CursorsDisplayPrefab::getClassPrefabDescriptor() }
  };

  struct VerifyNumberOfPrefabs {
    VerifyNumberOfPrefabs() { assert(prefabDescriptorMap.size() == numberOfPrefabs); }
  };

  VerifyNumberOfPrefabs verifyNumberOfPrefabs;
}

const ExtendedPrefabManager::CreatePrefab ExtendedPrefabManager::createPrefab[prefabs::numberOfPrefabs] = {
  ::prefabs::CursorsDisplayPrefab::createPrefab
};
