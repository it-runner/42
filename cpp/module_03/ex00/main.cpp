#include "ClapTrap.hpp"

int main()
{
	std::cout << "\n\t===== WELCOME TO THE CLAPTRAP WAR =====\n\n";

	// ClapTrap constructor test
	std::cout << "\n\033[34m=== Creating ClapTrap objects ===\033[0m\n";

	ClapTrap Monster1("Monster_1");		// create ClapTrap object
	ClapTrap Monster2("Monster_2");		// create ClapTrap object

	// initial attribute test
	std::cout << "\n\033[34m=== Initial attributes ===\033[0m\n";

	std::cout << "ClapTrap" << Monster1.getName() << " has " << Monster1.getHitPoints() << " HP, "
			  << Monster1.getEnergyPoints() << " EP, and " << Monster1.getAttackDamage()
			  << " AD\n";
	std::cout << "ClapTrap" << Monster2.getName() << " has " << Monster2.getHitPoints() << " HP, "
			  << Monster2.getEnergyPoints() << " EP, and " << Monster2.getAttackDamage()
			  << " AD\n";

	std::cout << "\n\033[34m=== Testing attack ===\033[0m\n";

	// attack test
	Monster1.attack("Shrek");
	Monster1.attack(Monster2.getName());
	Monster2.takeDamage(0);

	Monster2.takeDamage(5);
	Monster1.takeDamage(3);
	Monster1.takeDamage(3);

	std::cout << "\n\033[34m=== Testing attack & repair ===\033[0m\n";

	// attack & repair test
	Monster1.beRepaired(5);
	Monster1.attack("some other other robot");
	Monster2.beRepaired(30);
	Monster2.attack("Monster_1");
	Monster1.takeDamage(0);
	for (int i = 0; i < 12; i++)
		Monster2.attack("Rambo");
	Monster2.beRepaired(3);

	// copy test
	std::cout << "\n\033[34m=== Testing copy ===\033[0m\n";
	ClapTrap Monster3(Monster1);
	Monster3.attack("some other robot");

	// assignment test
	std::cout << "\n\033[34m=== Testing assignment ===\033[0m\n";
	ClapTrap Monster4("Monster_4");
	Monster4 = Monster2;
	Monster4.attack("some other robot");

	// destructor test (should be in reverse order)
	std::cout << "\n\033[34m=== Objects will be destroyed now ===\033[0m\n";
	
	return (0);
}
