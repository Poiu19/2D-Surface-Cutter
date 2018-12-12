#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "stepTest.hpp"

StepTestChilds::StepTestChilds()
{
	startStep = new Step(nullptr);
	firstChild = startStep->addChildStep();
	secondChildA = firstChild->addChildStep();
	secondChildB = firstChild->addChildStep();
	newParent = new Step(nullptr);
}

StepTestChilds::~StepTestChilds()
{
	delete startStep;
	delete newParent;
}

bool StepTestChilds::isSiblingAWithB()
{
	return secondChildA->getParentStep() == secondChildA->getParentStep() ? true : false;
}

bool StepTestChilds::isChildAGrandsonForStartStep()
{
	return secondChildA->getParentStep()->getParentStep() == startStep ? true : false;
}

bool StepTestChilds::isChildCountEqualTo(Step *parent, int howMany)
{
	return parent->childSteps.size() == howMany ? true : false;
}

bool StepTestChilds::isSettingParentMakeStepAsChild()
{
	bool success = false;
	secondChildB->setNewParentStep(newParent);
	if (newParent->childSteps.back() == secondChildB && secondChildB->getParentStep() == newParent)
	{
		success = true;
		secondChildB->setNewParentStep(firstChild);
	}
	return success;
}

BOOST_AUTO_TEST_SUITE(StepTest)
BOOST_AUTO_TEST_CASE(StepRelationTest)
{
	StepTestChilds data1;
	BOOST_CHECK(data1.isSiblingAWithB() == true);
	BOOST_CHECK(data1.isChildAGrandsonForStartStep() == true);
	BOOST_CHECK(data1.isChildCountEqualTo(data1.startStep, 3) == false);
	BOOST_CHECK(data1.isChildCountEqualTo(data1.firstChild, 2) == true);
	BOOST_CHECK(data1.isSettingParentMakeStepAsChild() == true);
}
BOOST_AUTO_TEST_SUITE_END()