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

#include <string>
#include <map>

class PrefabDescriptor {
public:

  PrefabDescriptor(int index, const char* name, const char* id, const char* objectModelPath, const char* resourceModelPath);

  const std::string& getName() const;
  const std::string& getId() const;
  const std::string& getObjectModelPath() const;
  const std::string& getResourceModelPath() const;

private:

  friend class ExtendedPrefabManager;
  int getIndex() const;

protected:

  int index_;
  std::string name_;
  std::string id_;
  std::string objectModelPath_;
  std::string resourceModelPath_;
};

bool operator<(const PrefabDescriptor& a, const PrefabDescriptor& b);
