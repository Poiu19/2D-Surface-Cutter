#include <iostream>
#include <memory>
#include "form/form.hpp"
#include "form/formsetup.hpp"
#include "form/formsorter.hpp"
#include "saw/sawconfig.hpp"
#include "generalconverters.hpp"
#include "algorithms/sorting.hpp"

int main()
{
    std::vector<std::shared_ptr<Form> > forms;
    std::shared_ptr<Form> form1(new Form(200, 100, StringConverter::strToChar("1111")));
    std::shared_ptr<FormSwapAble> form2(new FormSwapAble(1000, 2000, StringConverter::strToChar("1111")));
    std::shared_ptr<Form> form3(new Form(100, 200, StringConverter::strToChar("1111")));
    std::shared_ptr<Form> form4(new Form(300, 200, StringConverter::strToChar("1111")));
    std::shared_ptr<Form> form5(new Form(200, 300, StringConverter::strToChar("1111")));
    std::shared_ptr<Form> form6(new Form(500, 100, StringConverter::strToChar("1111")));
    std::shared_ptr<Form> form7(new Form(600, 150, StringConverter::strToChar("1111")));
    forms.push_back(form1);
    forms.push_back(form2);
    forms.push_back(form3);
    forms.push_back(form4);
    forms.push_back(form5);
    forms.push_back(form6);
    forms.push_back(form7);
    FormSetup::setupAllForms(forms);
    Sorter::sortBySizeLength(forms);
    std::vector<std::shared_ptr<Surface> > surfaces;
    std::shared_ptr<Surface> surface1(new Surface(0, 0, 200, 400));
    std::shared_ptr<Surface> surface2(new Surface(1, 2, 200, 300));
    std::shared_ptr<Surface> surface3(new Surface(5, 3, 300, 300));
    std::shared_ptr<Surface> surface4(new Surface(3, 4, 250, 400));
    std::shared_ptr<Surface> surface5(new Surface(3, 3, 300, 400));
    std::shared_ptr<Surface> surface6(new Surface(4, 8, 300, 200));
    surfaces.push_back(surface1);
    surfaces.push_back(surface2);
    surfaces.push_back(surface3);
    surfaces.push_back(surface4);
    surfaces.push_back(surface5);
    surfaces.push_back(surface6);
    std::vector<int> HH;
    HH.push_back(4); //1
    HH.push_back(5); //1
    HH.push_back(1); //3
    HH.push_back(17); //4
    HH.push_back(3);//5
    HH.push_back(1); //17
    sortBubble<int>(HH);
    for(h : HH)
        std::cout << h << std::endl;
    //bubbleSort<std::vector<int> >(vec1);
    std::cout << "Sortowanie SizeLength" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
    }
    Sorter::sortBySizeWidth(forms);
    std::cout << "Sortowanie SizeWidth" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
    }
    Sorter::sortByLengthWidth(forms);
    std::cout << "Sortowanie LengthWidth" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
    }
    Sorter::sortByWidthLength(forms);
    std::cout << "Sortowanie WidthLength" << std::endl;
    for (form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
    }
    Sorter::sortByLengthWidth(surfaces);
    for (surface : surfaces)
    {
        std::cout << "X: " << surface->getPosX() << ", Y: " << surface->getPosY() << ", LENGTH: " << surface->getLength() << ", WIDTH: " << surface->getWidth() << std::endl;
    }
    std::cout << SawConfig::getDoubleThickQuantion() << std::endl << SawConfig::getEdgeQuantion() << std::endl << SawConfig::getSawThick() << std::endl;
    std::cout << FlagDecryptor::getFlagQueuePlace(FLAG_NOTSWAPED) << " - " << FlagDecryptor::isStepFlagAssigned(FLAG_NOTSWAPED, 13) << std::endl;
    return 0;
}
