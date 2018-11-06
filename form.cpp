#include "form.hpp"

Form::Form(unsigned short int length, unsigned short int width, unsigned short int bordering)
{
    this->setLength(length)->setWidth(width)->setBordering(bordering)->setSwapAbleStatus(false)->setType(FORM_STANDARD);
}

Form * Form::setID(unsigned int ID)
{
    this->ID = ID;
    return this;
}

Form * Form::setLength(unsigned short int length)
{
    this->length = length;
    return this;
}

Form * Form::setWidth(unsigned short int width)
{
    this->width = width;
    return this;
}

Form * Form::setBordering(unsigned short int bordering)
{
    this->bordering = bordering;
    return this;
}

Form * Form::setFormSize(float formSize)
{
    this->formSize = formSize;
    return this;
}

Form * Form::setSwapAbleStatus(bool status)
{
    this->swapAble = status;
    return this;
}

Form * Form::setType(Form_Type type)
{
    this->type = type;
    return this;
}
unsigned int Form::getID()
{
    return this->ID;
}

unsigned short int Form::getLength()
{
    return this->length;
}

unsigned short int Form::getWidth()
{
    return this->width;
}

unsigned short int Form::getBordering()
{
    return this->bordering;
}

float Form::getFormSize()
{
    return this->formSize;
}

bool Form::getSwapAbleStatus()
{
    return this->swapAble;
}

Form_Type Form::getFormType()
{
    return this->type;
}

FormSwapAble::FormSwapAble(unsigned short int length, unsigned short int width, unsigned short int bordering)
    : Form(length, width, bordering)
{
    this->setSwapAbleStatus(true)->setType(FORM_SWAPABLE);
}
