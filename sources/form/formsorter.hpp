#ifndef FORMSORTER_HPP_INCLUDED
#define FORMSORTER_HPP_INCLUDED
#include <memory>
#include <algorithm>
#include <vector>
#include "form.hpp"
#include "surface.hpp"

class Sorter {
    public: static void sortBySizeLength(std::vector<std::shared_ptr<Form> > & forms);
    public: static void sortBySizeLength(std::vector<std::shared_ptr<Surface> > & surfaces);
    public: static void sortBySizeWidth(std::vector<std::shared_ptr<Form> > & forms);
    public: static void sortBySizeWidth(std::vector<std::shared_ptr<Surface> > & surfaces);
    public: static void sortByLengthWidth(std::vector<std::shared_ptr<Form> > & forms);
    public: static void sortByLengthWidth(std::vector<std::shared_ptr<Surface> > & surfaces);
    public: static void sortByWidthLength(std::vector<std::shared_ptr<Form> > & forms);
    public: static void sortByWidthLength(std::vector<std::shared_ptr<Surface> > & surfaces);
};

class FormSorter {
    public: static void sortBySizeLengthDesc(std::vector<std::shared_ptr<Form> > & forms);
    public: static void sortBySizeWidthDesc(std::vector<std::shared_ptr<Form> > & forms);
    public: static void sortByLengthWidthDesc(std::vector<std::shared_ptr<Form> > & forms);
    public: static void sortByWidthLengthDesc(std::vector<std::shared_ptr<Form> > & forms);
};

class SurfaceSorter {
    public: static void sortBySizeLengthAsc(std::vector<std::shared_ptr<Surface> > & surfaces);
    public: static void sortBySizeWidthAsc(std::vector<std::shared_ptr<Surface> > & surfaces);
    public: static void sortByLengthWidthAsc(std::vector<std::shared_ptr<Surface> > & surfaces);
    public: static void sortByWidthLengthAsc(std::vector<std::shared_ptr<Surface> > & surfaces);
	public: static void insertIntoCorrectPlaceBySizeLength(std::vector<std::shared_ptr<Surface> > & surfaces, std::shared_ptr<Surface> surface);
	public: static void insertIntoCorrectPlaceBySizeWidth(std::vector<std::shared_ptr<Surface> > & surfaces, std::shared_ptr<Surface> surface);
	public: static void insertIntoCorrectPlaceByWidthLength(std::vector<std::shared_ptr<Surface> > & surfaces, std::shared_ptr<Surface> surface);
	public: static void insertIntoCorrectPlaceByLengthWidth(std::vector<std::shared_ptr<Surface> > & surfaces, std::shared_ptr<Surface> surface);
};

class SurfacePointerCopier {
    public: static std::vector<std::shared_ptr<Form> > copySurfaces(std::vector<std::shared_ptr<Form> > forms);
    public: static std::vector<std::shared_ptr<Surface> > copySurfaces(std::vector<std::shared_ptr<Surface> > forms);
    public: static std::shared_ptr<Form> copySurface(std::shared_ptr<Form> form);
    public: static std::shared_ptr<Surface> copySurface(std::shared_ptr<Surface> surface);
};

#endif // FORMSORTER_HPP_INCLUDED
