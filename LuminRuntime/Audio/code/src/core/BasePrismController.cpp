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
#include <BasePrismController.h>
#include <ml_logging.h>

using namespace lumin;

namespace lumin {
  namespace SDKExamples {

    BasePrismController::Managers::Managers(lumin::Prism* prism) {
      extendedPrefab_ = new ExtendedPrefabManager(prism);
      extendedScene_ = new ExtendedSceneManager(prism, extendedPrefab_);
    }

    BasePrismController::Managers::~Managers() {
      // delete the managers:
      delete extendedScene_;
      delete extendedPrefab_;

      extendedScene_  = nullptr;
      extendedPrefab_ = nullptr;
    }

    BasePrismController::~BasePrismController() {
    }

    BasePrismController::BasePrismController(const std::string& name) :
      PrismController(name),
      managers_(nullptr) {
    }

    // Display the Base Prism Controller when attached to a prism:
    void BasePrismController::onAttachPrism(Prism* prism) {
      ML_LOG(Debug, "BasePrismController::onAttachPrism() Initializing the Base Prism scene");
      managers_ = new Managers(prism);
    }

    void BasePrismController::onAppPause() {

    }

    void BasePrismController::onAppResume() {

    }

    void BasePrismController::onToggleChanged(bool active) {

    }

    // Remove all nodes when detached from a prism:
    void BasePrismController::onDetachPrism(Prism*) {
      ML_LOG(Debug, "BasePrismController::onDetachPrism() Destroying the Base Prism scene");
      deleteSceneGraph();
      delete managers_;
      managers_  = nullptr;
    }
  } // SDKExamples
} // lumin