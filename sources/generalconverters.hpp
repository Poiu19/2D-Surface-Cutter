#ifndef GENERALCONVERTERS_HPP_INCLUDED
#define GENERALCONVERTERS_HPP_INCLUDED
#include <string>
#include <math.h>
#include "headers.hpp"
class StringConverter{
    public: static char * strToChar(std::string str);
    public: static float strToFloat(std::string str);
    public: static int strToInt(std::string str, Round_Type type = ROUND_NORMAL);
};


#endif // GENERALCONVERTERS_HPP_INCLUDED
