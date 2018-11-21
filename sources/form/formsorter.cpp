#include "formsorter.hpp"
#include "form.hpp"
void Sorter::sortBySizeLength(std::vector<Form*> & forms)
{
    FormSorter::sortBySizeLengthDesc(forms);
}
void Sorter::sortBySizeLength(std::vector<Surface*> & surfaces)
{
    SurfaceSorter::sortBySizeLengthAsc(surfaces);
}
void Sorter::sortBySizeWidth(std::vector<Form*> & forms)
{
    FormSorter::sortBySizeWidthDesc(forms);
}
void Sorter::sortBySizeWidth(std::vector<Surface*> & surfaces)
{
    SurfaceSorter::sortBySizeWidthAsc(surfaces);
}
void Sorter::sortByLengthWidth(std::vector<Form*> & forms)
{
        FormSorter::sortByLengthWidthDesc(forms);
}
void Sorter::sortByLengthWidth(std::vector<Surface*> & surfaces)
{
    SurfaceSorter::sortByLengthWidthAsc(surfaces);
}
void Sorter::sortByWidthLength(std::vector<Form*> & forms)
{
    FormSorter::sortByWidthLengthDesc(forms);
}
void Sorter::sortByWidthLength(std::vector<Surface*> & surfaces)
{
    SurfaceSorter::sortByWidthLengthAsc(surfaces);
}


void FormSorter::sortBySizeLengthDesc(std::vector<Form*> & forms)
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getSizeArea() < forms[i+1]->getSizeArea()) ||
                (forms[i]->getSizeArea() == forms[i+1]->getSizeArea() && forms[i]->getLength() < forms[i+1]->getLength()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortBySizeWidthDesc(std::vector<Form*> & forms)
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getSizeArea() < forms[i+1]->getSizeArea()) ||
                (forms[i]->getSizeArea() == forms[i+1]->getSizeArea() && forms[i]->getWidth() < forms[i+1]->getWidth()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortByLengthWidthDesc(std::vector<Form*> & forms) //same as sortByLengthSize but faster
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getLength() < forms[i+1]->getLength()) ||
                (forms[i]->getLength() == forms[i+1]->getLength() && forms[i]->getWidth() < forms[i+1]->getWidth()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortByWidthLengthDesc(std::vector<Form*> & forms) //same as sortByWidthSize but faster
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getWidth() < forms[i+1]->getWidth()) ||
                (forms[i]->getWidth() == forms[i+1]->getWidth() && forms[i]->getLength() < forms[i+1]->getLength()) )
                std::swap(forms[i], forms[i+1]);
}

void SurfaceSorter::sortBySizeLengthAsc(std::vector<Surface*> & surfaces)
{
    for(unsigned int j = 0; j < surfaces.size()-1; j++)
        for(unsigned int i = 0; i < surfaces.size()-1; i++)
            if ( (surfaces[i]->getSizeArea() > surfaces[i+1]->getSizeArea()) ||
                 (surfaces[i]->getSizeArea() == surfaces[i+1]->getSizeArea() && surfaces[i]->getLength() > surfaces[i+1]->getLength()) )
                 std::swap(surfaces[i], surfaces[i+1]);
}

void SurfaceSorter::sortBySizeWidthAsc(std::vector<Surface*> & surfaces)
{
    for(unsigned int j = 0; j < surfaces.size()-1; j++)
        for(unsigned int i = 0; i < surfaces.size()-1; i++)
            if ( (surfaces[i]->getSizeArea() > surfaces[i+1]->getSizeArea()) ||
                 (surfaces[i]->getSizeArea() == surfaces[i+1]->getSizeArea() && surfaces[i]->getWidth() > surfaces[i+1]->getWidth()) )
                 std::swap(surfaces[i], surfaces[i+1]);
}

void SurfaceSorter::sortByLengthWidthAsc(std::vector<Surface*> & surfaces)
{
    for(unsigned int j = 0; j < surfaces.size()-1; j++)
        for(unsigned int i = 0; i < surfaces.size()-1; i++)
            if ( (surfaces[i]->getLength() > surfaces[i+1]->getLength()) ||
                 (surfaces[i]->getLength() == surfaces[i+1]->getLength() && surfaces[i]->getWidth() > surfaces[i+1]->getWidth()) )
                 std::swap(surfaces[i], surfaces[i+1]);
}

void SurfaceSorter::sortByWidthLengthAsc(std::vector<Surface*> & surfaces)
{
    for(unsigned int j = 0; j < surfaces.size()-1; j++)
        for(unsigned int i = 0; i < surfaces.size()-1; i++)
            if ( (surfaces[i]->getWidth() > surfaces[i+1]->getWidth()) ||
                 (surfaces[i]->getWidth() == surfaces[i+1]->getWidth() && surfaces[i]->getLength() > surfaces[i+1]->getLength()) )
                 std::swap(surfaces[i], surfaces[i+1]);
}

std::vector<Form*> SurfacePointerCopier::copySurfaces(std::vector<Form*> forms)
{
    return forms;
}

std::vector<Surface*> SurfacePointerCopier::copySurfaces(std::vector<Surface*> surfaces)
{
    return surfaces;
}

Form* SurfacePointerCopier::copySurface(Form* form)
{
    return form;
}

Surface* SurfacePointerCopier::copySurface(Surface* surface)
{
    return surface;
}
