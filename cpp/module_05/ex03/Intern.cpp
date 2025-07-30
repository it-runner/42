#include "Intern.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================

Intern::Intern() {}																			// constructor

Intern::Intern(const Intern& other) {														// copy constructor
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {											// copy assignment operator
	(void)other;
	return *this;
}

Intern::~Intern() {																			// destructor
	std::cout << "\033[1;31mIntern destructor called\033[0m\n";
}

// ====================================================================
// subject functions:
// ====================================================================

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {		// makeForm
	const std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* form = NULL;

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << "\n";
			switch (i) {
				case 0: form = new ShrubberyCreationForm(target); 
					break;
				case 1: form = new RobotomyRequestForm(target); 
					break;
				case 2: form = new PresidentialPardonForm(target); 
					break;
			}
			return form;
		}
	}

	throw UnknownFormException();
}

// ====================================================================
// exception classes:
// ====================================================================

const char* Intern::UnknownFormException::what() const throw() {
	return "\033[38;5;230mError: Unknown form name\033[0m";
}
