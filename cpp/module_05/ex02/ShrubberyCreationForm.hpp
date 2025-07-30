#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;			// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
		ShrubberyCreationForm();		// default constructor (not used in this project), part of orthodox canonical form

	public:
		ShrubberyCreationForm(const std::string& target);						// constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& other);				// copy constructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);	// copy assignment operator
		~ShrubberyCreationForm();												// destructor

		void execute(const Bureaucrat &executor) const;							// execute
		void executeAction() const;												// execute Action

};

#endif
