#include <objects/sphere.hpp>

Sphere::Sphere (Vec3 pos, Colour col, float (*brdf) (Vec3, Vec3, Vec3), float r) : SceneObject (pos, col, brdf), r (r)
{
}

float Sphere::distance2intersection (Vec3 ray_origin, Vec3 ray_direction)
{
    /*float b     = dot (ray_direction, ray_origin - pos);
    float c     = norm (ray_origin - pos);
    c           = (c * c) - (r * r);
    float delta = (b * b) - (4 * c);

    if (delta > 0)
    {
        float t1 = (-b + sqrt (delta)) / 2;
        float t2 = (-b - sqrt (delta)) / 2;

        std::cout << t1 << ", " << t2 << "test\n";

        if (t1 > 0 && t2 > 0) { return fmin (t1, t2); }
    }*/

    // float a = (ray_direction.x * ray_direction.x) + (ray_direction.y * ray_direction.y)
    //           + (ray_direction.z * ray_direction.z);

    // if (a != 0)
    //{
    //     float b = ((2 * ray_origin.x * ray_direction.x) - (2 * ray_direction.x * pos.x))
    //               + ((2 * ray_origin.y * ray_direction.y) - (2 * ray_direction.y * pos.y))
    //               + ((2 * ray_origin.z * ray_direction.z) - (2 * ray_direction.z * pos.z));

    //    float c = ((pos.x * pos.x) + (ray_origin.x * ray_origin.x)) + ((pos.y * pos.y) + (ray_origin.y *
    //    ray_origin.y))
    //              + ((pos.z * pos.z) + (ray_origin.z * ray_origin.z));

    //    if ((-4 * a * c) + (4 * a * (r * r)) + (b * b) >= 0)
    //    {
    //        float d1 = (sqrt ((-4 * a * c) + (4 * a * (r * r)) + (b * b)) - b) / (2 * a);
    //        float d2 = (-sqrt ((-4 * a * c) + (4 * a * (r * r)) + (b * b)) - b) / (2 * a);

    //        // std::cout << d1 << ", " << d2 << "\n";


    //        if (d1 > 0 && (d1 < d2 || d2 < 0))
    //            return d1;
    //        else if (d2 > 0 && (d2 < d1 || d1 < 0))
    //            return d2;
    //    }
    //}

    double a            = dot (ray_direction, ray_direction);
    double b            = 2 * dot (ray_direction, ray_origin - pos);
    double c            = dot (ray_origin - pos, ray_origin - pos) - r * r;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        double t  = (-b + sqrt (discriminant)) / (2 * a);
        double t2 = -b / a - t;
        if (fabs (t2) < fabs (t)) t = t2;
        return t;
    }


    return -1;
}

Vec3 Sphere::normal_at_point (Vec3 p) { return unit (p - pos); }
