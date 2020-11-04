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

#include <AudioEditorBase.h>
#include <AudioEditor.h>

namespace prefabs {

  const PrefabDescriptor& AudioEditorBase::getClassPrefabDescriptor() {
    return classPrefabDescriptor_;
  }

  PrefabBase* AudioEditorBase::createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root) {
    PrefabBase* const prefab = new AudioEditor(extendedPrefabManager, root);
    return prefab;
  }

  AudioEditorBase::AudioEditorBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : PrefabBase(extendedPrefabManager, root) {

    topLayout = lumin::ui::UiLinearLayout::CastFrom(root->findChild(Names::topLayout));
    audioSwitcher = lumin::ui::UiDropDownList::CastFrom(root->findChild(Names::audioSwitcher));
    audioUI = lumin::ui::UiLinearLayout::CastFrom(root->findChild(Names::audioUI));
    audioTitle = lumin::ui::UiText::CastFrom(root->findChild(Names::audioTitle));
    pauseResumeButton = lumin::ui::UiButton::CastFrom(root->findChild(Names::pauseResumeButton));
    stopButton = lumin::ui::UiButton::CastFrom(root->findChild(Names::stopButton));
    muteButton = lumin::ui::UiButton::CastFrom(root->findChild(Names::muteButton));
    loop = lumin::ui::UiToggle::CastFrom(root->findChild(Names::loop));
    spatial = lumin::ui::UiToggle::CastFrom(root->findChild(Names::spatial));
    rotate = lumin::ui::UiToggle::CastFrom(root->findChild(Names::rotate));
    volume = lumin::ui::UiSlider::CastFrom(root->findChild(Names::volume));
    pitch = lumin::ui::UiSlider::CastFrom(root->findChild(Names::pitch));
    spatialLayout = lumin::ui::UiLinearLayout::CastFrom(root->findChild(Names::spatialLayout));
    innerAngle = lumin::ui::UiSlider::CastFrom(root->findChild(Names::innerAngle));
    outerAngle = lumin::ui::UiSlider::CastFrom(root->findChild(Names::outerAngle));
    outerGain = lumin::ui::UiSlider::CastFrom(root->findChild(Names::outerGain));
    outerGainHF = lumin::ui::UiSlider::CastFrom(root->findChild(Names::outerGainHF));
    minDistance = lumin::ui::UiSlider::CastFrom(root->findChild(Names::minDistance));
    maxDistance = lumin::ui::UiSlider::CastFrom(root->findChild(Names::maxDistance));
    channelDistance = lumin::ui::UiSlider::CastFrom(root->findChild(Names::channelDistance));
    gain = lumin::ui::UiSlider::CastFrom(root->findChild(Names::gain));
    gainLf = lumin::ui::UiSlider::CastFrom(root->findChild(Names::gainLf));
    gainMf = lumin::ui::UiSlider::CastFrom(root->findChild(Names::gainMf));
    gainHf = lumin::ui::UiSlider::CastFrom(root->findChild(Names::gainHf));

    audioSwitcher->onSelectionChangedSub(std::bind(&AudioEditorBase::audioSwitcher_audioSwitcherCallback, this, std::placeholders::_1, std::placeholders::_2));
    pauseResumeButton->onActivateSub(std::bind(&AudioEditorBase::pauseResumeButton_pauseResumeCallback, this, std::placeholders::_1));
    stopButton->onActivateSub(std::bind(&AudioEditorBase::stopButton_stopCallback, this, std::placeholders::_1));
    muteButton->onActivateSub(std::bind(&AudioEditorBase::muteButton_muteCallback, this, std::placeholders::_1));
    loop->onToggleChangedSub(std::bind(&AudioEditorBase::loop_loopCallback, this, std::placeholders::_1));
    spatial->onToggleChangedSub(std::bind(&AudioEditorBase::spatial_spatialCallback, this, std::placeholders::_1));
    rotate->onToggleChangedSub(std::bind(&AudioEditorBase::rotate_rotateCallback, this, std::placeholders::_1));
    volume->onSliderChangedSub(std::bind(&AudioEditorBase::volume_volumeCallback, this, std::placeholders::_1));
    pitch->onSliderChangedSub(std::bind(&AudioEditorBase::pitch_pitchCallback, this, std::placeholders::_1));
    innerAngle->onSliderChangedSub(std::bind(&AudioEditorBase::innerAngle_innerAngleCallback, this, std::placeholders::_1));
    outerAngle->onSliderChangedSub(std::bind(&AudioEditorBase::outerAngle_outerAngleCallback, this, std::placeholders::_1));
    outerGain->onSliderChangedSub(std::bind(&AudioEditorBase::outerGain_outerGainCallback, this, std::placeholders::_1));
    outerGainHF->onSliderChangedSub(std::bind(&AudioEditorBase::outerGainHF_outerGainCallback, this, std::placeholders::_1));
    minDistance->onSliderChangedSub(std::bind(&AudioEditorBase::minDistance_minDistanceCallback, this, std::placeholders::_1));
    maxDistance->onSliderChangedSub(std::bind(&AudioEditorBase::maxDistance_maxDistanceCallback, this, std::placeholders::_1));
    channelDistance->onSliderChangedSub(std::bind(&AudioEditorBase::channelDistance_channelDistanceCallback, this, std::placeholders::_1));
    gain->onSliderChangedSub(std::bind(&AudioEditorBase::gain_gainCallback, this, std::placeholders::_1));
    gainLf->onSliderChangedSub(std::bind(&AudioEditorBase::gainLf_gainCallback, this, std::placeholders::_1));
    gainMf->onSliderChangedSub(std::bind(&AudioEditorBase::gainMf_gainCallback, this, std::placeholders::_1));
    gainHf->onSliderChangedSub(std::bind(&AudioEditorBase::gainHf_gainCallback, this, std::placeholders::_1));
  }

  AudioEditorBase::~AudioEditorBase() {
  }

  const PrefabDescriptor& AudioEditorBase::getPrefabDescriptor() const {
    return classPrefabDescriptor_;
  }

  const PrefabBase::NodeReferences& AudioEditorBase::getNodeReferences() const {
    return classNodeReferences_;
  }

  lumin::ui::UiLinearLayout* AudioEditorBase::getTopLayout() {
    return topLayout;
  }

  lumin::ui::UiDropDownList* AudioEditorBase::getAudioSwitcher() {
    return audioSwitcher;
  }

  lumin::ui::UiLinearLayout* AudioEditorBase::getAudioUI() {
    return audioUI;
  }

  lumin::ui::UiText* AudioEditorBase::getAudioTitle() {
    return audioTitle;
  }

  lumin::ui::UiButton* AudioEditorBase::getPauseResumeButton() {
    return pauseResumeButton;
  }

  lumin::ui::UiButton* AudioEditorBase::getStopButton() {
    return stopButton;
  }

  lumin::ui::UiButton* AudioEditorBase::getMuteButton() {
    return muteButton;
  }

  lumin::ui::UiToggle* AudioEditorBase::getLoop() {
    return loop;
  }

  lumin::ui::UiToggle* AudioEditorBase::getSpatial() {
    return spatial;
  }

  lumin::ui::UiToggle* AudioEditorBase::getRotate() {
    return rotate;
  }

  lumin::ui::UiSlider* AudioEditorBase::getVolume() {
    return volume;
  }

  lumin::ui::UiSlider* AudioEditorBase::getPitch() {
    return pitch;
  }

  lumin::ui::UiLinearLayout* AudioEditorBase::getSpatialLayout() {
    return spatialLayout;
  }

  lumin::ui::UiSlider* AudioEditorBase::getInnerAngle() {
    return innerAngle;
  }

  lumin::ui::UiSlider* AudioEditorBase::getOuterAngle() {
    return outerAngle;
  }

  lumin::ui::UiSlider* AudioEditorBase::getOuterGain() {
    return outerGain;
  }

  lumin::ui::UiSlider* AudioEditorBase::getOuterGainHF() {
    return outerGainHF;
  }

  lumin::ui::UiSlider* AudioEditorBase::getMinDistance() {
    return minDistance;
  }

  lumin::ui::UiSlider* AudioEditorBase::getMaxDistance() {
    return maxDistance;
  }

  lumin::ui::UiSlider* AudioEditorBase::getChannelDistance() {
    return channelDistance;
  }

  lumin::ui::UiSlider* AudioEditorBase::getGain() {
    return gain;
  }

  lumin::ui::UiSlider* AudioEditorBase::getGainLf() {
    return gainLf;
  }

  lumin::ui::UiSlider* AudioEditorBase::getGainMf() {
    return gainMf;
  }

  lumin::ui::UiSlider* AudioEditorBase::getGainHf() {
    return gainHf;
  }

}
