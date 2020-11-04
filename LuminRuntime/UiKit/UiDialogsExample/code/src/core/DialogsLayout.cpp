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
#include <DialogsLayout.h>
#include <DialogsLayoutPrefab.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesHelpers.h>
#include <ExamplesDefines.h>

#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const float kDialogRadius      = 0.15f;
  const float kTimedDialogOffset = 0.05f;
  const float kDialogExpireTime  = 5.0f;
  const glm::vec2 kBackgroundSize(0.6f, 0.6f);
  const glm::vec2 kHeartListSize(0.5f, 0.13);
  const glm::vec3 kBackgroundPos(-0.3f, -0.3f, -lumin::render::MIN_ZDEPTH_OFFSET);
  const glm::vec3 kDialogPosition(0.0f, 0.0f, 0.3f);  // dialogs should have the most forward z position
  const glm::vec3 kLineLocalPosStart(-0.1f, 0.0f, 0.0f);
  const glm::vec3 kLineLocalPosEnd(0.42f, 0.0f, 0.0f);
  const glm::vec4 kLineColor(0.45f, 0.45f, 0.45f, 1.0f);  // (174, 174, 174)
  const glm::vec4 kTransparentBlack(0.0f, 0.0f, 0.0f, 0.05f);
  const lumin::render::RenderingLayer kDialogLayer = lumin::render::RenderingLayer::kPostObjectLayer;
}

DialogsLayout::DialogsLayout()
: BaseExample("Dialogs") {
}

DialogsLayout::~DialogsLayout() {

}

void DialogsLayout::onAttachPrism(Prism* prism) {
  ML_LOG(Debug, "DialogsLayout::onAttachPrism() Initializing the Dialogs Layout scene");
  BaseExample::onAttachPrism(prism);
  QuadNode* background = SDKExamples::createQuadNode(prism);
  background->setSize(kBackgroundSize);
  background->setColor(kTransparentBlack);
  background->setLocalPosition(kBackgroundPos);
  getRoot()->addChild(background);
}

TransformNode* DialogsLayout::loadSceneGraph(Prism* prism) {
  TransformNode* rootContainer = SDKExamples::createTransformNode(prism);
  prefabs::DialogsLayoutPrefab* prefab = managers_->extendedPrefab_->spawn<prefabs::DialogsLayoutPrefab>();
  LUMIN_ASSERT(prefab, "Failed to creare DialogsLayoutPrefab");
  prefab->setPrism(prism);
  rootContainer->addChild(prefab->getRoot());
  return rootContainer;
}

TransformNode* DialogsLayout::buildSceneGraph(Prism* prism) {
  UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
  topLayout->setAlignment(Alignment::CENTER_CENTER);
  topLayout->setOrientation(Orientation::kVertical);
  topLayout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);

  UiLinearLayout* dialogsLayout = SDKExamples::createUiLinearLayout(prism);
  dialogsLayout->setAlignment(Alignment::CENTER_CENTER);
  dialogsLayout->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  dialogsLayout->setDefaultItemAlignment(Alignment::TOP_CENTER);

  UiTab* singleAction = SDKExamples::createEclipseTab(prism, "Single Action Dialog", EclipseLabelType::kT1);
  UiTab* dualAction   = SDKExamples::createEclipseTab(prism, "Dual Action Dialog", EclipseLabelType::kT1);
  UiTab* timed        = SDKExamples::createEclipseTab(prism, "Timed Dialog", EclipseLabelType::kT1);
  dialogsLayout->addItem(singleAction);
  dialogsLayout->addItem(dualAction);
  dialogsLayout->addItem(timed);

  UiRectLayout* container = SDKExamples::createUiRectLayout(prism);
  UiListView* heartList   = SDKExamples::createUiListView(prism);
  container->setContentAlignment(Alignment::CENTER_CENTER);
  container->setSize(kHeartListSize);
  heartList->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  heartList->setOrientation(Orientation::kHorizontal);
  container->setContent(heartList);
  dialogsLayout->addItem(container);

  singleAction->onActivateSub(std::bind(&DialogsLayout::singleActionCallback, this,
      std::placeholders::_1, heartList));
  dualAction->onActivateSub(std::bind(&DialogsLayout::dualActionCallback, this,
      std::placeholders::_1, heartList));
  timed->onActivateSub(std::bind(&DialogsLayout::timedCallback, this,
      std::placeholders::_1, heartList));

  topLayout->addItem(dialogsLayout);
  return topLayout;
}

