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
#include <Gesture.h>

namespace prefabs {

  const PrefabBase::NodeReferences GestureBase::classNodeReferences_ = {
    "LeftHandValue",
    "RightHandValue",
    "Finger",
    "Fist",
    "Pinch",
    "Thumb",
    "L",
    "OpenHandBack",
    "Ok",
    "C",
    "LeftHandGestureValue",
    "RightHandGestureValue",
    "keypointModelToggle",
    "keypointNamesToggle",
    "Keypoint"
  };

  const std::string& GestureBase::Names::LeftHandValue = GestureBase::classNodeReferences_[0];
  const std::string& GestureBase::Names::RightHandValue = GestureBase::classNodeReferences_[1];
  const std::string& GestureBase::Names::Finger = GestureBase::classNodeReferences_[2];
  const std::string& GestureBase::Names::Fist = GestureBase::classNodeReferences_[3];
  const std::string& GestureBase::Names::Pinch = GestureBase::classNodeReferences_[4];
  const std::string& GestureBase::Names::Thumb = GestureBase::classNodeReferences_[5];
  const std::string& GestureBase::Names::L = GestureBase::classNodeReferences_[6];
  const std::string& GestureBase::Names::OpenHandBack = GestureBase::classNodeReferences_[7];
  const std::string& GestureBase::Names::Ok = GestureBase::classNodeReferences_[8];
  const std::string& GestureBase::Names::C = GestureBase::classNodeReferences_[9];
  const std::string& GestureBase::Names::LeftHandGestureValue = GestureBase::classNodeReferences_[10];
  const std::string& GestureBase::Names::RightHandGestureValue = GestureBase::classNodeReferences_[11];
  const std::string& GestureBase::Names::keypointModelToggle = GestureBase::classNodeReferences_[12];
  const std::string& GestureBase::Names::keypointNamesToggle = GestureBase::classNodeReferences_[13];
  const std::string& GestureBase::Names::Keypoint = GestureBase::classNodeReferences_[14];

  const PrefabDescriptor GestureBase::classPrefabDescriptor_(
    0,
    "Gesture",
    "root",
    "/assets/scenes/Gesture.scene.xml",
    "/assets/scenes/Gesture.scene.res.xml");

  const PrefabDescriptorMap prefabDescriptorMap = {
    { Gesture::getClassPrefabDescriptor().getName(), Gesture::getClassPrefabDescriptor() }
  };

  struct VerifyNumberOfPrefabs {
    VerifyNumberOfPrefabs() { assert(prefabDescriptorMap.size() == numberOfPrefabs); }
  };

  VerifyNumberOfPrefabs verifyNumberOfPrefabs;
}

const ExtendedPrefabManager::CreatePrefab ExtendedPrefabManager::createPrefab[prefabs::numberOfPrefabs] = {
  ::prefabs::Gesture::createPrefab
};