/*
	PmergeMe - Ford-Johnson Merge-Insertion Sort Algorithm for std::vector and std::list
	See detailed algorithm explanation in info.md.
*/

#include "PmergeMe.hpp"
#include "utils.hpp"
#include <algorithm>		// for std::sort (checking if correctly sorted)

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe [integers to sort]"  << std::endl;
		return 1;
	}
	try {
		compareSort(ac, av);
			// OPTIONAL compare with std::sort - uncomment below to use:
		// verify_sorting(ac, av);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
