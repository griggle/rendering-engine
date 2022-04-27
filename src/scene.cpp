#include <scene.hpp>



Scene::Scene () : camera (0, 0, 1)
{
    objects.push_back (new Sphere (Vec3 (0, 0, -3), 1.f));
    objects.push_back (new Sphere (Vec3 (0.7, 1, -1.5), 0.4f));
}

void Scene::close ()
{
    for (auto obj : objects) { delete obj; }
}