#include <string>
#include "generalconverters.hpp"
#include "step.hpp"
#include "form/form.hpp"
char * StringConverter::strToChar(std::string str)
{
    return (char*)str.c_str();
}

float StringConverter::strToFloat(std::string str)
{
    return std::stof(str);
}

int StringConverter::strToInt(std::string str, RoundType type)
{
    if(type == ROUND_DOWN)
        return std::stoi(str);
    else if(type == ROUND_UP)
        return ceil(strToFloat(str));
    return round(strToFloat(str));
}

std::string EdgeBandingConverter::bandingToString(EdgeBanding * banding)
{
    return bandingToString(banding->getCharFormat());
}

std::string EdgeBandingConverter::bandingToString(char * banding)
{
    std::string unitedEdgeBanding(banding, 4);
    return unitedEdgeBanding;
}

int FlagDecryptor::getFlagQueuePlace(FlagStepType flag)
{
    int queuePlace = 0;
    while(flag != 0)
    {
        flag = FlagStepType((int)flag / 2);
        queuePlace++;
    }
    return queuePlace;
}

bool FlagDecryptor::isStepFlagAssigned(FlagStepType flag, int flags) //giving place in que by variable make app faster but it can create bugs after changing some code
{
    int queuePlace = getFlagQueuePlace(flag);
    int divider = 1;
    for(int i = 0; i < queuePlace-1; i++)
        divider *= 2;
    flags /= divider;
    bool isAssigned = flags % 2;
    return isAssigned;
}

std::string ChainConnector::getChain(Step * lastStep)
{
	std::string result = "";
	while (lastStep != nullptr)
	{
		if (lastStep->params != nullptr)
		{
			result = lastStep->params->getString() + result;
			lastStep = lastStep->getParentStep();
		}
	}
	return result;
}