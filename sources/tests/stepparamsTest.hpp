#ifndef STEPPARAMSTEST_HPP_INCLUDED
#define STEPPARAMSTEST_HPP_INCLUDED
#include "headers.hpp"
#include "stepparams.hpp"

class StepParamsTest {
public: StepParams * params = nullptr;
	public: StepParamsTest(unsigned int formIndex, unsigned int surfaceIndex, Cut cutType, bool swap);
	public: ~StepParamsTest();
};

#endif