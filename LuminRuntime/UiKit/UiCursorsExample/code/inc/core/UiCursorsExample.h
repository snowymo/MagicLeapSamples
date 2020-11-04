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
#include <lumin/LandscapeApp.h>
#include <lumin/InitArg.h>
/**
 * This Lumin Runtime UiCursors Example app will showcase the Lumin Runtime UiKit's default cursor types.
 * This example changes the cursor to each default cursor types once the cursor enters
 * the circular UiPanel of that cursor type.
 * This example uses nodes created with the Lumin Runtime Editor.
 */
class UiCursorsExample : public lumin::LandscapeApp {
public:
  /**
   * Constructs the UiCursorsExample.
   */
  UiCursorsExample();

  /**
   * Destroys the UiCursorsExample.
   */
  virtual ~UiCursorsExample();

  /**
   * Disallows the copy constructor.
   */
  UiCursorsExample(const UiCursorsExample&) = delete;

  /**
   * Disallows the move constructor.
   */
  UiCursorsExample(UiCursorsExample&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  UiCursorsExample& operator=(const UiCursorsExample&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  UiCursorsExample& operator=(UiCursorsExample&&) = delete;

protected:
  /**
   * Sets up our UiCursorsExample.
   */
  int init() override;

  /**
   * Destroys our UiCursorsExample.
   */
  int deInit() override;

  /**
   * Creates an instance of our UiCursorsExample.
   * @param initArg - the initial application argument
   */
  void onAppStart(const lumin::InitArg&) override;
};
