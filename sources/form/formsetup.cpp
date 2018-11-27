#include "formsetup.hpp"
#include "form.hpp"
void FormSetup::setSize(std::shared_ptr<Form> form)
{
    form->setSizeArea(getLengthInMeters(form) * getWidthInMeters(form));
}

float FormSetup::getLengthInMeters(std::shared_ptr<Form> form)
{
    return (float)form->getLength()/1000;
}

float FormSetup::getWidthInMeters(std::shared_ptr<Form> form)
{
    return (float)form->getWidth()/1000;
}

void FormSetup::setID(std::shared_ptr<Form> form, unsigned int ID)
{
    form->setID(ID);
}

void FormSetup::setIDToAll(std::vector<std::shared_ptr<Form> > Forms, unsigned int startID)
{
    for(form : Forms)
        setID(form, startID++);
}

void FormSetup::setSizeToAll(std::vector<std::shared_ptr<Form> > Forms)
{
    for(form : Forms)
        setSize(form);
}

void FormSetup::setupAllForms(std::vector<std::shared_ptr<Form> > Forms)
{
    setIDToAll(Forms);
    setSizeToAll(Forms);
}
