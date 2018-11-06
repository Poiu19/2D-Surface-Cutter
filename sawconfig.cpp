#include <iostream>
#include <fstream>
#include <string.h>
#include "sawconfig.hpp"
SawConfig::SawConfig()
{
    std::ifstream config;
    std::string line;
    config.open("sawconfig.cfg");
    if(config.is_open() != true)
    {
        std::cout << "File error: sawconfig.cfg not found!" << std::endl;
        return;
    }
    while(getline(config, line))
    {
        if(line[0] == '#')
           continue;
        char* convertedLine = new char[line.length()+1];
        strcpy(convertedLine, line.c_str());
        char* property = new char[line.length()+1];
        int value;
        std::sscanf(convertedLine, "%[^=]=%d", property, &value);
        std::string stringProperty = property;
        std::string temp_str = "EDGE_QUANTION";
        if (stringProperty == temp_str.c_str())
            this->setEdgeQuantion(value);
        else if (stringProperty == "DOUBLE_THICK_QUANTION")
            this->setDoubleThickQuantion(value);
        else if (stringProperty == "SAW_THICK")
            this->setSawThick(value);

        delete [] convertedLine;
        delete [] property;
    }
    config.close();
}

int SawConfig::getEdgeQuantion()
{
    return this->edgeQuantion;
}
int SawConfig::getDoubleThickQuantion()
{
    return this->doubleThickQuantion;
}
int SawConfig::getSawThick()
{
    return this->sawThick;
}

SawConfig* SawConfig::setEdgeQuantion(int value)
{
    this->edgeQuantion = value;
    return this;
}

SawConfig* SawConfig::setDoubleThickQuantion(int value)
{
    this->doubleThickQuantion = value;
    return this;
}

SawConfig* SawConfig::setSawThick(int value)
{
    this->sawThick = value;
    return this;
}
