#include <brdfs/lambertian.hpp>

float lambertian (Vec3 in, Vec3 out, Vec3 normal, float p_d) { return p_d / M_PI; }