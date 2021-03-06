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
#include <lumin/node/TransformNode.h>
#include <lumin/ui/node/UiButton.h>
#include <lumin/ui/node/UiGridLayout.h>
#include <lumin/ui/node/UiImage.h>
#include <lumin/ui/node/UiLinearLayout.h>
#include <lumin/ui/node/UiListView.h>
#include <lumin/ui/node/UiListViewItem.h>
#include <lumin/ui/node/UiPanel.h>
#include <lumin/ui/node/UiRectLayout.h>
#include <lumin/ui/node/UiSlider.h>
#include <lumin/ui/node/UiText.h>
#include <lumin/ui/node/UiToggle.h>

class ExtendedPrefabManager;

namespace prefabs {

  class VideoUI;

  class VideoUIBase : public PrefabBase {
  public:

    static const PrefabDescriptor& getClassPrefabDescriptor();

  public:

    struct Names {
    public:

      static const std::string& cursorVisiblePanel;
      static const std::string& topLayout;
      static const std::string& title;
      static const std::string& videoUI;
      static const std::string& videoPlaceholderRoot;
      static const std::string& videoPlaceholder;
      static const std::string& playButton;
      static const std::string& fullMenu;
      static const std::string& videoSlider;
      static const std::string& fullToolbar;
      static const std::string& videoToolbar;
      static const std::string& playerButton;
      static const std::string& pauseButton;
      static const std::string& miniPlayButton;
      static const std::string& replayButton;
      static const std::string& volumeButton;
      static const std::string& muteButton;
      static const std::string& volumeSlider;
      static const std::string& videoTime;
      static const std::string& videoMenuIcon;
      static const std::string& errorMsg;
      static const std::string& settingsList;
      static const std::string& loopItem;
      static const std::string& loopToggle;
      static const std::string& resetItem;
      static const std::string& resetButton;

    protected:
      Names() = delete;
      ~Names() = delete;
    };

  public:

    const PrefabDescriptor& getPrefabDescriptor() const override;
    const NodeReferences& getNodeReferences() const override;

    virtual lumin::ui::UiPanel* getCursorVisiblePanel();
    virtual lumin::ui::UiLinearLayout* getTopLayout();
    virtual lumin::ui::UiText* getTitle();
    virtual lumin::ui::UiRectLayout* getVideoUI();
    virtual lumin::TransformNode* getVideoPlaceholderRoot();
    virtual lumin::ui::UiImage* getVideoPlaceholder();
    virtual lumin::ui::UiButton* getPlayButton();
    virtual lumin::ui::UiLinearLayout* getFullMenu();
    virtual lumin::ui::UiSlider* getVideoSlider();
    virtual lumin::ui::UiGridLayout* getFullToolbar();
    virtual lumin::ui::UiLinearLayout* getVideoToolbar();
    virtual lumin::ui::UiRectLayout* getPlayerButton();
    virtual lumin::ui::UiButton* getPauseButton();
    virtual lumin::ui::UiButton* getMiniPlayButton();
    virtual lumin::ui::UiButton* getReplayButton();
    virtual lumin::ui::UiButton* getVolumeButton();
    virtual lumin::ui::UiButton* getMuteButton();
    virtual lumin::ui::UiSlider* getVolumeSlider();
    virtual lumin::ui::UiText* getVideoTime();
    virtual lumin::ui::UiButton* getVideoMenuIcon();
    virtual lumin::ui::UiText* getErrorMsg();
    virtual lumin::ui::UiListView* getSettingsList();
    virtual lumin::ui::UiListViewItem* getLoopItem();
    virtual lumin::ui::UiToggle* getLoopToggle();
    virtual lumin::ui::UiListViewItem* getResetItem();
    virtual lumin::ui::UiButton* getResetButton();


  protected:

    lumin::ui::UiPanel* cursorVisiblePanel;
    lumin::ui::UiLinearLayout* topLayout;
    lumin::ui::UiText* title;
    lumin::ui::UiRectLayout* videoUI;
    lumin::TransformNode* videoPlaceholderRoot;
    lumin::ui::UiImage* videoPlaceholder;
    lumin::ui::UiButton* playButton;
    lumin::ui::UiLinearLayout* fullMenu;
    lumin::ui::UiSlider* videoSlider;
    lumin::ui::UiGridLayout* fullToolbar;
    lumin::ui::UiLinearLayout* videoToolbar;
    lumin::ui::UiRectLayout* playerButton;
    lumin::ui::UiButton* pauseButton;
    lumin::ui::UiButton* miniPlayButton;
    lumin::ui::UiButton* replayButton;
    lumin::ui::UiButton* volumeButton;
    lumin::ui::UiButton* muteButton;
    lumin::ui::UiSlider* volumeSlider;
    lumin::ui::UiText* videoTime;
    lumin::ui::UiButton* videoMenuIcon;
    lumin::ui::UiText* errorMsg;
    lumin::ui::UiListView* settingsList;
    lumin::ui::UiListViewItem* loopItem;
    lumin::ui::UiToggle* loopToggle;
    lumin::ui::UiListViewItem* resetItem;
    lumin::ui::UiButton* resetButton;


  private:

    friend class ::ExtendedPrefabManager;
    friend class VideoUI;

    static PrefabBase* createPrefab(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);

    static const PrefabDescriptor classPrefabDescriptor_;
    static const NodeReferences classNodeReferences_;

    VideoUIBase(ExtendedPrefabManager* extendedPrefabManager, lumin::Node* root);
    ~VideoUIBase() override;
  };
}
