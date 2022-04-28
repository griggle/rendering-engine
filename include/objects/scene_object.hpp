#pragma once

#include <linalg/vec.hpp>
#include <tools/colour.hpp>

class SceneObject
{
  public:
    Vec3   pos;
    Colour col;

  public:
    SceneObject (Vec3 pos, Colour col);

    virtual float distance2intersection (Vec3 ray_origin, Vec3 ray_direction) = 0;
    virtual Vec3  normal_at_point (Vec3 p)                                    = 0;
};