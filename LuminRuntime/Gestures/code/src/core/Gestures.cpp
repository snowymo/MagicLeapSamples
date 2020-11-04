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

#include <Gestures.h>
#include <lumin/node/RootNode.h>
#include <lumin/ui/Cursor.h>
#include <ml_logging.h>

#include <GestureVisualizer.h>
#include <ExamplesConstants.h>

Gestures::Gestures() {
  ML_LOG(Debug, "Gestures Constructor.");

  // Place your constructor implementation here.
}

Gestures::~Gestures() {
  ML_LOG(Debug, "Gestures Destructor.");

  // Place your destructor implementation here.
}

const glm::vec3 Gestures::getInitialPrismSize() const {
  return glm::vec3(1.0f, 1.0f, 2.0f);
}

// Create a prism of large size so it's easier to get hands inside it for keypoint rendering.
void Gestures::createInitialPrism() {
  prism_ = requestNewPrism(getInitialPrismSize());
  if (!prism_) {
    ML_LOG(Error, "Gestures Error creating default prism.");
    abort();
  }
}

int Gestures::init() {
  ML_LOG(Debug, "Gestures Initializing.");

  createInitialPrism();
  // Create the main prism controller for gestures.
  gestureVisualizer_ = std::make_shared<GestureVisualizer>();
  prism_->setPrismController(gestureVisualizer_);
  gestureVisualizer_->getRoot()->setLocalPosition({0.0f, 0.0f, -0.9f}); // Move to the back of the prism.
  lumin::ui::Cursor::SetScale(prism_, lumin::ExampleConsts::kCursorScale);
  lumin::ui::Cursor::SetPlaneDepth(prism_, -0.9f);

  return 0;
}

int Gestures::deInit() {
  ML_LOG(Debug, "Gestures Deinitializing.");

  // All prisms are deleted before deInit() is called.
  prism_ = nullptr;
  gestureVisualizer_.reset();
  
  return 0;
}

bool Gestures::updateLoop(float fDelta) {

  // Place your update here.

  // Return true for your app to continue running, false to terminate the app.
  return true;
}

bool Gestures::eventListener(lumin::ServerEvent* event) {

  // Place your event handling here.

  // Return true if the event is consumed.
  return false;
}

