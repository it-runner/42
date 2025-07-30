#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;			// Target for robotomy
		RobotomyRequestForm();			// default constructor (not used)

	public:
		RobotomyRequestForm(const std::string& target);							// constructor
		RobotomyRequestForm(const RobotomyRequestForm& other);					// copy constructor
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);		// copy assignment operator
		~RobotomyRequestForm();													// destructor

		void execute(const Bureaucrat &executor) const;							// execute
		void executeAction() const;												// execute Action
};

#endif
