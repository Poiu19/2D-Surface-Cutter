#ifndef HEADERS_HPP_INCLUDED
#define HEADERS_HPP_INCLUDED

enum FormType{
    FORM_STANDARD,
    FORM_SWAPABLE
};

enum RoundType{
    ROUND_DOWN,
    ROUND_NORMAL,
    ROUND_UP
};

enum Edge{
    EDGE_LEFT,
    EDGE_RIGHT,
    EDGE_TOP,
    EDGE_BOTTOM
};

enum Cut{
    CUT_VERTICAL,
    CUT_HORIZONTAL
};

enum FlagOption{
    FLAG_ADD,
    FLAG_REMOVE
};

enum FlagStepType{
    FLAG_NOTSWAPED = 1,
    FLAG_SWAPED = 2,
    FLAG_VERTICALCUT = 4,
    FLAG_HORIZONTALCUT = 8
};
#endif // HEADERS_HPP_INCLUDED
