#include "formcontroller.hpp"
#include "form.hpp"
Form * FormSetup::setSize(Form * form)
{
    return form->setFormSize(this->getLengthInMeters(form) * this->getWidthInMeters(form));
}

float FormSetup::getLengthInMeters(Form * form)
{
    return (float)form->getLength()/1000;
}

float FormSetup::getWidthInMeters(Form * form)
{
    return (float)form->getWidth()/1000;
}

Form * FormSetup::setID(Form * form, unsigned int ID)
{
    form->setID(ID);
    return form;
}

void FormSetup::setIDToAll(std::vector<Form*> Forms, unsigned int startID)
{
    for(form : Forms)
        this->setID(form, startID++);
}

void FormSetup::setSizeToAll(std::vector<Form*> Forms)
{
    for(form : Forms)
        this->setSize(form);
}

void FormSetup::setupAllForms(std::vector<Form*> Forms)
{
    this->setIDToAll(Forms);
    this->setSizeToAll(Forms);
}
