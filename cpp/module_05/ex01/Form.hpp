#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;				// grade required to sign the form
		const int			_gradeToExecute;			// grade required to execute the form
		Form();											// default constructor (not used in this project), part of orthodox canonical form)

	public:
		Form(const std::string &name, int gradeRToSign, int gradeToExecute);	// constructor
		Form(const Form &other);												// copy constructor
		Form &operator=(const Form &other);										// copy assignment operator
		~Form();																// destructor

		std::string	getName() const;					// getter (name)
		bool	getIsSigned() const;					// getter (isSigned)
		int		getGradeToSign() const;					// getter (gradeToSign)
		int		getGradeToExecute() const;				// getter (gradeToExecute)
		void	beSigned(const Bureaucrat &bureaucrat);	// changes the form status to signed if the bureaucrat’s grade is high enough

		class GradeTooHighException : public std::exception {					// nested exception class
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {					// nested exception class
			public:
				const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, const Form &obj);					// insertion operator

#endif
