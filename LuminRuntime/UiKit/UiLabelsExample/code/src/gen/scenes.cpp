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

#include <scenes.h>
#include <SceneManager.h>

namespace scenes {


  const SceneDescriptorMap sceneDescriptorMap = {
  };

  struct VerifyNumberOfScenes {
    VerifyNumberOfScenes() { assert(sceneDescriptorMap.size() == numberOfScenes); }
  };

  VerifyNumberOfScenes verifyNumberOfScenes;
}

const ExtendedSceneManager::CreateScene ExtendedSceneManager::createScene[1] = {
};
