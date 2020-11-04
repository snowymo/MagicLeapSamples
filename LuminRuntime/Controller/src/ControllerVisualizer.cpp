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
#include <ControllerVisualizer.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesHelpers.h>
#include <ExamplesDefines.h>
#include <lumin/node/RootNode.h>
#include <lumin/node/QuadNode.h>
#include <lumin/utils/RendererInterface.h>

#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <ml_logging.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtc/quaternion.hpp>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const uint32_t kTextLayoutColumns = 2;
  const float kTriggerMaxForce      = 255.0f;  // maximum trigger force value
  const float kTextLayoutWidth      = 0.55f;
  const float kIconSize             = 0.05f;
  const float kTouchpadRadius       = 2.0f;  // accounting for the local scale of the model
  const float kTouchscreenRadius    = 4.0f;  // accounting for the local scale of the model
  const glm::vec2 kTextBoundsSize(0.7f, 0.0f);
  const glm::vec2 kGestureBoundsSize(0.2f, 0.1f);
  const glm::vec2 kAuraSize(0.4f, 0.15f);
  const glm::vec3 kControllerScale(0.01f);
  const glm::vec3 kMobileDeviceScale(0.007f);
  const glm::vec3 kCalibrateTextPosition(-0.15f, 0.1f, 0.2f);
  const glm::vec3 kMobileDevicePosition(0.0f, 0.32f, 0.1f);
  const glm::vec3 kAuraPosition(0.15f, 0.0f, 0.0f);
  const glm::vec3 kTouchscreenOffset(0.0f, 0.0f, -0.3f);
  const glm::vec3 kThumbScale(0.03f);
  const glm::vec3 kStatusOffset(-0.0f, -0.1f, 0.1f);
  const glm::vec4 kTitlePadding(0.02f, 0.0f, 0.01f, 0.01f);
  const glm::vec4 kTransparentBlack(0.0f, 0.0f, 0.0f, 0.05f);
  const glm::quat kInitialCalibrationRotation = glm::angleAxis(glm::half_pi<float>(), VEC3_RIGHT);
  const std::string kDevicePrefix        = "Device ID: ";
  const std::string kPositionPrefix      = "Position: ";
  const std::string kRotationPrefix      = "Rotation: ";
  const std::string kTriggerPrefix       = "Trigger: ";
  const std::string kTouchpadXYPrefix    = "Location: ";
  const std::string kTouchpadForcePrefix = "Pressure: ";
  const std::string kGesturePrefix       = "Gesture: ";
  const std::string kTouchpadModelName   = "_TouchpadModelName";
  const std::string kTouchPlaceholder    = "_TouchPlaceholder";
  const std::string kCalibrationName     = "_CalibrationName";
  const std::string kCalibrationText     = "Calibrating Mobile Device";
  const std::string kDisconnectedText    = " is disconnected";
  const std::string kControllerTexture   = "res/Controller/Controller.png";
  const std::string kControllerKmat      = "res/Controller/Controller.kmat";
  const std::string kControllerModel     = "res/Controller/Controller.fbx";
  const std::string kTouchpadModel       = "res/Controller/Thumb_Indicator.fbx";
  const std::string kMobileDeviceModel   = "res/Controller/MobileDevice.fbx";
  const std::string kMobileDeviceKmat    = "res/Controller/MobileDevice.kmat";
  const std::string kMobileDeviceTexture = "res/Controller/MobileDevice_Diffuse.png";
  const std::string kMobileScreenTexture = "res/Controller/MobileApp_DotGrid.png";
  const std::string kMobileTouchTexture  = "res/Controller/MobileApp_Touch.png";
}

// Construct the controller visualizer:
ControllerVisualizer::ControllerVisualizer()
  : PrismController("Controller Visualizer"),
    statusLayout_(nullptr),
    prismOutline_(nullptr),
    mobileAppCalibration_(true),
    mobileAppRotation_(kInitialCalibrationRotation) {
}

ControllerVisualizer::~ControllerVisualizer() {
}

