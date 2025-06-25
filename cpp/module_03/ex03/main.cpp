#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n\t===== WELCOME TO THE DIAMONDTRAP WAR =====\n\n";

// ====================================================================
// Testing ClapTrap:
// ====================================================================
	std::cout << "\n\033[38;5;214m=== Testing ClapTrap ===\033[0m\n\n";
	{
		std::cout << "\033[34mConstructor\033[0m\n";
		ClapTrap a("ClapTop");
		ClapTrap b("ClapBot");

		std::cout << "\033[34mTest\033[0m\n";
		a.attack("mutant-killer-washing-mashine-1");
		a.takeDamage(9);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("mutant-killer-washing-mashine-2");
		b.beRepaired(3);
		for (int i = 0; i < 10; i++)
			b.attack("Shrek");
		b.beRepaired(3);
		std::cout << "\033[34mDestructor\033[0m\n";
	}

// ====================================================================
// Testing ScavTrap:
// ====================================================================
	std::cout << "\n\033[38;5;214m=== Testing ScavTrap ===\033[0m\n\n";
	{
		std::cout << "\033[34mConstructor\033[0m\n";
		ScavTrap a("ScavvyA");

		std::cout << "\033[34mTest\033[0m\n";
		std::cout << a.getName() << " has " << a.getHitPoints() << " hit points and " << a.getAttackDamage() << " attack damage and " << "has " << a.getEnergyPoints() << " energy points.\n";
		a.beRepaired(1);
		for (int i = 0; i < 50; i++)
			a.attack("Enemy Soldier2");
		a.beRepaired(3);
		a.takeDamage(4);
		a.beRepaired(30);
		a.guardGate();
		a.guardGate();
		a.guardGate();
		a.attack("Somebody");
		a.attack("ScavTrap-clone");
		a.takeDamage(20);
		std::cout << "\033[34mDestructor\033[0m\n";
	}

// ====================================================================
// Testing FragTrap:
// ====================================================================
	std::cout << "\n\033[38;5;214m=== Testing FragTrap ===\033[0m\n\n";
	{
		std::cout << "\033[34mConstructor\033[0m\n";
		FragTrap a("Mickey Mouse");
		FragTrap b("Goofy");

		std::cout << "\033[34mTest\033[0m\n";
		a.highFivesGuys();
		a.attack("enemy1");
		a.takeDamage(101);
		a.takeDamage(1);
		a.attack("enemy2");
		b.highFivesGuys();
		for(int i = 0; i < 101; i++)
			b.attack("Mr Robot");
		std::cout << "\033[34mDestructor\033[0m\n";
	}

// ====================================================================
// Testing DiamondTrap:
// ====================================================================
	std::cout << "\n\033[38;5;214m=== Testing DiamondTrap ===\033[0m\n\n";
	{
		std::cout << "\033[34mConstructor\033[0m\n";
		DiamondTrap a ("Alien");
		DiamondTrap b("Indiana Jones");
		DiamondTrap c(a);

		std::cout << "\033[34mTest\033[0m\n";
		a.whoAmI();
		a.attack("Terminator");
		b.whoAmI();
		b.attack("Space Ghost");
		a.attack("b.getName()");
		b.takeDamage(30);
		c.whoAmI();
		std::cout << "\033[34mDestructor\033[0m\n";
	}
	return (0);
}
