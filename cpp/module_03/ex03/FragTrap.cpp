#include "FragTrap.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================
FragTrap::FragTrap() : ClapTrap("FraggyUnnamed")									// default constructor
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default Constructor for " << this->name << " called\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)								// constructor
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Constructor for " << this->name << " called\n";
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)							// copy constructor
{
	std::cout << "FragTrap Copy Constructor for " << this->name << " called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)								// copy assignment operator
{
	if (this == &other)
	return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "FragTrap copy assignment operator for " << this->name << " called\n";
	return *this;	
}

FragTrap::~FragTrap()																// destructor
{
	std::cout << "FragTrap Destructor for " << this->name << " called\n";
}

// ====================================================================
// subject functions:
// ====================================================================

// attack
void	FragTrap::attack(const std::string &target)									// attack function
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "\033[32mFragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\033[0m\n";
		this->energyPoints--;
	}
	else if (this->energyPoints <= 0) {
		std::cout << "\033[31mFragTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left.\033[0m\n";
		return;
	}
	else {
		std::cout << "\033[31mFragTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m\n";
		return;
	}
}

// repair
void	FragTrap::beRepaired(unsigned int amount)									// repair function
{
	if (this->energyPoints > 0 && this->hitPoints > 0 && this->hitPoints + amount <= getMaxHitPoints())
	{
		this->hitPoints += amount;
		std::cout << "FragTrap " << this->name << " repaired itself and gained " << amount << " of hit points, now he has " << this->hitPoints << " hit points.\n";
		this->energyPoints--;
	}
	else if (this->energyPoints <= 0) {
		std::cout << "\033[31mFragTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m\n";
		return;
	}
	else if (this->hitPoints <= 0) {
		std::cout << "\033[31mFragTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m\n";
		return;
	}
	else {
		std::cout << "\033[33mFragTrap " << this->name << " can't be repaired to have more than " << getMaxHitPoints() << " hit points. He has been repaired to "<< getMaxHitPoints() << " hit points.\033[0m\n";
		this->hitPoints = getMaxHitPoints();
		this->energyPoints--;
	}
}

void	FragTrap::highFivesGuys(void)												// highFivesGuys function
{
	std::cout << "FragTrap "
			  << this->name
			  << ": You want a high five?\n-Yeah!\nHere you go.\n";
}

unsigned int FragTrap::getMaxHitPoints() { return 100; }
