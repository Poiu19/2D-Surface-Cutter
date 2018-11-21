#ifndef FORMSORTER_HPP_INCLUDED
#define FORMSORTER_HPP_INCLUDED
#include <algorithm>
#include "form.hpp"
#include "surface.hpp"

class Sorter {
    public: static void sortBySizeLength(std::vector<Form*> & forms);
    public: static void sortBySizeLength(std::vector<Surface*> & surfaces);
    public: static void sortBySizeWidth(std::vector<Form*> & forms);
    public: static void sortBySizeWidth(std::vector<Surface*> & surfaces);
    public: static void sortByLengthWidth(std::vector<Form*> & forms);
    public: static void sortByLengthWidth(std::vector<Surface*> & surfaces);
    public: static void sortByWidthLength(std::vector<Form*> & forms);
    public: static void sortByWidthLength(std::vector<Surface*> & surfaces);
};

class FormSorter {
    public: static void sortBySizeLengthDesc(std::vector<Form*> & forms);
    public: static void sortBySizeWidthDesc(std::vector<Form*> & forms);
    public: static void sortByLengthWidthDesc(std::vector<Form*> & forms);
    public: static void sortByWidthLengthDesc(std::vector<Form*> & forms);
};

class SurfaceSorter {
    public: static void sortBySizeLengthAsc(std::vector<Surface*> & surfaces);
    public: static void sortBySizeWidthAsc(std::vector<Surface*> & surfaces);
    public: static void sortByLengthWidthAsc(std::vector<Surface*> & surfaces);
    public: static void sortByWidthLengthAsc(std::vector<Surface*> & surfaces);
};

class SurfacePointerCopier {
    public: static std::vector<Form*> copySurfaces(std::vector<Form*> forms);
    public: static std::vector<Surface*> copySurfaces(std::vector<Surface*> forms);
    public: static Form* copySurface(Form* form);
    public: static Surface* copySurface(Surface* surface);
};

#endif // FORMSORTER_HPP_INCLUDED
