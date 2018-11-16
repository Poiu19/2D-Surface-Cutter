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
    //typedef FormSorter<Form*>::sortBySizeLength(forms);
    forms = FormSorter::sortBySizeLength(forms);
    std::cout << "Sortowanie SizeLength" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
        //delete form;
    }
    forms = FormSorter::sortBySizeWidth(forms);
    std::cout << "Sortowanie SizeWidth" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
       // delete form;
    }
    forms = FormSorter::sortByLengthWidth(forms);
    std::cout << "Sortowanie LengthWidth" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
        //delete form;
    }
    forms = FormSorter::sortByWidthLength(forms);
    std::cout << "Sortowanie WidthLength" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
        delete form;
    }
    std::cout << SawConfig::getDoubleThickQuantion() << std::endl << SawConfig::getEdgeQuantion() << std::endl << SawConfig::getSawThick() << std::endl;
    return 0;
}
