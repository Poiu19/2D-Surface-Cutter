#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "stepparams.hpp"
#include "stepparamsTest.hpp"
#include <iostream>
StepParamsTest::StepParamsTest(unsigned int formIndex, unsigned int surfaceIndex, Cut cutType, bool swap)
{
	params = new StepParams(formIndex, surfaceIndex, cutType, swap);
}

StepParamsTest::~StepParamsTest()
{
	if (params != nullptr)
	{
		delete params;
		params = nullptr;
	}
}
BOOST_AUTO_TEST_SUITE(StepParamTestSuite)
BOOST_AUTO_TEST_CASE(StepParamsStringTest)
{
	StepParamsTest data1(0, 0, CUT_HORIZONTAL, true);
	StepParamsTest data2(1, 2, CUT_VERTICAL, false);
	BOOST_CHECK(data1.params->getString() == "0,0,1,1;");
	BOOST_CHECK(data2.params->getString() == "1,2,0,0;");
}
BOOST_AUTO_TEST_SUITE_END()