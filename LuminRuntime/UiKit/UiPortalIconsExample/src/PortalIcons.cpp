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
#include <PortalIcons.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>

#include <lumin/ui/element/MaskingAura.h>
#include <lumin/utils/RendererInterface.h>
#include <lumin/utils/AABB.h>
#include <lumin/node/ModelNode.h>
#include <lumin/node/MoveData.h>
#include <lumin/node/QuadNode.h>
#include <lumin/ui/node/UiPortalIcon.h>
#include <lumin/event/TransformAnimationEventData.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;
using namespace lumin::utils;

namespace {
  const float kDefaultHoverScale = 1.5f;
  const float kCenterHoverScale  = 3.0f;
  const float kEaseRate          = 0.5f;
  const float kMoveTime          = 0.5f;
  const glm::vec2 kIconSize(0.045f);
  const glm::vec2 kGradientSize(0.07f);
  const glm::vec3 kDiceSize(0.025f);
  const glm::vec3 kSDKSize(0.0025f);
  const glm::vec3 kMLSize(0.02f);
  const glm::vec3 kDroidSize(0.013f);
  const glm::vec3 kScaleTo(0.7f);
  const glm::vec3 kScaleDefault(1.0f);
  const glm::vec3 kDiceOffset(0.0f, -0.02f, 0.0f);
  const glm::vec3 kDroidOffset(0.0f, 0.01f, 0.0f);
  const glm::vec3 kHoneyOffset(0.0f, 0.006f, 0.001f);
  const glm::vec3 kD12Offset(0.0f, -0.02f, -0.1f);
  const glm::vec3 kLeaperOffset(0.0f, 0.09f, 0.05f);

  const glm::vec3 kNorthLocalPos(0.0f, 0.28f, 0.0f);
  const glm::vec3 kNorthEastLocalPos(0.2f, 0.2f, 0.0f);
  const glm::vec3 kEastLocalPos(0.28f, 0.0f, 0.0f);
  const glm::vec3 kSouthEastLocalPos(0.2f, -0.2f, 0.0f);
  const glm::vec3 kSouthLocalPos(0.0f, -0.28f, 0.0f);
  const glm::vec3 kSouthWestLocalPos(-0.2f, -0.2f, 0.0f);
  const glm::vec3 kWestLocalPos(-0.28f, 0.0f, 0.0f);
  const glm::vec3 kNorthWestLocalPos(-0.2f, 0.2f, 0.0f);

  const glm::vec4 kLayoutPadding(0.06f, 0.02f, 0.04f, 0.02f);
  const glm::vec4 kItemPadding(-0.02f, 0.0f, 0.0f, 0.02f);
  const glm::quat kD12Rotation(glm::quat(glm::vec3(glm::radians(17.0f), 0, 0)) *
                               glm::quat(glm::vec3(0, glm::radians(-25.0f), 0)));
  const glm::quat kD20Rotation(glm::quat(glm::vec3(glm::radians(12.0f), 0, 0)) *
                               glm::quat(glm::vec3(0, glm::radians(-25.0f), 0)));

  const glm::vec3 oppositeDir(const glm::vec3 dir) {
    if (dir == kNorthLocalPos)
      return kSouthLocalPos;
    if (dir == kNorthEastLocalPos)
      return kSouthWestLocalPos;
    if (dir == kEastLocalPos)
      return kWestLocalPos;
    if (dir == kSouthEastLocalPos)
      return kNorthWestLocalPos;
    if (dir == kSouthLocalPos)
      return kNorthLocalPos;
    if (dir == kSouthWestLocalPos)
      return kNorthEastLocalPos;
    if (dir == kWestLocalPos)
      return kEastLocalPos;
    if (dir == kNorthWestLocalPos)
      return kSouthEastLocalPos;
    return ExampleConsts::kDefaultLocalPos;
  }
}

