#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form form_one("1. Form", 50, 25);
	std::cout << form_one << std::endl;

	Bureaucrat zulfiye("Zülfiye", 100);
	zulfiye.signForm(form_one);

	Bureaucrat Balim("Balim", 50);
	Balim.signForm(form_one);
	std::cout << form_one << std::endl;


	std::cout << "\n" << std::endl;
	
	
	try
	{
		Form form_two("2. Form", 0, 25);
		std::cout << form_two << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		Form form_three("3. Form", 50, 151);
		std::cout << form_three << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
