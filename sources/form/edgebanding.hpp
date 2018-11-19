#ifndef EDGEBANDING_HPP_INCLUDED
#define EDGEBANDING_HPP_INCLUDED

class EdgeBanding {
    protected: char edgeLeft, edgeRight, edgeTop, edgeBottom;
    protected: char * charFormat;
    public: EdgeBanding(char * banding);
    public: void setCharFormat(char * banding);
    public: void setEdgeLeft(char banding);
    public: void setEdgeRight(char banding);
    public: void setEdgeTop(char banding);
    public: void setEdgeBottom(char banding);

    public: char getEdgeLeft();
    public: char getEdgeRight();
    public: char getEdgeTop();
    public: char getEdgeBottom();
    public: char * getCharFormat();
};

#endif // EDGEBANDING_HPP_INCLUDED
