#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat zulfiye("Zulfiye", 2);
		std::cout << zulfiye << std::endl;
		zulfiye.incrementGrade();
		std::cout << zulfiye << std::endl;
		std::cout << "I'm here!" << std::endl;
		zulfiye.incrementGrade();
		std::cout << "AAAA I'm not here!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}


	std::cout << "\n" << std::endl;


	try
	{
		Bureaucrat balim("balim", 150);
		std::cout << balim << std::endl;
		balim.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}


	std::cout << "\n" << std::endl;
	

	try
	{
		Bureaucrat neslihan("neslihan", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}


	std::cout << "\n" << std::endl;


	try
	{
		Bureaucrat emma("Emma", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
