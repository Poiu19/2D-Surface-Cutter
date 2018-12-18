#include "cuttingprocess.hpp"
#include <vector>
void CuttingResult::setPlatesCount(int count)
{
	platesCount = count;
}

void CuttingResult::setUnusedSurfacesCount(int count)
{
	unusedSurfacesCount = count;
}

void CuttingResult::setUnusedArea(float area)
{
	unusedArea = area;
}

void CuttingResult::setSequenceChain(std::string chain)
{
	sequenceChain = chain;
}

void CuttingResult::setResult(std::string chain, int platesCount, int unusedSurfacesCount, float area)
{
	setSequenceChain(chain);
	setPlatesCount(platesCount);
	setUnusedSurfacesCount(unusedSurfacesCount);
	setUnusedArea(area);
}

bool CuttingResult::operator<=(CuttingResult const& result)
{
	if (platesCount < result.platesCount)
		return false;
	else if (platesCount > result.platesCount)
		return true;

	if (unusedArea > result.unusedArea)
		return false;
	else if (unusedArea < result.unusedArea)
		return true;

	if (unusedSurfacesCount < result.unusedSurfacesCount)
		return false;
	else if (unusedSurfacesCount > result.unusedSurfacesCount)
		return true;

	return true;
}

bool CuttingResult::operator<(CuttingResult const& result)
{
	if (platesCount < result.platesCount)
		return false;
	else if (platesCount > result.platesCount)
		return true;

	if (unusedArea > result.unusedArea)
		return false;
	else if (unusedArea < result.unusedArea)
		return true;

	if (unusedSurfacesCount < result.unusedSurfacesCount)
		return false;
	else if (unusedSurfacesCount > result.unusedSurfacesCount)
		return true;

	return false;
}

bool CuttingResult::operator>=(CuttingResult const& result)
{
	if (platesCount < result.platesCount)
		return true;
	else if (platesCount > result.platesCount)
		return false;

	if (unusedArea > result.unusedArea)
		return true;
	else if (unusedArea < result.unusedArea)
		return false;

	if (unusedSurfacesCount < result.unusedSurfacesCount)
		return true;
	else if (unusedSurfacesCount > result.unusedSurfacesCount)
		return false;

	return true;
}

bool CuttingResult::operator>(CuttingResult const& result)
{
	if (platesCount < result.platesCount)
		return true;
	else if (platesCount > result.platesCount)
		return false;

	if (unusedArea > result.unusedArea)
		return true;
	else if (unusedArea < result.unusedArea)
		return false;

	if (unusedSurfacesCount < result.unusedSurfacesCount)
		return true;
	else if (unusedSurfacesCount > result.unusedSurfacesCount)
		return false;

	return false;
}

bool CuttingResult::operator==(CuttingResult const& result)
{
	if (platesCount == result.platesCount &&
		unusedArea == result.unusedArea &&
		unusedSurfacesCount == result.unusedSurfacesCount)
		return true;
	return false;
}

std::string CuttingResult::getSequenceChain()
{
	return sequenceChain;
}

int CuttingResult::getPlatesCount()
{
	return platesCount;
}

int CuttingResult::getUnusedSurfacesCount()
{
	return unusedSurfacesCount;
}

float CuttingResult::getUnusedArea()
{
	return unusedArea;
}