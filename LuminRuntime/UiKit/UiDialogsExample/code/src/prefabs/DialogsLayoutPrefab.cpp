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
#include <DialogsLayoutPrefab.h>
#include <TimedDialogPrefab.h>
#include <SingleActionDialogPrefab.h>
#include <DualActionDialogPrefab.h>
#include <PrefabManager.h>
#include <ExamplesDefines.h>
#include <NodeCreationWrappers.h>
#include <lumin/ui/Cursor.h>
#include <lumin/node/RootNode.h>
#include <lumin/ui/node/UiToggle.h>
#include <lumin/ui/node/UiTab.h>
#include <lumin/ui/node/UiListViewItem.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const float kDialogPosition = 0.3f;  // dialogs should have the most forward z position
  const lumin::render::RenderingLayer kDialogLayer = lumin::render::RenderingLayer::kPostObjectLayer;
}

namespace prefabs {


  DialogsLayoutPrefab::DialogsLayoutPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root)
  : DialogsLayoutPrefabBase(extendedPrefabManager, root) {
  }

  DialogsLayoutPrefab::~DialogsLayoutPrefab() {
    prism_ = nullptr;
  }

  void DialogsLayoutPrefab::setPrism(Prism* prism) {
    prism_ = prism;
  }

  void DialogsLayoutPrefab::reset() {
    Cursor::SetCursorSnapMode(prism_, false);
    Cursor::SetPlaneDepth(prism_, 0.0f);  // bring the cursor plane back to the default plane
    getDS_ListView()->setVisible(true);
  }

  void DialogsLayoutPrefab::addItem(Node* item) {
    UiListViewItem* heartItem = lumin::SDKExamples::createUiListViewItem(prism_);
    heartItem->addChild(item);
    getDS_ListView()->addItem(heartItem);
  }

  void DialogsLayoutPrefab::setInteractions(bool enabled) {
    std::vector<Node*> uitoggles = prism_->getRootNode()->findChildren(UiToggle::GetNodeTypeEnum(), true);
    std::vector<Node*> uitabs    = prism_->getRootNode()->findChildren(UiTab::GetNodeTypeEnum(), true);
    for (Node* node : uitoggles) {
      UiNode::CastFrom(node)->setEnabled(enabled);
    }
    for (Node* node : uitabs) {
      UiNode::CastFrom(node)->setEnabled(enabled);
    }
  }

  // Handler methods are declared in the base class DialogsLayoutPrefabBase and can be implemented here

  void DialogsLayoutPrefab::SADS_Tab_SingleActionDialogTabHandlers(const lumin::ui::UiEventData& data) {
    Cursor::SetCursorSnapMode(prism_, true);  // force snap while showing dialog
    Cursor::SetPlaneDepth(prism_, kDialogPosition);  // force the cursor to be on the same plane as the dialog
    getDS_ListView()->setVisible(false);
    SingleActionDialogPrefab* prefab = extendedPrefabManager_->spawn<SingleActionDialogPrefab>();
    LUMIN_ASSERT(prefab, "Failed to create SingleActionDialogPrefab");
    prefab->setLayout(this);
    prefab->getSADN_Dialog()->setRenderingLayer(kDialogLayer);  // set any rendering layer after setContent to alter content too
    prism_->getRootNode()->addChild(prefab->getRoot());
    prefab->getSADN_Dialog()->init();  // call init when the dialog has content, is added to the scene and is ready
  }

  void DialogsLayoutPrefab::DADS_Tab_DualActionDialogTabHandlers(const lumin::ui::UiEventData& data) {
    Cursor::SetCursorSnapMode(prism_, true);  // force snap while showing dialog
    Cursor::SetPlaneDepth(prism_, kDialogPosition);  // force the cursor to be on the same plane as the dialog
    getDS_ListView()->setVisible(false);
    DualActionDialogPrefab* prefab = extendedPrefabManager_->spawn<DualActionDialogPrefab>();
    LUMIN_ASSERT(prefab, "Failed to create DualActionDialogPrefab");
    prefab->setLayout(this);
    prefab->getDADN_Dialog()->setRenderingLayer(kDialogLayer);  // set any rendering layer after setContent to alter content too
    prism_->getRootNode()->addChild(prefab->getRoot());
    prefab->getDADN_Dialog()->init();  // call init when the dialog has content, is added to the scene and is ready
  }

  void DialogsLayoutPrefab::TDS_Tab_TimedDialogTabHandlers(const lumin::ui::UiEventData& data) {
    Cursor::SetCursorSnapMode(prism_, true);  // force snap while showing dialog
    Cursor::SetPlaneDepth(prism_, kDialogPosition);  // force the cursor to be on the same plane as the dialog
    getDS_ListView()->setVisible(false);
    setInteractions(false);  // disable all ui interactions

    TimedDialogPrefab* prefab = extendedPrefabManager_->spawn<TimedDialogPrefab>();
    LUMIN_ASSERT(prefab, "Failed to create TimedDialogPrefab");
    prefab->setLayout(this);
    prefab->getTDN_Dialog()->setRenderingLayer(kDialogLayer);  // set any rendering layer after setContent to alter content too
    prefab->getTDN_Slider()->setSkipRaycast(true, true);
    prism_->getRootNode()->addChild(prefab->getRoot());
    prefab->getTDN_Dialog()->init();  // call init when the dialog has content, is added to the scene and is ready
  }

}
