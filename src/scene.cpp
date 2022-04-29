#include <scene.hpp>



Scene::Scene () : camera (0, 0, 1)
{
    objects.push_back (new Sphere (
        Vec3 (0, 0, -3), Colour (255, 0, 0, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return phong (in, out, normal, 1, 10); }, 1.f));
    objects.push_back (new Sphere (
        Vec3 (0.7, 1, -1.5), Colour (255, 255, 0, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return phong (in, out, normal, 0.9, 10); }, 0.4f));
    objects.push_back (new Sphere (
        Vec3 (-0.7, 0, -1.5), Colour (0, 255, 255, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return phong (in, out, normal, 0.9, 10); }, 0.2f));

    objects.push_back (new Plane (
        Vec3 (0, 2, 0), Colour (70, 70, 70, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return lambertian (in, out, normal, 0.01); }, Vec3 (0, -1, 0)));
    objects.push_back (new Plane (
        Vec3 (0, -4, 0), Colour (0, 70, 0, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return lambertian (in, out, normal, 0.01); }, Vec3 (0, 1, 0)));
    objects.push_back (new Plane (
        Vec3 (4, 0, 0), Colour (70, 0, 70, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return lambertian (in, out, normal, 0.01); }, Vec3 (-1, 0, 0)));
    objects.push_back (new Plane (
        Vec3 (-4, 0, 0), Colour (0, 70, 70, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return lambertian (in, out, normal, 0.01); }, Vec3 (1, 0, 0)));
    objects.push_back (new Plane (
        Vec3 (0, 0, -10), Colour (0, 0, 70, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return lambertian (in, out, normal, 0.01); }, Vec3 (0, 0, 1)));
    objects.push_back (new Plane (
        Vec3 (0, 0, 5), Colour (0, 0, 70, 255),
        [] (Vec3 in, Vec3 out, Vec3 normal) { return lambertian (in, out, normal, 0.01); }, Vec3 (0, 0, -1)));


    lights.push_back (new PointLight (Vec3 (-1, -1, -1), Vec3 (1, 1, 1)));
    // lights.push_back (new PointLight (Vec3 (1, 0, -1), Vec3 (1, 1, 1)));
}

void Scene::close ()
{
    for (auto obj : objects) { delete obj; }
    for (auto obj : lights) { delete obj; }
}