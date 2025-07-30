#include "Bureaucrat.hpp"

int main() {

	// FORM 1
	std::cout << "\n\033[38;5;154m	############## Form Test 1 CEO ##############\033[0m\n";
	try {
		Form taxForm("Tax Form 1", 50, 75);
		std::cout << taxForm << "\n";
		std::cout << "---------------------------------\n";
		Bureaucrat clerk("Clerk Rebecca", 60);
		Bureaucrat CEO("CEO Warren", 40);
		clerk.signForm(taxForm);
		CEO.signForm(taxForm);
		std::cout << taxForm << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";

	// FORM 2
	std::cout << "\n\033[38;5;154m	############## Form Test 2 CEO ##############\033[0m\n";
	try {
		Form taxForm("Tax Form 2", 10, 75);
		std::cout << taxForm << "\n";
		std::cout << "---------------------------------\n";
		Bureaucrat clerk("clerk Frank", 60);
		Bureaucrat boss("CEO Patricia", 1);
		clerk.signForm(taxForm);
		boss.signForm(taxForm);
		std::cout << taxForm << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";

	// FORM 3
	std::cout << "\n\033[38;5;154m	############## Form Test 3 clerk ##############\033[0m\n";
	try {
		Form taxForm("Tax Form 3", 150, 75);
		std::cout << taxForm << "\n";
		std::cout << "---------------------------------\n";
		Bureaucrat clerk("clerk George", 150);
		Bureaucrat boss("CEO Will", 1);
		clerk.signForm(taxForm);
		boss.signForm(taxForm);
		std::cout << taxForm << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";

	// FORM 4
	std::cout << "\n\033[38;5;154m	############## Form Test 4 clerk ##############\033[0m\n";
	try {
		Form taxForm("Tax Form 4", 150, 75);
		std::cout << taxForm << "\n";
		std::cout << "---------------------------------\n";
		Bureaucrat clerk("clerk George", 150);
		Bureaucrat boss("CEO Will", 1);
		clerk.signForm(taxForm);
		boss.signForm(taxForm);
		std::cout << taxForm << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";

	// FORM 5
	std::cout << "\n\033[38;5;154m	############## Form Test 5 too high ##############\033[0m\n";
	try {
		Form taxForm("Tax Form 5", 0, 75);
		std::cout << taxForm << "\n";
		std::cout << "---------------------------------\n";
		Bureaucrat clerk("clerk James", 20);
		Bureaucrat boss("CEO Linda", 1);
		clerk.signForm(taxForm);
		boss.signForm(taxForm);
		std::cout << taxForm << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";

	// FORM 6
	std::cout << "\n\033[38;5;154m	############## Form Test 6 too low ##############\033[0m\n";
	try {
		Form taxForm("Tax Form 5", 151, 75);
		std::cout << taxForm << "\n";
		std::cout << "---------------------------------\n";
		Bureaucrat clerk("clerk James", 150);
		Bureaucrat boss("CEO Linda", 1);
		clerk.signForm(taxForm);
		boss.signForm(taxForm);
		std::cout << taxForm << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	// FORM 7 - Already signed form
	std::cout << "\n\033[38;5;154m	############## Form Test 7 - already signed ##############\033[0m\n";
	try {
		Form taxForm("Tax Form 4", 50, 75);
		Bureaucrat boss("CEO Will", 1);
		std::cout << taxForm << "\n";
		std::cout << "---------------------------------\n";
		boss.signForm(taxForm);
		std::cout << taxForm << "\n";
		boss.signForm(taxForm);
		std::cout << taxForm << "\n";
	} catch (std::exception& e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n";

	return 0;
}
