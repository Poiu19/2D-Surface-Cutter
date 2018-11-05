#include "headers.hpp"
using namespace std;

int main()
{
    Step * a = (new Step());
    Step * aa = (a->createChildStep());
    Step * aaa = (aa->createChildStep());
    Step * b = a->createChildStep();
    Step * c = a->createChildStep();
    cout << "[A] Step::" << a << endl;
    delete a;
    a = nullptr;
    cout << "[A] Step::" << a << endl;
    Form * form1 = new Form(100, 200, 1111);
    FormSwapAble * form2 = new FormSwapAble(10, 20, 1011);
    cout << "Form1: " << form1->getFormType() << ", " << form1->getSwapAbleStatus() << endl;
    cout << "Form2: " << form2->getFormType() << ", " << form2->getSwapAbleStatus() << endl;
    FormController controller;
    std::vector<Form*> forms;
    forms.push_back(form1);
    forms.push_back(form2);
    controller.setupAllForms(forms);
    std::cout << "Form1 ID: " << form1->getID() << endl;
    std::cout << "Form2 ID: " << form2->getID() << endl;
    return 0;
}
