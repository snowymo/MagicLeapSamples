// -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING --
//
// THE CONTENTS OF THIS FILE IS GENERATED BY CODE AND
// ANY MODIFICATIONS WILL BE OVERWRITTEN
//
// -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING -- WARNING --

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

#include <CircleConfirmationLayoutBase.h>
#include <CircleConfirmationLayout.h>

namespace prefabs {

  const PrefabDescriptor& CircleConfirmationLayoutBase::getClassPrefabDescriptor() {
    return classPrefabDescriptor_;
  }

  PrefabBase* CircleConfirmationLayoutBase::createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root) {
    PrefabBase* const prefab = new CircleConfirmationLayout(extendedPrefabManager, root);
    return prefab;
  }

  CircleConfirmationLayoutBase::CircleConfirmationLayoutBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : PrefabBase(extendedPrefabManager, root) {

    CCM_Placeholder = lumin::TransformNode::CastFrom(root->findChild(Names::CCM_Placeholder));
    CCM_Message = lumin::ui::UiText::CastFrom(root->findChild(Names::CCM_Message));
    CCM_Button = lumin::ui::UiTab::CastFrom(root->findChild(Names::CCM_Button));

    CCM_Button->onActivateSub(std::bind(&CircleConfirmationLayoutBase::CCM_Button_CCM_Handlers_ResetCircleConfirmation, this, std::placeholders::_1));
  }

  CircleConfirmationLayoutBase::~CircleConfirmationLayoutBase() {
  }

  const PrefabDescriptor& CircleConfirmationLayoutBase::getPrefabDescriptor() const {
    return classPrefabDescriptor_;
  }

  const PrefabBase::NodeReferences& CircleConfirmationLayoutBase::getNodeReferences() const {
    return classNodeReferences_;
  }

  lumin::TransformNode* CircleConfirmationLayoutBase::getCCM_Placeholder() {
    return CCM_Placeholder;
  }

  lumin::ui::UiText* CircleConfirmationLayoutBase::getCCM_Message() {
    return CCM_Message;
  }

  lumin::ui::UiTab* CircleConfirmationLayoutBase::getCCM_Button() {
    return CCM_Button;
  }

  const std::string CircleConfirmationLayoutBase::getMessage() const {
    return CCM_Message->getText();
  }

  void CircleConfirmationLayoutBase::setMessage(const std::string& newValue) {
    CCM_Message->setText(newValue);
  }

}