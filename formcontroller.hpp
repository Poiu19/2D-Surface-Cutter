#ifndef FORMCONTROLLER_HPP_INCLUDED
#define FORMCONTROLLER_HPP_INCLUDED
#include <algorithm>
#include "form.hpp"
class FormSetup {
    public: Form * setSize(Form * form);
    private: float getLengthInMeters(Form * form);
    private: float getWidthInMeters(Form * form);
    public: Form * setID(Form * form, unsigned int ID);
    public: void setIDToAll(std::vector<Form*> Forms, unsigned int startID = 0);
    public: void setSizeToAll(std::vector<Form*> Forms);
    public: void setupAllForms(std::vector<Form*> Forms);
};

#endif // FORMCONTROLLER_HPP_INCLUDED
