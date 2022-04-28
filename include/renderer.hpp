#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <scene.hpp>
#include <tools/colour.hpp>
#include <vector>

class Renderer
{
  protected:
    int resolution;
    int recursion_depth;

    Scene scene;

    std::random_device              dev;
    std::mt19937                    rng;
    std::normal_distribution<float> rand_dist;

  public:
    Renderer (int resolution, int recursion_depth, Scene scene);

    void render_pixel (int x, int y, std::vector<std::vector<unsigned int>> & image);

  protected:
    float         pixel2world (float pixel, float pixel_max);
    SceneObject * nearest_intersected_object (Vec3 ray_origin, Vec3 ray_direction, float & distance);
    Colour        render_equ (Vec3 origin, Vec3 direction, int depth);
};
