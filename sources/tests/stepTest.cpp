#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "stepTest.hpp"

StepTestChilds::StepTestChilds()
{
	startStep = new Step(nullptr);
	firstChild = startStep->addChildStep();
	secondChildA = firstChild->addChildStep();
	secondChildB = firstChild->addChildStep();
}

StepTestChilds::~StepTestChilds()
{
	delete startStep;
}

bool StepTestChilds::isSiblingAWithB()
{
	return secondChildA->getParentStep() == secondChildA->getParentStep() ? true : false;
}

bool StepTestChilds::isChildAGrandsonForStartStep()
{
	return secondChildA->getParentStep()->getParentStep() == startStep ? true : false;
}

bool StepTestChilds::isChildCountEqualTo(Step *to, int howMany)
{
	return to->childSteps.size() == howMany ? true : false;
}

BOOST_AUTO_TEST_SUITE(StepTest)
BOOST_AUTO_TEST_CASE(StepRelationTest)
{
	StepTestChilds data1;
	BOOST_CHECK(data1.isSiblingAWithB() == true);
	BOOST_CHECK(data1.isChildAGrandsonForStartStep() == true);
	BOOST_CHECK(data1.isChildCountEqualTo(data1.startStep, 3) == false);
	BOOST_CHECK(data1.isChildCountEqualTo(data1.firstChild, 2) == true);
}
BOOST_AUTO_TEST_SUITE_END()