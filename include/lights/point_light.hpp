#pragma once

#include <iostream>
#include <lights/scene_light.hpp>
#include <linalg/linalg.hpp>
#include <linalg/vec.hpp>

class PointLight : public SceneLight
{
  public:
    PointLight (Vec3 pos, Vec3 strength);
};