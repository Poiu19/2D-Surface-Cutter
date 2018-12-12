#ifndef STEPTEST_HPP_INCLUDED
#define STEPTEST_HPP_INCLUDED

#include "step.hpp"
#include "headers.hpp"

class StepTestChilds {
	public: Step * firstChild, * secondChildA, * secondChildB, * startStep, * newParent;
			StepTestChilds();
			~StepTestChilds();
			bool isSiblingAWithB();
			bool isChildAGrandsonForStartStep();
			bool isChildCountEqualTo(Step *parent, int howMany);
			bool isSettingParentMakeStepAsChild();
};

#endif