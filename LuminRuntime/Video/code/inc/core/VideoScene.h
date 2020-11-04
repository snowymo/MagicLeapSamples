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
#include <LabelFader.h>
#include <BasePrismController.h>
#include <lumin/PrismController.h>
#include <lumin/ui/UiKit.h>
#include <lumin/node/VideoNode.h>
#include <lumin/utils/Status.h>
#include <lumin/event/ServerEvent.h>
/**
 * Video Example's Prism Controller, displays the video given with a user interface. Takes a
 * single video file, and adds a user interface to it.
 */
class VideoScene final : public lumin::SDKExamples::BasePrismController {
 public:
  /**
   * Constructs the Video Scene.
   * @param title          - the title of the video
   * @param videoLoc       - the path or URI to the video
   * @param videoRes       - the surface resolution of the video
   * @param viewMode       - the method to render the video on a quad: full area, or split left and right
   * @param loadFromEditor - true to use the scene graph created in the Lumin Runtime Editor
   * @param isPath         - true if the passed video location is a relative path, false if it is a URI
   */
  VideoScene(const std::string& title, const std::string& videoLoc,
      const glm::vec2& videoRes, lumin::ViewMode viewMode,
      bool loadFromEditor = false, bool isPath = true);

  /**
   * Destroys the Video Scene's Controller.
   */
  virtual ~VideoScene() {}

  /**
   * Creates the scene when it is attached to a prism.
   * @param prism - the prism the scene is attached to
   */
  void onAttachPrism(lumin::Prism* prism) override;

  /**
   * Destroys the scene when it is removed from a prism.
   * @param prism - the prism the scene will be removed from
   */
  void onDetachPrism(lumin::Prism* prism) override;

  /**
   * Updates the Video's slider and time display.
   * @param a_fDelta - time since last frame
   */
  void onUpdate(float a_fDelta) override;

  /**
   * Starts/Restarts the User Interface.
   * @param an_Event - returned Server Event
   * @return - true if the event was consumed, false otherwise
   */
  bool onEvent(lumin::ServerEvent* an_Event) override;

  /**
   * Plays the video.
   */
  void play();

  /**
   * Pauses the video.
   */
  void pause();

  /**
   * Called each time the page switcher is toggled for the active BasePrismController.
   * @param[in] on - true if this controller is the active page.
   */
  void onToggleChanged(bool active) override;

  /**
   * Called each time the application is paused for the active BasePrismController.
   */
  void onAppPause() override;

  /**
   * Called each time the application is resumed from the pause state for the active BasePrismController.
   */
  void onAppResume() override;

  /**
   * Initializes and loads the scene graph created in the Lumin Runtime Editor.
   * param[in] prism - The prism to associate loaded nodes with.
   */
  lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) override;

  /**
   * Initializes the scene graph created using the Lumin Runtime SDK.
   * param[in] prism - The prism to associated constructed nodes with.
   */
   lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) override;

 protected:
 /**
  * Creates a hidden panel for hidding the cursor during playback.
  * param[in] prism - The prism to associated constructed nodes with.
  */
  void createHiddenPanel(lumin::Prism* prism);

  /**
  * Creates the video node for playback.
  * param[in] prism - The prism to associated constructed nodes with.
  */
  void createVideoNode(lumin::Prism* prism);

  /**
   * Sets the common properties for both the loaded and built scene graphs.
   */
  void setCommonProperties();

  /**
   * Registers callbacks for video playback and UI.
   */
  void onVideoReady();

  /**
   * Disables the play buttons, enables the pause buttons.
   * Fades out the video title.
   * Used when the user plays the video.
   */
  void toggleUIForPlaying();

  /**
   * Disables the pause buttons, enables the play buttons.
   * Fades in the video title.
   * Used when the user pauses the video.
   */
  void toggleUIForPausing();

  /**
   * Hides the video UI in a callback format.
   * @param[in] UiEventData - the event data returned in UiKit callbacks
   * @param[in] videoUI     - the video UI to hide
   * @param[in] transition  - true to transition the cursor to the hidden panel.
   */
  void hideUICallback(const lumin::ui::UiEventData&, lumin::ui::UiLinearLayout* videoUI, bool transition = true);

  /**
  * Error Handling for VideoNodes.
  * @param status   - the status code returned from VideoNode's methods
  * @param errorMsg - the error message to display if there is an error
  * @return         - true if there is no error, false otherwise
  */
  bool errorHandler(lumin::utils::StatusCode status, const std::string& errorMsg);

 private:
  int duration_;
  bool isPath_;
  bool isPrepared_;  // true when the video is ready for playback
  bool isSliding_;   // true when the video is sliding (seeking) to a new position
  bool loadedFromEditor_;
  std::string title_;
  std::string videoLoc_;
  std::string videoDuration_;
  lumin::ViewMode viewMode_;
  lumin::VideoNode* video_;
  lumin::ui::UiText* errorMsg_;
  lumin::ui::UiText* videoTime_;
  lumin::ui::UiText* videoSliderText_;
  lumin::ui::UiSlider* videoSlider_;
  lumin::ui::UiButton* playButton_;
  lumin::ui::UiButton* pauseButton_;
  lumin::ui::UiButton* miniPlayButton_;
  lumin::ui::UiButton* replayButton_;
  lumin::ui::UiButton* resetButton_;
  lumin::ui::UiListView* settingsList_;
  lumin::ui::UiRectLayout* videoUiNode_;
  lumin::ui::UiLinearLayout* topLayout_;
  lumin::ui::UiPanel* cursorHiddenPanel_;
  lumin::ui::UiPanel* cursorVisiblePanel_;
  lumin::ui::UiToggle* loopToggle_;
  lumin::ui::UiButton* videoMenuIcon_;
  lumin::ui::UiLinearLayout* fullMenu_;
  lumin::ui::UiButton* volumeButton_;
  lumin::ui::UiButton* muteButton_;
  lumin::ui::UiSlider* volumeSlider_;
  lumin::ui::UiLinearLayout* videoToolbar_;
  glm::vec2 videoResolution_;
  glm::vec2 videoSize_;
  glm::vec3 previousCursorPos_;
  LabelFader* videoTitle_;
};