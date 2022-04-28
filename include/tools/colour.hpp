#pragma once

#include <algorithm>

class Colour
{
  public:
    unsigned int colour;

  public:
    Colour (unsigned int);
    Colour (int, int, int, int);

    float r ();
    float g ();
    float b ();
    float a ();

    Colour operator* (double rhs);
    Colour operator/ (double rhs);
};