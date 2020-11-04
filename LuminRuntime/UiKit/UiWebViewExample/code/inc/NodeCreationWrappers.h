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
#pragma once
#include <ExamplesDefines.h>
#include <lumin/LuminRuntime.h>
#include <lumin/ui/UiKit.h>

namespace lumin {
namespace SDKExamples {
  /**
   * Asserts that the given node is not null.
   * @param node     - pointer to a node
   * @param nodeName - name of the node
   * @return         - the valid node pointer on success, halts on failure
   */
  template<typename T>
  T assertNode(T node, const std::string& nodeName) {
    LUMIN_ASSERT(node != nullptr,
        "SDKExamples::NodeCreationWrappers::create%s() %s failed to be initialized.",
        nodeName.c_str(), nodeName.c_str());
    return node;
  }

  /**
   * Asserts that the given prism is not null.
   * @param prism - pointer to a prism
   * @return      - the valid prism pointer on success, halts on failure
   */
  inline Prism* assertPrism(Prism* prism) {
    LUMIN_ASSERT(prism != nullptr,
        "SDKExamples::NodeCreationWrappers Prism is invalid.");
    return prism;
  }

  /**
   * Creates an Eclipse button from UX specifications.
   * @param prism        - creates the Eclipse button in this prism
   * @param buttonParams - the EclipseButtonParams describing the Eclipse button to create
   * @return             - the new UiButton node representing the Eclipse button on success,
   *                       halts on failure
   */
  inline lumin::ui::UiButton* createEclipseButton(Prism* prism,
      const lumin::ui::EclipseButtonParams& buttonParams) {
    lumin::ui::UiButton* node = lumin::ui::UiButton::CreateEclipseButton(assertPrism(prism), buttonParams);
    return assertNode(node, "UiEclipseButton");
  }

  /**
   * Creates a new UiLinearLayout node.
   * @param prism  - creates the linear layout in this prism
   * @return       - new UiLinearLayout node on success, halts on failure
   */
  inline lumin::ui::UiLinearLayout* createUiLinearLayout(Prism* prism) {
    lumin::ui::UiLinearLayout* node = lumin::ui::UiLinearLayout::Create(assertPrism(prism));
    return assertNode(node, "UiLinearLayout");
  }
} // SDKExamples
} // lumin
