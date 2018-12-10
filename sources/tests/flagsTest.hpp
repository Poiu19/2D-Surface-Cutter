#ifndef FLAGSTEST_HPP_INCLUDED
#define FLAGSTEST_HPP_INCLUDED
#include "flags.hpp"
#include "headers.hpp"

struct DetectFlagTest {
	inline bool isAdded(FlagStepType flag);
	inline void setFlags(int flags);
	inline void addFlag(FlagStepType flag);
	private: Flag flags;
};


#endif