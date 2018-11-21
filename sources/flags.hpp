#ifndef FLAGS_HPP_INCLUDED
#define FLAGS_HPP_INCLUDED
#include "headers.hpp"
class Flag {
    protected: unsigned int flags;
    public: void setFlags(unsigned int flags);
    public: unsigned int getFlags();
    public: bool isFlagAdded(FlagStepType flag);
    public: bool addFlag(FlagStepType flag);
};

#endif // FLAGS_HPP_INCLUDED
