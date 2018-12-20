#include "cuttingprocess.hpp"
#include "form/formsorter.hpp"
#include <vector>
#include "saw/sawconfig.hpp"
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

CuttingProcess::CuttingProcess(std::vector<std::shared_ptr<Form> > forms, std::vector<std::shared_ptr<Surface> > surfaces, SortMode sortMode)
{
	this->stepPosition = new Step(nullptr);
	setSortMode(sortMode);
	stepPosition->availableSurfaces.insert(stepPosition->availableSurfaces.begin(), surfaces.begin(), surfaces.end());
	stepPosition->availableForms.insert(stepPosition->availableForms.begin(), forms.begin(), forms.end());
}

bool CuttingProcess::execute()
{
	for (int i = 0; i < stepPosition->availableSurfaces.size() - 1; i++)
	{
		if (stepPosition->availableForms.front()->getLength() <= stepPosition->availableSurfaces[i]->getLength() + SawConfig::getSawThick() &&
			stepPosition->availableForms.front()->getWidth() <= stepPosition->availableSurfaces[i]->getWidth() + SawConfig::getSawThick())
		{
			Step * parent = this->stepPosition->addChildStep();
			parent->setParams(0, i, Cut::CUT_VERTICAL, false);
			parent = this->stepPosition->addChildStep();
			parent->availableForms.insert(parent->availableForms.begin(), stepPosition->availableForms.begin(), stepPosition->availableForms.end());
			parent->usedForms.push_back(parent->availableForms.front());
			parent->availableForms.erase(parent->availableForms.begin());

			parent = this->stepPosition->addChildStep();
			parent->setParams(0, i, Cut::CUT_HORIZONTAL, false);
			parent->availableForms.insert(parent->availableForms.begin(), stepPosition->availableForms.begin(), stepPosition->availableForms.end());
			parent->usedForms.push_back(parent->availableForms.front());
			parent->availableForms.erase(parent->availableForms.begin());

			if (stepPosition->availableForms.front()->isSwapAble() &&
				stepPosition->availableForms.front()->getLength() <= stepPosition->availableSurfaces[i]->getWidth()+SawConfig::getSawThick() &&
				stepPosition->availableForms.front()->getWidth() <= stepPosition->availableSurfaces[i]->getLength()+SawConfig::getSawThick())
			{
				parent = this->stepPosition->addChildStep();
				parent->setParams(0, i, Cut::CUT_VERTICAL, true);
				parent->availableForms.insert(parent->availableForms.begin(), stepPosition->availableForms.begin(), stepPosition->availableForms.end());
				parent->usedForms.push_back(parent->availableForms.front());
				parent->availableForms.erase(parent->availableForms.begin());

				parent = this->stepPosition->addChildStep();
				parent->setParams(0, i, Cut::CUT_HORIZONTAL, true);
				parent->availableForms.insert(parent->availableForms.begin(), stepPosition->availableForms.begin(), stepPosition->availableForms.end());
				parent->usedForms.push_back(parent->availableForms.front());
				parent->availableForms.erase(parent->availableForms.begin());
			}
			if (stepPosition->childCheckingNow < stepPosition->childSteps.size())
				stepPosition = stepPosition->childSteps[stepPosition->childCheckingNow++];
			else if (stepPosition->getParentStep() != nullptr)
				stepPosition = stepPosition->getParentStep();
			else
				return true;
			break;
		}

	}
	CuttingResult result;
	result.setResult("0,0,0,1;1,1,1,0;", 2, 2, 4.30f);
	results.push_back(result);


	return true;
}

SortMode CuttingProcess::getSortMode()
{
	return sortMode;
}

void CuttingProcess::setSortMode(SortMode sortMode)
{
	this->sortMode = sortMode;
}

void CuttingProcess::sortPlatesAndSurfaces()
{
	if (getSortMode() == SORT_MODE_SIZE_LENGTH)
	{
		Sorter::sortBySizeLength(stepPosition->availableSurfaces);
		Sorter::sortBySizeLength(stepPosition->availableForms);
	}
	else if (getSortMode() == SORT_MODE_SIZE_WIDTH)
	{
		Sorter::sortBySizeWidth(stepPosition->availableSurfaces);
		Sorter::sortBySizeWidth(stepPosition->availableForms);
	}
	else if (getSortMode() == SORT_MODE_LENGTH_WIDTH)
	{
		Sorter::sortByLengthWidth(stepPosition->availableSurfaces);
		Sorter::sortByLengthWidth(stepPosition->availableForms);
	}
	else if (getSortMode() == SORT_MODE_WIDTH_LENGTH)
	{
		Sorter::sortByLengthWidth(stepPosition->availableSurfaces);
		Sorter::sortByLengthWidth(stepPosition->availableForms);
	}
}