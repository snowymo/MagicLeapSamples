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
#include <DualActionDialogPrefab.h>
#include <SingleActionDialogPrefab.h>
#include <TimedDialogPrefab.h>
#include <TimedDialogHeartPrefab.h>
#include <DialogsLayoutPrefab.h>

namespace prefabs {

  const PrefabBase::NodeReferences DualActionDialogPrefabBase::classNodeReferences_ = {
    "DADN_Dialog",
    "DADN_Button"
  };

  const std::string& DualActionDialogPrefabBase::Names::DADN_Dialog = DualActionDialogPrefabBase::classNodeReferences_[0];
  const std::string& DualActionDialogPrefabBase::Names::DADN_Button = DualActionDialogPrefabBase::classNodeReferences_[1];

  const PrefabDescriptor DualActionDialogPrefabBase::classPrefabDescriptor_(
    0,
    "DualActionDialogPrefab",
    "root",
    "/assets/scenes/DualActionDialogPrefab.scene.xml",
    "/assets/scenes/DualActionDialogPrefab.scene.res.xml");
  const PrefabBase::NodeReferences SingleActionDialogPrefabBase::classNodeReferences_ = {
    "SADN_Dialog",
    "SADN_Button"
  };

  const std::string& SingleActionDialogPrefabBase::Names::SADN_Dialog = SingleActionDialogPrefabBase::classNodeReferences_[0];
  const std::string& SingleActionDialogPrefabBase::Names::SADN_Button = SingleActionDialogPrefabBase::classNodeReferences_[1];

  const PrefabDescriptor SingleActionDialogPrefabBase::classPrefabDescriptor_(
    1,
    "SingleActionDialogPrefab",
    "root",
    "/assets/scenes/SingleActionDialogPrefab.scene.xml",
    "/assets/scenes/SingleActionDialogPrefab.scene.res.xml");
  const PrefabBase::NodeReferences TimedDialogPrefabBase::classNodeReferences_ = {
    "TDN_Dialog",
    "TDN_Label3",
    "TDN_Slider"
  };

  const std::string& TimedDialogPrefabBase::Names::TDN_Dialog = TimedDialogPrefabBase::classNodeReferences_[0];
  const std::string& TimedDialogPrefabBase::Names::TDN_Label3 = TimedDialogPrefabBase::classNodeReferences_[1];
  const std::string& TimedDialogPrefabBase::Names::TDN_Slider = TimedDialogPrefabBase::classNodeReferences_[2];

  const PrefabDescriptor TimedDialogPrefabBase::classPrefabDescriptor_(
    2,
    "TimedDialogPrefab",
    "root",
    "/assets/scenes/TimedDialogPrefab.scene.xml",
    "/assets/scenes/TimedDialogPrefab.scene.res.xml");
  const PrefabBase::NodeReferences TimedDialogHeartPrefabBase::classNodeReferences_ = {
  };

  const PrefabDescriptor TimedDialogHeartPrefabBase::classPrefabDescriptor_(
    3,
    "TimedDialogHeartPrefab",
    "root",
    "/assets/scenes/TimedDialogHeartPrefab.scene.xml",
    "/assets/scenes/TimedDialogHeartPrefab.scene.res.xml");
  const PrefabBase::NodeReferences DialogsLayoutPrefabBase::classNodeReferences_ = {
    "SADS_Tab",
    "DADS_Tab",
    "TDS_Tab",
    "DS_ListView"
  };

  const std::string& DialogsLayoutPrefabBase::Names::SADS_Tab = DialogsLayoutPrefabBase::classNodeReferences_[0];
  const std::string& DialogsLayoutPrefabBase::Names::DADS_Tab = DialogsLayoutPrefabBase::classNodeReferences_[1];
  const std::string& DialogsLayoutPrefabBase::Names::TDS_Tab = DialogsLayoutPrefabBase::classNodeReferences_[2];
  const std::string& DialogsLayoutPrefabBase::Names::DS_ListView = DialogsLayoutPrefabBase::classNodeReferences_[3];

  const PrefabDescriptor DialogsLayoutPrefabBase::classPrefabDescriptor_(
    4,
    "DialogsLayoutPrefab",
    "root",
    "/assets/scenes/DialogsLayoutPrefab.scene.xml",
    "/assets/scenes/DialogsLayoutPrefab.scene.res.xml");

  const PrefabDescriptorMap prefabDescriptorMap = {
    { DualActionDialogPrefab::getClassPrefabDescriptor().getName(), DualActionDialogPrefab::getClassPrefabDescriptor() },

    { SingleActionDialogPrefab::getClassPrefabDescriptor().getName(), SingleActionDialogPrefab::getClassPrefabDescriptor() },

    { TimedDialogPrefab::getClassPrefabDescriptor().getName(), TimedDialogPrefab::getClassPrefabDescriptor() },

    { TimedDialogHeartPrefab::getClassPrefabDescriptor().getName(), TimedDialogHeartPrefab::getClassPrefabDescriptor() },

    { DialogsLayoutPrefab::getClassPrefabDescriptor().getName(), DialogsLayoutPrefab::getClassPrefabDescriptor() }
  };

  struct VerifyNumberOfPrefabs {
    VerifyNumberOfPrefabs() { assert(prefabDescriptorMap.size() == numberOfPrefabs); }
  };

  VerifyNumberOfPrefabs verifyNumberOfPrefabs;
}

const ExtendedPrefabManager::CreatePrefab ExtendedPrefabManager::createPrefab[prefabs::numberOfPrefabs] = {
  ::prefabs::DualActionDialogPrefab::createPrefab,
  ::prefabs::SingleActionDialogPrefab::createPrefab,
  ::prefabs::TimedDialogPrefab::createPrefab,
  ::prefabs::TimedDialogHeartPrefab::createPrefab,
  ::prefabs::DialogsLayoutPrefab::createPrefab
};