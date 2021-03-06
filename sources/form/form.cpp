#include "form.hpp"
#include "generalconverters.hpp"
Form::Form(unsigned short int length, unsigned short int width, char * banding = StringConverter::strToChar("0000"))
    : Dimension(length, width), EdgeBanding(banding)
{
    this->setSwapAbleStatus(false);
    this->setType(FORM_STANDARD);
}

void Form::setID(unsigned int ID)
{
    this->ID = ID;
}

void Form::setSwapAbleStatus(bool status)
{
    this->swapAble = status;
}

void Form::setType(FormType type)
{
    this->type = type;
}
unsigned int Form::getID()
{
    return this->ID;
}

bool Form::isSwapAble()
{
    return this->swapAble;
}

FormType Form::getFormType()
{
    return this->type;
}

FormSwapAble::FormSwapAble(unsigned short int length, unsigned short int width, char * banding = StringConverter::strToChar("0000"))
    : Form(length, width, banding)
{
    this->setSwapAbleStatus(true);
    this->setType(FORM_SWAPABLE);
}