// Destroy the controller visualizer:
void ControllerVisualizer::onDetachPrism(Prism*) {
  ML_LOG(Debug, "ControllerVisualizer onDetachPrism: Destroying Controller Visualizer");
  controllerEvents_.onTouchpadUnsub(touchpad_);
  controllerEvents_.on6DOFmoveUnsub(sixDOF_);
  controllerEvents_.on3DOFmoveUnsub(threeDOF_);
  controllerEvents_.onTriggerUnsub(trigger_);
  controllerEvents_.onConnectionChangedUnsub(connection_);
  deleteSceneGraph();
  controllerModels_.clear();
  deviceText_.clear();
  positionText_.clear();
  rotationText_.clear();
  triggerText_.clear();
  touchpadXYText_.clear();
  touchpadForceText_.clear();
  gestureText_.clear();
  statusLayout_ = nullptr;
  prismOutline_ = nullptr;
}

// Set up the callbacks for the controller model:
void ControllerVisualizer::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "ControllerVisualizer::onAttachPrism Initializing Controller Visualizer");
  glm::vec3 prismSize = prism->getSize();
  statusLayout_ = SDKExamples::createUiGridLayout(prism);
  statusLayout_->setSize({prismSize.x - 0.2f, 0.0f});
  statusLayout_->setAlignment(Alignment::TOP_CENTER);
  statusLayout_->setColumns(kTextLayoutColumns);
  statusLayout_->setSkipInvisibleItems(true);
  statusLayout_->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  statusLayout_->setLocalPosition(glm::vec3(0.0f, prismSize.y / 2.01f,
      -prismSize.z / 2.0f) + kStatusOffset);
  getRoot()->addChild(statusLayout_);
  Cursor::SetEnabled(prism, false);  // remove the UiKit Cursor from the scene
  createPrismOutline(prism);
  createControllerResources(prism);
  addControllerCallbacks(prism);
}

void ControllerVisualizer::addControllerCallbacks(Prism* prism) {
  auto createNewVisualization = [prism, this](int32_t deviceID, input::EventSource source) {
    if (controllerModels_.find(deviceID) == controllerModels_.end()) {
      createControllerModel(prism, deviceID, source);
      createStatusLayout(prism, deviceID);
    }
  };

  // add the callbacks to the Controller API, save the callback IDs:
  connection_ = controllerEvents_.onConnectionChangedSub([prism, this, createNewVisualization](int32_t deviceID,
      input::EventSource source, input::DeviceEventType type, bool isConnected) {
    createNewVisualization(deviceID, source);
    connectionCallback(prism, deviceID, type);
  });

  trigger_ = controllerEvents_.onTriggerSub([prism, createNewVisualization, this](const EventWrappers::ControllerTriggerData& data) {
    int32_t deviceID = controllerEvents_.getDeviceID();
    input::EventSource source = controllerEvents_.getEventSource();
    createNewVisualization(deviceID, source);
    triggerCallback(prism, deviceID, source, data);
  });

  sixDOF_ = controllerEvents_.on6DOFmoveSub([prism, createNewVisualization, this](const glm::quat& rot, const glm::vec3& pos) {
    int32_t deviceID = controllerEvents_.getDeviceID();
    input::EventSource source = controllerEvents_.getEventSource();
    createNewVisualization(deviceID, source);
    displayController(prism, deviceID, rot, pos);
  });

  threeDOF_ = controllerEvents_.on3DOFmoveSub([prism, createNewVisualization, this](const glm::quat& rot) {
    if (controllerEvents_.getEventSource() == input::EventSource::COMPANION_APP) {
      int32_t deviceID = controllerEvents_.getDeviceID();
      input::EventSource source = controllerEvents_.getEventSource();
      createNewVisualization(deviceID, source);
      rotateMobileApp(prism, deviceID, rot);
    }
  });

  touchpad_ = controllerEvents_.onTouchpadSub([prism, createNewVisualization, this](const EventWrappers::ControllerTouchpadData& data) {
    int32_t deviceID = controllerEvents_.getDeviceID();
    input::EventSource source = controllerEvents_.getEventSource();
    createNewVisualization(deviceID, source);
    if (source == input::EventSource::COMPANION_APP) {
      displayMobileAppTouches(prism, deviceID, data);
    } else {
      displayControllerTouches(prism, deviceID, data);
    }
    // filter out NONE gesture types:
    if (data.type != input::GestureType::NONE) {
      gestureText_[deviceID]->setText(ExampleHelpers::gestureTypeToString(data.type));
    }
  });
}

