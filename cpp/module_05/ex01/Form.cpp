#include "Form.hpp"
#include "Bureaucrat.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================

Form::Form(const std::string &name, int gradeRToSign, int gradeToExecute)					// constructor
	: _name(name), _isSigned(false), _gradeToSign(gradeRToSign), 
		_gradeToExecute(gradeToExecute) {

		if (gradeRToSign < 1 || gradeToExecute < 1)
			throw Form::GradeTooHighException();
		if (gradeRToSign > 150 || gradeToExecute > 150)
			throw Form::GradeTooLowException();
};

Form::Form(const Form &other) 																// copy constructor
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), 
		_gradeToExecute(other._gradeToExecute) {};

Form &Form::operator=(const Form &other) {													// copy assignment operator
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
};

Form::~Form() {};																			// destructor

// ====================================================================
// subject functions:
// ====================================================================

std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned)
		throw std::logic_error("\033[38;5;230mForm is already signed.\033[0m\n");
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName() 
	<< " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< " | Grade to sign: " << form.getGradeToSign()
	<< " | Grade to execute: " << form.getGradeToExecute();
	return os;
}

// ====================================================================
// exception classes:
// ====================================================================

const char *Form::GradeTooHighException::what() const throw() {
  return ("\033[38;5;230mGrade is too High! (form exception)\033[0m\n");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("\033[38;5;230mGrade is too Low! (form exception)\033[0m\n");
}
