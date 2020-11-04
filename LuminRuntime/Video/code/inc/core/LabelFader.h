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
#include <lumin/ui/node/UiText.h>
/**
 * Provides a fade-in and fade-out animation for UiText nodes.
 * Example usage:
 *   // construct the LabelFader for the given UiText node to fade:
 *   UiText* nodeToFade     = SDKExamples::createUiText(prism, "Fading Text");
 *   LabelFader* labelFader = new LabelFader(nodeToFade);
 *   // when we want the label to fade in, call the fadeIn() function:
 *   labelFader->fadeIn();
 *   // when we want the label to fade out, call the fadeOut() function:
 *   labelFader->fadeOut();
 *
 * NOTE: to perform the fade functions, the LabelFader's update function must be
 * called on the Client Thread's Update Loop:
 * (updateLoop() for Landscape Apps, or onUpdate() for Prism Controllers.)
 * Example usage:
 *   bool updateLoop(float a_fDelta) {
 *    labelFader->update(a_fDelta);
 *    return true;
 *   }
 */
class LabelFader {
 public:
  /**
   * Fades the given label with the given fade in and fade out times.
   * @param label       - the UiText label to fade in and out
   * @param fadeInTime  - the fade in time
   * @param fadeOutTime - the fade out time
   */
  LabelFader(lumin::ui::UiText* label, float fadeInTime = 0.5f,
      float fadeOutTime = 1.0f);

  /**
   * Starts the fade in transformation.
   */
  void fadeIn();

  /**
   * Starts the fade out transformation.
   */
  void fadeOut();

  /**
   * Uses the delta time to update the fade transformations.
   * Call this function on the Client Thread's update loop.
   * @param a_fDelta - the current delta time
   */
  void update(float a_fDelta);

 private:
  /**
   * Changes the internal fade values based on the fade times.
   */
  void fade(float fadeEnd, float fadeTime);

 private:
  lumin::ui::UiText* label_;
  float fadeBegin_;
  float fadeEnd_;
  float fadeTimer_;
  float fadeTime_;
  const float maxFadeInTime_;
  const float maxFadeOutTime_;
};