void ControllerVisualizer::createStatusLayout(Prism* prism, int32_t deviceID) {
  UiGridLayout* textLayout = SDKExamples::createUiGridLayout(prism);
  textLayout->setColumns(kTextLayoutColumns);
  textLayout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  textLayout->setDefaultItemAlignment(Alignment::CENTER_LEFT);
  textLayout->setSize({kTextLayoutWidth, 0.0f});
  statusLayout_->addItem(textLayout, ExampleConsts::kDefaultPadding,
    (statusLayout_->getItemCount() % 2)? Alignment::TOP_RIGHT : Alignment::TOP_LEFT);
  auto setupText = [textLayout, prism](const std::string& name, const std::string& init) {
    UiText* prefix = SDKExamples::createEclipseLabel(prism, name, EclipseLabelType::kT2);
    UiText* text   = SDKExamples::createEclipseLabel(prism, init, EclipseLabelType::kT4);
    text->setBoundsSize(kTextBoundsSize);
    UiRectLayout* textContainer = SDKExamples::createUiRectLayout(prism);
    textContainer->setSize({kTextLayoutWidth / 2.0f, 0.0f});
    textContainer->setContent(text);
    textLayout->addItem(prefix);
    textLayout->addItem(textContainer);
    return text;
  };
  auto setupTitle = [textLayout, prism](const std::string& name) {
    UiText* title = SDKExamples::createEclipseLabel(prism, name, EclipseLabelType::kT2);
    title->setTextColor(color::ORANGE);
    textLayout->addItem(title, kTitlePadding);
    textLayout->addItem(SDKExamples::createTransformNode(prism)); // add extra item for alignment
  };
  deviceText_[deviceID]   = setupText(kDevicePrefix, std::to_string(deviceID));
  positionText_[deviceID] = setupText(kPositionPrefix, ExampleHelpers::vecToString(lumin::VEC3_ZERO));
  rotationText_[deviceID] = setupText(kRotationPrefix, ExampleHelpers::vecToString(lumin::VEC3_ZERO));
  setupTitle("Buttons");
  triggerText_[deviceID] = setupText(kTriggerPrefix, ExampleHelpers::floatToString(0.0f));
  setupTitle("Touchpad");
  touchpadXYText_[deviceID]    = setupText(kTouchpadXYPrefix, ExampleHelpers::vecToString(lumin::VEC2_ZERO));
  touchpadForceText_[deviceID] = setupText(kTouchpadForcePrefix, ExampleHelpers::floatToString(0.0f));
  setupTitle("Gestures");
  gestureText_[deviceID] = SDKExamples::createEclipseLabel(prism,
      ExampleHelpers::gestureTypeToString(input::GestureType::NONE), EclipseLabelType::kT4);
  gestureText_[deviceID]->setFont(resources::FontStyle::kItalic);
  UiRectLayout* textContainer = SDKExamples::createUiRectLayout(prism);
  textContainer->setSize(kGestureBoundsSize);
  textContainer->setContent(gestureText_[deviceID]);
  textLayout->addItem(textContainer);
}

ControllerEventWrapper& ControllerVisualizer::getControllerEventWrapper() {
  return controllerEvents_;
}

std::map<int32_t, ModelNode*> ControllerVisualizer::getModel() const {
  return controllerModels_;
}

UiGridLayout* ControllerVisualizer::getStatusLayout() const {
  return statusLayout_;
}

LineNode* ControllerVisualizer::getPrismOutline() const {
  return prismOutline_;
}

