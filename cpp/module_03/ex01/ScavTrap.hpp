#ifndef EX01_SCAVTRAP_HPP
#define EX01_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		bool			_guarding_gate;					// if true, ScavTrap is guarding the gate
		virtual unsigned int getMaxHitPoints();			// maximum hit points
		ScavTrap();										// default constructor

	public:
		// Orthodox Canonical Form elements:
		explicit ScavTrap(std::string Name);			// constructor
		ScavTrap(const ScavTrap &other);				// copy constructor
		ScavTrap &operator=(const ScavTrap &other);		// copy assignment operator
		~ScavTrap();									// destructor

		// subject functions:
		void attack(const std::string &target);			// attacking and repairing cost 1 energy point each
		void beRepaired(unsigned int amount);			// when ScavTrap repairs itself, it gets <amount> hit points back
		void guardGate();								// ScavTrap is now guarding the gate
};

#endif
