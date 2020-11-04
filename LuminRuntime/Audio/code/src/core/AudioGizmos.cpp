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
#include <AudioGizmos.h>
#include <NodeCreationWrappers.h>
#include <ExamplesConstants.h>
#include <ExamplesHelpers.h>
#include <ExamplesDefines.h>

#include <lumin/event/AudioEvent.h>
#include <lumin/node/LineNode.h>
#include <ml_logging.h>

using namespace lumin;
using namespace lumin::ui;

float CalculateConeHeight(float radius, float angle) {
  angle = glm::radians<float>(angle);
  angle = glm::half_pi<float>() - (angle / 2.0f);
  return glm::sin(angle) * radius / glm::cos(angle);
}

void ConstructWireframeCircle(LineNode* circle, float radius, int32_t numSegments, const glm::vec4& color) {
  float cAnglePerSegment = glm::pi<float>() * 2.0f / numSegments;
  for (int32_t i = 0; i <= numSegments; ++i) {
    float segmentAngle = cAnglePerSegment * i;
    circle->addPoints(glm::vec3(glm::cos(segmentAngle) * radius, glm::sin(segmentAngle) * radius, 0.0f));
  }
}

void ConstructWireframeCone(LineNode* cone, float radius, float height, int32_t numBaseSegments, int32_t numFaces, const glm::vec4& color) {
  // Construct the circle first followed by lines from the tip to the circle edge.
  float cAnglePerSegment = glm::pi<float>() * 2.0f / numFaces;
  ConstructWireframeCircle(cone, radius, numBaseSegments, color);
  for (int32_t i = 0; i < numFaces; ++i) {
    float segmentAngle = cAnglePerSegment * i;
    cone->addLineBreak();
    cone->addPoints(glm::vec3(0.0f, 0.0f, height));
    cone->addPoints(glm::vec3(glm::cos(segmentAngle) * radius, glm::sin(segmentAngle) * radius, 0.0f));
  }
}

void ConstructWireframeSphere(LineNode* sphere, float radius, int32_t numSegments, const glm::vec4& color) {
  // Constuct all the vertical slice circles on the sphere.
  for (int32_t y = 0; y <= numSegments; ++y) {
    float radian = (float)y / (float)numSegments * glm::pi<float>();
    float sinY = glm::sin(radian) * radius;
    float cosY = glm::cos(radian) * radius;
    for (int32_t x = 0; x <= numSegments; ++x) {
      radian = (float)x / (float)numSegments * 2.0f * glm::pi<float>();
      sphere->addPoints({glm::cos(radian) * sinY, cosY, glm::sin(radian) * sinY});
    }
    sphere->addLineBreak();
  }
  // Construct all the circles rotating around y on the sphere.
  for (int32_t y = 0; y <= numSegments; ++y) {
    float radian = (float)y / (float)numSegments * glm::pi<float>() * 2.0f;
    float sinY = glm::sin(radian) * radius;
    float cosY = glm::cos(radian) * radius;
    for (int32_t x = 0; x < numSegments; ++x) {
      radian = (float)x / (float)numSegments * glm::pi<float>() * 2.0f;
      float sinX = glm::sin(radian);
      sphere->addPoints({cosY * sinX, radius * glm::cos(radian), sinY * sinX});
    }
    sphere->addLineBreak();
  }
}

void ConstructWireframeLineSegment(LineNode* lineSegment, const glm::vec3& point1, const glm::vec3& point2, const glm::vec4& color) {
  lineSegment->addPoints(point1);
  lineSegment->addPoints(point2);
}

