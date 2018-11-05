#ifndef STEP_HPP_INCLUDED
#define STEP_HPP_INCLUDED
#include "headers.hpp"
class Step {
    protected: Step * parentStep;
    protected: std::vector<Step*> childSteps;
    public: Step(Step * parentStep = nullptr);
    public: ~Step();
    //creators
    public: Step * createChildStep();

    //setters
    public: Step * setParentStep(Step * step);

    //getters
    public: Step * getParentStep();
};

#endif
