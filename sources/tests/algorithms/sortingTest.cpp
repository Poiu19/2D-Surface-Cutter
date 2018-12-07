#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "sortingTest.hpp"
#include <vector>

BOOST_AUTO_TEST_SUITE(BubbleSorting)
	BOOST_AUTO_TEST_CASE(SortingIntegers)
	{
		SortingDataTest<int> data1(SORT_BUBBLE, 500);
		BOOST_CHECK(data1.isEqual() == true);
	}
	BOOST_AUTO_TEST_CASE(SortingFloats)
	{
		SortingDataTest<float> data1(SORT_BUBBLE, 500);
		BOOST_CHECK(data1.isEqual() == true);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(QuickSorting)
BOOST_AUTO_TEST_CASE(SortingIntegers)
{
	SortingDataTest<int> data1(SORT_QUICK, 1000);
	BOOST_CHECK(data1.isEqual() == true);
}
BOOST_AUTO_TEST_CASE(SortingFloats)
{
	SortingDataTest<float> data1(SORT_QUICK, 100);
	BOOST_CHECK(data1.isEqual() == true);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(HeapSorting)
BOOST_AUTO_TEST_CASE(SortingIntegers)
{
	SortingDataTest<int> data1(SORT_HEAP, 1000);
	BOOST_CHECK(data1.isEqual() == true);
}
BOOST_AUTO_TEST_CASE(SortingFloats)
{
	SortingDataTest<float> data1(SORT_HEAP, 100);
	BOOST_CHECK(data1.isEqual() == true);
}
BOOST_AUTO_TEST_SUITE_END()