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
#include <BaseExample.h>
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

    BaseExample::Managers::Managers(lumin::Prism* prism) {
      extendedPrefab_ = new ExtendedPrefabManager(prism);
      extendedScene_ = new ExtendedSceneManager(prism, extendedPrefab_);
    }

    BaseExample::Managers::~Managers() {
      // delete the managers:
      delete extendedScene_;
      delete extendedPrefab_;

      extendedScene_  = nullptr;
      extendedPrefab_ = nullptr;
    }

    BaseExample::~BaseExample() {
    }

    BaseExample::BaseExample(const std::string& name) :
      PrismController(name),
      managers_(nullptr) {
    }

    // Display the Base Content Example when attached to a prism:
    void BaseExample::onAttachPrism(Prism* prism) {
      ML_LOG(Debug, "BaseExample::onAttachPrism() Initializing the Base Example scene");
      managers_ = new Managers(prism);
      createLayout(prism);
    }

    void BaseExample::createLayout(Prism* prism) {
      UiLinearLayout* topLayout = SDKExamples::createUiLinearLayout(prism);
      topLayout->setAlignment(Alignment::CENTER_CENTER);
      topLayout->setDefaultItemAlignment(Alignment::CENTER_CENTER);
      EclipseToggleParams params(
        EclipseToggleType::kSwitchWithLabel,
        lumin::EMPTY_STRING,
        lumin::EMPTY_STRING,
        "Built Scene Graph",
        "Loaded Scene Graph");
      UiToggle* contentSwitcher = SDKExamples::createEclipseToggle(prism, params);
      UiPageView* pageLayout    = SDKExamples::createUiPageView(prism);
      TransformNode* builtRoot  = buildSceneGraph(prism);
      TransformNode* loadedRoot = loadSceneGraph(prism);
      pageLayout->addPage(builtRoot);
      pageLayout->addPage(loadedRoot);
      pageLayout->showPage(builtRoot);

      contentSwitcher->onToggleChangedSub([pageLayout, builtRoot, loadedRoot, this](const UiEventData& toggle) {
        if (UiToggle::CastFrom(toggle.getUiNode())->getOn()) {
          pageLayout->showPage(loadedRoot);
        } else {
          pageLayout->showPage(builtRoot);
        }
      });
      topLayout->addItem(contentSwitcher);
      LineNode* divider = SDKExamples::createLineNode(prism);
      divider->addPoints(kLineLocalPosStart);
      divider->addPoints(kLineLocalPosEnd);
      divider->setColor(kLineColor);
      topLayout->addItem(divider, {0.01f, 0.0f, 0.02f, 0.0f});
      topLayout->addItem(pageLayout);

      getRoot()->addChild(topLayout);
    }

    // Remove all nodes when detached from a prism:
    void BaseExample::onDetachPrism(Prism*) {
      ML_LOG(Debug, "BaseExample::onDetachPrism() Destroying the Base Example scene");
      deleteSceneGraph();
      delete managers_;
      managers_ = nullptr;
    }
  } // SDKExamples
} // lumin
