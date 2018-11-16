#ifndef SURFACE_HPP_INCLUDED
#define SURFACE_HPP_INCLUDED
#include "../dimension.hpp"
#include "../position.hpp"

class Surface : public Dimension, public Position {
    public: Surface(unsigned short int x, unsigned short int y, unsigned short int length, unsigned short int width);
};

#endif // SURFACE_HPP_INCLUDED
