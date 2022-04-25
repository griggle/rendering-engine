#pragma once

#include <SDL.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <vector>

class Canvas
{
  protected:
    SDL_Window *   gWindow   = NULL;    // The window we'll be rendering to
    SDL_Renderer * gRenderer = NULL;    // The window renderer
    int            width, height;

    bool      quit;    // Main loop flag
    SDL_Event e;       // Event handler

  public:
    Canvas (int width, int height);

    bool init ();                         // init canvas and memory
    bool step (std::vector<std::vector<unsigned int>> image);    // run a frame
    void close ();                        // free all memory
};