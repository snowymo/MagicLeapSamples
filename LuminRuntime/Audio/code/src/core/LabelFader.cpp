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
#include <LabelFader.h>
#include <ExamplesDefines.h>
#include <lumin/Consts.h>

#include <glm/glm.hpp>
#include <ml_logging.h>

#include <algorithm>

using namespace lumin;
using namespace lumin::ui;

LabelFader::LabelFader(UiText* label, float fadeInTime, float fadeOutTime)
: label_(label),
  fadeBegin_(0.0f),
  fadeEnd_(1.0f),
  fadeTimer_(0.0f),
  fadeTime_(0.0f),
  maxFadeInTime_(fadeInTime),
  maxFadeOutTime_(fadeOutTime) {
  LUMIN_ASSERT(label != nullptr,
      "LabelFader::LabelFader() UiText* label is invalid.");
}

void LabelFader::fadeIn() {
  fade(1.0f, maxFadeInTime_);
}

void LabelFader::fadeOut() {
  fade(0.0f, maxFadeOutTime_);
}

// Changes the alpha levels of the label based on the current delta time:
void LabelFader::update(float a_fDelta) {
  if (label_ && 0.0f != fadeTimer_) {
    fadeTimer_      = std::max(0.0f, fadeTimer_ - a_fDelta);
    glm::vec4 color = label_->getTextColor();
    color.w         = fadeBegin_ + ((fadeEnd_ - fadeBegin_) * (1.0f - (fadeTimer_/fadeTime_)));
    label_->setTextColor(color);
  }
}

void LabelFader::fade(float fadeEnd, float fadeTime) {
  if (label_) {
    fadeBegin_ = label_->getTextColor().w;
    fadeEnd_   = fadeEnd;
    fadeTime_  = fadeTime;
    fadeTimer_ = fadeTime;
  }
}