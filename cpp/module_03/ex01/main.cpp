#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n\t===== WELCOME TO THE SCAVTRAP WAR =====\n\n";
	
	// ClapTrap constructor test
	std::cout << "\n\033[34m=== Creating ClapTrap objects ===\033[0m\n";
	ClapTrap clap1("Clappy");

	// constructor and inheritance test
	std::cout << "\n\033[34m=== Creating ScavTrap objects ===\033[0m\n";

	std::cout << "\n";
	std::cout << "\n";

	ScavTrap scav1("Guardian");
	ScavTrap scav2("Protector");
	
	// initial attribute test
	std::cout << "\n\033[34m=== Initial attributes ===\033[0m\n";
	std::cout << "ScavTrap" << scav1.getName() << " has " << scav1.getHitPoints() << " HP, "
			  << scav1.getEnergyPoints() << " EP, and " << scav1.getAttackDamage()
			  << " AD\n";
	std::cout << "ScavTrap" << scav2.getName() << " has " << scav2.getHitPoints() << " HP, "
			  << scav2.getEnergyPoints() << " EP, and " << scav2.getAttackDamage()
			  << " AD\n";
	
	// attack test
	std::cout << "\n\033[34m=== Testing attack ===\033[0m\n";
	scav1.attack(scav2.getName());
	scav2.takeDamage(20);
	scav2.attack(scav1.getName());
	scav1.takeDamage(20);
	scav1.attack("Intruder");
	for (int i = 0; i < 52; i++)
		scav2.attack("Enemy");

	// repair test
	std::cout << "\n\033[34m=== Testing repair ===\033[0m\n";
	clap1.beRepaired(500);
	scav1.beRepaired(5);
	scav1.takeDamage(3);
	scav1.beRepaired(1);
	
	// guardGate test
	std::cout << "\n\033[34m=== Testing guardGate ===\033[0m\n";
	scav1.guardGate();
	scav1.guardGate();
	
	// copy test
	std::cout << "\n\033[34m=== Testing copy ===\033[0m\n";
	ScavTrap scav3(scav1);
	scav3.attack("Copy Target");
	
	// assignment test
	std::cout << "\n\033[34m=== Testing assignment ===\033[0m\n";
	ScavTrap scav4("Temporary");
	scav4 = scav2;
	scav4.attack("Assigned Target");
	
	// destructor test (should be in reverse order)
	std::cout << "\n\033[34m=== Objects will be destroyed now ===\033[0m\n";
	return 0;
}
