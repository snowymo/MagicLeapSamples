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

#include <PrefabDescriptor.h>
#include <AudioModel.h>

namespace prefabs {


  AudioModel::AudioModel(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : AudioModelBase(extendedPrefabManager, root) {
  }

  AudioModel::~AudioModel() {
  }

  // Handler methods are declared in the base class AudioModelBase and can be implemented here

}
