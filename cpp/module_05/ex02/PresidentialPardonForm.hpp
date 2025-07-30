#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		PresidentialPardonForm();  														// default constructor

	public:
		PresidentialPardonForm(const std::string& target);								// constructor
		PresidentialPardonForm(const PresidentialPardonForm& other);					// copy constructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);			// copy assignment operator
		~PresidentialPardonForm();														// destructor

		void execute(const Bureaucrat& executor) const;									// execute
		void executeAction() const;														// execute action
};

#endif
