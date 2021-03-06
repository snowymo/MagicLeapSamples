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

class SceneDescriptor;
class SceneManager;
class ExtendedSceneManager;
class ExtendedPrefabManager;

#include <lumin/node/Node.h>

#include <vector>

class SceneBase {
public:

  typedef std::vector<std::string> NodeReferences;

public:

  virtual const SceneDescriptor& getSceneDescriptor() const = 0;
  virtual const NodeReferences& getNodeReferences() const = 0;

  lumin::Node* getRoot() const;
  ExtendedSceneManager* getExtendedSceneManager() const;
  ExtendedPrefabManager* getExtendedPrefabManager() const;

protected:

  ExtendedSceneManager* const extendedSceneManager_ = nullptr;
  lumin::Node* root_ = nullptr;

  friend class ::SceneManager;
  SceneBase(ExtendedSceneManager* esm, lumin::Node* aRoot);
  virtual ~SceneBase();

  SceneBase() = delete;
  SceneBase(const SceneBase&) = delete;
  SceneBase(const SceneBase&&) = delete;
};
