#include "formsorter.hpp"
#include "form.hpp"
std::vector<Form*> FormSorter::sortBySizeLength(std::vector<Form*> forms)
{
    for(unsigned int i = 0; i < forms.size()-1; i++)
        if( (forms[i]->getFormSize() < forms[i+1]->getFormSize()) ||
            (forms[i]->getFormSize() == forms[i+1]->getFormSize() && forms[i]->getLength() < forms[i+1]->getLength()) )
            std::swap(forms[i], forms[i+1]);
    return forms;
}

std::vector<Form*> FormSorter::sortBySizeWidth(std::vector<Form*> forms)
{
    for(unsigned int i = 0; i < forms.size()-1; i++)
        if( (forms[i]->getFormSize() < forms[i+1]->getFormSize()) ||
            (forms[i]->getFormSize() == forms[i+1]->getFormSize() && forms[i]->getWidth() < forms[i+1]->getWidth()) )
            std::swap(forms[i], forms[i+1]);
    return forms;

}
std::vector<Form*> FormSorter::sortByLengthSize(std::vector<Form*> forms)
{
    for(unsigned int i = 0; i < forms.size()-1; i++)
        if( (forms[i]->getLength() < forms[i+1]->getLength()) ||
            (forms[i]->getLength() == forms[i+1]->getLength() && forms[i]->getFormSize() < forms[i+1]->getFormSize()) )
            std::swap(forms[i], forms[i+1]);
    return forms;
}

std::vector<Form*> FormSorter::sortByLengthWidth(std::vector<Form*> forms)
{
    for(unsigned int i = 0; i < forms.size()-1; i++)
        if( (forms[i]->getLength() < forms[i+1]->getLength()) ||
            (forms[i]->getLength() == forms[i+1]->getLength() && forms[i]->getWidth() < forms[i+1]->getWidth()) )
            std::swap(forms[i], forms[i+1]);
    return forms;
}

std::vector<Form*> FormSorter::sortByWidthSize(std::vector<Form*> forms)
{
    for(unsigned int i = 0; i < forms.size()-1; i++)
        if( (forms[i]->getWidth() < forms[i+1]->getWidth()) ||
             (forms[i]->getWidth() == forms[i+1]->getWidth() && forms[i]->getFormSize() < forms[i+1]->getFormSize()) )
             std::swap(forms[i], forms[i+1]);
    return forms;
}

std::vector<Form*> FormSorter::sortByWidthLength(std::vector<Form*> forms)
{
    for(unsigned int i = 0; i < forms.size()-1; i++)
        if( (forms[i]->getWidth() < forms[i+1]->getWidth()) ||
            (forms[i]->getWidth() == forms[i+1]->getWidth() && forms[i]->getLength() < forms[i+1]->getLength()) )
            std::swap(forms[i], forms[i+1]);
    return forms;
}
