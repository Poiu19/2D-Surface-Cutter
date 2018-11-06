#ifndef STEPSORTER_HPP_INCLUDED
#define STEPSORTER_HPP_INCLUDED
#include <algorithm>
#include "form.hpp"
class FormSorter {
    public: std::vector<Form*> sortBySizeLength(std::vector<Form*> forms);
    public: std::vector<Form*> sortBySizeWidth(std::vector<Form*> forms);
    public: std::vector<Form*> sortByLengthSize(std::vector<Form*> forms);
    public: std::vector<Form*> sortByLengthWidth(std::vector<Form*> forms);
    public: std::vector<Form*> sortByWidthSize(std::vector<Form*> forms);
    public: std::vector<Form*> sortByWidthLength(std::vector<Form*> forms);
};

#endif // STEPSORTER_HPP_INCLUDED
