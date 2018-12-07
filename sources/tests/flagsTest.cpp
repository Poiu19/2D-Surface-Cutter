#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "flagsTest.hpp"
#include "headers.hpp"
bool DetectFlagTest::isAdded(FlagStepType flag)
{
	return this->flags.isFlagAdded(flag);
}

void DetectFlagTest::setFlags(int flags)
{
	this->flags.setFlags(flags);
}

void DetectFlagTest::addFlag(FlagStepType flag)
{
	this->flags.addFlag(flag);
}

BOOST_AUTO_TEST_SUITE(FlagsTestSuite)
BOOST_AUTO_TEST_CASE(FlasIsAdded)
{
	DetectFlagTest data1;
	data1.setFlags(0);
	BOOST_CHECK(data1.isAdded(FlagStepType::FLAG_NOTSWAPED) == false);
	data1.setFlags(11);
	BOOST_CHECK(data1.isAdded(FlagStepType::FLAG_HORIZONTALCUT) == true);
	BOOST_CHECK(data1.isAdded(FlagStepType::FLAG_VERTICALCUT) == false);
	BOOST_CHECK(data1.isAdded(FlagStepType::FLAG_SWAPED) == true);
	BOOST_CHECK(data1.isAdded(FlagStepType::FLAG_NOTSWAPED) == true);
}
BOOST_AUTO_TEST_SUITE_END()