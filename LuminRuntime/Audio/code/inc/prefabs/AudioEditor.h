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

#pragma once

#include <AudioEditorBase.h>

class AudioScene;

namespace prefabs {

  class AudioEditor : public AudioEditorBase {
  public:

  protected:

    #define EVENT_OVERRIDES_INC
    #include <AudioEditor_EventOverrides.inc>

  protected:

    friend class AudioEditorBase;
    AudioEditor(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~AudioEditor() override;

  public:
    void setAudioScene(AudioScene* scene);

  private:
    AudioScene* scene_ = nullptr;
  };
}