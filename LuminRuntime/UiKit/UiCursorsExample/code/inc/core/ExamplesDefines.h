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
#include <stdint.h>
#include <cstdlib>
#include <ml_logging.h>
/**
 * Writes the error message to ML_LOG, used with `mldb log`, then halts.
 */
#ifndef LUMIN_ASSERT
#define LUMIN_ASSERT(test, format, ...) { \
  if(!(test)) { \
    ML_LOG(Error, format, ##__VA_ARGS__); \
    std::abort(); \
  } \
}
#endif
