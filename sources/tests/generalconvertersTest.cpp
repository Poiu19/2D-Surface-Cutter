#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "generalconvertersTest.hpp"

ChainConnectorTest::ChainConnectorTest()
{
	firstStep = new Step(nullptr);
	firstStep->setParams(0, 0, CUT_HORIZONTAL, true);
	lastStep = firstStep->addChildStep();
	lastStep->setParams(1, 1, CUT_VERTICAL, false);
	lastStep = lastStep->addChildStep();
	lastStep->setParams(2, 2, CUT_VERTICAL, true);
	lastStep = lastStep->addChildStep();
	lastStep->setParams(3, 33, CUT_HORIZONTAL, false);
	lastStep = lastStep->addChildStep();
	lastStep->setParams(4, 44, CUT_VERTICAL, false);
	lastStep = lastStep->addChildStep();
	lastStep->setParams(5, 2, CUT_HORIZONTAL, true);
}

ChainConnectorTest::~ChainConnectorTest()
{
	delete this->firstStep;
}

bool ChainConnectorTest::checkChain()
{
	std::string chain = ChainConnector::getChain(lastStep);
	if (chain == "0,0,1,1;1,1,0,0;2,2,0,1;3,33,1,0;4,44,0,0;5,2,1,1;")
		return true;
	return false;
}

BOOST_AUTO_TEST_SUITE(ConvertersTest)
BOOST_AUTO_TEST_CASE(ChainConnectorTests)
{
	ChainConnectorTest * data1 = new ChainConnectorTest();
	BOOST_CHECK(data1->checkChain() == true);
	delete data1;
}
BOOST_AUTO_TEST_SUITE_END()