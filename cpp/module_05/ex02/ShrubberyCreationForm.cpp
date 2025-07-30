#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include "Bureaucrat.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// ====================================================================
// subject functions:
// ====================================================================

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!this->getIsSigned()) {
		std::cout << executor.getName() << "(" << executor.getGrade() << ") cannot execute " << this->getName() << " because ";
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		std::cout << executor.getName() << "(" << executor.getGrade() << ") cannot execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
		
	this->executeAction();
}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	
	if (!outfile.is_open()) {
		throw std::runtime_error("Failed to create shrubbery file");
	}

	outfile <<
		"           mae&&& &&  & &&\n"
		"      && &\\/&\\|& ()|/ @, &&\n"
		"      &\\/(/&/&||/& /_/)_&/_&\n"
		"   &() &\\/&|()|/&\\/ '%\" & ()\n"
		"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
		"&&   && & &| &| /& & % ()& /&&\n"
		" ()&_---()&\\&\\|&&-&&--%---()~\n"
		"     &&     \\|||\n"
		"             |||\n"
		"             |||\n"
		"             |||\n"
		"       , -=-~  .-^- _\n\n\n"

		"           mae&&& &&  & &&\n"
		"      && &\\/&\\|& ()|/ @, &&\n"
		"      &\\/(/&/&||/& /_/)_&/_&\n"
		"   &() &\\/&|()|/&\\/ '%\" & ()\n"
		"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
		"&&   && & &| &| /& & % ()& /&&\n"
		" ()&_---()&\\&\\|&&-&&--%---()~\n"
		"     &&     \\|||\n"
		"             |||\n"
		"             |||\n"
		"             |||\n"
		"       , -=-~  .-^- _\n\n\n"

		"           mae&&& &&  & &&\n"
		"      && &\\/&\\|& ()|/ @, &&\n"
		"      &\\/(/&/&||/& /_/)_&/_&\n"
		"   &() &\\/&|()|/&\\/ '%\" & ()\n"
		"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
		"&&   && & &| &| /& & % ()& /&&\n"
		" ()&_---()&\\&\\|&&-&&--%---()~\n"
		"     &&     \\|||\n"
		"             |||\n"
		"             |||\n"
		"             |||\n"
		"       , -=-~  .-^- _\n\n\n";

	outfile.close();
	std::cout << "\033[38;5;46mShrubbery has been planted at " << _target << "!\033[0m\n";
}
