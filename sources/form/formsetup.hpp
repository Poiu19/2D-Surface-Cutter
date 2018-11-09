#ifndef FORMCONTROLLER_HPP_INCLUDED
#define FORMCONTROLLER_HPP_INCLUDED
#include <algorithm>
#include "form.hpp"
class FormSetup {
    public: static void setSize(Form * form);
    private: static float getLengthInMeters(Form * form);
    private: static float getWidthInMeters(Form * form);
    public: static void setID(Form * form, unsigned int ID);
    public: static void setIDToAll(std::vector<Form*> Forms, unsigned int startID = 0);
    public: static void setSizeToAll(std::vector<Form*> Forms);
    public: static void setupAllForms(std::vector<Form*> Forms);
};

#endif // FORMCONTROLLER_HPP_INCLUDED
