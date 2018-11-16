#include "form.hpp"

Form::Form(unsigned short int length, unsigned short int width, char * bordering)
    : Dimension(length, width)
{
    this->setBordering(bordering);
    this->setSwapAbleStatus(false);
    this->setType(FORM_STANDARD);
}

void Form::setID(unsigned int ID)
{
    this->ID = ID;
}

void Form::setBordering(char * bordering)
{
    this->bordering = bordering;
}

void Form::setSwapAbleStatus(bool status)
{
    this->swapAble = status;
}

void Form::setType(Form_Type type)
{
    this->type = type;
}
unsigned int Form::getID()
{
    return this->ID;
}

char * Form::getBordering()
{
    return this->bordering;
}

bool Form::getSwapAbleStatus()
{
    return this->swapAble;
}

Form_Type Form::getFormType()
{
    return this->type;
}

FormSwapAble::FormSwapAble(unsigned short int length, unsigned short int width, char * bordering)
    : Form(length, width, bordering)
{
    this->setSwapAbleStatus(true);
    this->setType(FORM_SWAPABLE);
}
