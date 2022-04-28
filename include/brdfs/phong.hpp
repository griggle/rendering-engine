#pragma once

#include <cmath>
#include <linalg/linalg.hpp>
#include <linalg/vec.hpp>

float phong (Vec3 in, Vec3 out, Vec3 normal, float k_s, float m);