#ifndef STEP_HPP_INCLUDED
#define STEP_HPP_INCLUDED
#include <algorithm>
#include <vector>
#include "form/form.hpp"
#include "form/surface.hpp"

class Step {
	protected: Step * parentStep;
    public: std::vector<Step*> childSteps;
    protected: std::vector<Form*> availableForms;
			std::vector<Form*> usedForms;
			std::vector<Surface*> availableSurfaces;
			std::vector<Surface*> usedSurfaces;
    public: Step(Step * parentStep = nullptr);
			~Step();
    //creators
			Step * addChildStep();

    //setters
	protected: Step * setParentStep(Step * step);
	public: Step * setNewParentStep(Step * newParent);
    //getters
			Step * getParentStep();
};

#endif
