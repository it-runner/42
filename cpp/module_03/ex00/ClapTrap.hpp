#ifndef EX00_CLAPTRAP_HPP
#define EX00_CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ClapTrap {
	private:
		std::string		name;							// name of the ClapTrap object
		unsigned int	hitPoints;						// health of the ClapTrap
		unsigned int	energyPoints;					// attacking and repairing cost 1 energy point each
		unsigned int	attackDamage;					// when ClapTrap attacks, it causes its target to lose <attack damage> hit points
		unsigned int getMaxHitPoints();					// maximum hit points
		ClapTrap();										// default constructor

	public:
		// Orthodox Canonical Form elements:
		explicit ClapTrap(std::string Name);			// constructor
		ClapTrap(const ClapTrap &other);				// copy constructor
		ClapTrap &operator=(const ClapTrap &other);		// copy assignment operator
		~ClapTrap();									// destructor

		// getters:
		std::string getName() const;					// getter (name)
		int getHitPoints() const;						// getter (hit points)
		int getEnergyPoints() const;					// getter (energy points)
		int getAttackDamage() const;					// getter (attack damage)

		// setter:
		void setAttackDamage(int amount);				// setter (attack damage)

		// subject functions:
		void attack(const std::string &target);			// attacking and repairing cost 1 energy point each
		void takeDamage(unsigned int amount);			// when ClapTrap is attacked, it loses <amount> hit points
		void beRepaired(unsigned int amount);			// when ClapTrap repairs itself, it gets <amount> hit points back

		// others:
		void addHitPoints(int amount);					// add hit points
};

#endif
