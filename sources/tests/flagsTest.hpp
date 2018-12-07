#ifndef FLAGSTEST_HPP_INCLUDED
#define FLAGSTEST_HPP_INCLUDED
#include "flags.hpp"
#include "headers.hpp"

struct DetectFlagTest {
	Flag flags;
	bool isAdded(FlagStepType flag);
	void setFlags(int flags);
	void addFlag(FlagStepType flag);
};


#endif