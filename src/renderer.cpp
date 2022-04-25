#include <renderer.hpp>

void render_pixel (int x, int y, std::vector<std::vector<unsigned int>>& image)
{
    image[x][y] = 0xFF0000FF;
}