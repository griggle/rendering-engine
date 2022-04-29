#include <canvas.hpp>
#include <chrono>
#include <ctime>
#include <renderer.hpp>
#include <scene.hpp>

int main (int argc, char * args[])
{
    int resolution = 900;

    Canvas   canvas (resolution, resolution);
    Scene    scene;
    Renderer renderer (resolution, 1, scene);

    std::vector<std::vector<unsigned int>> image;
    for (int i = 0; i < resolution; i++)
    {
        std::vector<unsigned int> row;
        for (int j = 0; j < resolution; j++) { row.push_back (0x222222FF); }
        image.push_back (row);
    }

    // render to buffer
    for (int y = 0; y < resolution; y++)
    {
        for (int x = 0; x < resolution; x++)
        {
            renderer.render_pixel (x, y, image);
            if ((y * resolution + x) % 100 == 0)
                std::cout << 100 * ((y * resolution + x) / (1.0f * resolution * resolution)) << "%            \r";
        }
    }
    printf ("done        \n");

    // Start up SDL and create window
    if (!canvas.init ())
        printf ("Failed to initialize!\n");
    else
    {
        canvas.step (image);
        canvas.screen_shot ();
        while (!canvas.step (image)) {}
    }

    // Free resources and close SDL
    canvas.close ();
    scene.close ();

    return 0;
}