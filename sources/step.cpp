#include "step.hpp"
using namespace std;

Step::Step(Step * parentStep)
{
    this->setParentStep(parentStep);
}

Step::~Step()
{
	if (params != nullptr)
	{
		delete params;
		params = nullptr;
	}
    for (Step * childStep : this->childSteps)
    {
        if(childStep != nullptr)
            delete childStep;
        childStep = nullptr;
    }
}

Step * Step::addChildStep()
{
    this->childSteps.push_back(new Step(this));
    return this->childSteps.back();
}

Step * Step::setParentStep(Step * parentStep)
{
    this->parentStep = parentStep;
    return this;
}

Step * Step::getParentStep()
{
	if (parentStep != nullptr)
		return this->parentStep;
	return nullptr;
}

Step * Step::setNewParentStep(Step * newParent)
{
	if (this->getParentStep() != nullptr)
	{
		for (auto it = this->getParentStep()->childSteps.begin(); it != this->getParentStep()->childSteps.end(); ++it)
		{
			if (*it == this)
			{
				this->getParentStep()->childSteps.erase(it);
				break;
			}
		}
	}
	this->parentStep = newParent;
	newParent->childSteps.push_back(this);
	return this;
}

void Step::setParams(unsigned int formIndex, unsigned int surfaceIndex, Cut cutType, bool swap)
{
	params = new StepParams(formIndex, surfaceIndex, cutType, swap);
}