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
#include <ControllerEventWrapper.h>
#include <lumin/Consts.h>
#include <lumin/Prism.h>
#include <lumin/PrismController.h>
#include <lumin/node/ModelNode.h>
#include <lumin/node/LineNode.h>
#include <lumin/ui/node/UiText.h>
#include <lumin/ui/node/UiGridLayout.h>
#include <lumin/utils/CallbackID.h>

class ControllerVisualizer final : public lumin::PrismController {
 public:
  /**
   * Sets up the Visualizer with a default model placed in the prism, and controller status messages.
   */
  ControllerVisualizer();

  /**
   * Destroys the Visualizer.
   */
  virtual ~ControllerVisualizer();

  /**
   * Creates the scene when it is attached to a prism.
   * @param[in] prism - the prism the scene is attached to.
   */
  void onAttachPrism(lumin::Prism* prism) override;

  /**
   * Deletes the scene when it is removed from a prism.
   * Removes all callbacks from the Controller Event Wrapper.
   * @param[in] prism - the prism the scene will be detached from.
   */
  void onDetachPrism(lumin::Prism* prism) override;

  /**
   * Dispatches Controller Events.
   * @param an_Event - returned Server Event.
   * @return - true if the event was consumed, false otherwise.
   */
  bool onEvent(lumin::ServerEvent* an_Event) override;

  /**
   * Gets the Controller Event Wrapper used to add the visualization.
   */
  ControllerEventWrapper& getControllerEventWrapper();

  /**
   * Gets all of the controller models.
   * @return - the controller models.
   */
  std::map<int32_t /* device id */, lumin::ModelNode*> getModel() const;

  /**
   * Gets the status layout.
   * @return - the layout containing the controller's status.
   */
  lumin::ui::UiGridLayout* getStatusLayout() const;

  /**
   * Gets the prism outline.
   * @return - the prism outline.
   */
  lumin::LineNode* getPrismOutline() const;

 private:
  /**
   * Adds the callbacks for controller connection, trigger, 6DOF, 3DOF, and touchpad events.
   * @param[in] prism - prism to display the visualization in.
   */
  void addControllerCallbacks(lumin::Prism* prism);

  /**
   * Creates a status layout for the controller.
   * @param[in] prism    - prism to create the status layout in.
   * @param[in] deviceID - ID associated with the controller.
   */
  void createStatusLayout(lumin::Prism* prism, int32_t deviceID);

  /**
   * Creates an outline for the prism.
   * @param[in] prism - prism to create the outline for.
   */
  void createPrismOutline(lumin::Prism* prism);

  /**
   * Adds resources for the controller model to the given prism.
   * @param[in] prism - prism to create the model for.
   */
  void createControllerResources(lumin::Prism* prism);

  /**
   * Creates a default controller model.
   * @param[in] prism    - prism to create the model in.
   * @param[in] deviceID - ID associated with the controller model.
   * @param[in] source   - source of the controller.
   */
  void createControllerModel(lumin::Prism* prism, int32_t deviceID, lumin::input::EventSource source);

  /**
   * Displays or hides the controller model. Changes the device text to match connection changes.
   * @param[in] prism    - prism to visualize the event in.
   * @param[in] deviceID - ID associated with the controller model.
   * @param[in] type     - connected or disconnected event.
   */
  void connectionCallback(lumin::Prism* prism, int32_t deviceID, lumin::input::DeviceEventType type);

  /**
   * Visualizes trigger events.
   * @param[in] prism    - prism to visualize the event in.
   * @param[in] deviceID - ID associated with the controller model.
   * @param[in] source   - source of the controller.
   * @param[in] data     - trigger data to use.
   */
  void triggerCallback(lumin::Prism* prism, int32_t deviceID, lumin::input::EventSource source,
      const lumin::EventWrappers::ControllerTriggerData& data);

  /**
   * Rotates the mobile app.
   * @param[in] prism    - prism to create the model in.
   * @param[in] deviceID - ID associated with the controller model.
   * @param[in] rotation - rotates the Mobile App model to the given rotation.
   */
  void rotateMobileApp(lumin::Prism* prism, int32_t deviceID, const glm::quat& rotation);

  /**
   * Rotates and positions the controller.
   * @param[in] prism    - prism to create the model in.
   * @param[in] deviceID - ID associated with the controller model.
   * @param[in] rotation - rotates the controller model to the given rotation.
   * @param[in] position - positions the controller model to the given position.
   */
  void displayController(lumin::Prism* prism, int32_t deviceID, const glm::quat& rotation, const glm::vec3& position);

  /**
   * Displays the mobile app's touchscreen information.
   * @param[in] prism    - prism to create the visualization in.
   * @param[in] deviceID - ID associated with the controller model.
   * @param[in] data     - touchpad data to use.
   */
  void displayMobileAppTouches(lumin::Prism* prism, int32_t deviceID, const lumin::EventWrappers::ControllerTouchpadData& data);

  /**
   * Displays the controller's touchscreen information.
   * @param[in] prism    - prism to create the visualization in.
   * @param[in] deviceID - ID associated with the controller model.
   * @param[in] data     - touchpad data to use.
   */
  void displayControllerTouches(lumin::Prism* prism, int32_t deviceID, const lumin::EventWrappers::ControllerTouchpadData& data);

  /**
   * Calibrates the rotation of the mobile App model with the given rotation.
   * @param[in] prism    - prism to create the model in.
   * @param[in] deviceID - ID associated with the controller model.
   */
  void calibrateMobileApp(lumin::Prism* prism, int32_t deviceID);

  /**
   * Visualizes mobile app calibration.
   * @param[in] prism - prism to create the calibration text in.
   */
  void createCalibrationText(lumin::Prism* prism);

 private:
  ControllerEventWrapper controllerEvents_;  // provides an interface for event callbacks
  std::map<int32_t /* device id */, lumin::ModelNode*> controllerModels_;   // visualization of the controller
  std::map<int32_t /* device id */, lumin::ui::UiText*> deviceText_;
  std::map<int32_t /* device id */, lumin::ui::UiText*> positionText_;
  std::map<int32_t /* device id */, lumin::ui::UiText*> rotationText_;
  std::map<int32_t /* device id */, lumin::ui::UiText*> triggerText_;
  std::map<int32_t /* device id */, lumin::ui::UiText*> touchpadXYText_;
  std::map<int32_t /* device id */, lumin::ui::UiText*> touchpadForceText_;
  std::map<int32_t /* device id */, lumin::ui::UiText*> gestureText_;
  lumin::ui::UiGridLayout* statusLayout_;    // status text display of the controller
  lumin::LineNode* prismOutline_;            // outline of the prism
  lumin::ResourceIDType controllerRes_;
  lumin::ResourceIDType touchpadRes_;
  lumin::ResourceIDType mobileAppRes_;

  // Save the callback IDs for deletion:
  lumin::utils::CallbackID trigger_;
  lumin::utils::CallbackID sixDOF_;
  lumin::utils::CallbackID threeDOF_;
  lumin::utils::CallbackID touchpad_;
  lumin::utils::CallbackID connection_;

  bool mobileAppCalibration_;
  glm::quat mobileAppRotation_;
};