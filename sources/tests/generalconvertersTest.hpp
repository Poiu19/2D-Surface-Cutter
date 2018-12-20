#include "generalconverters.hpp"
#include "step.hpp"

class ChainConnectorTest
{
	Step * firstStep = nullptr;
	Step * lastStep = nullptr;
public: ChainConnectorTest();
		~ChainConnectorTest();
		bool checkChain();
};