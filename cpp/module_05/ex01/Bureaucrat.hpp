#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		enum 				{_MAX_GRADE = 1};
		enum			 	{_MIN_GRADE = 150};
		Bureaucrat();														// default constructor (not used in this project), part of orthodox canonical form

	public:
		Bureaucrat(std::string name, int grade);							// constructor
		Bureaucrat(const Bureaucrat& other);								// copy constructor
		Bureaucrat &operator=(const Bureaucrat &copy);						// copy assignment operator
		~Bureaucrat();														// destructor

		Bureaucrat cloneWithNewName(const std::string& newName) const;		// member function (my copy "constructor") returns new Bureaucrat object

		std::string getName() const;										// getter (name)
		int getGrade() const;												// getter (grade)
		void incrementGrade();												// incrementing the grade
		void decrementGrade();												// decrementing the grade

		/* subject function (This function must call Form::beSigned() to attempt to sign the form): */
		void signForm(Form &formToSign);

		class GradeTooHighException : public std::exception {				// nested exception class
			public:
				virtual const char* what() const throw();					// throw = noexcept (C++11) - no exception is thrown
		};

		class GradeTooLowException : public std::exception {				// nested exception class
			public:
				virtual const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);			// insertion operator
/* "<name>, bureaucrat grade <grade>. */

#endif
