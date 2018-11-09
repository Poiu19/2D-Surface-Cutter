#include "surface.hpp"

Surface::Surface(unsigned short int x, unsigned short int y, unsigned short int length, unsigned short int width)
    : Dimension(length, width), Position(x, y) {}
