#ifndef STEP_HPP_INCLUDED
#define STEP_HPP_INCLUDED
#include <algorithm>
#include <vector>
#include "form/surface.hpp"
#include "stepparams.hpp"
#include "form/form.hpp"
class Step {
	protected: Step * parentStep;
    public: std::vector<Step*> childSteps;
			StepParams * params = nullptr;
    protected:	std::vector<Form*> availableForms;
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
			void setParams(unsigned int formIndex, unsigned int surfaceIndex, Cut cutType, bool swap);
    //getters
			Step * getParentStep();
};

#endif
