#include "edgebanding.hpp"
#include "../headers.hpp"
EdgeBanding::EdgeBanding(char * banding)
{
    this->setEdgeLeft(banding[EDGE_LEFT]);
    this->setEdgeRight(banding[EDGE_RIGHT]);
    this->setEdgeTop(banding[EDGE_TOP]);
    this->setEdgeBottom(banding[EDGE_BOTTOM]);
    this->setCharFormat(banding);
}

void EdgeBanding::setCharFormat(char * banding)
{
    this->charFormat = banding;
}

void EdgeBanding::setEdgeLeft(char banding)
{
    this->edgeLeft = banding;
}

void EdgeBanding::setEdgeRight(char banding)
{
    this->edgeRight = banding;
}

void EdgeBanding::setEdgeTop(char banding)
{
    this->edgeTop = banding;
}

void EdgeBanding::setEdgeBottom(char banding)
{
    this->edgeBottom = banding;
}

char EdgeBanding::getEdgeLeft()
{
    return this->edgeLeft;
}

char EdgeBanding::getEdgeRight()
{
    return this->edgeRight;
}

char EdgeBanding::getEdgeTop()
{
    return this->edgeTop;
}

char EdgeBanding::getEdgeBottom()
{
    return this->edgeBottom;
}

char * EdgeBanding::getCharFormat()
{
    return this->charFormat;
}
