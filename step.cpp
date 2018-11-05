#include "headers.hpp"
using namespace std;

Step::Step(Step * parentStep)
{
    this->setParentStep(parentStep);
    cout << "Stworzono STEP pod adresem::" << this << ", parent address::" << parentStep << endl;
}

Step::~Step()
{
    for (Step * childStep : this->childSteps)
    {
        if(childStep != nullptr)
            delete childStep;
        childStep = nullptr;
    }
    cout << "Usunieto STEP pod adresem::" << this << endl;
}

Step * Step::createChildStep()
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
