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
    std::vector<Form*> forms;
    forms.push_back(form1);
    forms.push_back(form2);
    forms.push_back(form3);
    FormSetup::setupAllForms(forms);
    forms = FormSorter::sortBySizeLength(forms);
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << std::endl;
        delete form;
    }
    std::cout << SawConfig::getDoubleThickQuantion() << std::endl << SawConfig::getEdgeQuantion() << std::endl << SawConfig::getSawThick() << std::endl;
    return 0;
}