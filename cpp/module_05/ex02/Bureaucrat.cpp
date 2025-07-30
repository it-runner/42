#include "Bureaucrat.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================

Bureaucrat::Bureaucrat(std::string name, int grade) 						// constructor
	: _name(name), _grade(grade) {
		if (grade < _MAX_GRADE)
			throw GradeTooHighException();
		if (grade > _MIN_GRADE)
			throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)								// copy constructor
		: _name(other._name), _grade(other._grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {				// copy assignment operator
	if (this != &other) {
		// _name can't be assigned because it's const
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {													// destructor
	std::cout << "\033[1;31mBureaucrat destructor called\033[0m\n";
}

// ====================================================================
// others:
// ====================================================================

Bureaucrat Bureaucrat::cloneWithNewName(const std::string& newName) const {	// my copy "constructor"
	return Bureaucrat(newName, _grade);
}

// ====================================================================
// subject functions:
// ====================================================================

std::string	Bureaucrat::getName() const {									// getter (name)
	return _name;
}

int	Bureaucrat::getGrade() const {											// getter (grade)
	return _grade;
}

void Bureaucrat::incrementGrade() {											// incrementing the grade
	if (_grade - 1 < _MAX_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {											// decrementing the grade
	if (_grade + 1 > _MIN_GRADE)
		throw GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {			// insertion operator
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
  return os;
}

void Bureaucrat::signForm(AForm &formToSign) {								// sign form
	try {
		formToSign.beSigned(*this);
		std::cout << _name << " (" << _grade << ") signed " << formToSign.getName() << "\n";
	} catch (std::exception &e) {
		std::cout << _name << " (" << _grade << ") couldn't sign " << formToSign.getName()
				<< " because " << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(AForm const &form) {							// execute form
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
}

// ====================================================================
// exception classes:
// ====================================================================

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "\033[38;5;230mGrade is too high! Maximum grade is 1 (bureaucrat exception)\033[0m\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "\033[38;5;230mGrade is too low! Minimum grade is 150 (bureaucrat exception)\033[0m\n";
}
