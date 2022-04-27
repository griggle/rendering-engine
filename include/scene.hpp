#pragma once

#include <linalg/vec.hpp>
#include <objects/scene_object.hpp>
#include <objects/sphere.hpp>
#include <vector>

class Scene
{
  public:
    std::vector<SceneObject *> objects;
    Vec3                       camera;

  public:
    Scene ();
    void close ();
};