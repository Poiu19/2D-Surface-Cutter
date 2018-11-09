#include "generalconverters.hpp"

char * StringConverter::strToChar(std::string str)
{
    return (char*)str.c_str();
}

float StringConverter::strToFloat(std::string str)
{
    return std::stof(str);
}

int StringConverter::strToInt(std::string str, Round_Type type)
{
    if(type == ROUND_DOWN)
        return std::stoi(str);
    else if(type == ROUND_UP)
        return ceil(strToFloat(str));
    return round(strToFloat(str));
}
