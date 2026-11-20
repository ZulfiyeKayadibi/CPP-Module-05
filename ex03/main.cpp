#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm *rrf;

    rrf = intern.makeForm(
        "presidential pardon", "Bender");

    if (rrf)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    return 0;
}
