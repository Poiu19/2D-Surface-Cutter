#ifndef POSITION_HPP_INCLUDED
#define POSITION_HPP_INCLUDED

class Position {
    protected: unsigned short int x, y;

    public: Position(unsigned short int x, unsigned short int y);

    public: unsigned short int getPosX();
    public: unsigned short int getPosY();
    public: void setPosX(unsigned short int x);
    public: void setPosY(unsigned short int y);
};


#endif // POSITION_HPP_INCLUDED
