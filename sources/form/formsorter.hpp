#ifndef STEPSORTER_HPP_INCLUDED
#define STEPSORTER_HPP_INCLUDED
#include <algorithm>
#include "form.hpp"
#include "surface.hpp"
class FormSorter {
    public: static void sortBySizeLength(std::vector<Form*> & forms);
    public: static void sortBySizeWidth(std::vector<Form*> & forms);
    public: static void sortByLengthWidth(std::vector<Form*> & forms);
    public: static void sortByWidthLength(std::vector<Form*> & forms);
};

class SurfaceSorter {
    public: static void sortByLengthWidthAsc(std::vector<Surface*> & surfaces);
};

class FormPointerCopier {
    public: static std::vector<Form*> copyForms(std::vector<Form*> forms);
    public: static Form* copyForm(Form* form);
};

#endif // STEPSORTER_HPP_INCLUDED
