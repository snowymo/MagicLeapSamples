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
#include <ButtonsLayoutPrefab.h>

namespace prefabs {

  const PrefabBase::NodeReferences ButtonsLayoutPrefabBase::classNodeReferences_ = {
    "BLS_Label1",
    "BLS_Button1",
    "BES_Label1",
    "BLS_Button2",
    "BES_Label2",
    "BLS_Button3",
    "BES_Label3",
    "BLS_Button4",
    "BES_Label4",
    "BLS_Button5",
    "BES_Label5",
    "BLS_Button6",
    "BES_Label6",
    "BLS_Label8",
    "CBS_Button",
    "BES_Label7",
    "RCB_Button",
    "BES_Label8",
    "SB_Button",
    "BES_Label9"
  };

  const std::string& ButtonsLayoutPrefabBase::Names::BLS_Label1 = ButtonsLayoutPrefabBase::classNodeReferences_[0];
  const std::string& ButtonsLayoutPrefabBase::Names::BLS_Button1 = ButtonsLayoutPrefabBase::classNodeReferences_[1];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label1 = ButtonsLayoutPrefabBase::classNodeReferences_[2];
  const std::string& ButtonsLayoutPrefabBase::Names::BLS_Button2 = ButtonsLayoutPrefabBase::classNodeReferences_[3];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label2 = ButtonsLayoutPrefabBase::classNodeReferences_[4];
  const std::string& ButtonsLayoutPrefabBase::Names::BLS_Button3 = ButtonsLayoutPrefabBase::classNodeReferences_[5];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label3 = ButtonsLayoutPrefabBase::classNodeReferences_[6];
  const std::string& ButtonsLayoutPrefabBase::Names::BLS_Button4 = ButtonsLayoutPrefabBase::classNodeReferences_[7];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label4 = ButtonsLayoutPrefabBase::classNodeReferences_[8];
  const std::string& ButtonsLayoutPrefabBase::Names::BLS_Button5 = ButtonsLayoutPrefabBase::classNodeReferences_[9];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label5 = ButtonsLayoutPrefabBase::classNodeReferences_[10];
  const std::string& ButtonsLayoutPrefabBase::Names::BLS_Button6 = ButtonsLayoutPrefabBase::classNodeReferences_[11];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label6 = ButtonsLayoutPrefabBase::classNodeReferences_[12];
  const std::string& ButtonsLayoutPrefabBase::Names::BLS_Label8 = ButtonsLayoutPrefabBase::classNodeReferences_[13];
  const std::string& ButtonsLayoutPrefabBase::Names::CBS_Button = ButtonsLayoutPrefabBase::classNodeReferences_[14];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label7 = ButtonsLayoutPrefabBase::classNodeReferences_[15];
  const std::string& ButtonsLayoutPrefabBase::Names::RCB_Button = ButtonsLayoutPrefabBase::classNodeReferences_[16];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label8 = ButtonsLayoutPrefabBase::classNodeReferences_[17];
  const std::string& ButtonsLayoutPrefabBase::Names::SB_Button = ButtonsLayoutPrefabBase::classNodeReferences_[18];
  const std::string& ButtonsLayoutPrefabBase::Names::BES_Label9 = ButtonsLayoutPrefabBase::classNodeReferences_[19];

  const PrefabDescriptor ButtonsLayoutPrefabBase::classPrefabDescriptor_(
    0,
    "ButtonsLayoutPrefab",
    "root",
    "/assets/scenes/ButtonsLayoutPrefab.scene.xml",
    "/assets/scenes/ButtonsLayoutPrefab.scene.res.xml");

  const PrefabDescriptorMap prefabDescriptorMap = {
    { ButtonsLayoutPrefab::getClassPrefabDescriptor().getName(), ButtonsLayoutPrefab::getClassPrefabDescriptor() }
  };

  struct VerifyNumberOfPrefabs {
    VerifyNumberOfPrefabs() { assert(prefabDescriptorMap.size() == numberOfPrefabs); }
  };

  VerifyNumberOfPrefabs verifyNumberOfPrefabs;
}

const ExtendedPrefabManager::CreatePrefab ExtendedPrefabManager::createPrefab[prefabs::numberOfPrefabs] = {
  ::prefabs::ButtonsLayoutPrefab::createPrefab
};
