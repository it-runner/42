#include "FragTrap.hpp"

int main()
{
	std::cout << "\n\t===== WELCOME TO THE FRAGTRAP WAR =====\n\n";

	// ClapTrap constructor test
	std::cout << "\n\033[34m=== Creating ClapTrap objects ===\033[0m\n";
	ClapTrap clap1("Clappy");

	// constructor and inheritance test
	std::cout << "\n\033[34m=== Creating FragTrap objects ===\033[0m\n";

	std::cout << "\n";
	std::cout << "\n";

	FragTrap frag1("Fraggy1");
	FragTrap frag2("Fraggy2");

	// initial attribute test
	std::cout << "\n\033[34m=== Initial attributes ===\033[0m\n";
	std::cout << "FragTrap" << frag1.getName() << " has " << frag1.getHitPoints() << " HP, "
			  << frag1.getEnergyPoints() << " EP, and " << frag1.getAttackDamage()
			  << " AD\n";
	std::cout << "FragTrap" << frag2.getName() << " has " << frag2.getHitPoints() << " HP, "
			  << frag2.getEnergyPoints() << " EP, and " << frag2.getAttackDamage()
			  << " AD\n";

	// attack test
	std::cout << "\n\033[34m=== Testing attack ===\033[0m\n";

	frag1.attack(frag2.getName());
	frag2.takeDamage(30);
	frag2.attack(frag1.getName());
	frag1.takeDamage(30);
	frag1.attack("Somebody");
	for (int i = 0; i < 102; i++)
		frag2.attack("Target");

	// repair test
	std::cout << "\n\033[34m=== Testing repair ===\033[0m\n";
	clap1.beRepaired(500);
	frag1.beRepaired(1);
	frag1.beRepaired(500);

	// highFivesGuys test
	std::cout << "\n\033[34m=== Testing highFivesGuys ===\033[0m\n";
	frag1.highFivesGuys();
	frag2.highFivesGuys();

	// copy test
	std::cout << "\n\033[34m=== Testing copy ===\033[0m\n";
	FragTrap frag3(frag1);
	frag3.attack("Shrek");

	// assignment test
	std::cout << "\n\033[34m=== Testing assignment ===\033[0m\n";
	FragTrap frag4("Temporary");
	frag4 = frag2;
	frag4.attack("Shrek");

	// destructor test (should be in reverse order)
	std::cout << "\n\033[34m=== Objects will be destroyed now ===\033[0m\n";
	return 0;
}