void DialogsLayout::dualActionCallback(const UiEventData&, UiListView* heartList) {
  Cursor::SetCursorSnapMode(getPrism(), true);  // force snap while showing dialog
  Cursor::SetPlaneDepth(getPrism(), kDialogPosition.z);  // force the cursor to be on the same plane as the dialog
  heartList->setVisible(false);

  UiDialog* dialog = SDKExamples::createUiDialog(getPrism(), DialogType::kDualAction);
  dialog->setLocalPosition(kDialogPosition);
  getRoot()->addChild(dialog);

  UiLinearLayout* content = SDKExamples::createUiLinearLayout(getPrism());
  content->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  content->setAlignment(Alignment::CENTER_CENTER);
  content->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  UiText* title   = SDKExamples::createEclipseLabel(getPrism(), "Modal Dual Action", EclipseLabelType::kT3);
  UiText* desc    = SDKExamples::createEclipseLabel(getPrism(), "Example Content", EclipseLabelType::kT4);
  UiButton* heart = SDKExamples::createEclipseButton(getPrism(),
      EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kHeart));
  heart->onActivateSub(std::bind(&DialogsLayout::dualActionHeartActivateCallback, this,
      std::placeholders::_1));
  content->addItem(title);
  content->addItem(desc);
  content->addItem(heart);

  dialog->setDialogContent(content);
  dialog->setRenderingLayer(kDialogLayer); // set any rendering layer after setContent to alter content too
  dialog->init(); // call init when the dialog has content, is added to the scene and is ready

  // Dual Action Dialogs send out both onConfirm and onCancel.
  dialog->onConfirmSub(std::bind(&DialogsLayout::confirmCallback, this, std::placeholders::_1,
      heart, heartList));
  dialog->onCancelSub(std::bind(&DialogsLayout::dialogActivateCallback, this, std::placeholders::_1,
      heartList));
}

void DialogsLayout::singleActionCallback(const UiEventData&, UiListView* heartList) {
  Cursor::SetCursorSnapMode(getPrism(), true);  // force snap while showing dialog
  heartList->setVisible(false);
  Cursor::SetPlaneDepth(getPrism(), kDialogPosition.z);  // force the cursor to be on the same plane as the dialog
  UiDialog* dialog = SDKExamples::createUiDialog(getPrism(), DialogType::kSingleAction);
  dialog->setLocalPosition(kDialogPosition);
  dialog->setConfirmButtonText("OKAY");
  dialog->setConfirmButtonIcon(SystemIcon::kThumbsUpRight);
  getRoot()->addChild(dialog);

  UiLinearLayout* content = SDKExamples::createUiLinearLayout(getPrism());
  content->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  content->setAlignment(Alignment::CENTER_CENTER);
  content->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  UiText* title   = SDKExamples::createEclipseLabel(getPrism(), "Modal Single Action", EclipseLabelType::kT3);
  UiText* desc    = SDKExamples::createEclipseLabel(getPrism(), "Example Content", EclipseLabelType::kT4);
  UiButton* heart = SDKExamples::createEclipseButton(getPrism(),
      EclipseButtonParams(EclipseButtonType::kIcon, SystemIcon::kHeart));
  heart->onActivateSub(std::bind(&DialogsLayout::singleActionHeartActivateCallback, this,
      std::placeholders::_1, heartList));
  content->addItem(heart);
  content->addItem(title);
  content->addItem(desc);

  dialog->setDialogContent(content);
  dialog->setRenderingLayer(kDialogLayer); // set any custom rendering layer after setContent to alter content too.
  dialog->init();// call init when the dialog has content, is added to the scene and is ready

  // Single Action Dialogs send out onConfirm.
  dialog->onConfirmSub(std::bind(&DialogsLayout::dialogActivateCallback, this,
      std::placeholders::_1, heartList));
}

