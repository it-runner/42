#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// ====================================================================
// subject functions:
// ====================================================================

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
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

void RobotomyRequestForm::executeAction() const {
	std::cout << "\033[38;5;208m* LOUD DRILLING NOISES *\033[0m\n";
	
	// Seed random number generator - C++98 compatible
	std::time_t current_time = std::time(NULL);
	if (current_time == -1) {
		std::cerr << "Error getting time for random seed\n";
		return;
	}
	std::srand(std::time(NULL) + getpid());
	
	if (std::rand() % 2) {
		std::cout << _target << " has been robotomized successfully!\n";
	} else {
		std::cout << "Robotomy of " << _target << " failed...\n";
	}
}
