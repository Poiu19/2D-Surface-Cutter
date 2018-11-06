#ifndef STEP_HPP_INCLUDED
#define STEP_HPP_INCLUDED
#include <algorithm>
#include "form.hpp"
#include "surface.hpp"
class Step {
    protected: Step * parentStep;
    protected: std::vector<Step*> childSteps;
    protected: std::vector<Form*> availableForms;
    protected: std::vector<Form*> usedForms;
    protected: std::vector<Surface*> availableSurfaces;
    protected: std::vector<Surface*> usedSurfaces;
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