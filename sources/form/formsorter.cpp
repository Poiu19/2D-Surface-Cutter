#include "formsorter.hpp"
#include "form.hpp"
void FormSorter::sortBySizeLength(std::vector<Form*> & forms)
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getSizeArea() < forms[i+1]->getSizeArea()) ||
                (forms[i]->getSizeArea() == forms[i+1]->getSizeArea() && forms[i]->getLength() < forms[i+1]->getLength()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortBySizeWidth(std::vector<Form*> & forms)
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getSizeArea() < forms[i+1]->getSizeArea()) ||
                (forms[i]->getSizeArea() == forms[i+1]->getSizeArea() && forms[i]->getWidth() < forms[i+1]->getWidth()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortByLengthWidth(std::vector<Form*> & forms) //same as sortByLengthSize but faster
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getLength() < forms[i+1]->getLength()) ||
                (forms[i]->getLength() == forms[i+1]->getLength() && forms[i]->getWidth() < forms[i+1]->getWidth()) )
                std::swap(forms[i], forms[i+1]);
}

void FormSorter::sortByWidthLength(std::vector<Form*> & forms) //same as sortByWidthSize but faster
{
    for(unsigned int j = 0; j < forms.size()-1; j++)
        for(unsigned int i = 0; i < forms.size()-1; i++)
            if( (forms[i]->getWidth() < forms[i+1]->getWidth()) ||
                (forms[i]->getWidth() == forms[i+1]->getWidth() && forms[i]->getLength() < forms[i+1]->getLength()) )
                std::swap(forms[i], forms[i+1]);
}

std::vector<Form*> FormPointerCopier::copyForms(std::vector<Form*> forms)
{
    return forms;
}

Form* FormPointerCopier::copyForm(Form* form)
{
    return form;
}
