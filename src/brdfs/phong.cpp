#include <brdfs/phong.hpp>

float phong (Vec3 in, Vec3 out, Vec3 normal, float k_s, float m) { return k_s * powf(dot (out, reflect (in, normal)), m); }
