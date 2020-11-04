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
#include <BaseExampleController.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

namespace {
  const glm::vec3 kLineLocalPosStart(-0.4f, 0.0f, 0.0f);
  const glm::vec3 kLineLocalPosEnd(0.4f, 0.0f, 0.0f);
  const glm::vec4 kLineColor(0.6f, 0.6f, 0.6f, 1.0f);
}

namespace lumin {
  namespace SDKExamples {

    BaseExampleController::~BaseExampleController() {
    }

    BaseExampleController::BaseExampleController(const std::string& name, const glm::vec3& position,
        const std::shared_ptr<BasePrismController> generatedProgrammatically,
        const std::shared_ptr<BasePrismController> generatedExternally) :
      PrismController(name),
      position_(position),
      generatedProgrammatically_(generatedProgrammatically),
      generatedExternally_(generatedExternally),
      activeController_(nullptr) {
    }

    // Display the Base Content Example when attached to a prism:
    void BaseExampleController::onAttachPrism(Prism* prism) {
      ML_LOG(Debug, "BaseExampleController::onAttachPrism() Initializing the Base Example scene");
      createLayout(prism);
    }

    std::shared_ptr<BasePrismController> BaseExampleController::getActiveController() {
      return activeController_;
    }

    void BaseExampleController::createLayout(Prism* prism) {
      UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
      topLayout->setAlignment(Alignment::CENTER_CENTER);
      topLayout->setDefaultItemAlignment(Alignment::CENTER_CENTER);
      topLayout->setName("BaseExampleController_topLayout");
      EclipseToggleParams params(
        EclipseToggleType::kSwitchWithLabel,
        lumin::EMPTY_STRING,
        lumin::EMPTY_STRING,
        "Built Scene Graph",
        "Loaded Scene Graph");
      UiToggle* contentSwitcher = SDKExamples::createEclipseToggle(prism, params);
      UiPageView* pageLayout    = SDKExamples::createUiPageView(prism);
      addChildController(generatedProgrammatically_);
      addChildController(generatedExternally_);
      TransformNode* builtRoot  = generatedProgrammatically_->buildSceneGraph(prism);
      TransformNode* loadedRoot = generatedExternally_->loadSceneGraph(prism);
      pageLayout->addPage(builtRoot);
      pageLayout->addPage(loadedRoot);
      pageLayout->showPage(builtRoot);
      pageLayout->setName("BaseExampleController_pageLayout");
      activeController_ = generatedProgrammatically_;

      contentSwitcher->onToggleChangedSub([pageLayout, builtRoot, loadedRoot, this](const UiEventData& toggle) {
        if (UiToggle::CastFrom(toggle.getUiNode())->getOn()) {
          pageLayout->showPage(loadedRoot);
          generatedProgrammatically_->onToggleChanged(false);
          generatedExternally_->onToggleChanged(true);
          activeController_ = generatedExternally_;
        } else {
          pageLayout->showPage(builtRoot);
          generatedExternally_->onToggleChanged(false);
          generatedProgrammatically_->onToggleChanged(true);
          activeController_ = generatedProgrammatically_;
        }
      });
      topLayout->addItem(contentSwitcher);
      LineNode* divider = SDKExamples::createLineNode(prism);
      divider->addPoints(kLineLocalPosStart);
      divider->addPoints(kLineLocalPosEnd);
      divider->setColor(kLineColor);
      topLayout->addItem(divider, {0.01f, 0.0f, 0.02f, 0.0f});
      topLayout->addItem(pageLayout);
      topLayout->setLocalPosition(position_);
      getRoot()->addChild(topLayout);
    }

    // Remove all nodes when detached from a prism:
    void BaseExampleController::onDetachPrism(Prism*) {
      ML_LOG(Debug, "BaseExampleController::onDetachPrism() Destroying the Base Example scene");
      removeChildController(generatedProgrammatically_);
      removeChildController(generatedExternally_);
      deleteSceneGraph();
    }
  } // SDKExamples
} // lumin