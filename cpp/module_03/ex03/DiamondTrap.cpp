#include "DiamondTrap.hpp"

// ====================================================================
// Orthodox Canonical Form elements:
// ====================================================================
DiamondTrap::DiamondTrap()															// default constructor
	: ClapTrap("default Claptrap-name"),
	  ScavTrap(),
	  FragTrap(),
	  name("DiamondUnnamed")
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Default Constructor for " << this->name << " called\n";
}

DiamondTrap::DiamondTrap(std::string name)											// constructor
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(),
	  FragTrap(),
	  name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Constructor for " << this->name << " called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
	: ClapTrap(copy), ScavTrap(copy), FragTrap(copy), name(copy.name)				// copy constructor
{
	std::cout << "DiamondTrap Copy Constructor for " << this->name << " called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)							// copy assignment operator
{
	if (this == &src)
		return *this;
		
	ClapTrap::operator=(src);
	ScavTrap::operator=(src);
	FragTrap::operator=(src);
	
	this->name = src.name;
	std::cout << "DiamondTrap Assignment Operator for " << this->name << " called\n";
	return *this;
}

DiamondTrap::~DiamondTrap()															// destructor
{
	std::cout << "DiamondTrap Destructor for " << this->name << " called\n";
}

// ====================================================================
// subject functions:
// ====================================================================

// attack
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

// repair
void DiamondTrap::beRepaired(unsigned int amount)
{
	FragTrap::beRepaired(amount);
}

// whoAmI
void DiamondTrap::whoAmI(void)
{
	std::cout << "I'm a DiamondTrap named " << this->name <<
	" and I come from the ClapTrap named " << ClapTrap::name << "." <<
	std::endl;
}

// getMaxHitPoints
unsigned int DiamondTrap::getMaxHitPoints() 
{ 
	return FragTrap::hitPoints;
}