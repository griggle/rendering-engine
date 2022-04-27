#pragma once

#include <linalg/vec.hpp>

class SceneObject
{
  protected:
    Vec3 pos;

  public:
    SceneObject (Vec3 pos);

    virtual float distance2intersection (Vec3 ray_origin, Vec3 ray_direction) = 0;
};