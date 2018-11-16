#ifndef STEPSORTER_HPP_INCLUDED
#define STEPSORTER_HPP_INCLUDED
#include <algorithm>
#include "form.hpp"
class FormSorter {
    public: static std::vector<Form*> sortBySizeLength(std::vector<Form*> forms);
    public: static std::vector<Form*> sortBySizeWidth(std::vector<Form*> forms);
    public: static std::vector<Form*> sortByLengthWidth(std::vector<Form*> forms);
    public: static std::vector<Form*> sortByWidthLength(std::vector<Form*> forms);
};

#endif // STEPSORTER_HPP_INCLUDED