// Trace the path of the edges of the prism:
void ControllerVisualizer::createPrismOutline(Prism* prism) {
  glm::vec3 prismSize = prism->getSize() * 0.49f;
  prismOutline_ = SDKExamples::createLineNode(getPrism());
  prismOutline_->addPoints(glm::vec3(-prismSize.x, prismSize.y, prismSize.z));
  prismOutline_->addPoints(glm::vec3(-prismSize.x, -prismSize.y, prismSize.z));
  prismOutline_->addPoints(glm::vec3(prismSize.x, -prismSize.y, prismSize.z));
  prismOutline_->addPoints(glm::vec3(prismSize.x, prismSize.y, prismSize.z));
  prismOutline_->addPoints(glm::vec3(-prismSize.x, prismSize.y, prismSize.z));
  prismOutline_->addPoints(glm::vec3(-prismSize.x, prismSize.y, -prismSize.z));
  prismOutline_->addPoints(glm::vec3(prismSize.x, prismSize.y, -prismSize.z));
  prismOutline_->addPoints(glm::vec3(prismSize.x, prismSize.y, prismSize.z));
  prismOutline_->addPoints(glm::vec3(prismSize.x, -prismSize.y, prismSize.z));
  prismOutline_->addPoints(glm::vec3(prismSize.x, -prismSize.y, -prismSize.z));
  prismOutline_->addPoints(glm::vec3(prismSize.x, prismSize.y, -prismSize.z));
  prismOutline_->addPoints(glm::vec3(prismSize.x, -prismSize.y, -prismSize.z));
  prismOutline_->addPoints(glm::vec3(-prismSize.x, -prismSize.y, -prismSize.z));
  prismOutline_->addPoints(glm::vec3(-prismSize.x, -prismSize.y, prismSize.z));
  prismOutline_->addPoints(glm::vec3(-prismSize.x, -prismSize.y, -prismSize.z));
  prismOutline_->addPoints(glm::vec3(-prismSize.x, prismSize.y, -prismSize.z));
  prismOutline_->setColor(color::MAGENTA);
  getRoot()->addChild(prismOutline_);

  // create transparent quadnodes of the prism extents:
  // this is to make focusing on the prism easier
  auto createQuad = [prismSize, prism, root = getRoot()](const glm::vec3& pos, const glm::quat& rot) {
    QuadNode* face = SDKExamples::createQuadNode(prism);
    face->setSize(prismSize * 2.0f);
    face->setColor(kTransparentBlack);
    face->setLocalPosition(pos);
    face->setLocalRotation(rot);
    face->setBackFaceCulls(true);
    root->addChild(face);
  };
  createQuad({-prismSize.x, -prismSize.y, prismSize.z}, ExampleConsts::kNoRotation);
  createQuad({-prismSize.x, -prismSize.y, -prismSize.z}, ExampleConsts::kNoRotation);
  createQuad({-prismSize.x, -prismSize.y, prismSize.z},
      glm::angleAxis(glm::half_pi<float>(), lumin::VEC3_UP));
  createQuad({prismSize.x, -prismSize.y, prismSize.z},
      glm::angleAxis(glm::half_pi<float>(), lumin::VEC3_UP));
  createQuad({-prismSize.x, prismSize.y, prismSize.z},
      glm::angleAxis(glm::half_pi<float>(), lumin::VEC3_RIGHT));
  createQuad({-prismSize.x, -prismSize.y, prismSize.z},
      glm::angleAxis(glm::half_pi<float>(), lumin::VEC3_RIGHT));
}

void ControllerVisualizer::createControllerResources(Prism* prism) {
  // create all textures:
  ResourceIDType texture  = prism->createTextureResourceId(Desc2d::DEFAULT, kControllerTexture);
  ResourceIDType kmat     = prism->createMaterialResourceId(kControllerKmat.c_str());
  ResourceIDType mTexture = prism->createTextureResourceId(Desc2d::DEFAULT, kMobileDeviceTexture);
  ResourceIDType screen   = prism->createTextureResourceId(Desc2d::DEFAULT, kMobileScreenTexture);
  ResourceIDType mKmat    = prism->createMaterialResourceId(kMobileDeviceKmat.c_str());

  // create the object resources:
  controllerRes_ = prism->createModelResourceId(kControllerModel.c_str(), 1.0f);
  touchpadRes_   = prism->createModelResourceId(kTouchpadModel.c_str(), 1.0f);
  mobileAppRes_  = prism->createModelResourceId(kMobileDeviceModel.c_str(), 1.0f);
  LUMIN_ASSERT(controllerRes_ != INVALID_RESOURCE_ID, "ControllerVisualizer::createControllerModel: Invalid Controller Model.");
  LUMIN_ASSERT(touchpadRes_ != INVALID_RESOURCE_ID, "ControllerVisualizer::createControllerModel: Invalid Touchpad Model.");
  LUMIN_ASSERT(mobileAppRes_ != INVALID_RESOURCE_ID, "ControllerVisualizer::createControllerModel: Invalid MobileApp Model.");
}

