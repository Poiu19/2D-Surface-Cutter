#ifndef STEPPARAMS_HPP_INCLUDED
#define STEPPARAMS_HPP_INCLUDED
#include "headers.hpp"
#include <string>

class StepParams {
	bool swap;
	Cut cutType;
	unsigned int formIndex, surfaceIndex;

	public: StepParams(unsigned int formIndex, unsigned int surfaceeIndex, Cut cutType, bool swap);
	public: std::string getString();

private: unsigned int getFormIndex();
		 unsigned int getSurfaceIndex();
		 bool isSwaped();
		 Cut getCutType();
};

#endif