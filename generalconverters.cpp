#include "generalconverters.hpp"

char * StringConverter::strToChar(std::string str)
{
    return (char*)str.c_str();
}
