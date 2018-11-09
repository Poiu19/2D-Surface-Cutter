#include <iostream>
#include <fstream>
#include <string.h>
#include "sawconfig.hpp"
bool SawConfig::loaded = false;
int SawConfig::doubleThickQuantion;
int SawConfig::edgeQuantion;
int SawConfig::sawThick;

bool SawConfig::loadParams()
{
    std::ifstream config;
    std::string line;
    config.open("./sawconfig.cfg");
    if(!config.is_open()) //only for development mode
        config.open("./sources/saw/sawconfig.cfg");
    if(!config.is_open())
    {
        std::cout << "File error: sawconfig.cfg not found!" << std::endl;
        return false;
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
        setProperty(property, value);
        delete [] convertedLine;
        delete [] property;
    }
    loaded = true;
    config.close();
    return loaded;
}

bool SawConfig::setProperty(std::string property, int value)
{
    if (property == "EDGE_QUANTION")
        setEdgeQuantion(value);
    else if (property == "DOUBLE_THICK_QUANTION")
        setDoubleThickQuantion(value);
    else if (property == "SAW_THICK")
        setSawThick(value);
    else
        return false;
    return true;
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