void PortalIcons::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "UiPortalIconsExample::onAttachPrism() Initializing the Portal Icons scene");

  UiLinearLayout* portalIconsLayout = SDKExamples::createUiLinearLayout(prism);
  portalIconsLayout->setAlignment(Alignment::TOP_CENTER);
  portalIconsLayout->setDefaultItemAlignment(Alignment::TOP_CENTER);
  portalIconsLayout->setLocalPosition(ExampleConsts::kLayoutPos);

  UiText* title = SDKExamples::createUiText(prism, "Portal Icons",
      resources::FontStyle::kItalic, resources::FontWeight::kBold);
  title->setTextSize(ExampleConsts::kTitleSize);
  portalIconsLayout->addItem(title);

  TransformNode* portalCenter = SDKExamples::createTransformNode(prism);
  scaleIn_                    = EaseInTime::Create(kEaseRate);
  scaleOut_                   = EaseOutTime::Create(kEaseRate);

  // create the gradient and icon image assets :
  auto createUiImage = [prism](const std::string& path, const glm::vec2& size) {
    UiImage* image = SDKExamples::createUiImage(prism, path, size.x, size.y);
    image->setIsOpaque(false);
    return image;
  };
  UiImage* firstIcon       = createUiImage("res/portal_icon/Misc_icons/ML.png", kIconSize);
  UiImage* firstGradient   = createUiImage("res/portal_icon/Misc_icons/Orange_gradient.png", kGradientSize);
  UiImage* secondIcon      = createUiImage("res/portal_icon/Misc_icons/Ripple.png", kIconSize);
  UiImage* secondGradient  = createUiImage("res/portal_icon/Misc_icons/Blue_purple_gradient.png", kGradientSize);
  UiImage* thirdIcon       = createUiImage("res/portal_icon/Misc_icons/TriRipple.png", kIconSize);
  UiImage* thirdGradient   = createUiImage("res/portal_icon/Misc_icons/yellow_gradient.png", kGradientSize);
  UiImage* fourthGradient  = createUiImage("res/portal_icon/SDK_icons/LR_gradient.png", kGradientSize);
  UiImage* fifthGradient   = createUiImage("res/portal_icon/SDK_icons/ML_GradientPattern_BG.png", kGradientSize);
  UiImage* sixthGradient   = createUiImage("res/portal_icon/SDK_icons/Unity_gradient.png", kGradientSize);
  UiImage* seventhGradient = createUiImage("res/portal_icon/Misc_icons/Green_gradient.png", kGradientSize);

  // create the background and icon model assets:
  auto createModel = [prism](const std::string& path, const glm::vec3& scale,
      const glm::quat& rotation = ExampleConsts::kNoRotation, const std::string& aniName = "",
      const ShaderType shader   = ShaderType::kUnlitTextured) {
    auto resId = prism->createModelResourceId(path.c_str(), 1.0f);
    ModelNode* icon  = SDKExamples::createModelNode(prism, resId);
    icon->setLocalScale(scale);
    icon->setLocalRotation(rotation);
    icon->setShader(shader);
    icon->playAnimation(resId, aniName.c_str(), true);
    return icon;
  };
  ModelNode* fourthIcon   = createModel("res/portal_icon/Misc_icons/D20_spin.fbx",
      kDiceSize, kD20Rotation, "Take 001");
  prism->createTextureResourceId(Desc2d::DEFAULT, "res/portal_icon/Icon_Grid/model/white.png");
  prism->createTextureResourceId(Desc2d::DEFAULT, "res/portal_icon/Icon_Grid/model/Leaper.png");
  prism->createMaterialResourceId("res/portal_icon/Icon_Grid/model/ML_SDK_Icon_Anim.kmat");
  ModelNode* fifthIcon    = createModel("res/portal_icon/Icon_Grid/model/ML_SDK_Icon_Anim.fbx",
      kMLSize, ExampleConsts::kNoRotation, "idle");
  fifthIcon->setIsOpaque(false);
  ModelNode* sixthIcon    = createModel("res/portal_icon/Misc_icons/ScanDroid_003.fbx",
      kDroidSize, kD20Rotation);
  ModelNode* seventhIcon  = createModel("res/portal_icon/Misc_icons/D20_spin.fbx",
      kDiceSize, kD20Rotation);
  ModelNode* eightIcon    = createModel("res/portal_icon/SDK_icons/SDK_Icon.fbx",
      kSDKSize, ExampleConsts::kNoRotation);
  ModelNode* eightBgModel = createModel("res/portal_icon/Misc_icons/d12.fbx",
      kDiceSize, kD12Rotation);

  centerIcon_ = createPortalIcon("Default", ExampleConsts::kDefaultLocalPos);
  UiPortalIcon::CastFrom(centerIcon_->getContent())->setHoverScale(kCenterHoverScale);
  prevIcon_   = centerIcon_;
  portalCenter->addChild(centerIcon_);

  auto wrapIcon = [prism](Node* icon){
    ModelNode* iconModel = SDKExamples::createModelNode(prism, lumin::INVALID_RESOURCE_ID);
    iconModel->addChild(icon);
    return iconModel;
  };
  portalCenter->addChild(createPortalIcon("MagicLeap Icon", wrapIcon(firstIcon),
      firstGradient, kNorthLocalPos));
  portalCenter->addChild(createPortalIcon("Ripples", wrapIcon(secondIcon),
      secondGradient, kEastLocalPos));
  portalCenter->addChild(createPortalIcon("HoneyBee", wrapIcon(thirdIcon),
      thirdGradient, kSouthLocalPos, kHoneyOffset));
  portalCenter->addChild(createPortalIcon("Hover", fourthIcon, fourthGradient, kWestLocalPos,
      kDiceOffset, ExampleConsts::kDefaultBackground, "Take 001"));
  portalCenter->addChild(createPortalIcon("", fifthIcon, fifthGradient, kNorthEastLocalPos,
      ExampleConsts::kDefaultForeground, ExampleConsts::kDefaultBackground, "hover", "idle"));
  portalCenter->addChild(createPortalIcon("ScanDroid", sixthIcon, sixthGradient,
      kSouthEastLocalPos, kDroidOffset));
  portalCenter->addChild(createPortalIcon("Idle", seventhIcon, seventhGradient,
      kNorthWestLocalPos, kDiceOffset, ExampleConsts::kDefaultBackground));
  // add the Dice d12 model in the background, to showcase the depth of a portal icon's background:
  portalCenter->addChild(createPortalIcon("D12", eightIcon, eightBgModel, kSouthWestLocalPos,
      kDiceOffset, kD12Offset));

  portalIconsLayout->addItem(portalCenter, kItemPadding);
  getRoot()->addChild(portalIconsLayout);
}

