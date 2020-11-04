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
#include <CircleConfirmationLayout.h>
#include <CircleConfirmationPrefab.h>
#include <lumin/node/Node.h>
#include <PrefabManager.h>
#include <ExamplesDefines.h>

namespace prefabs {


  CircleConfirmationLayout::CircleConfirmationLayout(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : CircleConfirmationLayoutBase(extendedPrefabManager, root) {
  }

  CircleConfirmationLayout::~CircleConfirmationLayout() {
  }

  void CircleConfirmationLayout::setCircleConfirmationPrefab(CircleConfirmationPrefab* prefab) {
    prefab_ = prefab;
  }

  // Handler methods are declared in the base class CircleConfirmationLayoutBase and can be implemented here

  void CircleConfirmationLayout::CCM_Button_CCM_Handlers_ResetCircleConfirmation(const lumin::ui::UiEventData& data) {
    extendedPrefabManager_->destroyPrefab(prefab_);
    prefab_ = extendedPrefabManager_->spawn<CircleConfirmationPrefab>();
    LUMIN_ASSERT(prefab_, "Failed to create CircleConfirmationPrefab");
    prefab_->setLayout(this);
    getCCM_Placeholder()->addChild(prefab_->getRoot());
    getCCM_Message()->setText("Complete the Circle Confirmation");
  }

}
