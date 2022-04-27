#include <linalg/vec.hpp>

Vec3::Vec3 (float x, float y, float z) : x (x), y (y), z (z) {}

Vec3 Vec3::operator+ (const Vec3 & rhs) { return Vec3 (x + rhs.x, y + rhs.y, z + rhs.z); }

Vec3 Vec3::operator- (const Vec3 & rhs) { return Vec3 (x - rhs.x, y - rhs.y, z - rhs.z); }

Vec3 Vec3::operator* (double rhs) { return Vec3 (x * rhs, y * rhs, z * rhs); }

Vec3 Vec3::operator/ (double rhs) { return Vec3 (x / rhs, y / rhs, z / rhs); }
