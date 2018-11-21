#include "flags.hpp"
#include "generalconverters.hpp"
void Flag::setFlags(unsigned int flags)
{
    this->flags = flags;
}

unsigned int Flag::getFlags()
{
    return this->flags;
}

bool Flag::isFlagAdded(FlagStepType flag)
{
    return FlagDecryptor::isStepFlagAssigned(flag, this->getFlags());
}

bool Flag::addFlag(FlagStepType flag)
{
    if(this->isFlagAdded(flag))
        return false;

    this->setFlags(this->getFlags() + (unsigned int)flag);
    return true;
}
