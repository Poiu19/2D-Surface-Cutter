#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "cuttingprocessTest.hpp"

BOOST_AUTO_TEST_SUITE(CuttingResultTests)
BOOST_AUTO_TEST_CASE(CuttingResultIsBetter)
{
	CuttingResultTest data1;
	data1.resultA.setResult("", 10, 5, 4.20);
	data1.resultB.setResult("", 10, 4, 4.20);
	BOOST_CHECK((data1.resultA > data1.resultB) == false);
	BOOST_CHECK((data1.resultB > data1.resultA) == true);
	data1.resultB.setResult("", 10, 5, 4.20);
	BOOST_CHECK((data1.resultA > data1.resultB) == false);
	BOOST_CHECK((data1.resultB > data1.resultA) == false);
	data1.resultA.setResult("", 9, 5, 4.20);
	BOOST_CHECK((data1.resultA > data1.resultB) == true);
	BOOST_CHECK((data1.resultB > data1.resultA) == false);
}
BOOST_AUTO_TEST_CASE(CuttingResultIsWorse)
{
	CuttingResultTest data1;
	data1.resultA.setResult("", 10, 5, 4.20);
	data1.resultB.setResult("", 10, 4, 4.20);
	BOOST_CHECK((data1.resultA < data1.resultB) == true);
	BOOST_CHECK((data1.resultB < data1.resultA) == false);
	data1.resultB.setResult("", 10, 5, 4.20);
	BOOST_CHECK((data1.resultA < data1.resultB) == false);
	BOOST_CHECK((data1.resultB < data1.resultA) == false);
	data1.resultA.setResult("", 9, 5, 4.20);
	BOOST_CHECK((data1.resultA < data1.resultB) == false);
	BOOST_CHECK((data1.resultB < data1.resultA) == true);
}
BOOST_AUTO_TEST_CASE(CuttingResultIsBetterOrEqual)
{
	CuttingResultTest data1;
	data1.resultA.setResult("", 10, 5, 4.20);
	data1.resultB.setResult("", 10, 5, 4.20);
	BOOST_CHECK((data1.resultA >= data1.resultB) == true);
	BOOST_CHECK((data1.resultB >= data1.resultA) == true);
	data1.resultA.setResult("", 11, 5, 4.20);
	BOOST_CHECK((data1.resultA >= data1.resultB) == false);
	BOOST_CHECK((data1.resultB >= data1.resultA) == true);
	data1.resultB.setResult("", 11, 5, 4.30);
	BOOST_CHECK((data1.resultA >= data1.resultB) == false);
	BOOST_CHECK((data1.resultB >= data1.resultA) == true);
}
BOOST_AUTO_TEST_CASE(CuttingResultIsWorseOrEqual)
{
	CuttingResultTest data1;
	data1.resultA.setResult("", 10, 5, 4.20);
	data1.resultB.setResult("", 10, 5, 4.20);
	BOOST_CHECK((data1.resultA <= data1.resultB) == true);
	BOOST_CHECK((data1.resultB <= data1.resultA) == true);
	data1.resultA.setResult("", 11, 5, 4.20);
	BOOST_CHECK((data1.resultA <= data1.resultB) == true);
	BOOST_CHECK((data1.resultB <= data1.resultA) == false);
	data1.resultB.setResult("", 11, 5, 4.30);
	BOOST_CHECK((data1.resultA <= data1.resultB) == true);
	BOOST_CHECK((data1.resultB <= data1.resultA) == false);
}
BOOST_AUTO_TEST_SUITE_END();