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

#include <GestureVisualizer.h>
#include <ExamplesDefines.h>
#include <ExamplesHelpers.h>
#include <NodeCreationWrappers.h>
#include <Gesture.h>
#include <DesignManager.h>

#include <lumin/Prism.h>
#include <lumin/event/GestureInputEventData.h>
#include <lumin/node/RootNode.h>
#include <lumin/node/TransformNode.h>
#include <lumin/ui/node/UiImage.h>
#include <lumin/ui/node/UiText.h>
#include <functional>
#include <regex>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;
using namespace lumin::input;
using namespace lumin::SDKExamples;

const uint32_t kMaxKeypoints   = 24;
const uint32_t kLeftHandIndex  = 0;
const uint32_t kRightHandIndex = 1;
const float kTextSize          = 0.05f;
const float kSmallTextSize     = 0.01f;
const float kVerySmallTextSize = 0.008f;
const glm::vec2 kTextContainerSize = {0.125f, 0.08f};
const glm::vec2 kTextBoundsSize    = {0.2f, 0.0f};
const glm::vec2 kImageSize         = {0.15f, 0.15f};
const glm::vec2 kGridSize          = {0.0f, 0.17f};
const glm::vec3 kKeypointScale     = glm::vec3(0.005f, 0.005f, 0.005f);
const std::vector<glm::vec2> kLeftTexCoords  = {{0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}};
const std::vector<glm::vec2> kRightTexCoords = {{1.0f, 1.0f}, {0.0f, 1.0f}, {0.0, 0.0f}, {1.0f, 0.0f}};
const std::string kLeftHandConfidence        = "Left Pose Confidence: ";
const std::string kRightHandConfidence       = "Right Pose Confidence: ";
const std::string kLeftHandGesture           = "Left Hand Gesture: ";
const std::string kRightHandGesture          = "Right Hand Gesture: ";
const std::string kKeypointModelText         = "Display Keypoint Models: ";
const std::string kKeypointNamesText         = "Display Keypoint Names: ";
const std::string kNoPoseName                = ExampleHelpers::gestureTypeToString(GestureType::HAND_NO_POSE);

// Taken from scenes/Gesture.scene.res.xml.
// These are the paths used for these resources in our application.
const std::string kFingerResourcePath  = "assets/Gesture_Finger.png/Q1IyFtCYpXs/Gesture_Finger.png";
const std::string kFistResourcePath    = "assets/Gesture_Fist.png/7v9085hS3gk/Gesture_Fist.png";
const std::string kPinchResourcePath   = "assets/Gesture_Pinch.png/AXdsAplKz8w/Gesture_Pinch.png";
const std::string kThumbResourcePath   = "assets/Gesture_Thumb.png/RTZnGZLCSeI/Gesture_Thumb.png";
const std::string kLResourcePath       = "assets/Gesture_L.png/Wf_b8HCy-dw/Gesture_L.png";
const std::string kOpenResourcePath    = "assets/Gesture_OpenHandBack.png/HFieWK_LlOY/Gesture_OpenHandBack.png";
const std::string kOkResourcePath      = "assets/Gesture_OK.png/0jfibYs6oTw/Gesture_OK.png";
const std::string kCResourcePath       = "assets/Gesture_C.png/NLCjltmxMhU/Gesture_C.png";
const std::string kSphereResourcePath  = "assets/sphere.fbx/74_mt_wL7no/sphere.fbx";
const std::string kMatResourcePath     = "assets/sphere.kmat/wA8NQGulXEI/sphere.kmat";

GestureVisualizer::GestureVisualizer()
: BaseExample("GestureVisualizer") {
  gestureController_ = std::make_shared<GestureController>();
  addChildController(gestureController_);
}

GestureVisualizer::~GestureVisualizer() {
  gestureController_.reset();
}

