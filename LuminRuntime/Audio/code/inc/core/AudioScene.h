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
#include <lumin/PrismController.h>
#include <lumin/audio/Audio.h>
#include <lumin/ui/UiKit.h>
#include <lumin/node/AudioNode.h>
#include <lumin/utils/Status.h>
#include <lumin/event/ServerEvent.h>
#include <BaseExampleController.h>
#include <LabelFader.h>
#include <AudioExample.h>

#include <AudioModel.h>
#include <AudioEditor.h>

/**
 * Audio Example's Prism Controller, visualizes and plays Audio with a user interface.
 * Takes a single audio file, and adds a user interface to it.
 */
class AudioScene final : public lumin::SDKExamples::BasePrismController {
 public:
  /**
   * Constructs the Audio Scene.
   * @param application  - reference to the application using AudioScene, used to create and edit prisms.
   * @param audioTitle   - title of the audio file.
   * @param audioPath    - relative path of audio file to use for both streaming and non-streaming sound.
   * @param channelCount - number of channels in the audio file. Stereo = 2, Mono = 1, etc.
   */
  AudioScene(AudioBaseApp& application, const std::string& audioTitle, const std::string& audioPath, uint32_t channelCount);

  /**
   * Destroys the Audio Scene's Controller.
   */
  virtual ~AudioScene() {}

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
   * Updates the Audio Models rotation; used for spatial audio.
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
   * Plays the audio. Audio must be chosen first from the UI.
   */
  void play();

  /**
   * Pauses the audio. Audio must be chosen first from the UI.
   */
  void pause();

