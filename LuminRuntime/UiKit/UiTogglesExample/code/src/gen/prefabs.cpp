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
#include <TogglesLayoutPrefab.h>

namespace prefabs {

  const PrefabBase::NodeReferences TogglesLayoutPrefabBase::classNodeReferences_ = {
    "TLS_Label1",
    "IOTS_Toggle",
    "BES_Label1",
    "IOSTS_Toggle",
    "BES_Label2",
    "IOOTS_Toggle",
    "BES_Label3",
    "SWITS_Toggle",
    "BES_Label4",
    "SWLTS_Toggle",
    "BES_Label5",
    "TLS_Label7",
    "DTS_Toggle",
    "BES_Label6",
    "RTS_Toggle",
    "BES_Label7",
    "CTS_Toggle",
    "BES_Label8"
  };

  const std::string& TogglesLayoutPrefabBase::Names::TLS_Label1 = TogglesLayoutPrefabBase::classNodeReferences_[0];
  const std::string& TogglesLayoutPrefabBase::Names::IOTS_Toggle = TogglesLayoutPrefabBase::classNodeReferences_[1];
  const std::string& TogglesLayoutPrefabBase::Names::BES_Label1 = TogglesLayoutPrefabBase::classNodeReferences_[2];
  const std::string& TogglesLayoutPrefabBase::Names::IOSTS_Toggle = TogglesLayoutPrefabBase::classNodeReferences_[3];
  const std::string& TogglesLayoutPrefabBase::Names::BES_Label2 = TogglesLayoutPrefabBase::classNodeReferences_[4];
  const std::string& TogglesLayoutPrefabBase::Names::IOOTS_Toggle = TogglesLayoutPrefabBase::classNodeReferences_[5];
  const std::string& TogglesLayoutPrefabBase::Names::BES_Label3 = TogglesLayoutPrefabBase::classNodeReferences_[6];
  const std::string& TogglesLayoutPrefabBase::Names::SWITS_Toggle = TogglesLayoutPrefabBase::classNodeReferences_[7];
  const std::string& TogglesLayoutPrefabBase::Names::BES_Label4 = TogglesLayoutPrefabBase::classNodeReferences_[8];
  const std::string& TogglesLayoutPrefabBase::Names::SWLTS_Toggle = TogglesLayoutPrefabBase::classNodeReferences_[9];
  const std::string& TogglesLayoutPrefabBase::Names::BES_Label5 = TogglesLayoutPrefabBase::classNodeReferences_[10];
  const std::string& TogglesLayoutPrefabBase::Names::TLS_Label7 = TogglesLayoutPrefabBase::classNodeReferences_[11];
  const std::string& TogglesLayoutPrefabBase::Names::DTS_Toggle = TogglesLayoutPrefabBase::classNodeReferences_[12];
  const std::string& TogglesLayoutPrefabBase::Names::BES_Label6 = TogglesLayoutPrefabBase::classNodeReferences_[13];
  const std::string& TogglesLayoutPrefabBase::Names::RTS_Toggle = TogglesLayoutPrefabBase::classNodeReferences_[14];
  const std::string& TogglesLayoutPrefabBase::Names::BES_Label7 = TogglesLayoutPrefabBase::classNodeReferences_[15];
  const std::string& TogglesLayoutPrefabBase::Names::CTS_Toggle = TogglesLayoutPrefabBase::classNodeReferences_[16];
  const std::string& TogglesLayoutPrefabBase::Names::BES_Label8 = TogglesLayoutPrefabBase::classNodeReferences_[17];

  const PrefabDescriptor TogglesLayoutPrefabBase::classPrefabDescriptor_(
    0,
    "TogglesLayoutPrefab",
    "root",
    "/assets/scenes/TogglesLayoutPrefab.scene.xml",
    "/assets/scenes/TogglesLayoutPrefab.scene.res.xml");

  const PrefabDescriptorMap prefabDescriptorMap = {
    { TogglesLayoutPrefab::getClassPrefabDescriptor().getName(), TogglesLayoutPrefab::getClassPrefabDescriptor() }
  };

  struct VerifyNumberOfPrefabs {
    VerifyNumberOfPrefabs() { assert(prefabDescriptorMap.size() == numberOfPrefabs); }
  };

  VerifyNumberOfPrefabs verifyNumberOfPrefabs;
}

const ExtendedPrefabManager::CreatePrefab ExtendedPrefabManager::createPrefab[prefabs::numberOfPrefabs] = {
  ::prefabs::TogglesLayoutPrefab::createPrefab
};