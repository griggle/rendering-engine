#include <renderer.hpp>


Renderer::Renderer (int resolution, int recursion_depth, Scene scene)
    : resolution (resolution), recursion_depth (recursion_depth), scene (scene), rng (dev ()), rand_dist (0, 0.5)
{
}

void Renderer::render_pixel (int x, int y, std::vector<std::vector<unsigned int>> & image)
{
    Vec3 world_pixel (pixel2world (x, resolution), pixel2world (y, resolution), 0);

    image[x][y] = render_equ (scene.camera, unit (world_pixel - scene.camera), 5).hex ();
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

Colour Renderer::render_equ (Vec3 origin, Vec3 direction, int depth)
{
    Colour colour (0, 0, 0);

    if (depth == 0) return colour;

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
                lightness_mul = lightness_mul + light->strength;


            colour = colour + nearest->col;
            colour = Colour (colour.r () * lightness_mul.x, colour.g () * lightness_mul.y,
                             colour.b () * lightness_mul.z, colour.a ())
                     * dot (unit (light->pos - intersection), normal);

            Colour incoming (0, 0, 0);

            // reflected
            incoming = (colour
                        + (render_equ (intersection, unit (reflect (direction, normal)), depth - 1))
                              * dot (unit (light->pos - intersection), normal)
                              * nearest->brdf (direction, unit (reflect (direction, normal)), unit (normal)));

            // random scatters
            int num_scatters = 0;    // 5 * depth;
            for (int i = 0; i < num_scatters; i++)
            {
                Vec3 random_scatter (normal.x + rand_dist (rng), normal.y + rand_dist (rng),
                                     normal.z + rand_dist (rng));

                incoming = incoming
                           + (colour
                              + (render_equ (intersection, unit (random_scatter), depth - 1))
                                    * dot (unit (light->pos - intersection), normal)
                                    * nearest->brdf (direction, unit (random_scatter), unit (normal)));
            }

            colour = colour + (incoming / (num_scatters + 1));
        }
    }

    return colour;
}
