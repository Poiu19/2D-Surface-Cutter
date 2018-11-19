#include <iostream>
#include <memory>
#include "form/form.hpp"
#include "form/formsetup.hpp"
#include "form/formsorter.hpp"
#include "saw/sawconfig.hpp"
#include "generalconverters.hpp"

int main()
{
    Form * form1 = new Form(200, 100, StringConverter::strToChar("1111"));
    FormSwapAble * form2 = new FormSwapAble(1000, 2000, StringConverter::strToChar("1111"));
    Form * form3 = new Form(100, 200, StringConverter::strToChar("1111"));
    Form * form4 = new Form(300, 200, StringConverter::strToChar("1111"));
    Form * form5 = new Form(200, 300, StringConverter::strToChar("1111"));
    Form * form6 = new Form(500, 100, StringConverter::strToChar("1111"));
    Form * form7 = new Form(600, 150, StringConverter::strToChar("1111"));
    std::vector<Form*> forms;
    forms.push_back(form1);
    forms.push_back(form2);
    forms.push_back(form3);
    forms.push_back(form4);
    forms.push_back(form5);
    forms.push_back(form6);
    forms.push_back(form7);
    FormSetup::setupAllForms(forms);
    FormSorter::sortBySizeLength(forms);
    std::vector<Surface*> surfaces;
    Surface * surface1 = new Surface(0, 0, 200, 400);
    Surface * surface2 = new Surface(1, 2, 200, 300);
    Surface * surface3 = new Surface(5, 3, 300, 300);
    Surface * surface4 = new Surface(3, 4, 250, 400);
    Surface * surface5 = new Surface(3, 3, 300, 400);
    Surface * surface6 = new Surface(4, 8, 300, 200);
    surfaces.push_back(surface1);
    surfaces.push_back(surface2);
    surfaces.push_back(surface3);
    surfaces.push_back(surface4);
    surfaces.push_back(surface5);
    surfaces.push_back(surface6);
    std::cout << "Sortowanie SizeLength" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
    }
    FormSorter::sortBySizeWidth(forms);
    std::cout << "Sortowanie SizeWidth" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
    }
    FormSorter::sortByLengthWidth(forms);
    std::cout << "Sortowanie LengthWidth" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
    }
    FormSorter::sortByWidthLength(forms);
    std::cout << "Sortowanie WidthLength" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
        delete form;
    }
    SurfaceSorter::sortByLengthWidthAsc(surfaces);
    for (surface : surfaces)
    {
        std::cout << "X: " << surface->getPosX() << ", Y: " << surface->getPosY() << ", LENGTH: " << surface->getLength() << ", WIDTH: " << surface->getWidth() << std::endl;
    }
    std::cout << SawConfig::getDoubleThickQuantion() << std::endl << SawConfig::getEdgeQuantion() << std::endl << SawConfig::getSawThick() << std::endl;
    return 0;
}
