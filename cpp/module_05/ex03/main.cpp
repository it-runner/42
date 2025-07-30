#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

// =====================================================================================================
// ==================================== ShrubberyCreationForm tests ====================================
// =====================================================================================================

	std::cout << "\n\033[38;5;176m\t\t\t===== SHRUBBERY TESTS) =====\033[0m\n";
	std::cout << "\n\033[38;5;154m===== ShrubberyCreationForm successful case =====\033[0m\n";
	try {
		Bureaucrat jack("Jack", 100);
		ShrubberyCreationForm form("garden");
		
		jack.signForm(form);
		jack.executeForm(form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== ShrubberyCreationForm too low grade to sign (150 > 145) =====\033[0m\n";
	try {
		Bureaucrat lowRank("LowRank", 150);
		ShrubberyCreationForm form("backyard");
		
		lowRank.signForm(form);					// This should fail
		lowRank.executeForm(form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== ShrubberyCreationForm can sign but too low to execute (140 > 137) =====\033[0m\n";
	try {
		Bureaucrat midRank("MidRank", 140);
		ShrubberyCreationForm form("park");
		
		midRank.signForm(form);					// This should work (140 <= 145)
		midRank.executeForm(form);				// This should fail (140 > 137)
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== ShrubberyCreationForm try to execute unsigned form =====\033[0m\n";
	try {
		Bureaucrat highRank("HighRank", 1);
		ShrubberyCreationForm form("forest");
		
		// Don't sign the form
		highRank.executeForm(form);				// This should fail
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	// ===================================================================================================
	// ==================================== RobotomyRequestForm tests ====================================
	// ===================================================================================================

	std::cout << "\n\033[38;5;176m\t\t\t===== ROBOTOMY TESTS =====\033[0m\n";
	std::cout << "\n\033[38;5;154m===== RobotomyRequestForm successful case =====\033[0m\n";
	try {
		Bureaucrat highRank("Dr. Smith", 1);
		RobotomyRequestForm form("Patient X");
		
		highRank.signForm(form);
		highRank.executeForm(form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== RobotomyRequestForm too low grade to sign (100 > 72) =====\033[0m\n";
	try {
		Bureaucrat midRank("Nurse", 100);
		RobotomyRequestForm form("Patient Y");
		
		midRank.signForm(form);					// This should fail
		midRank.executeForm(form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== RobotomyRequestForm can sign but too low to execute (50 > 45) =====\033[0m\n";
	try {
		Bureaucrat doctor("Doctor", 50);
		RobotomyRequestForm form("Patient Z");
		
		doctor.signForm(form);					// This should work (50 <= 72)
		doctor.executeForm(form);				// This should fail (50 > 45)
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== RobotomyRequestForm try to execute unsigned form =====\033[0m\n";
	try {
		Bureaucrat chief("Chief", 1);
		RobotomyRequestForm form("VIP Patient");
		
		// Don't sign the form
		chief.executeForm(form);				// This should fail
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	// ======================================================================================================
	// ==================================== PresidentialPardonForm tests ====================================
	// ======================================================================================================

	std::cout << "\n\033[38;5;176m\t\t===== PRESIDENTIAL PARDON TESTS =====\033[0m\n";
	std::cout << "\n\033[38;5;154m===== Successful presidential pardon =====\033[0m\n";
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm form("Arthur Dent");
		
		president.signForm(form);
		president.executeForm(form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== Too low grade to sign (30 > 25) =====\033[0m\n";
	try {
		Bureaucrat minister("Minister", 30);
		PresidentialPardonForm form("Ford Prefect");
		
		minister.signForm(form);
		minister.executeForm(form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== Can sign but too low to execute (10 > 5) =====\033[0m\n";
	try {
		Bureaucrat secretary("Secretary", 10);
		PresidentialPardonForm form("Zaphod Beeblebrox");
		
		secretary.signForm(form);
		secretary.executeForm(form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== Try to execute unsigned form =====\033[0m\n";
	try {
		Bureaucrat intern("Intern", 1);
		PresidentialPardonForm form("Marvin");
		
		intern.executeForm(form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	// ===================================================================
	// ========================== INTERN TESTS ===========================
	// ===================================================================

	std::cout << "\n\033[38;5;176m\t\t\t===== INTERN TESTS =====\033[0m\n";
	std::cout << "\n\033[38;5;154m===== Intern creates ShrubberyCreationForm =====\033[0m\n";
	try {
		Intern someRandomIntern;
		AForm* form;
		Bureaucrat sally("Sally", 1);

		form = someRandomIntern.makeForm("shrubbery creation", "home");
		sally.signForm(*form);
		sally.executeForm(*form);
		delete form;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== Intern creates RobotomyRequestForm =====\033[0m\n";
	try {
		Intern someRandomIntern;
		AForm* form;
		Bureaucrat frank("Frank", 1);

		form = someRandomIntern.makeForm("robotomy request", "Bender");
		frank.signForm(*form);
		frank.executeForm(*form);
		delete form;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== Intern creates PresidentialPardonForm =====\033[0m\n";
	try {
		Intern someRandomIntern;
		AForm* form;
		Bureaucrat marvin("Marvin", 1);

		form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		marvin.signForm(*form);
		marvin.executeForm(*form);
		delete form;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\033[38;5;154m===== Intern tries to create unknown form =====\033[0m\n";
	try {
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("unknown form", "target");
		delete form;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	std::cout << "\n\n";

	return 0;
}
