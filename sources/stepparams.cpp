#include "headers.hpp"
#include "stepparams.hpp"
#include <string>
StepParams::StepParams(unsigned int formIndex, unsigned int surfaceIndex, Cut cutType, bool swap)
{
	this->formIndex = formIndex;
	this->surfaceIndex = surfaceIndex;
	this->cutType = cutType;
	this->swap = swap;
}

std::string StepParams::getString()
{
	std::string connectedString = std::to_string(formIndex);
	connectedString += ",";
	connectedString += std::to_string(surfaceIndex);
	if (getCutType() == CUT_VERTICAL)
		connectedString += ",0";
	else
		connectedString += ",1";
	if (isSwaped())
		connectedString += ",1;";
	else
		connectedString += ",0;";

	return connectedString;
}

unsigned int StepParams::getFormIndex()
{
	return formIndex;
}

unsigned int StepParams::getSurfaceIndex()
{
	return surfaceIndex;
}

bool StepParams::isSwaped()
{
	return swap;
}

Cut StepParams::getCutType()
{
	return cutType;
}