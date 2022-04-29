#include <objects/plane.hpp>

Plane::Plane (Vec3 pos, Colour col, float (*brdf) (Vec3, Vec3, Vec3), Vec3 normal)
    : SceneObject (pos, col, brdf), normal (normal)
{
}

float Plane::distance2intersection (Vec3 ray_origin, Vec3 ray_direction)
{
    float a = dot (normal, ray_direction);

    if (fabs (a) > 0.0001f) { return dot ((pos - ray_origin), normal) / a; }

    return -1;
}

Vec3 Plane::normal_at_point (Vec3 p) { return normal; }
