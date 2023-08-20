#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "------------test 1----------" << std::endl;

    Bureaucrat b("othmane", 10);
    ShrubberyCreationForm f("form1");
    b.signForm(f);
    try
    {
        f.apply_execute(b);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << f;
}