void ControllerVisualizer::createControllerModel(Prism* prism, int32_t deviceID, input::EventSource source) {
  if (source == input::EventSource::COMPANION_APP) {
    // design the mobile device:
    ModelNode* mobileModel = SDKExamples::createModelNode(prism, mobileAppRes_);
    mobileModel->setLocalScale(kMobileDeviceScale);
    mobileModel->setShader(lumin::utils::ShaderType::kPbr);
    mobileModel->setSkipRaycast(true);
    mobileModel->setColor(color::PINK);
    mobileModel->setLocalPosition(kMobileDevicePosition);
    mobileModel->setLocalRotation(kInitialCalibrationRotation);
    createCalibrationText(prism);
    getRoot()->addChild(mobileModel);
    controllerModels_[deviceID] = mobileModel;
  } else {
    // design the touchpad indicator:
    ModelNode* touchpadModel = SDKExamples::createModelNode(prism, touchpadRes_);
    touchpadModel->setColor(color::BLACK * 0.0f);
    touchpadModel->setLocalScale(kThumbScale / kControllerScale);
    touchpadModel->setShader(lumin::utils::ShaderType::kUnlitTextured);
    touchpadModel->setName(kTouchpadModelName + std::to_string(deviceID));
    // design the controller:
    ModelNode* controllerModel = SDKExamples::createModelNode(prism, controllerRes_);
    controllerModel->setLocalScale(kControllerScale);
    controllerModel->setShader(lumin::utils::ShaderType::kPbr);
    controllerModel->setSkipRaycast(true);
    controllerModel->addChild(touchpadModel);
    getRoot()->addChild(controllerModel);
    controllerModels_[deviceID] = controllerModel;
  }
}

bool ControllerVisualizer::onEvent(ServerEvent* an_Event) {
  return controllerEvents_.eventDispatcher(an_Event);
}

void ControllerVisualizer::connectionCallback(Prism* prism, int32_t deviceID, input::DeviceEventType type) {
  UiText* calibrating = UiText::CastFrom(prism->findNode(kCalibrationName, getRoot()));
  if (type == input::DeviceEventType::CONNECT) {
    controllerModels_[deviceID]->setVisible(true, true);
    deviceText_[deviceID]->setText(std::to_string(deviceID));
    deviceText_[deviceID]->setTextColor(color::WHITE);
    if (calibrating) {
      calibrating->setVisible(true, true);
    }
  } else if (type == input::DeviceEventType::DISCONNECT) {
    if (controllerModels_[deviceID] && deviceText_[deviceID]) {
      controllerModels_[deviceID]->setVisible(false, true);
      deviceText_[deviceID]->setText(std::to_string(deviceID) + kDisconnectedText);
      deviceText_[deviceID]->setTextColor(color::RED);
      if (calibrating) {
        calibrating->setVisible(false, true);
      }
    }
  }
}

void ControllerVisualizer::triggerCallback(Prism* prism, int32_t deviceID, input::EventSource source,
    const EventWrappers::ControllerTriggerData& data) {
  // display the normalized trigger force:
  triggerText_[deviceID]->setText(ExampleHelpers::floatToString(data.force / kTriggerMaxForce));
  gestureText_[deviceID]->setText(ExampleHelpers::gestureTypeToString(data.type));

  if (source == input::EventSource::COMPANION_APP) {
    if (data.type == input::GestureType::TriggerClick) {
      calibrateMobileApp(prism, deviceID);
    }
  }
}

void ControllerVisualizer::rotateMobileApp(Prism* prism, int32_t deviceID, const glm::quat& rotation) {
  if (mobileAppCalibration_) {
    mobileAppRotation_ = prism->getRotation() * kInitialCalibrationRotation * glm::inverse(rotation);
    controllerModels_[deviceID]->setLocalRotation(kInitialCalibrationRotation);
  } else {
    controllerModels_[deviceID]->setLocalRotation(ExampleHelpers::worldToPrismSpace(prism, mobileAppRotation_ * rotation));
  }
  controllerModels_[deviceID]->setLocalPosition(kMobileDevicePosition);
  controllerModels_[deviceID]->setLocalScale(kMobileDeviceScale / prism->getScale());  // size does not change with prism's scale
  positionText_[deviceID]->setText(ExampleHelpers::vecToString(ExampleConsts::kDefaultLocalPos));
  rotationText_[deviceID]->setText(ExampleHelpers::vecToString(glm::degrees(glm::eulerAngles(rotation))));
}

