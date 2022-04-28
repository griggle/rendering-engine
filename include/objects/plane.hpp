#pragma once

#include <iostream>
#include <linalg/linalg.hpp>
#include <linalg/vec.hpp>
#include <objects/scene_object.hpp>

class Plane : public SceneObject
{
  protected:
    Vec3 normal;

  public:
    Plane (Vec3 pos, Colour col, float (*brdf) (Vec3, Vec3, Vec3), Vec3 normal);

    float distance2intersection (Vec3 ray_origin, Vec3 ray_direction);
    Vec3  normal_at_point (Vec3 p);
};