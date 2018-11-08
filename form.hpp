#ifndef FORM_HPP_INCLUDED
#define FORM_HPP_INCLUDED
#include "headers.hpp"
#include "generalconverters.hpp"
class Form {
    protected: unsigned int ID;
    protected: unsigned short int length, width;
    protected: char * bordering;
    protected: float formSize;
    protected: bool swapAble;
    protected: Form_Type type;

    public: Form(unsigned short int length, unsigned short int width, char * bordering = StringConverter::strToChar("0000"));

    //setters
    public: Form * setID(unsigned int ID);
    public: Form * setLength(unsigned short int length);
    public: Form * setWidth(unsigned short int width);
    public: Form * setBordering(char * bordering);
    public: Form * setFormSize(float formSize);
    public: Form * setSwapAbleStatus(bool status);
    public: Form * setType(Form_Type type);
    //getters
    public: unsigned int getID();
    public: unsigned short int getLength();
    public: unsigned short int getWidth();
    public: char * getBordering();
    public: float getFormSize();
    public: bool getSwapAbleStatus();
    public: Form_Type getFormType();
};

class FormSwapAble : public Form {
    public: FormSwapAble(unsigned short int length, unsigned short int width, char * bordering = StringConverter::strToChar("0000"));
};


#endif // FORM_HPP_INCLUDED
