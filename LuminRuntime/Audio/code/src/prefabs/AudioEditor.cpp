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
#include <AudioEditor.h>
#include <AudioScene.h>
#include <lumin/ui/node/UiDropDownList.h>
#include <lumin/ui/node/UiSlider.h>
#include <lumin/ui/node/UiToggle.h>
#include <lumin/ui/node/UiButton.h>

namespace prefabs {

  AudioEditor::AudioEditor(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : AudioEditorBase(extendedPrefabManager, root) {
  }

  AudioEditor::~AudioEditor() {
    scene_ = nullptr;
  }

  void AudioEditor::setAudioScene(AudioScene* scene) {
    scene_ = scene;
  }

  // Handler methods are declared in the base class AudioEditorBase and can be implemented here

  void AudioEditor::audioSwitcher_audioSwitcherCallback(const lumin::ui::UiEventData& data, const std::vector<const lumin::ui::DropDownListItem*>& selection) {
    if (scene_) {
      scene_->audioSwitcherCallback(data, selection);
    }
  }

  void AudioEditor::pauseResumeButton_pauseResumeCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->pauseResumeCallback(data);
    }
  }

  void AudioEditor::stopButton_stopCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->stopCallback(data);
    }
  }

  void AudioEditor::muteButton_muteCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->muteCallback();
    }
  }

  void AudioEditor::loop_loopCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->loopCallback(data);
    }
  }

  void AudioEditor::spatial_spatialCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->spatialCallback();
    }
  }

  void AudioEditor::rotate_rotateCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->rotateCallback(data);
    }
  }

  void AudioEditor::volume_volumeCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->volumeCallback();
    }
  }

  void AudioEditor::pitch_pitchCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->pitchCallback();
    }
  }

  void AudioEditor::innerAngle_innerAngleCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->innerAngleCallback(data);
    }
  }

  void AudioEditor::outerAngle_outerAngleCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->outerAngleCallback(data);
    }
  }

  void AudioEditor::outerGain_outerGainCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->outerGainCallback(data);
    }
  }

  void AudioEditor::outerGainHF_outerGainCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->outerGainCallback(data);
    }
  }

  void AudioEditor::minDistance_minDistanceCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->minDistanceCallback(data);
    }
  }

  void AudioEditor::maxDistance_maxDistanceCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->maxDistanceCallback(data);
    }
  }

  void AudioEditor::channelDistance_channelDistanceCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->channelDistanceCallback(data);
    }
  }

  void AudioEditor::gain_gainCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->gainCallback(data);
    }
  }

  void AudioEditor::gainLf_gainCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->gainCallback(data);
    }
  }

  void AudioEditor::gainMf_gainCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->gainCallback(data);
    }
  }

  void AudioEditor::gainHf_gainCallback(const lumin::ui::UiEventData& data) {
    if (scene_) {
      scene_->gainCallback(data);
    }
  }

}
