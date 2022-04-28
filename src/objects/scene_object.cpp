#include <objects/scene_object.hpp>

SceneObject::SceneObject (Vec3 pos, Colour col, float (*brdf) (Vec3, Vec3, Vec3)) : pos (pos), col (col), brdf (brdf) {}