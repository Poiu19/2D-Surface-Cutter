#ifndef GENERALCONVERTERS_HPP_INCLUDED
#define GENERALCONVERTERS_HPP_INCLUDED
#include <string>
#include <math.h>
#include "step.hpp"
#include "form/edgebanding.hpp"
#include "headers.hpp"
class StringConverter {
    public: static char * strToChar(std::string str);
			static float strToFloat(std::string str);
			static int strToInt(std::string str, RoundType type = ROUND_NORMAL);
};

class EdgeBandingConverter {
    public: static std::string bandingToString(EdgeBanding * banding);
    public: static std::string bandingToString(char * banding);
};

class FlagDecryptor {
    public: static int getFlagQueuePlace(FlagStepType flag);
    public: static bool isStepFlagAssigned(FlagStepType flag, int flags);
};

class ChainConnector {
	public: static std::string getChain(Step * lastStep);
};


#endif // GENERALCONVERTERS_HPP_INCLUDED
