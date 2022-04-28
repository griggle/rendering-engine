#include <tools/colour.hpp>

Colour::Colour (unsigned int colour) : colour (colour) {}

Colour::Colour (int r, int g, int b, int a)
{
    colour = 0;
    colour += std::max (std::min (255, a), 0);
    colour += std::max (std::min (255, b), 0) << 8;
    colour += std::max (std::min (255, g), 0) << 16;
    colour += std::max (std::min (255, r), 0) << 24;
}

float Colour::r () { return (colour & 0xff000000) >> 24; }

float Colour::g () { return (colour & 0x00ff0000) >> 16; }

float Colour::b () { return (colour & 0x0000ff00) >> 8; }

float Colour::a () { return (colour & 0x000000ff); }


Colour Colour::operator* (double rhs) { return Colour (r () * rhs, g () * rhs, b () * rhs, a ()); }

Colour Colour::operator/ (double rhs) { return Colour (colour) * (1.f / rhs); }
