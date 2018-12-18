#include "formsorter.hpp"
#include "form.hpp"
void Sorter::sortBySizeLength(std::vector<std::shared_ptr<Form> > & forms)
{
    FormSorter::sortBySizeLengthDesc(forms);
}
void Sorter::sortBySizeLength(std::vector<std::shared_ptr<Surface> > & surfaces)
{
    SurfaceSorter::sortBySizeLengthAsc(surfaces);
}
void Sorter::sortBySizeWidth(std::vector<std::shared_ptr<Form> > & forms)
{
    FormSorter::sortBySizeWidthDesc(forms);
}
void Sorter::sortBySizeWidth(std::vector<std::shared_ptr<Surface> > & surfaces)
{
    SurfaceSorter::sortBySizeWidthAsc(surfaces);
}
void Sorter::sortByLengthWidth(std::vector<std::shared_ptr<Form> > & forms)
{
        FormSorter::sortByLengthWidthDesc(forms);
}
void Sorter::sortByLengthWidth(std::vector<std::shared_ptr<Surface> > & surfaces)
{
    SurfaceSorter::sortByLengthWidthAsc(surfaces);
}
void Sorter::sortByWidthLength(std::vector<std::shared_ptr<Form> > & forms)
{
    FormSorter::sortByWidthLengthDesc(forms);
}
void Sorter::sortByWidthLength(std::vector<std::shared_ptr<Surface> > & surfaces)
{
    SurfaceSorter::sortByWidthLengthAsc(surfaces);
}


void FormSorter::sortBySizeLengthDesc(std::vector<std::shared_ptr<Form> > & forms)
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getSizeArea() < forms[i+1]->getSizeArea()) ||
                (forms[i]->getSizeArea() == forms[i+1]->getSizeArea() && forms[i]->getLength() < forms[i+1]->getLength()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortBySizeWidthDesc(std::vector<std::shared_ptr<Form> > & forms)
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getSizeArea() < forms[i+1]->getSizeArea()) ||
                (forms[i]->getSizeArea() == forms[i+1]->getSizeArea() && forms[i]->getWidth() < forms[i+1]->getWidth()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortByLengthWidthDesc(std::vector<std::shared_ptr<Form> > & forms) //same as sortByLengthSize but faster
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getLength() < forms[i+1]->getLength()) ||
                (forms[i]->getLength() == forms[i+1]->getLength() && forms[i]->getWidth() < forms[i+1]->getWidth()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortByWidthLengthDesc(std::vector<std::shared_ptr<Form> > & forms) //same as sortByWidthSize but faster
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getWidth() < forms[i+1]->getWidth()) ||
                (forms[i]->getWidth() == forms[i+1]->getWidth() && forms[i]->getLength() < forms[i+1]->getLength()) )
                std::swap(forms[i], forms[i+1]);
}

void SurfaceSorter::sortBySizeLengthAsc(std::vector<std::shared_ptr<Surface> > & surfaces)
{
    for(unsigned int j = 0; j < surfaces.size()-1; j++)
        for(unsigned int i = 0; i < surfaces.size()-1; i++)
            if ( (surfaces[i]->getSizeArea() > surfaces[i+1]->getSizeArea()) ||
                 (surfaces[i]->getSizeArea() == surfaces[i+1]->getSizeArea() && surfaces[i]->getLength() > surfaces[i+1]->getLength()) )
                 std::swap(surfaces[i], surfaces[i+1]);
}

void SurfaceSorter::sortBySizeWidthAsc(std::vector<std::shared_ptr<Surface> > & surfaces)
{
    for(unsigned int j = 0; j < surfaces.size()-1; j++)
        for(unsigned int i = 0; i < surfaces.size()-1; i++)
            if ( (surfaces[i]->getSizeArea() > surfaces[i+1]->getSizeArea()) ||
                 (surfaces[i]->getSizeArea() == surfaces[i+1]->getSizeArea() && surfaces[i]->getWidth() > surfaces[i+1]->getWidth()) )
                 std::swap(surfaces[i], surfaces[i+1]);
}

