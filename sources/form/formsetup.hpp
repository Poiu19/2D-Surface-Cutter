#ifndef FORMCONTROLLER_HPP_INCLUDED
#define FORMCONTROLLER_HPP_INCLUDED
#include <memory>
#include <algorithm>
#include "form.hpp"
class FormSetup {
    public: static void setSize(std::shared_ptr<Form> form);
    private: static float getLengthInMeters(std::shared_ptr<Form> form);
    private: static float getWidthInMeters(std::shared_ptr<Form> form);
    public: static void setID(std::shared_ptr<Form> form, unsigned int ID);
    public: static void setIDToAll(std::vector<std::shared_ptr<Form> > Forms, unsigned int startID = 0);
    public: static void setSizeToAll(std::vector<std::shared_ptr<Form> > Forms);
    public: static void setupAllForms(std::vector<std::shared_ptr<Form> > Forms);
};

#endif // FORMCONTROLLER_HPP_INCLUDED
