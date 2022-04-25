#include <canvas.hpp>
#include <chrono>
#include <ctime>
#include <renderer.hpp>

int main (int argc, char * args[])
{
    int resolution = 600;

    Canvas canvas (resolution, resolution);

    std::vector<std::vector<unsigned int>> image;
    for (int i = 0; i < resolution; i++)
    {
        std::vector<unsigned int> row;
        for (int j = 0; j < resolution; j++) { row.push_back (0x222222FF); }
        image.push_back (row);
    }

    // Start up SDL and create window
    if (!canvas.init ())
        printf ("Failed to initialize!\n");
    else
    {
        bool running = true;
        auto start   = std::chrono::system_clock::now ();

        for (int y = 0; y < resolution; y++)
        {
            for (int x = 0; x < resolution; x++)
            {
                render_pixel (x, y, image);

                auto end = std::chrono::system_clock::now ();

                std::chrono::duration<double> elapsed_seconds = end - start;

                if (elapsed_seconds.count () > 1)
                {
                    running = !canvas.step (image);
                    start   = std::chrono::system_clock::now ();
                }

                if (!running) break;
            }
            if (!running) break;
        }
        while (running && !canvas.step (image)) {}
    }

    // Free resources and close SDL
    canvas.close ();

    return 0;
}