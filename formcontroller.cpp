#include "headers.hpp"
Form * FormController::setSize(Form * form)
{
    return form->setFormSize(this->getLengthInMeters(form) * this->getWidthInMeters(form));
}

float FormController::getLengthInMeters(Form * form)
{
    return form->getLength()/1000;
}

float FormController::getWidthInMeters(Form * form)
{
    return form->getWidth()/1000;
}

Form * FormController::setID(Form * form, unsigned int ID)
{
    form->setID(ID);
    return form;
}

void FormController::setIDToAll(std::vector<Form*> Forms, unsigned int startID)
{
    for(form : Forms)
        this->setID(form, startID++);
}

void FormController::setSizeToAll(std::vector<Form*> Forms)
{
    for(form : Forms)
        this->setSize(form);
}

void FormController::setupAllForms(std::vector<Form*> Forms)
{
    this->setIDToAll(Forms);
    this->setSizeToAll(Forms);
}
