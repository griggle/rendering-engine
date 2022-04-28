#pragma once

#include <iostream>
#include <linalg/linalg.hpp>
#include <linalg/vec.hpp>
#include <objects/scene_object.hpp>

class Sphere : public SceneObject
{
  protected:
    float r;

  public:
    Sphere (Vec3 pos, Colour col, float r);

    float distance2intersection (Vec3 ray_origin, Vec3 ray_direction);
    Vec3  normal_at_point (Vec3 p);
};