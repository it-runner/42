#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================

AForm::AForm(const std::string &name, int gradeRToSign, int gradeToExecute)						// constructor
	: _name(name), _isSigned(false), _gradeToSign(gradeRToSign), 
		_gradeToExecute(gradeToExecute) {

		if (gradeRToSign < 1 || gradeToExecute < 1)
			throw AForm::GradeTooHighException();
		if (gradeRToSign > 150 || gradeToExecute > 150)
			throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) 																// copy constructor
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), 
		_gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {													// copy assignment operator
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}																				// destructor

// ====================================================================
// subject functions:
// ====================================================================

std::string AForm::getName() const {															//	getter (name)
	return this->_name;
}

bool AForm::getIsSigned() const {																// getter (isSigned)
	return this->_isSigned;
}

int AForm::getGradeToSign() const {																// getter (gradeToSign)
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {															// getter (gradeToExecute)
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {											// changes the AForm status to signed
	if (_isSigned)
		throw std::logic_error("Form is already signed");
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {											// executes the AForm
    if (getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    this->executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {									// insertion operator
	os << "Form: " << form.getName() 
	<< " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< " | Grade to sign: " << form.getGradeToSign()
	<< " | Grade to execute: " << form.getGradeToExecute();
	return os;
}

// ====================================================================
// exception classes:
// ====================================================================

const char *AForm::GradeTooHighException::what() const throw() {
  return "\033[38;5;230mGrade is too High! \033[0m";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "\033[38;5;230mGrade is too Low! \033[0m";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "\033[38;5;230mForm is not signed! \033[0m";
}
