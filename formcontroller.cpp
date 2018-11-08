#include "formcontroller.hpp"
#include "form.hpp"
void FormSetup::setSize(Form * form)
{
    form->setFormSize(getLengthInMeters(form) * getWidthInMeters(form));
}

float FormSetup::getLengthInMeters(Form * form)
{
    return (float)form->getLength()/1000;
}

float FormSetup::getWidthInMeters(Form * form)
{
    return (float)form->getWidth()/1000;
}

void FormSetup::setID(Form * form, unsigned int ID)
{
    form->setID(ID);
}

void FormSetup::setIDToAll(std::vector<Form*> Forms, unsigned int startID)
{
    for(form : Forms)
        setID(form, startID++);
}

void FormSetup::setSizeToAll(std::vector<Form*> Forms)
{
    for(form : Forms)
        setSize(form);
}

void FormSetup::setupAllForms(std::vector<Form*> Forms)
{
    setIDToAll(Forms);
    setSizeToAll(Forms);
}