void SurfaceSorter::sortByLengthWidthAsc(std::vector<std::shared_ptr<Surface> > & surfaces)
{
    for(unsigned int j = 0; j < surfaces.size()-1; j++)
        for(unsigned int i = 0; i < surfaces.size()-1; i++)
            if ( (surfaces[i]->getLength() > surfaces[i+1]->getLength()) ||
                 (surfaces[i]->getLength() == surfaces[i+1]->getLength() && surfaces[i]->getWidth() > surfaces[i+1]->getWidth()) )
                 std::swap(surfaces[i], surfaces[i+1]);
}

void SurfaceSorter::sortByWidthLengthAsc(std::vector<std::shared_ptr<Surface> > & surfaces)
{
    for(unsigned int j = 0; j < surfaces.size()-1; j++)
        for(unsigned int i = 0; i < surfaces.size()-1; i++)
            if ( (surfaces[i]->getWidth() > surfaces[i+1]->getWidth()) ||
                 (surfaces[i]->getWidth() == surfaces[i+1]->getWidth() && surfaces[i]->getLength() > surfaces[i+1]->getLength()) )
                 std::swap(surfaces[i], surfaces[i+1]);
}

void SurfaceSorter::insertIntoCorrectPlaceBySizeLength(std::vector<std::shared_ptr<Surface> > & surfaces, std::shared_ptr<Surface> surface)
{
	for (std::vector<std::shared_ptr<Surface> >::iterator it = surfaces.begin(); it != surfaces.end(); it++)
	{
		if ((*it)->getSizeArea() > surface->getSizeArea() || ((*it)->getSizeArea() == surface->getSizeArea() && (*it)->getLength() > surface->getLength()))
		{
			surfaces.insert(it, surface);
			return;
		}
	}
	surfaces.push_back(surface);
}

void SurfaceSorter::insertIntoCorrectPlaceBySizeWidth(std::vector<std::shared_ptr<Surface> > & surfaces, std::shared_ptr<Surface> surface)
{
	for (std::vector<std::shared_ptr<Surface> >::iterator it = surfaces.begin(); it != surfaces.end(); it++)
	{
		if ((*it)->getSizeArea() > surface->getSizeArea() || ((*it)->getSizeArea() == surface->getSizeArea() && (*it)->getWidth() > surface->getWidth()))
		{
			surfaces.insert(it, surface);
			return;
		}
	}
	surfaces.push_back(surface);
}

void SurfaceSorter::insertIntoCorrectPlaceByWidthLength(std::vector<std::shared_ptr<Surface> > & surfaces, std::shared_ptr<Surface> surface)
{
	for (std::vector<std::shared_ptr<Surface> >::iterator it = surfaces.begin(); it != surfaces.end(); it++)
	{
		if ((*it)->getWidth() > surface->getWidth() || ((*it)->getWidth() == surface->getWidth() && (*it)->getLength() > surface->getLength()))
		{
			surfaces.insert(it, surface);
			return;
		}
	}
	surfaces.push_back(surface);
}

void SurfaceSorter::insertIntoCorrectPlaceByLengthWidth(std::vector<std::shared_ptr<Surface> > & surfaces, std::shared_ptr<Surface> surface)
{
	for (std::vector<std::shared_ptr<Surface> >::iterator it = surfaces.begin(); it != surfaces.end(); it++)
	{
		if ((*it)->getLength() > surface->getLength() || ((*it)->getLength() == surface->getLength() && (*it)->getWidth() > surface->getWidth()))
		{
			surfaces.insert(it, surface);
			return;
		}
	}
	surfaces.push_back(surface);
}

std::vector<std::shared_ptr<Form> > SurfacePointerCopier::copySurfaces(std::vector<std::shared_ptr<Form> > forms)
{
    //TODO (when necessary)
    //Create new vector with shared_ptr<Form> and push new Form with parametrs from 'forms'
    //like for(a : forms)
    //std::shared_ptr<Form> form (new Form (l, w, b))
    // newVector.push_back(form)
    return forms;
}

std::vector<std::shared_ptr<Surface> > SurfacePointerCopier::copySurfaces(std::vector<std::shared_ptr<Surface> > surfaces)
{
    return surfaces;
}

std::shared_ptr<Form> SurfacePointerCopier::copySurface(std::shared_ptr<Form> form)
{
    return form;
}

std::shared_ptr<Surface> SurfacePointerCopier::copySurface(std::shared_ptr<Surface> surface)
{
    return surface;
}
