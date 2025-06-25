#include "ClapTrap.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================
ClapTrap::ClapTrap()																// default constructor
	: name("ClappyUnnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor for " << this->name << " called\n";
}

ClapTrap::ClapTrap(std::string name)												// constructor
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)					// initialization list
{
	std::cout << "ClapTrap Constructor for " << this->name << " called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)											// copy constructor
	  : name(other.name), 
		hitPoints(other.hitPoints),
		energyPoints(other.energyPoints),
		attackDamage(other.attackDamage) 
{
  std::cout << "ClapTrap Copy constructor for " << this->name << " called\n";
}

/* OR
ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap Copy constructor for " << this->name << " called\n";
	*this = other;
} */

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {								// copy assignment operator
	if (this == &other)
		return *this;
	this->name = other.getName();
	this->hitPoints = other.getHitPoints();
	this->energyPoints = other.getEnergyPoints();
	this->attackDamage = other.getAttackDamage();
	std::cout << "ClapTrap Copy assignment operator for " << this->name << " called\n";
	return *this;
}

ClapTrap::~ClapTrap() {																// destructor
  std::cout << "ClapTrap Destructor for " << this->name << " called\n";
}

// ====================================================================
// getters:
// ====================================================================
std::string ClapTrap::getName() const { return name; }								// getter (name)
int ClapTrap::getHitPoints() const { return hitPoints; }							// getter (hit points)
int ClapTrap::getEnergyPoints() const { return energyPoints; }						// getter (energy points)
int ClapTrap::getAttackDamage() const { return attackDamage; }						// getter (attack damage)

// ====================================================================
// setter:
// ====================================================================
void ClapTrap::setAttackDamage(int amount) { attackDamage = amount; }

// ====================================================================
// subject functions:
// ====================================================================
void	ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
		this->energyPoints--;
	}
	else if (this->energyPoints <= 0) {
		std::cout << "\033[31mClapTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left.\033[0m\n";\
		return;
	}
	else {
		std::cout << "\033[31mClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m\n";
		return;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0 && this->hitPoints + amount <= getMaxHitPoints())
	{
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " of hit points, now he has " << this->hitPoints << " hit points.\n";
		this->energyPoints--;
	}
	else if (this->energyPoints <= 0) {
		std::cout << "\033[31mClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m\n";
		return;
	}
	else if (this->hitPoints <= 0) {
		std::cout << "\033[31mClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m\n";
		return;
	}
	else {
		std::cout << "\033[33mClapTrap " << this->name << " can't be repaired to have more than " << getMaxHitPoints() << " hit points. He has been repaired to "<< getMaxHitPoints() << " hit points.\033[0m\n";
		this->hitPoints = getMaxHitPoints();
		this->energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > amount)
		this->hitPoints -= amount;
	else if (this->hitPoints > 0)
		this->hitPoints = 0;
	else
	{
		return;
	}
	std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, now he has " << this->hitPoints << " hit points.\n";
}

// ====================================================================
// others:
// ====================================================================

void ClapTrap::addHitPoints(int amount) {
	this->hitPoints += amount;
	if (this->hitPoints > 10)
		this->hitPoints = 10;
}

unsigned int ClapTrap::getMaxHitPoints() { return 10; }
