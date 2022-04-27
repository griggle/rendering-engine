#pragma once

class Vec3
{
  public:
    float x, y, z;

  public:
    Vec3 (float x, float y, float z);

    Vec3 operator+ (const Vec3 & rhs);
    Vec3 operator- (const Vec3 & rhs);
    Vec3 operator* (double rhs);
    Vec3 operator/ (double rhs);
};