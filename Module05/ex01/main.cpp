#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "------------test 1----------" << std::endl;

    Bureaucrat b("othmane", 13);
    Form f("form1", 131, 13);
    b.signForm(f);
    std::cout << f;

    std::cout << "------------test 2----------" << std::endl;

    Bureaucrat b1("alae", 13);
    Form f1("form1", 11, 13);
    b1.signForm(f1);
    std::cout << f1;
}
