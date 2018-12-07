#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SortingAlgorithms
#include <boost/test/unit_test.hpp>
#include "algorithms/sorting.hpp"
#include "sortingTest.hpp"
#include <vector>

BOOST_AUTO_TEST_SUITE(BubbleSorting)
	BOOST_AUTO_TEST_CASE(SortingIntegers)
	{
		SortingDataTest<int> data1(SORT_BUBBLE, 100);
		SortingDataTest<int> data2(SORT_BUBBLE, 1000);
		SortingDataTest<int> data3(SORT_BUBBLE, 2000);
		BOOST_CHECK(data1.isEqual() == true);
		BOOST_CHECK(data2.isEqual() == true);
		BOOST_CHECK(data3.isEqual() == true);
	}
	BOOST_AUTO_TEST_CASE(SortingFloats)
	{
		SortingDataTest<float> data1(SORT_BUBBLE, 100);
		SortingDataTest<float> data2(SORT_BUBBLE, 1000);
		SortingDataTest<float> data3(SORT_BUBBLE, 2000);
		BOOST_CHECK(data1.isEqual() == true);
		BOOST_CHECK(data2.isEqual() == true);
		BOOST_CHECK(data3.isEqual() == true);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(QuickSorting)
BOOST_AUTO_TEST_CASE(SortingIntegers)
{
	SortingDataTest<int> data1(SORT_QUICK);
	SortingDataTest<int> data2(SORT_QUICK, 1000);
	SortingDataTest<int> data3(SORT_QUICK, 10000);
	BOOST_CHECK(data1.isEqual() == true);
	BOOST_CHECK(data2.isEqual() == true);
	BOOST_CHECK(data3.isEqual() == true);
}
BOOST_AUTO_TEST_CASE(SortingFloats)
{
	SortingDataTest<float> data1(SORT_QUICK);
	SortingDataTest<float> data2(SORT_QUICK, 1000);
	SortingDataTest<float> data3(SORT_QUICK, 10000);
	BOOST_CHECK(data1.isEqual() == true);
	BOOST_CHECK(data2.isEqual() == true);
	BOOST_CHECK(data3.isEqual() == true);
}
BOOST_AUTO_TEST_SUITE_END()