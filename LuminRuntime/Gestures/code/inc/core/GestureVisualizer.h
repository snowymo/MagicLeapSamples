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
#include <GestureController.h>
#include <BaseExample.h>
#include <lumin/Consts.h>
#include <memory>

// Forward declarations.
namespace lumin {
  inline namespace LUMIN_VERSION_NAMESPACE {
    namespace ui {
      class UiImage;
      class UiText;
    }
  }
}
class GestureController;

/**
 * Creates a scene that handles the gesture icons and response.
 */
class GestureVisualizer : public lumin::SDKExamples::BaseExample {
public:
 /**
  * Constructor.
  */
  GestureVisualizer();

 /**
  * Destructor.
  */
  virtual ~GestureVisualizer();

 /**
  * Creates the scene when it is attached to a prism.
  * @param[in] prism - the prism the graph is attached to.
  */
  void onAttachPrism(lumin::Prism* prism) override;

 /**
  * Cleans up the scene when it is removed from a prism.
  * @param[in] prism - the prism the scene will be detached from.
  */
  void onDetachPrism(lumin::Prism* prism) override;

private:
 /**
  * Loads the scene from the Lumin Runtime Editor.
  * @param[in] prism - the prism to load the scene in.
  * @return - the root node of the scene, to be added.
  */
  lumin::TransformNode* loadSceneGraph(lumin::Prism* prism) override;

 /**
  * Builds the scene in code.
  * @param[in] prism - the prism to build the scene in.
  * @return - the root node of the scene, to be added.
  */
  lumin::TransformNode* buildSceneGraph(lumin::Prism* prism) override;

 /**
  * Finds previously created UiText and Model nodes for hand position and keypoint positions or creates them if not found.
  * @param[in] prism - The prism to create nodes for.
  * @param[in] text - The text to use for the name and visible text.
  * @returns - The newly created nodes.
  */
  std::pair<lumin::ui::UiText*, lumin::ModelNode*> findOrCreateHandNode(lumin::Prism* prism, std::string& text);

 /**
  * Sets the gesture confidence text for the appropriate hand.
  * param[in] handIndex - 0 left hand, 1 right hand.
  * param[in] confidenceLevel - The [0, 1] confidence value of the tracked gesture for the handIndex.
  */
  void setGestureText(lumin::HandType handIndex, float confidenceLevel, const std::string& name);

 /**
  * Stores the gesture keypoint positions for the tracked hand.
  * param[in] handIndex - 0 left hand, 1 right hand.
  * param[in] handPosition - The position of the tracked gesture.
  * param[in] keypoints - Map of keypoints for the tracked gestures.
  */
  void setGestureKeypointPositions(lumin::HandType handIndex, const glm::vec3& handPosition,
      std::map<lumin::input::HandGestureKeypointName, glm::vec3>& keypoints);

 /**
  * The callback for hand gestures.
  * param[in] name - The name of the hand gesture icon to change.
  * param[in] handIndex - 0 left hand, 1 right hand.
  * param[in] confidence - The [0, 1] confidence value of the Finger gesture for the hand index.
  * param[in] handPosition - The position of the tracked hand. Data lifetime ends after function callback.
  * param[in] keypointPositions - The map of tracked keypoints for the gesture. Data lifetime ends after function callback.
  * param[in] status - The status of the hand gesture event this frame.
  */
  void onGestureHand(const std::string& name, lumin::HandType handIndex, float confidence, glm::vec3& handPosition,
      std::map<lumin::input::HandGestureKeypointName, glm::vec3>& keypointPositions, lumin::HandEvent status);

 /**
  * Clears the gesture display whenever a lumin::HandEvent::kHandEnd status is received.
  * param[in] handIndex - 0 left hand, 1 right hand.
  */
  void onGestureHand_End(lumin::HandType handIndex);

 /**
  * Marks the activeGesture image magenta (right), cyan (left), or hot pink (both) if it's tracked or white if untracked.
  * Flips the activeGesture image to match the left or right hand.
  * param[in] activeGesture - The UiImage node to setColor() on.
  * param[in] gestureHand - 0 left hand, 1 right hand.
  */
  void markGestureTracked(lumin::ui::UiImage* activeGesture, lumin::HandType handIndex);

 /**
  * Swaps the active gesture image to the other hand's image and color.
  * Used when both hands were previously performing the same gesture.
  * param[in] gestureHand - 0 left hand, 1 right hand.
  */
  void swapToPrevious(lumin::HandType handIndex);

private:
  lumin::ui::UiPageView* pageLayout_ = nullptr;
  std::shared_ptr<GestureController> gestureController_;
  lumin::ui::UiImage* activeGesture_[2] = { nullptr, nullptr }; // Image node for associated tracked gesture per hand.
};