void DialogsLayout::timedCallback(const UiEventData& tab, UiListView* heartList) {
  std::vector<Node*> uitoggles = getRoot()->findChildren(UiToggle::GetNodeTypeEnum(), true);
  std::vector<Node*> uitabs    = getRoot()->findChildren(UiTab::GetNodeTypeEnum(), true);
  for (Node* node : uitoggles) {
    UiNode::CastFrom(node)->setEnabled(false);  // disable all ui interactions
  }
  for (Node* node : uitabs) {
    UiNode::CastFrom(node)->setEnabled(false);  // disable all ui interactions
  }
  heartList->setVisible(false);
  UiDialog* dialog = SDKExamples::createUiDialog(getPrism(), DialogType::kTimed);
  dialog->setLocalPosition(kDialogPosition);
  dialog->setExpireTime(kDialogExpireTime);  // expires in 5 seconds
  getRoot()->addChild(dialog);

  UiLinearLayout* content = SDKExamples::createUiLinearLayout(getPrism());
  content->setDefaultItemAlignment(Alignment::CENTER_CENTER);
  content->setAlignment(Alignment::CENTER_CENTER);
  content->setDefaultItemPadding(ExampleConsts::kDefaultPadding);
  UiText* title   = SDKExamples::createEclipseLabel(getPrism(), "Modeless Timed Dialog", EclipseLabelType::kT3);
  UiText* desc    = SDKExamples::createEclipseLabel(getPrism(), "Dialog will expire in:", EclipseLabelType::kT4);
  UiText* expire  = SDKExamples::createEclipseLabel(getPrism(), std::to_string(kDialogExpireTime),
      EclipseLabelType::kT3);
  content->addItem(title);
  content->addItem(desc);
  content->addItem(expire);

  EclipseSliderParams params(EclipseSliderType::kRadialWithIcon, SystemIcon::kHeart);
  UiSlider* progressBar = SDKExamples::createEclipseSlider(getPrism(), params);
  progressBar->setMax(kDialogExpireTime);
  progressBar->setSkipRaycast(true, true);

  content->addItem(progressBar);
  dialog->setDialogContent(content);
  dialog->setRenderingLayer(kDialogLayer); // set any rendering layer after setContent to alter content too.
  dialog->init(); // call init when the dialog has content, is added to the scene and is ready.

  // update timer text:
  dialog->onUpdateSub(std::bind(&DialogsLayout::setExpireTime, this, std::placeholders::_1,
      std::placeholders::_2, expire, progressBar));
  dialog->onTimeExpiredSub(std::bind(&DialogsLayout::timeExpiredCallback, this,
      std::placeholders::_1, heartList));
  dialog->onTimeExpiredSub(std::bind(&DialogsLayout::dialogActivateCallback, this,
      std::placeholders::_1, heartList));
}

// Dual action dialogs send out onConfirm or onCancel.
void DialogsLayout::confirmCallback(const UiEventData& dialog, UiButton* heart, UiListView* heartList) {
  UiListViewItem* heartItem = SDKExamples::createUiListViewItem(getPrism());
  heartItem->addChild(heart);
  heartList->addItem(heartItem);
  Cursor::SetCursorSnapMode(getPrism(), false);
  Cursor::SetPlaneDepth(getPrism(), 0.0f);  // bring the cursor plane back to the default plane
  heartList->setVisible(true);
  Node::Delete(dialog.getUiNode());
}

void DialogsLayout::dialogActivateCallback(const UiEventData& dialog, UiListView* heartList) {
  Cursor::SetCursorSnapMode(getPrism(), false);
  Cursor::SetPlaneDepth(getPrism(), 0.0f);  // bring the cursor plane back to the default plane
  heartList->setVisible(true);
  Node::Delete(dialog.getUiNode());
}

void DialogsLayout::dualActionHeartActivateCallback(const UiEventData& heart) {
  UiButton::CastFrom(heart.getUiNode())->setIconColor(color::RED);
}

void DialogsLayout::singleActionHeartActivateCallback(const UiEventData& heart, UiListView* heartList) {
  UiListViewItem* heartItem = SDKExamples::createUiListViewItem(getPrism());
  heartItem->addChild(heart.getUiNode());
  heartList->addItem(heartItem);
  UiButton::CastFrom(heart.getUiNode())->setIconColor(color::RED);
  heart.getUiNode()->setEnabled(false);
}

void DialogsLayout::timeExpiredCallback(const UiEventData&, UiListView* heartList) {
  std::vector<Node*> uitoggles = getRoot()->findChildren(UiToggle::GetNodeTypeEnum(), true);
  std::vector<Node*> uitabs    = getRoot()->findChildren(UiTab::GetNodeTypeEnum(), true);
  for (Node* node : uitoggles) {
    UiNode::CastFrom(node)->setEnabled(true);  // enable all ui interactions
  }
  for (Node* node : uitabs) {
    UiNode::CastFrom(node)->setEnabled(true);  // enable all ui interactions
  }
  EclipseButtonParams params(EclipseButtonType::kIcon, SystemIcon::kHeart);
  UiButton* heart           = SDKExamples::createEclipseButton(getPrism(), params);
  UiListViewItem* heartItem = SDKExamples::createUiListViewItem(getPrism());
  heartItem->addChild(heart);
  heartList->addItem(heartItem);
}

void DialogsLayout::setExpireTime(const UiEventData& dialog, float, UiText* expireTime,
    UiSlider* progressBar) {
  UiDialog* updatedDialog = UiDialog::CastFrom(dialog.getUiNode());
  expireTime->setText(ExampleHelpers::floatToString(updatedDialog->getCurrentExpireTime()));
  progressBar->setValue(updatedDialog->getCurrentExpireTime());
}

// Remove all nodes when detached from a prism:
void DialogsLayout::onDetachPrism(Prism* prism) {
  ML_LOG(Debug, "DialogsLayout::onDetachPrism() Destroying the Dialogs Layout scene");
  deleteSceneGraph();
  lumin::SDKExamples::BaseExample::onDetachPrism(prism);
}