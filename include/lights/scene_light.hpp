#pragma once

#include <linalg/vec.hpp>

class SceneLight
{
  public:
    Vec3 pos;
    Vec3 strength;

  public:
    SceneLight (Vec3 pos, Vec3 strength);
};