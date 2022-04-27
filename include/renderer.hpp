#pragma once

#include <iostream>
#include <scene.hpp>
#include <vector>

class Renderer
{
  protected:
    int resolution;
    int recursion_depth;

    Scene scene;

  public:
    Renderer (int resolution, int recursion_depth, Scene scene);

    void render_pixel (int x, int y, std::vector<std::vector<unsigned int>> & image);

  protected:
    float         pixel2world (float pixel, float pixel_max);
    SceneObject * nearest_intersected_object (Vec3 ray_origin, Vec3 ray_direction, float & distance);
};
