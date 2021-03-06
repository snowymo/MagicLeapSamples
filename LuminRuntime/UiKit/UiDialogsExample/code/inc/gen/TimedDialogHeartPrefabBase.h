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

#pragma once

#include <PrefabBase.h>
#include <PrefabDescriptor.h>

class ExtendedPrefabManager;

namespace prefabs {

  class TimedDialogHeartPrefab;

  class TimedDialogHeartPrefabBase : public PrefabBase {
  public:

    static const PrefabDescriptor& getClassPrefabDescriptor();

  public:

    struct Names {
    protected:
      Names() = delete;
      ~Names() = delete;
    };

  public:

    const PrefabDescriptor& getPrefabDescriptor() const override;
    const NodeReferences& getNodeReferences() const override;


  protected:



  private:

    friend class ::ExtendedPrefabManager;
    friend class TimedDialogHeartPrefab;

    static PrefabBase* createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);

    static const PrefabDescriptor classPrefabDescriptor_;
    static const NodeReferences classNodeReferences_;

    TimedDialogHeartPrefabBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~TimedDialogHeartPrefabBase() override;
  };
}
