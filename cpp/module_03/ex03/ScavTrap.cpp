#include "ScavTrap.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================
ScavTrap::ScavTrap() : ClapTrap(), _guarding_gate(false)							// default constructor
{
	this->name = "ScavyUnnamed";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Default Constructor for " << this->name << " called\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _guarding_gate(false)			// constructor
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Constructor for " << this->name << " called\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)							// copy constructor
{
	this->_guarding_gate = copy._guarding_gate;
	std::cout << "ScavTrap Copy Constructor for " << this->name << " called\n";
}

// Overloaded Operators
ScavTrap &ScavTrap::operator=(const ScavTrap &other)								// copy assignment operator
{
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	this->_guarding_gate = other._guarding_gate;
	std::cout << "ScavTrap copy assignment operator called\n";
	return *this;
}

ScavTrap::~ScavTrap()																// destructor
{
	std::cout << "ScavTrap Destructor for " << this->name << " called\n";
}

// ====================================================================
// subject functions:
// ====================================================================

// attack
void	ScavTrap::attack(const std::string &target)									// attack function
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "\033[32mScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\033[0m\n";
		this->energyPoints--;
	}
	else if (this->energyPoints <= 0) {
		std::cout << "\033[31mScavTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left.\033[0m\n";
		return;
	}
	else {
		std::cout << "\033[31mScavTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m\n";
		return;
	}
}

// repair
void	ScavTrap::beRepaired(unsigned int amount)									// repair function
{
	if (this->energyPoints > 0 && this->hitPoints > 0 && this->hitPoints + amount <= getMaxHitPoints())
	{
		this->hitPoints += amount;
		std::cout << "ScavTrap " << this->name << " repaired itself and gained " << amount << " of hit points, now he has " << this->hitPoints << " hit points.\n";
		this->energyPoints--;
	}
	else if (this->energyPoints <= 0) {
		std::cout << "\033[31mScavTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m\n";
		return;
	}
	else if (this->hitPoints <= 0) {
		std::cout << "\033[31mScavTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m\n";
		return;
	}
	else {
		std::cout << "\033[33mScavTrap " << this->name << " can't be repaired to have more than " << getMaxHitPoints() << " hit points. He has been repaired to "<< getMaxHitPoints() << " hit points.\033[0m\n";
		this->hitPoints = getMaxHitPoints();
		this->energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->_guarding_gate == false)
	{
		this->_guarding_gate = true;
		std::cout << "ScavTrap " << this->name << " is now guarding the gate.\n";
	}
	else
		std::cout << "\033[33mScavTrap " << this->name << " is already guarding the gate.\033[0m\n";
}

unsigned int ScavTrap::getMaxHitPoints() { return 100; }
