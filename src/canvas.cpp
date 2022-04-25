#include <canvas.hpp>

Canvas::Canvas (int width, int height) : width (width), height (height), quit (false) {}

bool Canvas::step (std::vector<std::vector<unsigned int>> image)
{
    // Handle events on queue
    while (SDL_PollEvent (&e) != 0)
    {
        // User requests quit
        if (e.type == SDL_QUIT) { quit = true; }
    }

    // Clear screen
    SDL_SetRenderDrawColor (gRenderer, 0, 0, 0, 0xFF);
    SDL_RenderClear (gRenderer);

    // Draw pixels
    for (int w = 0; w < width; w++)
        for (int h = 0; h < height; h++)
        {
            unsigned int colour = image[w][h];
            SDL_SetRenderDrawColor (gRenderer, (colour & 0xFF000000) >> 24, (colour & 0x00FF0000) >> 16,
                                    (colour & 0x0000FF00) >> 8, (colour & 0x000000FF));
            SDL_RenderDrawPoint (gRenderer, w, h);
        }

    // Update screen
    SDL_RenderPresent (gRenderer);

    return quit;
}

void Canvas::close ()
{
    // Destroy window
    SDL_DestroyRenderer (gRenderer);
    SDL_DestroyWindow (gWindow);
    gWindow   = NULL;
    gRenderer = NULL;

    // Quit SDL subsystems
    SDL_Quit ();
}


bool Canvas::init ()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init (SDL_INIT_VIDEO) < 0)
    {
        printf ("SDL could not initialize! SDL Error: %s\n", SDL_GetError ());
        success = false;
    }
    else
    {
        // Create window
        gWindow = SDL_CreateWindow ("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                    SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf ("Window could notwidth be created! SDL Error: %s\n", SDL_GetError ());
            success = false;
        }
        else
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer (gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf ("Renderer could not be created! SDL Error: %s\n", SDL_GetError ());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor (gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    return success;
}