LineNode* ConstructGizmo(Prism* prism, Node* parent, float radius, float angle, float distance, const glm::vec3& position, const glm::quat& rotation, const glm::vec4& color, const std::string& name) {
  // Create a cone or sphere to represent direction of audio.
  static const int32_t cNumConeBaseSegments = 180;
  static const int32_t cNumConeFaces = 16;
  static const int32_t cSphereSegments = 24;
  static const float cXSize = 0.01f;
  float coneHeight = 0.0f;
  LineNode* gizmo = static_cast<LineNode*>(prism->findNode(name, parent));
  if (!gizmo) {
    gizmo = SDKExamples::createLineNode(prism);
    gizmo->setName(name);
  }
  gizmo->clearPoints();
  gizmo->setColor(color);

  if (distance > 0.0f) {
    if (angle != 0.0f) {
      if (fmod(angle, 360.0f) == 0.0f) {
        ConstructWireframeSphere(gizmo, radius, cSphereSegments, color);
      } else {
        coneHeight += CalculateConeHeight(radius, angle);
        ConstructWireframeCone(gizmo, radius, coneHeight, cNumConeBaseSegments, cNumConeFaces, color);
      }
    }
    // Add a line segment to represent distance of audio with a little x marking the spot.
    gizmo->addLineBreak();
    float dist = distance + coneHeight;
    ConstructWireframeLineSegment(gizmo, {0.0f, 0.0f, coneHeight}, {0.0f, 0.0f, dist}, color);
    gizmo->addLineBreak();
    ConstructWireframeLineSegment(gizmo, {-cXSize, -cXSize, dist}, {cXSize, cXSize, dist}, color);
    gizmo->addLineBreak();
    ConstructWireframeLineSegment(gizmo, {-cXSize, cXSize, dist}, {cXSize, -cXSize, dist}, color);

    // Setup in the world.
    gizmo->setLocalPosition(position + glm::vec3(0.0f, 0.0f, -1.0f * coneHeight));
    gizmo->setLocalRotation(rotation);
  }
  return gizmo;
}

void constructAudioGizmos(std::weak_ptr<Prism> prism_ptr, AudioNode* node, uint32_t channelCount) {
  // Construct a gizmo for each channel for spatial audio.
  // Create a gizmo for each of the inner radiation cone and min distance and for outer radiation cone and max distance.
  static const float cInnerRadiationConeRadius = 0.08f;
  static const float cOuterRadiationConeRadius = 0.18f;
  static const float cInnerRadiationSphereRadius = 0.09f;
  static const float cOuterRadiationSphereRadius = 0.19f;
  bool isSpatial = false;
  if (!prism_ptr.lock() || !node) {
    ML_LOG(Error, "ConstructAudioGizmos::Prism or Node is null");
    return;
  }
  Prism* prism = prism_ptr.lock().get();
  node->getSpatialSoundEnable(isSpatial);
  if (isSpatial) {
    TransformNode* parent = static_cast<TransformNode*>(prism->findNode("__AudioGizmoParent", node));
    if (!parent) {
      parent = SDKExamples::createTransformNode(prism);
      parent->setName("__AudioGizmoParent");
    }
    node->addChild(parent);
    glm::vec3 position;
    glm::quat direction;
    SpatialSoundDistanceProperties distance;
    SpatialSoundRadiationProperties radiation;
    for (int i = 0; i < channelCount; ++i) {
      node->getSpatialSoundPosition(i, position);
      node->getSpatialSoundDirection(i, direction);
      node->getSpatialSoundDistanceProperties(i, distance);
      node->getSpatialSoundRadiationProperties(i, radiation);
      bool isSphere = fmod(radiation.inner_angle, 360.0f) == 0.0f;
      float radius = isSphere ? cInnerRadiationSphereRadius : cInnerRadiationConeRadius;
      float angle = isSphere ? radiation.inner_angle : 360.0f - radiation.inner_angle;
      std::string name = "__AudioGizmoInnerChild" + std::to_string(i);
      LineNode* gizmo = ConstructGizmo(prism, parent, radius, angle, distance.min_distance,
                                       position, direction, color::ORANGE, name);
      parent->addChild(gizmo);
      isSphere = fmod(radiation.outer_angle, 360.0f) == 0.0f;
      radius = isSphere ? cOuterRadiationSphereRadius : cOuterRadiationConeRadius;
      angle = isSphere ? radiation.outer_angle : 360.0f - radiation.outer_angle;
      name = "__AudioGizmoOuterChild" + std::to_string(i);
      gizmo = ConstructGizmo(prism, parent, radius, angle, distance.max_distance,
                             position, direction, color::INDIGO, name);
      parent->addChild(gizmo);
    }
  }
}

void removeAudioGizmos(std::weak_ptr<Prism> prism, TransformNode* attached) {
  if (prism.lock() && attached) {
    Node::Delete(prism.lock()->findNode("__AudioGizmoParent", attached));
  }
}