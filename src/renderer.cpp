#include <renderer.hpp>


Renderer::Renderer (int resolution, int recursion_depth, Scene scene)
    : resolution (resolution), recursion_depth (recursion_depth), scene (scene)
{
}

void Renderer::render_pixel (int x, int y, std::vector<std::vector<unsigned int>> & image)
{
    Vec3 world_pixel (pixel2world (x, resolution), pixel2world (y, resolution), 0);
    Vec3 origin    = scene.camera;
    Vec3 direction = unit (world_pixel - origin);

    float         distance = 0;
    SceneObject * nearest  = nearest_intersected_object (origin, direction, distance);
    if (nearest != nullptr)
    {
        unsigned int colour    = 0x000000ff;
        unsigned int lightness = 0xff;
        lightness *= 1 - ((distance - origin.z) / 3);
        colour += lightness << 24;
        image[x][y] = colour;
    }
}

float Renderer::pixel2world (float pixel, float pixel_max) { return (2 * (pixel / pixel_max)) - 1; }

SceneObject * Renderer::nearest_intersected_object (Vec3 ray_origin, Vec3 ray_direction, float & distance)
{
    distance                     = 99999;
    SceneObject * nearest_object = nullptr;

    for (auto object : scene.objects)
    {
        float temp = object->distance2intersection (ray_origin, ray_direction);
        if (temp > 0 && temp < distance)
        {
            // std::cout << object << "\n";
            distance       = temp;
            nearest_object = object;
        }
    }

    return nearest_object;
}
