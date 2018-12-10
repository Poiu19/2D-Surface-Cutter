#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "dimensionTest.hpp"
DimensionTestArea::DimensionTestArea(unsigned short int length, unsigned short int width)
{
	setDimensions(length, width);
}

inline void DimensionTestArea::setDimensions(unsigned short int length, unsigned short int width)
{
	inputData.setLength(length);
	inputData.setWidth(width);
	inputData.setSizeArea(((float)length / 1000) * ((float)width / 1000));
}

inline bool DimensionTestArea::isEqualArea(float area)
{
	return (int)(inputData.getSizeArea()*1000) == (int)(area*1000) ? true : false;
}

BOOST_AUTO_TEST_SUITE(DimensionTest)
BOOST_AUTO_TEST_CASE(SizeAreaTest)
{
	DimensionTestArea data1(1000, 500);
	BOOST_CHECK(data1.isEqualArea(0.5) == true);
	data1.setDimensions(300, 400);
	BOOST_CHECK(data1.isEqualArea(0.12) == true);
}
BOOST_AUTO_TEST_SUITE_END()