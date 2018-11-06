#ifndef SURFACE_HPP_INCLUDED
#define SURFACE_HPP_INCLUDED

class Surface {
    protected: unsigned short int x, y, length, width;

    public: unsigned short int getPosX();
    public: unsigned short int getPosY();
    public: unsigned short int getLength();
    public: unsigned short int getWidth();
};

#endif // SURFACE_HPP_INCLUDED
