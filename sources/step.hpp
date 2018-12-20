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
			std::vector<std::shared_ptr<Form> > availableForms;
			std::vector<std::shared_ptr<Form> > usedForms;
			std::vector<std::shared_ptr<Surface> > availableSurfaces;
			std::vector<std::shared_ptr<Surface> > usedSurfaces;
			Step(Step * parentStep = nullptr);
			~Step();
			int childCheckingNow = 0;
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
