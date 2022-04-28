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
        Vec3 intersection = origin + (direction * distance);
        Vec3 normal       = nearest->normal_at_point (intersection);
        intersection      = intersection + normal * 0.00001;

        Vec3 lightness_mul (0, 0, 0);

        for (auto light : scene.lights)
        {
            float         distance_blocking = 0;
            SceneObject * nearest_blocking
                = nearest_intersected_object (intersection, unit (light->pos - intersection), distance_blocking);

            if (distance_blocking > norm ((light->pos - intersection)) || nearest_blocking == nullptr)
                lightness_mul = lightness_mul + light->strength * dot (unit (light->pos - intersection), normal);
        }

        Colour colour = nearest->col;
        colour        = Colour (colour.r () * std::fmax (std::fmin (1.f, lightness_mul.x), 0.f),
                                colour.g () * std::fmax (std::fmin (1.f, lightness_mul.y), 0.f),
                                colour.b () * std::fmax (std::fmin (1.f, lightness_mul.z), 0.f), colour.a ());
        image[x][y]   = colour.colour;
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
