#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// ====================================================================
// Orthodox Canonical Form elements
// ====================================================================

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// ====================================================================
// subject functions:
// ====================================================================

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
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

void PresidentialPardonForm::executeAction() const {
	std::cout << "\033[38;5;46m" << _target 
			  << " has been pardoned by Zaphod Beeblebrox!\033[0m\n";
}
