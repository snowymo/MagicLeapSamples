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
   * Creates a new Node.
   * @param prism          - creates the transform node in this prism
   * @return               - new Node on success, halts on failure
   */
  inline Node* createNode(Prism* prism) {
    Node* node = assertPrism(prism)->createNode();
    return assertNode(node, "Node");
  }

  /**
   * Creates a new TransformNode.
   * @param prism          - creates the transform node in this prism
   * @param localTransform - the local transform of the new node,
   *                         uses glm::mat4() for the identity matrix
   * @return               - new TransformNode on success, halts on failure
   */
  inline TransformNode* createTransformNode(Prism* prism,
      const glm::mat4& localTransform = glm::mat4()) {
    TransformNode* node = assertPrism(prism)->createTransformNode(localTransform);
    return assertNode(node, "TransformNode");
  }

  /**
   * Creates a new ModelNode.
   * @param prism      - creates the model node in this prism
   * @param resourceID - resource ID to use for the node
   * @return           - new ModelNode on success, halts on failure
   */
  inline ModelNode* createModelNode(Prism* prism,
      ResourceIDType resourceID = lumin::INVALID_RESOURCE_ID) {
    ModelNode* node = assertPrism(prism)->createModelNode(resourceID);
    return assertNode(node, "ModelNode");
  }

  /**
   * Creates a new QuadNode.
   * @param prism      - creates the quad node in this prism
   * @param resourceID - resource Id to use for the node (optional)
   * @return           - new QuadNode on success, halts on failure
   */
  inline QuadNode* createQuadNode(Prism* prism,
      ResourceIDType resourceID = lumin::INVALID_RESOURCE_ID) {
    QuadNode* node = assertPrism(prism)->createQuadNode(resourceID);
    return assertNode(node, "QuadNode");
  }

  /**
   * Creates a new LineNode.
   * @param prism  - creates the line node in this prism
   * @return       - new LineNode on success, halts on failure
   */
  inline LineNode* createLineNode(Prism* prism) {
    LineNode* node = assertPrism(prism)->createLineNode();
    return assertNode(node, "LineNode");
  }

  /**
   * Creates a new SpriteNode from a texture pack resource.
   * @param prism    - creates the sprite node in this prism
   * @param resource - pointer to the resource that contains the frames for the sprite
   * @return         - new SpriteNode on success, halts on failure
   */
  inline SpriteNode* createSpriteNode(Prism* prism, ResourceIDType resource) {
    SpriteNode* node = assertPrism(prism)->createSpriteNode(resource);
    return assertNode(node, "SpriteNode");
  }

  /**
   * Creates a new AudioNode.
   * After calling this createAudioNode(), must call one of the AudioNode::createSoundXxxxX() methods
   * to create a specific type of audio node.
   * @param prism - creates the audio node in this prism
   * @return      - new AudioNode on success, halts on failure
   */
  inline AudioNode* createAudioNode(Prism* prism) {
    AudioNode* node = assertPrism(prism)->createAudioNode();
    return assertNode(node, "AudioNode");
  }

  /**
   * Create a new ParticleNode.
   * @param prism      - creates the particle node in this prism
   * @param resourceId - optional resource Id of the particle effect package to use
   * @return           - new ParticleNode on success, halts on failure
   */
  inline ParticleNode* createParticleNode(Prism* prism,
      ResourceIDType packageResource = lumin::INVALID_RESOURCE_ID) {
    ParticleNode* node = assertPrism(prism)->createParticleNode(packageResource);
    return assertNode(node, "ParticleNode");
  }

  /**
   * Creates a VideoNode with the given resolution and display mode.
   * @param prism    - creates the video node in this prism
   * @param a_width  - the surface resolution width 1 to 2048
   * @param a_height - the surface resolution height 1 to 2048
   * @return         - the new VideoNode on success, halts on failure
   */
  inline VideoNode* createVideoNode(Prism* prism,
      uint32_t a_width = 512, uint32_t a_height = 512) {
    VideoNode* node = assertPrism(prism)->createVideoNode(a_width, a_height);
    return assertNode(node, "VideoNode");
  }

  /**
   * Creates a 2D text node using the Magic Leap UI font (regular weight).
   * @param prism - creates the 2D text node in this prism
   * @param desc  - information about the Text2dNode to create
   * @param style - either normal or italic style are supported
   * @return      - the new Text2dNode on success, halts on failure
   */
  inline Text2dNode* createDefaultText2dNode(Prism* prism, const Text2dDesc& desc,
      resources::FontStyle style = resources::FontStyle::kNormal) {
    Text2dNode* node = assertPrism(prism)->createDefaultText2dNode(desc, style);
    return assertNode(node, "Default Text2dNode");
  }

  /**
   * Creates a 2D text node with the given font and properties.
   * @param prism          - creates the 2D text node in this prism
   * @param fontResourceId - ID of a FontResource to use
   * @param desc           - information about the Text2dNode to create
   * @return               - the new Text2dNode on success, halts on failure
   */
  inline Text2dNode* createText2dNode(Prism* prism, ResourceIDType fontResourceId,
      const Text2dDesc& desc) {
    Text2dNode* node = assertPrism(prism)->createText2dNode(fontResourceId, desc);
    return assertNode(node, "Text2dNode");
  }

  /**
   * Creates a directional light node.
   * @return - the new LightNode on success, halts on failure
   */
  inline LightNode* createLightNode(Prism* prism) {
    LightNode* node = assertPrism(prism)->createLightNode();
    return assertNode(node, "LightNode");
  }

  /**
   * Creates an instance of the MaskingAura and the accompanying node
   * hierarchy.  The returned MaskingAura pointer is managed by the
   * parent UiNode it is attached to and does not need to be deleted.  The node
   * hierarchy parent UiNode can be obtained with node() and is initially
   * orphaned and must be added to the scene as any other node.
   *
   * @param prism  - the prism to create the Masking Aura in
   * @return       - pointer to the MaskingAura instance on success, halts on failure
   */
  inline lumin::ui::MaskingAura* createMaskingAura(Prism* prism) {
    lumin::ui::MaskingAura* node = lumin::ui::MaskingAura::Create(assertPrism(prism));
    return assertNode(node, "MaskingAura");
  }

  /**
   * Creates a new UiNode.
   * @param prism  - creates the node in this prism
   * @return       - new UiNode on success, halts on failure
   */
  inline lumin::ui::UiNode* createUiNode(Prism* prism) {
    lumin::ui::UiNode* node = lumin::ui::UiNode::Create(assertPrism(prism));
    return assertNode(node, "UiNode");
  }

  /**
   * Creates a UiButton element using default settings.
   *
   * The default values for width and height are 0, which instructs
   * the button to use the default button height and automatically
   * calculates button width based on the button text dimensions.
   *
   * Setting a value greater than 0 for width or height will override
   * the defaults.
   *
   * Button text size is automatically set based on the button height,
   * unless overridden with UiButton::setTextSize().
   *
   * @param prism     - creates the button in this prism
   * @param labelText - the UTF-8 encoded text to initially set the UiButton label to
   * @param width     - the width of the button, 0 for default
   * @param height    - the height of the button, 0 for default
   * @param roundness - the ratio of corner rounding [0-1]
   *                    1 [default] = fully rounded (circle, capsule), 0 = sharp corner
   * @return          - the new UiButton node on success, halts on failure
   */
  inline lumin::ui::UiButton* createUiButton(Prism* prism, const std::string& labelText,
      float width = 0.0f, float height = 0.0f, float roundness = 1.0f) {
     lumin::ui::UiButton* node = lumin::ui::UiButton::Create(assertPrism(prism),
        labelText, width, height, roundness);
    return assertNode(node, "UiButton");
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
   * Creates a UiText element with default settings.
   * @param prism  - creates the text in this prism
   * @param text   - the UTF-8 encoded text to initially set the UiText to
   * @param style  - the style of the Magic Leap font (optional)
   * @param weight - the weight (i.e., thickness) of the Magic Leap font (optional)
   * @return       - the new UiText node on success, halts on failure
   */
  inline lumin::ui::UiText* createUiText(lumin::Prism* prism,
      const std::string& text, resources::FontStyle style = resources::FontStyle::kNormal,
      resources::FontWeight weight = resources::FontWeight::kRegular) {
    lumin::ui::UiText* node = lumin::ui::UiText::Create(assertPrism(prism), text, style, weight);
    return assertNode(node, "UiText");
  }

  /**
   * Creates an Eclipse label from UX specifications.
   * @param prism     - creates the Eclipse label in this prism
   * @param text      - the UTF-8 encoded text to initially set the Eclipse label to
   * @param labelType - the EclipseLabelType
   * @return          - the new UiText EclipseLabel on success, halts on failure
   */
  inline lumin::ui::UiText* createEclipseLabel(Prism* prism, const std::string& text,
      lumin::ui::EclipseLabelType labelType) {
    lumin::ui::UiText* node = lumin::ui::UiText::CreateEclipseLabel(assertPrism(prism), text, labelType);
    return assertNode(node, "UiEclipseLabel");
  }

  /**
   * Creates a UiTextEdit element with default settings.
   * @param prism  - creates the text edit in this prism
   * @param text   - the UTF-8 encoded text to initially set the UiTextEdit to
   * @param width  - the width of the text edit area
   * @param height - the height of the text edit area
   * @return       - the new UiTextEdit node on success, halts on failure
   */
  inline lumin::ui::UiTextEdit* createUiTextEdit(Prism* prism, const std::string& text,
      float width, float height) {
    lumin::ui::UiTextEdit* node = lumin::ui::UiTextEdit::Create(assertPrism(prism), text, width, height);
    return assertNode(node, "UiTextEdit");
  }

  /**
   * Creates a UiImage element with System icon.
   * @param prism  - the prism to create this image for
   * @param type   - the SystemIcon type for the image
   * @param height - the height of the image
   * @return       - the new UiImage node on success, halts on failure
   */
  inline lumin::ui::UiImage* createUiImage(Prism* prism, lumin::ui::SystemIcon type,
      float height = 0.05f) {
    lumin::ui::UiImage* node = lumin::ui::UiImage::Create(assertPrism(prism), type, height);
    return assertNode(node, "UiImage");
  }

  /**
   * Creates a UiImage element. Default settings create a blank 1 meter by 1 meter square.
   * @param prism    - creates the image in this prism
   * @param resID    - the resource ID to render for the image
   * @param width    - the width of the image
   * @param height   - the height of the image
   * @param useFrame - specifies whether the image should have a frame
   * @return         - the new UiImage node, halts on failure
   */
  inline lumin::ui::UiImage* createUiImage(Prism* prism,
      ResourceIDType resID = lumin::INVALID_RESOURCE_ID,
      float width = 1.0f, float height = 1.0f, bool useFrame = false) {
    lumin::ui::UiImage* node = lumin::ui::UiImage::Create(assertPrism(prism),
        resID, width, height, useFrame);
    return assertNode(node, "UiImage");
  }

  /**
   * Creates a UiImage element with default settings.
   * @param prism        - creates the image in this prism
   * @param pngFile      - the path to the PNG to render for the image
   * @param width        - the width of the image
   * @param height       - the height of the image
   * @param absolutePath - flag that pngFile is an absolute path name, instead of a relative path
   * @param useFrame     - specifies whether the image should have a frame
   * @return             - the new UiImage node on success, halts on failure
   */
  inline lumin::ui::UiImage* createUiImage(Prism* prism, const std::string& pngFile,
      float width, float height, bool absolutePath = false, bool useFrame = false) {
    lumin::ui::UiImage* node = lumin::ui::UiImage::Create(assertPrism(prism),
        pngFile, width, height, absolutePath, useFrame);
    return assertNode(node, "UiImage");
  }

  /**
   * Creates a UiToggle element using default settings.
   * The default values for height is 0, which instructs
   * the toggle to use the default toggle height.  A value
   * greater than 0 will override the defaults.
   *
   * Label text size is automatically set based on the toggle height
   * unless overridden with UiToggle::setTextSize().
   *
   * Note: This creates a standard, typed (default switch, radio, checkbox) toggle element.
   *
   * @param prism     - creates the toggle in this prism
   * @param labelText - the UTF-8 encoded text to initially set the UiToggle label to
   * @param height    - the height of the toggle (optional)
   * @return          - the new UiToggle node on success, halts on failure
   */
  inline lumin::ui::UiToggle* createUiToggle(Prism* prism, const std::string& labelText,
      float height = 0.0f) {
    lumin::ui::UiToggle* node = lumin::ui::UiToggle::Create(assertPrism(prism), labelText, height);
    return assertNode(node, "UiToggle");
  }

  /*
   * Creates a UiToggle element using default settings.
   *
   * The default values for height is 0, which instructs
   * the toggle to use the default toggle height.  A value
   * greater than 0 will override the defaults.
   *
   * Label text size is automatically set based on the toggle height
   * unless overridden with UiToggle::setTextSize().
   *
   * Note: This creates a standard, typed (default switch, radio, checkbox) toggle element.
   * For specific instances of toggle from the UX spec, see createEclipseToggle.
   *
   * @param prism      - creates the toggle in this prism
   * @param labelText  - the UTF-8 encoded text to initially set the UiToggle label to
   * @param toggleType - the type of the toggle (kDefault, kRadio, kCheckbox)
   * @param height     - the height of the toggle (optional)
   * @return           - the new UiToggle node on success, halts on failure
   */
  inline lumin::ui::UiToggle* createUiToggle(Prism* prism, const std::string& labelText,
      lumin::ui::ToggleType toggleType, float height = 0.0f) {
    lumin::ui::UiToggle* node = lumin::ui::UiToggle::Create(assertPrism(prism),
        labelText, toggleType, height);
    return assertNode(node, "UiToggle");
  }

  /**
   * Creates an Eclipse toggle from UX specifications.
   * @param prism        - creates the Eclipse toggle in this prism
   * @param toggleParams - the EclipseToggleParams describing the Eclipse toggle to create
   * @return             - the new UiToggle node representing the Eclipse toggle on success,
   *                       halts on failure
   */
  inline lumin::ui::UiToggle* createEclipseToggle(Prism* prism,
      const lumin::ui::EclipseToggleParams& toggleParams) {
    lumin::ui::UiToggle* node = lumin::ui::UiToggle::CreateEclipseToggle(assertPrism(prism), toggleParams);
    return assertNode(node, "UiEclipseToggle");
  }

  /**
   * Creates a UiToggleGroup element using default settings.
   * @param prism           - creates the toggle group in this prism
   * @param allowMultipleOn - the default (false) does not allow multiple toggles ON
   * @param allowAllOff     - the default (false) does not allow all toggles OFF
   * @return                - the new UiToggleGroup node on success, halts on failure
   */
  inline lumin::ui::UiToggleGroup* createUiToggleGroup(Prism* prism,
      bool allowMultipleOn = false, bool allowAllOff = false) {
     lumin::ui::UiToggleGroup* node = lumin::ui::UiToggleGroup::Create(assertPrism(prism),
        allowMultipleOn, allowAllOff);
    return assertNode(node, "UiToggleGroup");
  }

  /**
   * Creates a UiSlider element using default settings.
   *
   * The default values for height is 0, which instructs
   * the slider to use the default slider height. A value
   * greater than 0 will override the defaults.
   *
   * Note: This creates a standard, horizontal slider. For specific
   * instances of slider from the UX spec, see createEclipseSlider.
   *
   * @param prism  - creates the slider in this prism
   * @param width  - the width of the slider
   * @param height - the height of the slider (optional)
   * @return       - the new UiSlider node on success, halts on failure
   */
  inline lumin::ui::UiSlider* createUiSlider(Prism* prism, float width, float height = 0.0f) {
    lumin::ui::UiSlider* node = lumin::ui::UiSlider::Create(assertPrism(prism), width, height);
    return assertNode(node, "UiSlider");
  }

  /**
   * Creates an Eclipse slider from UX specifications.
   * @param prism        - creates the Eclipse slider in this prism
   * @param sliderParams - the EclipseButtonParams describing the Eclipse slider to create
   * @return             - the new UiSlider node representing the Eclipse slider on success,
   *                       halts on failure
   */
  inline lumin::ui::UiSlider* createEclipseSlider(Prism* prism,
      const lumin::ui::EclipseSliderParams& sliderParams) {
    lumin::ui::UiSlider* node = lumin::ui::UiSlider::CreateEclipseSlider(assertPrism(prism), sliderParams);
    return assertNode(node, "UiEclipseSlider");
  }

  /**
   * Creates a UiProgressBar element using default settings.
   *
   * The default values for height is 0, which instructs
   * the progress bar to use the default progress bar height. A value
   * greater than 0 will override the defaults.
   *
   * Note: This creates a standard, horizontal progress bar.
   *
   * @param prism  - creates the progress bar in this prism
   * @param width  - the width of the progress bar
   * @param height - the height of the progress bar (optional)
   * @return       - the new UiProgressBar node on success, halts on failure
   */
  inline lumin::ui::UiProgressBar* createUiProgressBar(Prism* prism,
      float width, float height = 0.0f) {
    lumin::ui::UiProgressBar* node = lumin::ui::UiProgressBar::Create(assertPrism(prism), width, height);
    return assertNode(node, "UiProgressBar");
  }

  /**
   * Creates a UiPageView element with default settings.
   * @param prism  - creates the page view in this prism
   * @param width  - the width of the page view,
   *                 the default (0) allows the view to grow to content
   * @param height - the height of the page view,
   *                 the default (0) allows the view to grow to content
   * @return       - the new UiPageView node on success, halts on failure
   */
  inline lumin::ui::UiPageView* createUiPageView(Prism* prism, float width = 0.0f,
      float height = 0.0f) {
    lumin::ui::UiPageView* node = lumin::ui::UiPageView::Create(assertPrism(prism), width, height);
    return assertNode(node, "UiPageView");
  }

  /**
   * Creates a UiDropDownList element using default settings.
   * @param prism     - creates the drop-down list in this prism
   * @param labelText - the UTF-8 encoded text to initially set the drop-down list label to
   * @return          - the new UiDropDownList node on success, halts on failure
   */
  inline lumin::ui::UiDropDownList* createUiDropDownList(Prism* prism,
      const std::string& labelText) {
    lumin::ui::UiDropDownList* node = lumin::ui::UiDropDownList::Create(assertPrism(prism), labelText);
    return assertNode(node, "UiDropDownList");
  }

  /**
   * Creates a UiPortalIcon element using default settings.
   * @param prism     - the prism to create the icon for
   * @param labelText - the UTF-8 encoded text to initially set the portal icon label to
   * @param size      - one of the built-in sizes for the portal icon (defaults to Small)
   * @return          - the new UiPortalIcon node on success, halts on failure
   */
  inline lumin::ui::UiPortalIcon* createUiPortalIcon(Prism* prism,
      const std::string& labelText, lumin::ui::PortalIconSize portalSize =
      lumin::ui::PortalIconSize::kSmall) {
    lumin::ui::UiPortalIcon* node = lumin::ui::UiPortalIcon::Create(assertPrism(prism),
        labelText, portalSize);
    return assertNode(node, "UiPortalIcon");
  }

  /**
   * Creates a UiLoadingSpinner element using default settings.
   * @param prism   - creates the loading spinner in this prism
   * @param type    - loading spinner type (kParticlePackage, etc.)
   * @param resID   - the resource ID (optional)
   * @param resPath - the resource path in the resource (optional)
   * @param height  - the height of the loading spinner (optional)
   * @return        - the new UiLoadingSpinner node on success, halts on failure
   */
  inline lumin::ui::UiLoadingSpinner* createUiLoadingSpinner(Prism* prism,
      lumin::ui::LoadingSpinnerType type, ResourceIDType resID = INVALID_RESOURCE_ID,
      const std::string& resPath = "", float height = 0.0f) {
    lumin::ui::UiLoadingSpinner* node = lumin::ui::UiLoadingSpinner::Create(assertPrism(prism),
        type, resID, resPath, height);
    return assertNode(node, "UiLoadingSpinner");
  }

  /**
   * Creates a UiCircleConfirmation element using default settings.
   * @param prism  - creates the circle confirmation in this prism
   * @param height - the radius of the circle the knob evolves at (optional)
   * @return       - the new UiCircleConfirmation node on success, halts on failure
   */
  inline lumin::ui::UiCircleConfirmation* createUiCircleConfirmation(Prism* prism,
      const float height = 0.0f) {
    lumin::ui::UiCircleConfirmation* node = lumin::ui::UiCircleConfirmation::Create(assertPrism(prism), height);
    return assertNode(node, "UiCircleConfirmation");
  }

  /**
   * Creates a UiColorPicker element using default settings.
   * @param prism         - creates the color picker in this prism
   * @param startingColor - the initial color for the color picker, default is white
   * @param height        - height for the color picker (optional)
   * @return              - the new UiColorPicker node on success, halts on failure
   */
  inline lumin::ui::UiColorPicker* createUiColorPicker(Prism* prism,
      const glm::vec4& startingColor = color::WHITE, float height = 0.0f) {
    lumin::ui::UiColorPicker* node = lumin::ui::UiColorPicker::Create(assertPrism(prism), startingColor, height);
    return assertNode(node, "UiColorPicker");
  }

  /**
   * Creates a UiListView element with default settings.
   * @param prism  - creates the list view in this prism
   * @param width  - the width of the list view,
   *                 the default (0) allows the list to grow to content
   * @param height - the height of the list view,
   *                 the default (0) allows the list to grow to content
   * @return       - the new UiListView node on success, halts on failure
   */
  inline lumin::ui::UiListView* createUiListView(Prism* prism, float width = 0.0f,
      float height = 0.0f) {
    lumin::ui::UiListView* node = lumin::ui::UiListView::Create(assertPrism(prism), width, height);
    return assertNode(node, "UiListView");
  }

  /**
   * Creates a new UiGroup node.
   * @param prism  - creates the group in this prism
   * @return       - new UiGroup node on success, halts on failure
   */
  inline lumin::ui::UiGroup* createUiGroup(Prism* prism) {
    lumin::ui::UiGroup* node = lumin::ui::UiGroup::Create(assertPrism(prism));
    return assertNode(node, "UiGroup");
  }

  /**
   * Creates a UiScrollBar element with default settings.
   * @param prism  - the prism to create this node for
   * @param width  - the length of the scrollbar,
   *                 this is a little bit longer than the scroll range
   *                 (which is the range the thumb will run)
   * @param height - this is how wide the scrollbar will be,
   *                 a user should normally not care about this unless they
   *                 intend to change the skin of an app
   * @return       - the new UiScrollBar node on success, halts on failure
   */
  inline lumin::ui::UiScrollBar* createUiScrollBar(Prism* prism, float width, float height = 0.0f) {
    lumin::ui::UiScrollBar* node = lumin::ui::UiScrollBar::Create(assertPrism(prism), width, height);
    return assertNode(node, "UiScrollBar");
  }

  /**
   * Creates a new UiScrollView node.
   * @param prism  - creates the scroll view in this prism
   * @return       - new UiScrollView node on success, halts on failure
   */
  inline lumin::ui::UiScrollView* createUiScrollView(Prism* prism) {
    lumin::ui::UiScrollView* node = lumin::ui::UiScrollView::Create(assertPrism(prism));
    return assertNode(node, "UiScrollView");
  }

  /**
   * Creates a new UiRectLayout node.
   * @param prism  - creates the scroll view in this prism
   * @return       - new UiRectLayout node on success, halts on failure
   */
  inline lumin::ui::UiRectLayout* createUiRectLayout(Prism* prism) {
    lumin::ui::UiRectLayout* node = lumin::ui::UiRectLayout::Create(assertPrism(prism));
    return assertNode(node, "UiRectLayout");
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

  /**
   * Creates a new UiGridLayout node.
   * @param prism  - creates the grid layout in this prism
   * @return       - new UiGridLayout node on success, halts on failure
   */
  inline lumin::ui::UiGridLayout* createUiGridLayout(Prism* prism) {
    lumin::ui::UiGridLayout* node = lumin::ui::UiGridLayout::Create(assertPrism(prism));
    return assertNode(node, "UiGridLayout");
  }

  /**
   * Creates a new UiListViewItem node.
   * @param prism  - creates the list view item in this prism
   * @return       - new UiListViewItem node on success, halts on failure
   */
  inline lumin::ui::UiListViewItem* createUiListViewItem(Prism* prism) {
    lumin::ui::UiListViewItem* node = lumin::ui::UiListViewItem::Create(assertPrism(prism));
    return assertNode(node, "UiListViewLayout");
  }

  /**
   * Creates a new UiPanel node.
   * @param prism  - creates the panel in this prism
   * @return       - new UiPanel node on success, halts on failure
   */
  inline lumin::ui::UiPanel* createUiPanel(Prism* prism) {
    lumin::ui::UiPanel* node = lumin::ui::UiPanel::Create(assertPrism(prism));
    return assertNode(node, "UiPanel");
  }

  /**
   * Creates a UiTab element using default settings.
   * @param prism     - The prism to create this button for
   * @param labelText - the UTF-8 encoded text to initially set the UiTab label to
   * @return          - the new UiTab node on success, halts on failure
   */
  inline lumin::ui::UiTab* createUiTab(Prism* prism, const std::string& labelText) {
    lumin::ui::UiTab* node = lumin::ui::UiTab::Create(assertPrism(prism), labelText);
    return assertNode(node, "UiTab");
  }

  /**
   * Creates an Eclipse Tab from UX specifications.
   * @param prism     - the prism to create this node for
   * @param text      - the UTF-8 encoded text to initially set the Eclipse label to
   * @param labelType - the EclipseLabelType
   * @return          - the new UiTab node on success, halts on failure
   */
  inline lumin::ui::UiTab* createEclipseTab(Prism* prism, const std::string& text,
      lumin::ui::EclipseLabelType labelType) {
    lumin::ui::UiTab* node = lumin::ui::UiTab::CreateEclipseTab(assertPrism(prism), text, labelType);
    return assertNode(node, "UiTab");
  }

  /**
   * Creates a UiDialog element from UX specifications.
   * @param prism - the prism to create this node for
   * @param type  - the type of dialog
   * @return      - the new UiDialog on success; halts on failure
   */
  inline lumin::ui::UiDialog* createUiDialog(Prism* prism, lumin::ui::DialogType type) {
    lumin::ui::UiDialog* node = lumin::ui::UiDialog::Create(assertPrism(prism), type);
    return assertNode(node, "UiDialog");
  }

  /**
   * Creates a new UiDialog with generated content.
   * @param prism        - the prism to create this dialog for
   * @param title        - the dialog title text.  Use an empty string to not show title
   * @param message      - the dialog message text.  Use an empty string to not show message
   * @param imageModel   - the dialog image model hierarchy.  Use nullptr to not show image model
   * @param dialogType   - the type of dialog
   * @param dialogLayout - the dialog layout preference
   * @return             - new UiDialog on success; halts on failure
   */
  inline lumin::ui::UiDialog* createUiDialog(Prism* prism, const std::string& title, const std::string& message,
      TransformNode* imageModel = nullptr, lumin::ui::DialogType dialogType = lumin::ui::DialogType::kDualAction,
      lumin::ui::DialogLayout dialogLayout = lumin::ui::DialogLayout::kStandard) {
    lumin::ui::UiDialog* node = lumin::ui::UiDialog::Create(assertPrism(prism), title, message, imageModel,
        dialogType, dialogLayout);
    return assertNode(node, "UiDialog");
  }

  /**
   * Creates a new UiDialog with vertical scrolling content.
   * @param prism        - the prism to create this dialog for
   * @param title        - the dialog title text.  Use an empty string to not show title
   * @param message      - the dialog message text to scroll
   * @param dialogType   - the type of dialog
   * @param dialogLayout - the dialog layout preference
   * @return             - new UiDialog on success; halts on failure
   */
  inline lumin::ui::UiDialog* createScrollingDialog(Prism* prism, const std::string& title,
      const std::string& message, lumin::ui::DialogType dialogType = lumin::ui::DialogType::kDualAction,
      lumin::ui::DialogLayout dialogLayout = lumin::ui::DialogLayout::kWide) {
    lumin::ui::UiDialog* node = lumin::ui::UiDialog::CreateScrolling(assertPrism(prism), title, message,
        dialogType, dialogLayout);
    return assertNode(node, "UiDialog");
  }

  /**
   * Create a new UiDialog with vertical scrolling content.
   * @param prism         - the prism to create this dialog for
   * @param title         - the dialog title text.  Use an empty string to not show title
   * @param scrollContent - the top level node of the content to scroll
   * @param dialogType    - the type of dialog
   * @param dialogLayout  - the dialog layout preference
   * @return              - new UiDialog on success; halts on failure
   */
  inline lumin::ui::UiDialog* CreateScrolling(Prism* prism, const std::string& title,
      TransformNode* scrollContent, lumin::ui::DialogType dialogType = lumin::ui::DialogType::kDualAction,
      lumin::ui::DialogLayout dialogLayout = lumin::ui::DialogLayout::kWide) {
    lumin::ui::UiDialog* node = lumin::ui::UiDialog::CreateScrolling(assertPrism(prism), title, scrollContent,
        dialogType, dialogLayout);
    return assertNode(node, "UiDialog");
  }

  /**
   * Creates a UiDatePicker element using default settings.
   *
   * @param prism            - the prism to create the node for
   * @param datePickerParams - custom params set for this UiDatePicker
   *
   * @return                 - the new UiDatePicker node on success; halts on failure
   */
  inline lumin::ui::UiDatePicker* createUiDatePicker(Prism* prism, const ui::DatePickerParams& datePickerParams) {
    lumin::ui::UiDatePicker* node = lumin::ui::UiDatePicker::Create(assertPrism(prism), datePickerParams);
    return assertNode(node, "UiDatePicker");
  }

  /**
   * Creates a UiTimePicker element using default settings.
   *
   * @param prism            - the prism to create the node for
   * @param timePickerParams - custom params set for this UiTimePicker
   *
   * @return                 - the new UiTimePicker node on success; halts on failure
   */
  inline lumin::ui::UiTimePicker* createUiTimePicker(Prism* prism, const ui::TimePickerParams& timePickerParams) {
    lumin::ui::UiTimePicker* node = lumin::ui::UiTimePicker::Create(assertPrism(prism), timePickerParams);
    return assertNode(node, "UiTimePicker");
  }

} // SDKExamples
} // lumin
