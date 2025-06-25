#ifndef EX03_FRAGTRAP_HPP
#define EX03_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	protected:
		virtual unsigned int getMaxHitPoints();			// maximum hit points
		FragTrap();										// default constructor

	public:
		// Orthodox Canonical Form elements:
		explicit FragTrap(std::string name);			// constructor
		FragTrap(const FragTrap &other);				// copy constructor
		FragTrap &operator=(const FragTrap &other);		// copy assignment operator
		~FragTrap();									// destructor

		// subject functions:
		void attack(const std::string &target);			// attacking and repairing cost 1 energy point each
		void beRepaired(unsigned int amount);			// when FragTrap repairs itself, it gets <amount> hit points back
		void highFivesGuys(void);						// displays a positive high fives request on the standard output
};

#endif
