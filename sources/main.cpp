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
#include "cuttingprocess.hpp"
#include <thread>
#include <future>
int main()
{
	SawConfig::loadParams();
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
    std::vector<std::shared_ptr<Surface> > surfaces;
    std::shared_ptr<Surface> surface1(new Surface(0, 0, 2800, 2100));
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

	SurfaceSorter::insertIntoCorrectPlaceBySizeLength(surfaces, surface7);
	std::shared_ptr<CuttingProcess> sizeLengthProcess(new CuttingProcess(forms, surfaces, SORT_MODE_SIZE_LENGTH));
	std::thread future(&CuttingProcess::execute, sizeLengthProcess);
	future.join();
	sizeLengthProcess->stepPosition->availableSurfaces.pop_back();
	for (std::shared_ptr<Surface> surface : sizeLengthProcess->stepPosition->availableSurfaces)
	{
		std::cout << surface->getPosX() << ", " << surface->getPosY() << ", size: " << surface->getSizeArea() << ", L: " << surface->getLength() << ", W: " << surface->getWidth() << "\n";
	}
	std::cout << "\n";
	for (std::shared_ptr<Surface> surface : surfaces)
		std::cout << surface->getPosX() << ", " << surface->getPosY() << ", size: " << surface->getSizeArea() << ", L: " << surface->getLength() << ", W: " << surface->getWidth() << "\n";

	std::cout << sizeLengthProcess->results.front().getSequenceChain() << std::endl;

    return 0;
}