UiRectLayout* PortalIcons::createPortalIcon(const std::string& title, const glm::vec3& position,
    const PortalIconSize size) {
  UiRectLayout* layout = createLayout(position);
  UiPortalIcon* portal = SDKExamples::createUiPortalIcon(getPrism(), title, size);
  layout->setContent(portal);
  portal->onActivateSub(std::bind(&PortalIcons::onPortalIconActivate, this,
      std::placeholders::_1, layout));
  return layout;
}

UiRectLayout* PortalIcons::createPortalIcon(const std::string& title, ModelNode* icon, Node* bg,
    const glm::vec3& position, const glm::vec3& iconOffset, const glm::vec3& bgOffset,
    const std::string& hoverAni, const std::string& idleAni, const PortalIconSize size) {
  UiRectLayout* layout = createLayout(position);
  UiPortalIcon* portal = SDKExamples::createUiPortalIcon(getPrism(), title, size);
  (portal->getUiTextLabel())->setBoundsSize(portal->getUiTextLabel()->getBoundsSize() * 1.1f, false);
  portal->setBackgroundModel(bg, bgOffset);
  portal->setIconModel(icon, iconOffset);
  portal->setIconHoverAnimation(hoverAni);
  portal->setIconIdleAnimation(idleAni);
  layout->setContent(portal);
  portal->onActivateSub(std::bind(&PortalIcons::onPortalIconActivate, this,
      std::placeholders::_1, layout));
  return layout;
}

// Layout will provide padding for entire circular layout so zoomed icons don't clip:
UiRectLayout* PortalIcons::createLayout(const glm::vec3& position) {
  UiRectLayout* layout = SDKExamples::createUiRectLayout(getPrism());
  layout->setPadding(kLayoutPadding);
  layout->setAlignment(Alignment::TOP_CENTER);
  layout->setLocalPosition(position);
  return layout;
}

void PortalIcons::onPortalIconActivate(const UiEventData& portal, UiRectLayout* layout) {
  // if the activated icon is a border icon, begin swapping it with the center icon if
  // no other icon is moving:
  if (!isMoving_) {
    if (layout != centerIcon_) {
      UiPortalIcon* activatedPortal = UiPortalIcon::CastFrom(portal.getUiNode());
      UiPortalIcon* centerPortal    = UiPortalIcon::CastFrom(centerIcon_->getContent());
      centerPortal->setEnabled(false);
      activatedPortal->setEnabled(false);
      centerIcon_->moveBy(layout->getLocalPosition(), kMoveTime);
      centerPortal->setHoverScale(kDefaultHoverScale);
      centerPortal->setLabelDisplayMode(LabelDisplayMode::kHover);
      activatedPortal->setLabelDisplayMode(LabelDisplayMode::kHover);
      layout->moveBy(oppositeDir(layout->getLocalPosition()), kMoveTime);
      layout->addMoveCallback();  // signal when the transforms are complete
      prevIcon_   = centerIcon_;
      centerIcon_ = layout;
      isMoving_   = true;
    }
  }
}

bool PortalIcons::onEvent(ServerEvent* anEvent) {
  if (anEvent->getServerEventTypeValue() == TransformAnimationEventData::GetServerEventTypeValue()) {
    isMoving_ = false;
    UiPortalIcon* centerPortal = UiPortalIcon::CastFrom(centerIcon_->getContent());
    UiPortalIcon* prevPortal   = UiPortalIcon::CastFrom(prevIcon_->getContent());
    centerPortal->setHoverScale(kCenterHoverScale);
    centerPortal->setLabelDisplayMode(LabelDisplayMode::kAlways);
    prevPortal->setLabelDisplayMode(LabelDisplayMode::kAlways);
    centerPortal->setEnabled(true);
    prevPortal->setEnabled(true);
    return true;
  }
  return false;
}

void PortalIcons::onDetachPrism(Prism*) {
  ML_LOG(Debug, "UiPortalIconsExample::onDetachPrism() Destroying the Portal Icons scene");
  deleteSceneGraph();
}
