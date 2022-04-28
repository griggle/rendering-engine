#include <linalg/linalg.hpp>

float dot (Vec3 lhs, Vec3 rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z); }

float norm (Vec3 v) { return sqrt ((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

Vec3 unit (Vec3 v) { return v / norm (v); }

Vec3 reflect (Vec3 v, Vec3 axis) { return v - (axis * 2 * dot (v, axis)); }