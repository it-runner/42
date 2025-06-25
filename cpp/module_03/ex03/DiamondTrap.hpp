#ifndef EX03_DIAMONDTRAP_HPP
#define EX03_DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public virtual ScavTrap, public virtual FragTrap {
	private:
		std::string		name;							// name of the DiamondTrap object
		unsigned int getMaxHitPoints();					// maximum hit points
		DiamondTrap();									// default constructor

	public:
		// Orthodox Canonical Form elements:
		explicit DiamondTrap(std::string name);			// constructor
		DiamondTrap(const DiamondTrap &other);			// copy constructor
		DiamondTrap &operator=(const DiamondTrap &src);	// copy assignment operator
		~DiamondTrap();									// destructor

		// subject functions:
		void attack(const std::string &target);			// attacking and repairing cost 1 energy point each
		void whoAmI(void);								// displays both its name and its ClapTrap name
		void beRepaired(unsigned int amount);			// when DiamondTrap repairs itself, it gets <amount> hit points back
};

#endif