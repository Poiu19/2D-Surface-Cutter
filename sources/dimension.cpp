#include "dimension.hpp"
Dimension::Dimension(unsigned short int length, unsigned short int width)
{
    this->setLength(length);
    this->setWidth(width);
}
void Dimension::setLength(unsigned short int length)
{
    this->length = length;
}

void Dimension::setWidth(unsigned short int width)
{
    this->width = width;
}

void Dimension::setSizeArea(float sizeArea)
{
    this->sizeArea = sizeArea;
}

float Dimension::getSizeArea()
{
    return this->sizeArea;
}
