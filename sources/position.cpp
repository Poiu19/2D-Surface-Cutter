#include "position.hpp"

Position::Position(unsigned short int x, unsigned short int y)
{
    this->setPosX(x);
    this->setPosY(y);
}

unsigned short int Position::getPosX()
{
    return this->x;
}

unsigned short int Position::getPosY()
{
    return this->y;
}

void Position::setPosX(unsigned short int x)
{
    this->x = x;
}

void Position::setPosY(unsigned short int y)
{
    this->y = y;
}
