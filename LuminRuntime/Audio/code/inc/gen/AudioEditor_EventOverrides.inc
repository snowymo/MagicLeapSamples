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

#ifndef EVENT_OVERRIDES_INC
#error expected EVENT_OVERRIDES_INC defined (prevents accidental misuse)
#endif
#undef EVENT_OVERRIDES_INC

    void audioSwitcher_audioSwitcherCallback(const lumin::ui::UiEventData& data, const std::vector<const lumin::ui::DropDownListItem*>& selection) override;
    void pauseResumeButton_pauseResumeCallback(const lumin::ui::UiEventData& data) override;
    void stopButton_stopCallback(const lumin::ui::UiEventData& data) override;
    void muteButton_muteCallback(const lumin::ui::UiEventData& data) override;
    void loop_loopCallback(const lumin::ui::UiEventData& data) override;
    void spatial_spatialCallback(const lumin::ui::UiEventData& data) override;
    void rotate_rotateCallback(const lumin::ui::UiEventData& data) override;
    void volume_volumeCallback(const lumin::ui::UiEventData& data) override;
    void pitch_pitchCallback(const lumin::ui::UiEventData& data) override;
    void innerAngle_innerAngleCallback(const lumin::ui::UiEventData& data) override;
    void outerAngle_outerAngleCallback(const lumin::ui::UiEventData& data) override;
    void outerGain_outerGainCallback(const lumin::ui::UiEventData& data) override;
    void outerGainHF_outerGainCallback(const lumin::ui::UiEventData& data) override;
    void minDistance_minDistanceCallback(const lumin::ui::UiEventData& data) override;
    void maxDistance_maxDistanceCallback(const lumin::ui::UiEventData& data) override;
    void channelDistance_channelDistanceCallback(const lumin::ui::UiEventData& data) override;
    void gain_gainCallback(const lumin::ui::UiEventData& data) override;
    void gainLf_gainCallback(const lumin::ui::UiEventData& data) override;
    void gainMf_gainCallback(const lumin::ui::UiEventData& data) override;
    void gainHf_gainCallback(const lumin::ui::UiEventData& data) override;