void GestureVisualizer::onAttachPrism(Prism* prism) {
  BaseExample::onAttachPrism(prism);
  std::vector<Node*> pageLayouts = getRoot()->findChildren(UiPageView::GetNodeTypeEnum());
  LUMIN_ASSERT(!pageLayouts.empty(), "Invalid UiPageView");
  pageLayout_ = UiPageView::CastFrom(pageLayouts[0]);

  // Regsiter for every gesture type callback with the gesture controller.
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_FINGER, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Finger, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_FIST, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Fist, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_PINCH, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Pinch, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_THUMB, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Thumb, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_L, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::L, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_OPENHANDBACK, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::OpenHandBack, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_OK, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Ok, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_C, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::C, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->addGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_NO_POSE, std::bind(&GestureVisualizer::onGestureHand, this, kNoPoseName, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
}

void GestureVisualizer::onDetachPrism(Prism* prism) {
  // Deregister every gesture type callback.
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_FINGER, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Finger, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_FIST, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Fist, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_PINCH, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Pinch, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_THUMB, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Thumb, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_L, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::L, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_OPENHANDBACK, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::OpenHandBack, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_OK, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::Ok, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_C, std::bind(&GestureVisualizer::onGestureHand, this,
      prefabs::GestureBase::Names::C, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  gestureController_->removeGestureCallback(reinterpret_cast<int64_t>(this), GestureType::HAND_NO_POSE, std::bind(&GestureVisualizer::onGestureHand, this, kNoPoseName, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
  BaseExample::onDetachPrism(prism);
}

TransformNode* GestureVisualizer::loadSceneGraph(Prism* prism) {
  prefabs::Gesture* prefab = managers_->extendedPrefab_->spawn<prefabs::Gesture>();
  LUMIN_ASSERT(prefab, "Failed to create Gestures Prefab");

  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  rootContainer->addChild(prefab->getRoot());
  Node::Delete(prefab->getKeypoint()); // re-create the keypoint instance when a hand is present in the prism.
  return rootContainer;
}

TransformNode* GestureVisualizer::buildSceneGraph(Prism* prism) {
  // Want to share assets so load the editor scene assets here so they can be used when creating the images.
  const PrefabDescriptor &sd = prefabs::GestureBase::getClassPrefabDescriptor();
  managers_->extendedPrefab_->setModelState(sd, DesignManager::ModelState::ResourceModelLoaded);

  // Build out the scene graph.  Start with a vertical layout.
  UiLinearLayout* linearLayout = SDKExamples::createUiLinearLayout(prism);
  linearLayout->setOrientation(Orientation::kVertical);
  linearLayout->setLocalScale({0.6f, 0.6f, 0.6f});
  linearLayout->setAlignment(Alignment::CENTER_CENTER);
  linearLayout->setDefaultItemAlignment(Alignment::CENTER_CENTER);

  // Create a grid to contain the textual confidence data and the gesture name data.
  auto createGrid = [prism, linearLayout]() -> UiGridLayout* {
    UiGridLayout* grid = SDKExamples::createUiGridLayout(prism);
    grid->setRows(2);
    grid->setColumns(2);
    grid->setSize(kGridSize);
    grid->setDefaultItemPadding({0.01f, 0.01f, 0.01f, 0.01f});
    grid->setDefaultItemAlignment(Alignment::CENTER_LEFT);
    grid->setAlignment(Alignment::TOP_CENTER);
    linearLayout->addItem(grid);
    return grid;
  };
  UiGridLayout* confidenceGrid = createGrid();

  // Create text layouts to contain the titles and their changing text values.
  auto createText = [prism](UiGridLayout* grid, const std::string& name,
      const std::string& title, const std::string& value = "0.00") {
    UiText* handText = SDKExamples::createUiText(prism, title);
    handText->setTextSize(kTextSize);
    UiRectLayout* textContainer = SDKExamples::createUiRectLayout(prism);
    textContainer->setContentAlignment(Alignment::CENTER_LEFT);
    textContainer->setSize(kTextContainerSize);
    UiText* handValue = SDKExamples::createUiText(prism, value);
    handValue->setTextSize(kTextSize);
    handValue->setName(name);
    handValue->setBoundsSize(kTextBoundsSize);
    textContainer->setContent(handValue);
    grid->addItem(handText);
    grid->addItem(textContainer);
  };
  createText(confidenceGrid, prefabs::GestureBase::Names::LeftHandValue, kLeftHandConfidence);
  createText(confidenceGrid, prefabs::GestureBase::Names::RightHandValue, kRightHandConfidence);

  // Create a grid of UI images for each supported gesture.
  UiGridLayout* gestureImageGrid = SDKExamples::createUiGridLayout(prism);
  gestureImageGrid->setRows(2);
  gestureImageGrid->setColumns(4);
  gestureImageGrid->setDefaultItemPadding({0.05f, 0.05f, 0.05f, 0.05f});
  gestureImageGrid->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  gestureImageGrid->setAlignment(Alignment::CENTER_CENTER);

  auto createImage = [prism, gestureImageGrid] (const std::string& name, const std::string& path) {
    UiImage* gesture = SDKExamples::createUiImage(prism, prism->getResource(path), kImageSize.x, kImageSize.y);
    gesture->setName(name);
    gesture->setAlignment(Alignment::CENTER_CENTER);
    gestureImageGrid->addItem(gesture);
  };
  createImage(prefabs::GestureBase::Names::Finger, kFingerResourcePath);
  createImage(prefabs::GestureBase::Names::Fist, kFistResourcePath);
  createImage(prefabs::GestureBase::Names::Pinch, kPinchResourcePath);
  createImage(prefabs::GestureBase::Names::Thumb, kThumbResourcePath);
  createImage(prefabs::GestureBase::Names::L, kLResourcePath);
  createImage(prefabs::GestureBase::Names::OpenHandBack, kOpenResourcePath);
  createImage(prefabs::GestureBase::Names::Ok, kOkResourcePath);
  createImage(prefabs::GestureBase::Names::C, kCResourcePath);
  linearLayout->addItem(gestureImageGrid);

  // Add the gesture name data to the end of the linear layout.
  UiGridLayout* gestureTextGrid = createGrid();
  createText(gestureTextGrid, prefabs::GestureBase::Names::LeftHandGestureValue, kLeftHandGesture,
      ExampleHelpers::gestureTypeToString(input::GestureType::NONE));
  createText(gestureTextGrid, prefabs::GestureBase::Names::RightHandGestureValue, kRightHandGesture,
      ExampleHelpers::gestureTypeToString(input::GestureType::NONE));

  // Create keypoint toggles.
  auto createKeypointToggle = [prism, linearLayout](const std::string& text, const std::string& name) {
    UiToggle* keypoint = SDKExamples::createEclipseToggle(prism, EclipseToggleParams(EclipseToggleType::kSwitchWithIcon, ""));
    keypoint->setText(text);
    keypoint->setTextSize(kTextSize);
    keypoint->setName(name);
    keypoint->setOn(true);
    linearLayout->addItem(keypoint, ExampleConsts::kDefaultPadding);
  };
  createKeypointToggle(kKeypointModelText, prefabs::GestureBase::Names::keypointModelToggle);
  createKeypointToggle(kKeypointNamesText, prefabs::GestureBase::Names::keypointNamesToggle);
  return linearLayout;
}

std::pair<UiText*, ModelNode*> GestureVisualizer::findOrCreateHandNode(Prism* prism, std::string& text) {
  UiText* uiText   = static_cast<UiText*>(getPrism()->findNode(text, prism->getRootNode()));
  ModelNode* model = static_cast<ModelNode*>(getPrism()->findNode(text + "keypoint", prism->getRootNode()));
  if (!uiText) {
    uiText = SDKExamples::createUiText(prism, text);
    uiText->setTextSize(kSmallTextSize);
    uiText->setName(text);
    uiText->setTextColor(color::RED);
    uiText->setLocalScale(1.0f / kKeypointScale);  // Account for the scale of the keypoint sphere.
    if (text.find('\n') == std::string::npos) {
      uiText->setLocalPosition(-1.0f * VEC3_FORWARD);  // align hand text
    } else {
      uiText->setLocalPosition(VEC3_UP);  // align keypoint text
      uiText->setTextSize(kVerySmallTextSize);
    }
    if (!model) {
      prism->createMaterialResourceId(kMatResourcePath.c_str());
      model = SDKExamples::createModelNode(prism,
          prism->createInstancedModelResourceId(kSphereResourcePath.c_str(), kMaxKeypoints * 2));
      model->setLocalScale(kKeypointScale);
      model->setShader(lumin::utils::ShaderType::kUnlitTextured);
      model->setName(text + "keypoint");
      model->addChild(uiText);
      prism->getRootNode()->addChild(model);
    }
  }
  return std::make_pair(uiText, model);
}

void GestureVisualizer::setGestureText(HandType handIndex, float confidenceLevel, const std::string& name) {
  // Find the text node for the appropriate confidence value.
  switch (handIndex) {
    case HandType::kLeftHand: {
      UiText* confidence = static_cast<UiText*>(getPrism()->findNode(prefabs::GestureBase::Names::LeftHandValue,
          pageLayout_->getActivePage()));
      confidence->setText(ExampleHelpers::floatToString(confidenceLevel));
      UiText* gesture = static_cast<UiText*>(getPrism()->findNode(prefabs::GestureBase::Names::LeftHandGestureValue,
          pageLayout_->getActivePage()));
      gesture->setText(name);
      break;
    }
    case HandType::kRightHand: {
      UiText* confidence = static_cast<UiText*>(getPrism()->findNode(prefabs::GestureBase::Names::RightHandValue,
          pageLayout_->getActivePage()));
      confidence->setText(ExampleHelpers::floatToString(confidenceLevel));
      UiText* gesture = static_cast<UiText*>(getPrism()->findNode(prefabs::GestureBase::Names::RightHandGestureValue,
          pageLayout_->getActivePage()));
      gesture->setText(name);
      break;
    }
  }
}

void GestureVisualizer::setGestureKeypointPositions(HandType handIndex, const glm::vec3& handPosition,
    std::map<HandGestureKeypointName, glm::vec3>& keypoints) {
  std::string handText = "H" + std::string(handIndex == HandType::kRightHand? "R" : "L");
  std::pair<UiText*, ModelNode*> handNode = findOrCreateHandNode(getPrism(), handText);
  UiToggle* modelToggle = static_cast<UiToggle*>(getPrism()->findNode(prefabs::GestureBase::Names::keypointModelToggle, pageLayout_->getActivePage()));
  UiToggle* namesToggle = static_cast<UiToggle*>(getPrism()->findNode(prefabs::GestureBase::Names::keypointNamesToggle, pageLayout_->getActivePage()));

  handNode.second->setLocalPosition(handPosition);
  handNode.second->setVisible(modelToggle->getOn());
  handNode.first->setText(handText);
  if (handIndex == HandType::kLeftHand) {
    handNode.second->setColor(color::CYAN);
    handNode.first->setTextColor(color::GREEN);
  } else {
    handNode.second->setColor(color::MAGENTA);
    handNode.first->setTextColor(color::ORANGE);
  }

  for (uint32_t i = (uint32_t)HandGestureKeypointName::NONE; i
      <= (uint32_t)HandGestureKeypointName::WRIST_THUMB_SIDE; ++i) {
    std::string keypointText = handText + "\nKP" + std::to_string(i);
    std::pair<UiText*, ModelNode*> keypointNode = findOrCreateHandNode(getPrism(), keypointText);
    keypointNode.first->setText("");
    keypointNode.first->setVisible(false);
    keypointNode.second->setVisible(false);
  }

  for (std::map<HandGestureKeypointName, glm::vec3>::iterator it = keypoints.begin(); it != keypoints.end(); ++it) {
    std::string keypointText = handText + "\nKP" + std::to_string(static_cast<uint32_t>(it->first));
    std::pair<UiText*, ModelNode*> keypointNode = findOrCreateHandNode(getPrism(), keypointText);
    keypointNode.second->setLocalPosition(it->second);
    keypointNode.second->setVisible(modelToggle->getOn());
    std::string name = ExampleHelpers::handKeypointToString(it->first);
    std::regex r ("_");
    keypointNode.first->setText(std::regex_replace(name, r, std::string("\n")));
    keypointNode.first->setVisible(namesToggle->getOn());
    if (handIndex == HandType::kLeftHand) {
      keypointNode.second->setColor(glm::mix(color::CYAN, color::WHITE,
         static_cast<uint32_t>(it->first) / static_cast<float>(kMaxKeypoints)));
      keypointNode.first->setTextColor(color::INDIGO);
    } else {
      keypointNode.second->setColor(glm::mix(color::MAGENTA, color::WHITE,
         static_cast<uint32_t>(it->first) / static_cast<float>(kMaxKeypoints)));
      keypointNode.first->setTextColor(color::RED);
    }
  }
}

void GestureVisualizer::onGestureHand(const std::string& name, HandType handIndex, float confidence,
    glm::vec3& handPosition, std::map<HandGestureKeypointName, glm::vec3>& keypointPositions, HandEvent status) {
  if (status == HandEvent::kHandEnd) {
    onGestureHand_End(handIndex);
  } else {
    setGestureText(handIndex, confidence, name);
    if (name != kNoPoseName) {
      UiImage* activeGesture = static_cast<UiImage*>(getPrism()->findNode(name, pageLayout_->getActivePage()));
      markGestureTracked(activeGesture, handIndex);
      setGestureKeypointPositions(handIndex, handPosition, keypointPositions);
    }
  }
}

void GestureVisualizer::onGestureHand_End(HandType handIndex) {
  if (activeGesture_[handIndex]) {
    swapToPrevious(handIndex);  // Reset the active gesture image
    setGestureText(handIndex, 0.0f, ExampleHelpers::gestureTypeToString(input::GestureType::NONE));  // Reset the gesture confidence to 0.0f.
    std::string handText = "H" + std::string(handIndex == HandType::kRightHand? "R" : "L");  // Reset keypoints.
    std::pair<UiText*, ModelNode*> handNode = findOrCreateHandNode(getPrism(), handText);
    handNode.first->setText("");
    handNode.second->setVisible(false);

    for (uint32_t i = (uint32_t)HandGestureKeypointName::NONE; i
        <= (uint32_t)HandGestureKeypointName::WRIST_THUMB_SIDE; ++i) {
      std::string keypointText = handText + "\nKP" + std::to_string(i);
      std::pair<UiText*, ModelNode*> keypointNode = findOrCreateHandNode(getPrism(), keypointText);
      keypointNode.first->setText("");
      keypointNode.second->setVisible(false);
    }
    activeGesture_[handIndex] = nullptr;
  }
}

void GestureVisualizer::markGestureTracked(UiImage* activeGesture, lumin::HandType handIndex) {

  // Set the color of the previously tracked gesture image WHITE and the newly tracked gesture
  // image MAGENTA (right), CYAN (left), or HOTPINK (both hands for the same gesture).
  // If the previously tracked gesture was the same for both hands, change the color to match the other hand.
  // Flip the image for left and right hands.
  if (activeGesture != activeGesture_[handIndex]) {

    // Change the previous tracked image if applicable:
    swapToPrevious(handIndex);

    // Mark the currently tracked image:
    if (activeGesture) {
      if (handIndex == HandType::kRightHand) {
        activeGesture->setTexCoords(kRightTexCoords);
        activeGesture->setColor(color::MAGENTA);
      } else {
        activeGesture->setTexCoords(kLeftTexCoords);
        activeGesture->setColor(color::CYAN);
      }
    }
    activeGesture_[handIndex] = activeGesture;
    if (activeGesture_[HandType::kLeftHand] == activeGesture_[HandType::kRightHand]) {
      activeGesture->setColor(color::HOTPINK);
    }
  }
}

void GestureVisualizer::swapToPrevious(HandType handIndex) {
  if (activeGesture_[handIndex]) {
    if (activeGesture_[HandType::kLeftHand] != activeGesture_[HandType::kRightHand]) {
      activeGesture_[handIndex]->setColor(color::WHITE);
    } else {
      if (handIndex == HandType::kLeftHand) {
        activeGesture_[handIndex]->setTexCoords(kRightTexCoords);
        activeGesture_[handIndex]->setColor(color::MAGENTA);
      } else {
        activeGesture_[handIndex]->setTexCoords(kLeftTexCoords);
        activeGesture_[handIndex]->setColor(color::CYAN);
      }
    }
  }
}