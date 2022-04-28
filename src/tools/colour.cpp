#include <tools/colour.hpp>

//Colour::Colour (unsigned int colour) : colour (colour) {}

Colour::Colour (int r, int g, int b) : Colour (r, g, b, 255) {}

Colour::Colour (int r, int g, int b, int a) : c_r (r), c_g (g), c_b (b), c_a (a) {}

float Colour::r () { return c_r; }

float Colour::g () { return c_g; }

float Colour::b () { return c_b; }

float Colour::a () { return c_a; }

unsigned int Colour::hex ()
{
    unsigned int colour = 0;

    colour += std::max (std::min (255, c_a), 0);
    colour += std::max (std::min (255, c_b), 0) << 8;
    colour += std::max (std::min (255, c_g), 0) << 16;
    colour += std::max (std::min (255, c_r), 0) << 24;

    return colour;
}


Colour Colour::operator* (double rhs) { return Colour (r () * rhs, g () * rhs, b () * rhs, a ()); }

Colour Colour::operator/ (double rhs) { return this->operator* (1.f / rhs); }

Colour Colour::operator+ (Colour rhs) { return Colour (r () + rhs.r (), g () + rhs.g (), b () + rhs.b ()); }
