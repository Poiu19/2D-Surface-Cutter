#ifndef GENERALCONVERTERS_HPP_INCLUDED
#define GENERALCONVERTERS_HPP_INCLUDED
#include <string>
#include <math.h>
#include "headers.hpp"
#include "form/edgebanding.hpp"
class StringConverter {
    public: static char * strToChar(std::string str);
    public: static float strToFloat(std::string str);
    public: static int strToInt(std::string str, RoundType type = ROUND_NORMAL);
};

class EdgeBandingConverter {
    public: static std::string bandingToString(EdgeBanding * banding);
    public: static std::string bandingToString(char * banding);
};

class FlagDecryptor {
    public: static int getFlagQueuePlace(FlagStepType flag);
    public: static bool isStepFlagAssigned(FlagStepType flag, int flags);
};



#endif // GENERALCONVERTERS_HPP_INCLUDED
