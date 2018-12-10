#ifndef FLAGSTEST_HPP_INCLUDED
#define FLAGSTEST_HPP_INCLUDED
#include "dimension.hpp"
#include "headers.hpp"

class DimensionTestArea {
private: Dimension inputData;
	public: DimensionTestArea(unsigned short int length, unsigned short int width);

	public: inline void setDimensions(unsigned short int length, unsigned short int width);
	public: inline bool isEqualArea(float area);
};

#endif