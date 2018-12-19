#ifndef FORM_HPP_INCLUDED
#define FORM_HPP_INCLUDED
#include "edgebanding.hpp"
#include "dimension.hpp"
#include "headers.hpp"
class Form : public Dimension, public EdgeBanding {
    protected: unsigned int ID;
    protected: bool swapAble;
    protected: FormType type;

public: Form(unsigned short int length, unsigned short int width, char * banding);
		
    //setters
    public: void setID(unsigned int ID);
    public: void setSwapAbleStatus(bool status);
    public: void setType(FormType type);
    //getters
    public: unsigned int getID();
    public: bool isSwapAble();
    public: FormType getFormType();

    public: bool isForm()
    {
        return true;
    }
};

class FormSwapAble : public Form {
public: FormSwapAble(unsigned short int length, unsigned short int width, char * banding);
};


#endif // FORM_HPP_INCLUDED
