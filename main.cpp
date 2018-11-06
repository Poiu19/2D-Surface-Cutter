#include <iostream>
#include "form.hpp"
#include "formcontroller.hpp"
#include "formsorter.hpp"
#include "sawconfig.hpp"
int main()
{
    SawConfig * saw = new SawConfig();
    Form * form1 = new Form(200, 100, 1111);
    FormSwapAble * form2 = new FormSwapAble(1000, 2000, 1011);
    Form * form3 = new Form(100, 200, 1111);
    std::vector<Form*> forms;
    forms.push_back(form1);
    forms.push_back(form2);
    forms.push_back(form3);
    FormSetup controller;
    controller.setupAllForms(forms);
    FormSorter sorter;
    forms = sorter.sortBySizeLength(forms);
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getFormSize() << std::endl;
        delete form;
    }
    std::cout << saw->getDoubleThickQuantion() << std::endl << saw->getEdgeQuantion() << std::endl << saw->getSawThick() << std::endl;
    return 0;
}
