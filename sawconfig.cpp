#include <iostream>
#include <fstream>
#include <string.h>
#include "sawconfig.hpp"
bool SawConfig::loaded = false;
int SawConfig::doubleThickQuantion;
int SawConfig::edgeQuantion;
int SawConfig::sawThick;

void SawConfig::loadParams()
{
    std::ifstream config;
    std::string line;
    config.open("./sawconfig.cfg");
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
            setEdgeQuantion(value);
        else if (stringProperty == "DOUBLE_THICK_QUANTION")
            setDoubleThickQuantion(value);
        else if (stringProperty == "SAW_THICK")
            setSawThick(value);

        delete [] convertedLine;
        delete [] property;
        loaded = true;
    }
    config.close();
}

int SawConfig::getEdgeQuantion()
{
    if(!loaded)
        loadParams();
    return edgeQuantion;
}
int SawConfig::getDoubleThickQuantion()
{
    if(!loaded)
        loadParams();
    return doubleThickQuantion;
}
int SawConfig::getSawThick()
{
    if(!loaded)
        loadParams();
    return sawThick;
}

void SawConfig::setEdgeQuantion(int value)
{
    edgeQuantion = value;
}

void SawConfig::setDoubleThickQuantion(int value)
{
    doubleThickQuantion = value;
}

void SawConfig::setSawThick(int value)
{
    sawThick = value;
}
