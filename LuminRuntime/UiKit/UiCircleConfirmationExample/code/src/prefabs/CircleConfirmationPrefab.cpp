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

#include <PrefabDescriptor.h>
#include <CircleConfirmationPrefab.h>

namespace prefabs {


  CircleConfirmationPrefab::CircleConfirmationPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : CircleConfirmationPrefabBase(extendedPrefabManager, root) {
  }

  CircleConfirmationPrefab::~CircleConfirmationPrefab() {
    layout_ = nullptr;
  }

  void CircleConfirmationPrefab::setLayout(CircleConfirmationLayout* layout) {
    layout_ = layout;
  }

  // Handler methods are declared in the base class CircleConfirmationPrefabBase and can be implemented here

  void CircleConfirmationPrefab::CCM_CircleConfirmation_CCM_Handlers_onConfirmationCanceled(const lumin::ui::UiEventData& data) {
    layout_->setMessage("Canceled confirmation");
  }

  void CircleConfirmationPrefab::CCM_CircleConfirmation_CCM_Handlers_onConfirmationComplete(const lumin::ui::UiEventData& data) {
    layout_->setMessage("Completed confirmation");
  }

  void CircleConfirmationPrefab::CCM_CircleConfirmation_CCM_Handlers_onConfirmationUpdate(const lumin::ui::UiEventData& data, const float progress) {
    layout_->setMessage(std::to_string(static_cast<int>(progress * 100)) + "% away from confirming");
  }

  void CircleConfirmationPrefab::CCM_CircleConfirmation_CCM_Handlers_onActivate(const lumin::ui::UiEventData& data) {
    layout_->setMessage("Press the home button to cancel");
  }

}
