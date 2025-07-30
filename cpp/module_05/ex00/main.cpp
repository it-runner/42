#include "Bureaucrat.hpp"

int main() {
	std::cout << "\033[38;5;215m\n";
	std::cout << "=========================================================================\n";
	std::cout << "================== Welcome to the Bureaucrat's office! ==================\n";
	std::cout << "=========================================================================\n";
	std::cout << "\n\033[0m";

	// correct:
	std::cout << "\033[38;5;154m	############## George 23 ##############\033[0m\n";
	try {
		Bureaucrat George("George", 23);
		std::cout << George;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// grade too low:
	std::cout << "\n\033[38;5;154m	############## Alice 151 ##############\033[0m\n";
	try {
		Bureaucrat Alice("other", 151);
		std::cout << Alice << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// grade too high:
	std::cout << "\n\033[38;5;154m	############## Peter 0 ##############\033[0m\n";
	try {
		Bureaucrat Peter("Peter", 0);
		std::cout << Peter << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// correct but too high after increment:
	std::cout << "\033[38;5;154m	############## Robert 1 (with increment) ##############\033[0m\n";
	try {
		Bureaucrat Robert("Robert", 1);
		std::cout << Robert;
		Robert.incrementGrade();
		std::cout << Robert;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// correct but too low after decrement:
	std::cout << "\n\033[38;5;154m	############## John 149 (with decrement) ##############\033[0m\n";
	try {
		Bureaucrat John("John", 149);
		std::cout << John;
		John.decrementGrade();
		std::cout << John;
		John.decrementGrade();
		std::cout << John;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// correct but too high after increment with for loop:
	std::cout << "\n\033[38;5;154m	############## Mary 4 (with increment and decrement) ##############\033[0m\n";
	try {
		Bureaucrat Mary("Mary", 4);
		for (int i = 4; i >= 1; i--)
		{
			std::cout << Mary;
			Mary.incrementGrade();
		}
		std::cout << Mary;
		Mary.decrementGrade();
		std::cout << Mary;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// copy constructor:
	std::cout << "\n\033[38;5;154m	############## Copy David 23 -> DavidCopy ##############\033[0m\n";
	try {
		Bureaucrat David("David", 23);
		std::cout << David;
		Bureaucrat DavidCopy = David.cloneWithNewName("DavidCopy");
		std::cout << DavidCopy;
		DavidCopy.incrementGrade();
		std::cout << DavidCopy;
		std::cout << David;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// copy assignment operator:
	std::cout << "\n\033[38;5;154m	############## Copy Assignment Tim 56 -> TimAssign 98 ##############\033[0m\n";
	try {
		Bureaucrat Tim("Tim", 56);
		std::cout << Tim;
		Bureaucrat TimAssign("TimAssign", 98);
		std::cout << TimAssign;
		std::cout << "\033[38;5;178mAssigning Tim to TimAssign...\033[0m\n";
		TimAssign = Tim;
		std::cout << TimAssign;
		TimAssign.incrementGrade();
		std::cout << TimAssign;
		std::cout << Tim;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// true copy
	std::cout << "\n\033[38;5;154m	############## True Copy Sarah 145 -> SarahCopy ##############\033[0m\n";
	std::cout << "\033[38;5;178m_name is const, so you can't change it! ";
	std::cout << "The new object will have the same name as the original ";
	std::cout << "(Sarah instead of SarahCopy).\033[0m\n";
	try {
		Bureaucrat Sarah("Sarah", 145);
		std::cout << Sarah;
		Bureaucrat SarahCopy(Sarah);
		std::cout << SarahCopy;
		SarahCopy.incrementGrade();
		std::cout << SarahCopy;
		std::cout << Sarah;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";

	return 0;
}
