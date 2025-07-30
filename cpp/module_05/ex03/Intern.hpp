#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
	private:
		Intern(const Intern& other);									// copy constructor
		Intern& operator=(const Intern& other);							// copy assignment operator

	public:
		Intern();														// constructor
		~Intern();														// destructor

		AForm* makeForm(const std::string& formName, const std::string& target) const;

		class UnknownFormException : public std::exception {			// nested exception class
			public:
				const char* what() const throw();
		};

};

#endif
