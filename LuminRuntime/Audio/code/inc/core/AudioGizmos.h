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
#pragma once
#include <lumin/Prism.h>
#include <lumin/audio/Audio.h>
#include <lumin/node/AudioNode.h>

/**
 * Constructs a Visualization of Spatial Audio around the given node.
 */
void constructAudioGizmos(std::weak_ptr<lumin::Prism> prism_ptr, lumin::AudioNode* node, uint32_t channelCount);

/**
 * Remove Audio Gizmos.
 */
void removeAudioGizmos(std::weak_ptr<lumin::Prism> prism, lumin::TransformNode* attached);