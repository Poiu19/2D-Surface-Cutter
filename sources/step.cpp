#include "step.hpp"
using namespace std;

Step::Step(Step * parentStep)
{
    this->setParentStep(parentStep);
}

Step::~Step()
{
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
    return this->parentStep;
}