void ControllerVisualizer::displayController(Prism* prism, int32_t deviceID, const glm::quat& rotation, const glm::vec3& position) {
  controllerModels_[deviceID]->setLocalPosition(ExampleHelpers::worldToPrismSpace(prism, position));
  controllerModels_[deviceID]->setLocalRotation(ExampleHelpers::worldToPrismSpace(prism, rotation));
  controllerModels_[deviceID]->setLocalScale(kControllerScale / prism->getScale());  // size does not change with prism's scale
  positionText_[deviceID]->setText(ExampleHelpers::vecToString(position));
  rotationText_[deviceID]->setText(ExampleHelpers::vecToString(glm::degrees(glm::eulerAngles(rotation))));
}

void ControllerVisualizer::displayMobileAppTouches(Prism* prism, int32_t deviceID,
    const EventWrappers::ControllerTouchpadData& data) {
  TransformNode* touchPlaceholder = TransformNode::CastFrom(prism->findNode(kTouchPlaceholder, controllerModels_[deviceID]));
  Node::Delete(touchPlaceholder);
  touchPlaceholder = SDKExamples::createTransformNode(prism);
  touchPlaceholder->setName(kTouchPlaceholder);
  controllerModels_[deviceID]->addChild(touchPlaceholder);
  std::string touchLocations = "";
  for (int i = 0; i < data.count; ++i) {
    UiImage* touch = SDKExamples::createUiImage(prism, kMobileTouchTexture, 1.0f, 1.0f);
    touch->setIsOpaque(false);
    touch->setLocalPosition(kTouchscreenRadius *
        (kTouchscreenOffset + glm::vec3(data.positions[i].x, 0.5f, -data.positions[i].y)));
    touch->setLocalRotation(glm::inverse(kInitialCalibrationRotation));
    touchPlaceholder->addChild(touch);
    touchLocations += ExampleHelpers::vecToString({data.positions[i].x, data.positions[i].y});
    if (i != data.count - 1) {
      touchLocations += ",  ";
    }
  }
  touchpadXYText_[deviceID]->setText(touchLocations);
  touchpadForceText_[deviceID]->setText(ExampleHelpers::floatToString(0.0f));
}

void ControllerVisualizer::displayControllerTouches(Prism* prism, int32_t deviceID,
    const EventWrappers::ControllerTouchpadData& data) {
  if (data.count > 0) {
    glm::vec3 touchpadData   = data.positions[data.count - 1];
    ModelNode* touchpadModel = ModelNode::CastFrom(prism->findNode(kTouchpadModelName + std::to_string(deviceID),
        controllerModels_[deviceID]));
    if (touchpadModel) {
      touchpadModel->setLocalPosition(glm::vec3(touchpadData.x * kTouchpadRadius, 1.0f,
          -touchpadData.y * kTouchpadRadius));
      touchpadModel->setLocalRotation(glm::vec3(0.0f, glm::pi<float>() -
          glm::atan(touchpadData.x, touchpadData.y), 0.0f));
      glm::quat color = glm::lerp(glm::quat(color::CYAN),
          glm::quat(color::RED), touchpadData.z);
      touchpadModel->setColor(glm::vec4(color.x, color.y, color.z, 1.0f));
    }
    touchpadXYText_[deviceID]->setText(ExampleHelpers::vecToString({touchpadData.x, touchpadData.y}));
    touchpadForceText_[deviceID]->setText(ExampleHelpers::floatToString(touchpadData.z));
  }
}

void ControllerVisualizer::calibrateMobileApp(Prism* prism, int32_t deviceID) {
  mobileAppCalibration_ = !mobileAppCalibration_;
  UiText* calibrating = UiText::CastFrom(prism->findNode(kCalibrationName, getRoot()));
  if (mobileAppCalibration_) {
    if (!calibrating) {
      createCalibrationText(prism);
    }
  } else {
    Node::Delete(calibrating);
  }
}

void ControllerVisualizer::createCalibrationText(Prism* prism) {
  MaskingAura* aura = SDKExamples::createMaskingAura(prism);
  UiText* calibrating = SDKExamples::createEclipseLabel(prism, kCalibrationText, EclipseLabelType::kT4);
  calibrating->setLocalPosition(kMobileDevicePosition + kCalibrateTextPosition);
  calibrating->setTextColor(color::ORANGE);
  calibrating->setTextAlignment(HorizontalTextAlignment::kCenter);
  calibrating->setName(kCalibrationName);
  aura->setSize(kAuraSize);
  aura->node()->setLocalPosition(kAuraPosition);
  calibrating->addChild(aura->node());
  getRoot()->addChild(calibrating);
}