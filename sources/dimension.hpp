#ifndef DIMENSION_HPP_INCLUDED
#define DIMENSION_HPP_INCLUDED

class Dimension{
    protected: unsigned short int length = 0, width = 0;
    protected: float sizeArea;

    public: Dimension(unsigned short int length = 0, unsigned short int width = 0);

    public: void setLength(unsigned short int length);
    public: void setWidth(unsigned short int width);
    public: void setSizeArea(float sizeArea);
    public: float getSizeArea();
    public: unsigned short int getLength();
    public: unsigned short int getWidth();
};

#endif // DIMENSION_HPP_INCLUDED