 private:
  /**
   * Loads the scene from the Lumin Runtime Editor.
   * @param[in] prism - the prism to load the scene in.
   * @return          - the root node of the scene, to be added.
   */
  lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) override;

  /**
   * Builds the scene.
   * @param[in] prism - the prism to build the scene in.
   * @return          - the root node of the scene, to be added.
   */
  lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) override;

  /**
   * Builds the Audio Model in the given prism.
   * @param[in] prism - prism to build the audio model in.
   */
  void buildAudio(lumin::Prism* prism);

  /**
   * Loads the Audio Model in the given prism.
   * @param[in] prism - prism to load the audio model in.
   */
  void loadAudio(lumin::Prism* prism);

  /**
   * Creates a Ui Dialog that spawns while all audio resources are being loaded in the Audio Prism.
   * Resources are loaded asynchronously; however large files will block the main thread.
   */
  void loadResources();

  /**
   * Deletes the given Ui Dialog when all audio resources are finished loading into the Audio Prism.
   * @param[in] loadingDialog - dialog to destroy once all resources are loaded.
   */
  void createResources(lumin::ui::UiDialog* loadingDialog);

  /**
   * Creates and populates the Audio Prism with a visualization of the AudioNode.
   */
  void createAudioPrism();

  /**
   * Removes the visualization of the AudioNode from the Audio Prism.
   */
  void removeAudioNodes();

  /**
   * Pauses the audio whenever the scene is switched.
   * @param[in] active - true if this scene is active.
   */
  void onToggleChanged(bool active) override;

  /**
   * Creates an AudioNode used for Output Streaming.
   */
  void createOutputStreamingBuffer();

  /**
   * The callback function used when creating an Output Streaming AudioNode.
   * @param AudioId - the Audio Stream to fill and release.
   * @param context - a pointer to an instance of an AudioScene.
   */
  static void fillAndReleaseOutputBufferWrapper(lumin::AudioId id, void* context);

  /**
   * Fills and Releases the output buffer used in Output Streaming AudioNodes.
   * This allows the AudioNode to start playing sound.
   * @param AudioId - the Audio Stream to fill and release.
   */
  void fillAndReleaseOutputBuffer(lumin::AudioId id);

  /**
   * Creates the UI used to change Audio properties.
   * @return - the layout containing the Audio UI
   */
  lumin::ui::UiLinearLayout* createAudioUI();

  /**
   * Creates the visual representation of the AudioNode.
   * @return - the parent TransformNode containing each representation of the AudioNode
   */
  lumin::TransformNode* createAudioModel(lumin::Prism* prism);

  /**
   * Creates a list which switches the type of audio played.
   * @return - the audio switcher list.
   */
  lumin::ui::UiDropDownList* createAudioSwitcher();

  /**
   * On Selection Changed Callback for the Audio Switcher List.
   * @param UiEventData - ignored
   * @param list        - list of elements
   */
  void audioSwitcherCallback(const lumin::ui::UiEventData&,
    const std::vector<const lumin::ui::DropDownListItem*>& list);

  /**
   * Copies the sound properties from one AudioNode to another.
   * @param copyFrom - copies the sound properties from this node
   * @param copyTo   - pastes the sound properties to this node
   */
  void copyAudioProperties(lumin::AudioNode* copyFrom, lumin::AudioNode* copyTo);

  /**
   * Stops the AudioNode and resets the Ui to the stopped state.
   */
  void reset();

  /**
   * Copies the values in the Ui to all AudioNodes.
   */
  void copyUi();

  /**
   * Creates all custom labels used for the UiSliders. Labels are displayed when the UiSlider is
   * changing values.
   */
  void createAllCustomLabels();

  /**
   * Creates buttons for START, RESUME, PAUSE, and STOP actions.
   * @param layout - adds the buttons to this layout
   */
  void createAudioPlayerButtons(lumin::ui::UiLinearLayout* layout);

  /**
   * On Activate Callback for the Stop button.
   * Stops the selected audio. Audio will play from the beginning when started.
   * @param UiEventData - ignored
   */
  void stopCallback(const lumin::ui::UiEventData&);

  /**
   * On Activate Callback for the Pause/Resume button.
   * Starts, Resumes, or Pauses the selected audio.
   * @param UiEventData - ignored
   */
  void pauseResumeCallback(const lumin::ui::UiEventData&);

  /**
   * On Activate Callback for the Mute/Unmute button.
   * Mutes or Unmutes the selected audio.
   * @param UiEventData - ignored
   */
  void muteCallback();

  /**
   * Creates toggles for enabling LOOP, SPATIAL, and ROTATE actions.
   * @param layout - adds the toggles to this layout
   */
  void createAudioPlayerToggles(lumin::ui::UiLinearLayout* layout);

  /**
   * On Activate Callback for the Loop toggle.
   * @param toggle - the updated toggle
   */
  void loopCallback(const lumin::ui::UiEventData& toggle);

  /**
   * On Activate Callback for the Spatial toggle.
   */
  void spatialCallback();

  /**
   * On Activate Callback for the Rotate toggle.
   * @param toggle - the updated toggle
   */
  void rotateCallback(const lumin::ui::UiEventData& toggle);

  /**
   * Creates sliders for setting VOLUME and PITCH.
   * @param layout - adds the sliders to this layout
   */
  void createAudioPlayerSliders(lumin::ui::UiLinearLayout* layout);

  /**
   * On Slider Changed Callback for the Volume slider.
   */
  void volumeCallback();

  /**
   * On Slider Changed Callback for the Pitch slider.
   */
  void pitchCallback();

  /**
   * Creates sliders for setting INNER ANGLE, OUTER ANGLE, and OUTER GAIN for spatial audio.
   * @param layout - adds the sliders to this layout
   */
  void createSpatialAngleSliders(lumin::ui::UiLinearLayout* layout);

  /**
   * Creates sliders for setting the Spatial Sound Level's gain, gain low frequency, gain mid frequency,
   * and gain high frequency levels.
   * @param layout - adds the sliders to this layout
   */
  void createSpatialGainSliders(lumin::ui::UiLinearLayout* layout);

  /**
   * On Slider Changed Callback for the Outer Angle slider.
   * @param UiEventData - ignored
   */
  void outerAngleCallback(const lumin::ui::UiEventData&);

  /**
   * On Slider Changed Callback for the Inner Angle slider.
   * @param UiEventData - ignored
   */
  void innerAngleCallback(const lumin::ui::UiEventData&);

  /**
   * On Slider Changed Callback for the Outer Gain slider.
   * @param UiEventData - the slider to change.
   */
  void outerGainCallback(const lumin::ui::UiEventData& slider);

  /**
   * On Slider Changed Callback for the Inner Gain slider.
   * @param UiEventData - the slider to change.
   */
  void gainCallback(const lumin::ui::UiEventData& slider);

  /**
   * Creates sliders for setting MIN DISTANCE, MAX DISTANCE, and CHANNEL DISTANCE for spatial audio.
   * @param layout - adds the sliders to this layout
   */
  void createSpatialDistanceSliders(lumin::ui::UiLinearLayout* layout);

  /**
   * On Slider Changed Callback for the Minimum Distance slider.
   * Minimum distance is the threshold past which the audio will not get any louder.
   * @param UiEventData - ignored
   */
  void minDistanceCallback(const lumin::ui::UiEventData&);

  /**
   * On Slider Changed Callback for the Maximum Distance slider.
   * Maximum distance is the threshold past which the audio will not get any quieter.
   * @param UiEventData - ignored
   */
  void maxDistanceCallback(const lumin::ui::UiEventData&);

  /**
   * On Slider Changed Callback for the Channel Distance slider.
   * Channel distance is the distance between the left and right channels.
   * @param UiEventData - ignored
   */
  void channelDistanceCallback(const lumin::ui::UiEventData&);

 private:
 /**
  * Allow handlers created in the editor access to private fields.
  */
  friend class prefabs::AudioEditor;

  uint32_t channelCount_;
  uint32_t streamedFileSize_;
  uint32_t streamedFileReadIndex_;
  float basePitch_;
  float audioPlacer_;
  bool moving_;
  bool noSound_;
  bool rotation_;
  bool firstPlay_;
  bool loaded_;
  const std::string audioPath_;
  const std::string audioTitle_;
  char* streamedFileBuf_;
  LabelFader* audioLabel_;
  Managers* audioModelManagers_;
  prefabs::AudioEditor* prefab_;
  prefabs::AudioModel* modelPrefab_;
  AudioBaseApp& application_;
  std::weak_ptr<lumin::Prism> audioPrism_;
  lumin::AudioNode* loadedAudio_;
  lumin::AudioNode* streamedAudio_;
  lumin::AudioNode* outputAudio_;
  lumin::AudioNode* audioNode_;
  lumin::TransformNode* audioHolder_;
  lumin::TransformNode* audioParent_;
  lumin::ui::UiLinearLayout* audioUI_;
  lumin::ui::UiDropDownList* audioSwitcher_;
  lumin::ui::UiButton* stopButton_;
  lumin::ui::UiButton* pauseResumeButton_;
  lumin::ui::UiButton* muteButton_;
  lumin::ui::UiToggle* loopToggle_;
  lumin::ui::UiToggle* spatialToggle_;
  lumin::ui::UiSlider* volume_;
  lumin::ui::UiSlider* pitch_;
  lumin::ui::UiSlider* outerAngle_;
  lumin::ui::UiSlider* innerAngle_;
  lumin::ui::UiSlider* gain_;
  lumin::ui::UiSlider* gainHf_;
  lumin::ui::UiSlider* gainLf_;
  lumin::ui::UiSlider* gainMf_;
  lumin::ui::UiSlider* outerGain_;
  lumin::ui::UiSlider* outerGainHf_;
  lumin::ui::UiSlider* minDistance_;
  lumin::ui::UiSlider* maxDistance_;
  lumin::ui::UiSlider* channelDistance_;
  lumin::ui::UiText* pitchText_;
  lumin::ui::UiText* outerLabel_;
  lumin::ui::UiText* innerLabel_;
  lumin::ui::UiText* minText_;
  lumin::ui::UiText* maxText_;
  lumin::ui::UiText* channelText_;
  lumin::ModelNode* muteModel_;
  lumin::ModelNode* offModel_;
  lumin::ModelNode* onModel_;
  lumin::ModelNode* playModel_;
  lumin::ui::UiLinearLayout* spatialLayout_;
};