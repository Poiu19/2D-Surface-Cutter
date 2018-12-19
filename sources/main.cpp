#include <iostream>
#include <memory>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "step.hpp"
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
	std::shared_ptr<Surface> surface7(new Surface(11, 11, 100, 600));
    surfaces.push_back(surface1);
    surfaces.push_back(surface2);
    surfaces.push_back(surface3);
    surfaces.push_back(surface4);
    surfaces.push_back(surface5);
    surfaces.push_back(surface6);
	Sorter::sortBySizeLength(surfaces);
	
	for (std::shared_ptr<Surface> surface : surfaces)
		std::cout << surface->getPosX() << ", " << surface->getPosY() << ", size: " << surface->getSizeArea() << ", L: " << surface->getLength() << ", W: " << surface->getWidth() << "\n";

	SurfaceSorter::insertIntoCorrectPlaceBySizeLength(surfaces, surface7);
	std::cout << std::endl;
	for (std::shared_ptr<Surface> surface : surfaces)
		std::cout << surface->getPosX() << ", " << surface->getPosY() << ", size: " << surface->getSizeArea() << ", L: " << surface->getLength() << ", W: " << surface->getWidth() << "\n";

    std::cout << "Sortowanie SizeLength" << std::endl;
    for (std::shared_ptr<Form> form : forms)
    {
        std::cout << "ID: " << form->getID() << ", size: " << form->getSizeArea() << ", L: " << form->getLength() << ", W: " << form->getWidth() << std::endl;
    }

    return 0;
}
