#include <scene.hpp>



Scene::Scene () : camera (0, 0, 2)
{
    objects.push_back (new Sphere (Vec3 (0, 0, -3), Colour (255, 0, 0, 255), 1.f));
    objects.push_back (new Sphere (Vec3 (0.7, 1, -1.5), Colour (255, 255, 0, 255), 0.4f));
    objects.push_back (new Sphere (Vec3 (-0.7, -0.7, -1.5), Colour (0, 255, 255, 255), 0.2f));

    lights.push_back (new PointLight (Vec3 (-1, -1, -1), Vec3 (1, 1, 1)));
    // lights.push_back (new PointLight (Vec3 (1, 0, -1), Vec3 (1, 1, 1)));
}

void Scene::close ()
{
    for (auto obj : objects) { delete obj; }
    for (auto obj : lights) { delete obj; }
}