#pragma once

#include <lights/scene_light.hpp>
#include <lights/point_light.hpp>
#include <linalg/vec.hpp>
#include <objects/scene_object.hpp>
#include <objects/sphere.hpp>
#include <vector>

class Scene
{
  public:
    std::vector<SceneObject *> objects;
    std::vector<SceneLight *>  lights;
    Vec3                       camera;

  public:
    Scene ();
    void close ();
};