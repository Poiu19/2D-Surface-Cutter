#ifndef FORM_HPP_INCLUDED
#define FORM_HPP_INCLUDED
#include "edgebanding.hpp"
#include "../generalconverters.hpp"
#include "../headers.hpp"
#include "../dimension.hpp"

class Form : public Dimension, public EdgeBanding {
    protected: unsigned int ID;
    protected: bool swapAble;
    protected: Form_Type type;

    public: Form(unsigned short int length, unsigned short int width, char * banding = StringConverter::strToChar("0000"));

    //setters
    public: void setID(unsigned int ID);
    public: void setSwapAbleStatus(bool status);
    public: void setType(Form_Type type);
    //getters
    public: unsigned int getID();
    public: bool getSwapAbleStatus();
    public: Form_Type getFormType();
};

class FormSwapAble : public Form {
    public: FormSwapAble(unsigned short int length, unsigned short int width, char * banding = StringConverter::strToChar("0000"));
};


#endif // FORM_HPP_INCLUDED
