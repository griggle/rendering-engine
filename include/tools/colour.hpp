#pragma once

#include <algorithm>

class Colour
{
  public:
    int c_r;
    int c_g;
    int c_b;
    int c_a;

  public:
    //Colour (unsigned int);
    Colour (int, int, int);
    Colour (int, int, int, int);

    float r ();
    float g ();
    float b ();
    float a ();

    unsigned int hex ();

    Colour operator* (double rhs);
    Colour operator/ (double rhs);

    Colour operator+ (Colour rhs);
};