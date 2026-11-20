#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

AForm::AForm(const AForm &src)
	: name(src.name), isSigned(src.isSigned),
	  gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &nw)
{
	if (this != &nw)
		this->isSigned = nw.isSigned;
	return *this;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::validateGrade(int value) const
{
	if (value < 1)
		throw GradeTooHighException();
	if (value > 150)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &exec)
{
	if (exec.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	execAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& mineClass)
{
	os << "Form " << mineClass.getName()
		<< ", signed: " << (mineClass.getIsSigned() ? "yes" : "no")
		<< ", grade to sign " << mineClass.getGradeToSign()
		<< ", grade to execute " << mineClass.getGradeToExecute();
	return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "The form is not signed!";
}
