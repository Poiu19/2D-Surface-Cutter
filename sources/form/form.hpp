#ifndef FORM_HPP_INCLUDED
#define FORM_HPP_INCLUDED
#include "../headers.hpp"
#include "../generalconverters.hpp"
#include "../dimension.hpp"
class Form : public Dimension {
    protected: unsigned int ID;
    protected: char * bordering;
    protected: float formSize;
    protected: bool swapAble;
    protected: Form_Type type;

    public: Form(unsigned short int length, unsigned short int width, char * bordering = StringConverter::strToChar("0000"));

    //setters
    public: void setID(unsigned int ID);
    public: void setLength(unsigned short int length);
    public: void setWidth(unsigned short int width);
    public: void setBordering(char * bordering);
    public: void setSwapAbleStatus(bool status);
    public: void setType(Form_Type type);
    //getters
    public: unsigned int getID();
    public: unsigned short int getLength();
    public: unsigned short int getWidth();
    public: char * getBordering();
    public: bool getSwapAbleStatus();
    public: Form_Type getFormType();
};

class FormSwapAble : public Form {
    public: FormSwapAble(unsigned short int length, unsigned short int width, char * bordering = StringConverter::strToChar("0000"));
};


#endif // FORM_HPP_INCLUDED
