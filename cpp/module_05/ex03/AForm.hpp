#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;				// grade required to sign the AForm
		const int			_gradeToExecute;			// grade required to execute the AForm
		AForm();										// default constructor (not used in this project), part of orthodox canonical form)

	public:
		AForm(const std::string &name, int gradeRToSign, int gradeToExecute);		// constructor
		AForm(const AForm &other);													// copy constructor
		AForm &operator=(const AForm &other);										// copy assignment operator
		virtual ~AForm();															// destructor

		std::string	getName() const;							// getter (name)
		bool	getIsSigned() const;							// getter (isSigned)
		int		getGradeToSign() const;							// getter (gradeToSign)
		int		getGradeToExecute() const;						// getter (gradeToExecute)
		void	beSigned(const Bureaucrat &bureaucrat);			// changes the AForm status to signed if the bureaucrat’s grade is high enough

		virtual void execute(Bureaucrat const &executor) const;	// execute
		virtual void executeAction() const = 0;					// pure virtual function

		class GradeTooHighException : public std::exception {						// nested exception class
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {						// nested exception class
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {						// additional nested exception class
			public:
				const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, const AForm &obj);						// insertion operator

#endif
