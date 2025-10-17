#include "utils.hpp"
#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>			// for INT_MAX
#include <algorithm>		// for std::sort
#include <cstddef>			// for size_t
#include <iomanip>			// for std::setw
#include <limits>			// for INT_MAX
#include <sstream>			// for std::stringstream

// convert vector / list of integers to space-separated string
std::string intVectorToString(std::vector<int> &vector) {
	std::stringstream ss;
	if (vector.empty())
		return ( "" );
	std::vector<int>::iterator it = vector.begin();
	ss << *it;				// first element without space
	++it;
	for (; it != vector.end(); ++it)
		ss << " " << *it;	// next elements with space
	return ss.str();
}

std::string intListToString(std::list<int> &list) {
	std::stringstream ss;
	if (list.empty())
		return "";
	std::list<int>::iterator it = list.begin();
	ss << *it;					// first element without space
	++it;
	for (; it != list.end(); ++it)
		ss << " " << *it;		// next elements with space
	return ss.str();
}

std::string intVectorToString(std::vector< std::pair<int, int> > &vector) {
	std::stringstream ss;
	if (vector.empty())
		return "";
	std::vector< std::pair<int, int> >::iterator it = vector.begin();
	for (; it != vector.end(); ++it)
		ss << "[" << it->first << "--"  << it->second << "]";
	return ss.str();
}

std::string intListToString(std::list< std::pair<int, int> > &list) {
	std::stringstream ss;
	if (list.empty())
		return "";
	std::list< std::pair<int, int> >::iterator it = list.begin();
	for (; it != list.end(); ++it)
		ss << "[" << it->first << "--"  << it->second << "]";
	return ss.str();
}
// ---------------

// create and return an integer array from command line arguments, converting them to numbers.
int *createArrayFromArgs(int array_size, char **av) {
	int *array = new int[array_size];
	for (int i = 0; i < array_size; ++i)
		array[i] = -1;
	try {
		for (int i = 0; av[i + 1] && i < array_size; ++i)
			array[i] = convertStringToInt(av[i + 1], array, array_size);
	}
	catch (...) {
		delete[] array;
		throw;
	}
	return array;
}	

// convert string to integer with full validation: parsing errors, range checks, and duplicate detection
int convertStringToInt(char *nbStr, int *array, int array_size)
{
	char* endptr;
	long nb = strtol(nbStr, &endptr, 10);
	
	// check if parsing was successful
	if (endptr == nbStr)  // nothing was parsed
		throw std::out_of_range("Invalid number: no digits found");
	
	// check if there are non-digit characters
	if (*endptr != '\0')
		throw std::out_of_range("Invalid number: contains non-digit characters");
	
	// check if the number is within the valid range
	if (nb <= 0 || nb > INT_MAX || errno == ERANGE)
		throw std::out_of_range("Number out of valid range");
	
	// check if the number is a duplicate
	if (isNumberInArray(array, array_size, nb))
		throw std::out_of_range("Duplicate number");
	
	return static_cast<int>(nb);
}
// ***************

// print the given string to standard output followed by a newline
void printLine(std::string key) {
	std::cout << key << std::endl;
}

// print a key-value pair with formatted alignment
void printLine(std::string key, std::string value) {
	std::cout << std::setw( 35 ) << std::left << key
		<< value << std::endl;
}

// check if the given number exists in the array
bool isNumberInArray(const int * array, const int array_size, const int nb) {
	for (int i = 0; i < array_size; ++i) {
		if (array[i] != -1 && array[i] == nb)
			return true;
	}
	return false;
}

// *** TIME MEASUREMENT *** 

// measure and display the time taken to sort an array
std::clock_t time_vector_sort(int *array, int array_size) {
	std::cout << "\n________ STD::VECTOR - insertion-merge sort ________"  << std::endl;
	
	// Display unsorted vector first
	std::vector<int> beforeVec(array, array + array_size);
	std::cout << "Unsorted   (size " << beforeVec.size() << "): " << intVectorToString(beforeVec) << std::endl;
	
	PmergeMe vectorSorter(array, array_size, VECTOR);
	std::clock_t start = std::clock();
	vectorSorter.sort();
	std::clock_t vectorTime = std::clock() - start;

	std::vector<int> &sortedVec = vectorSorter.getSortedVector();
	std::cout << "Sorted     (size " << sortedVec.size() << "): " << intVectorToString(sortedVec) << std::endl;

	return vectorTime;
}

// measure and display the time taken to sort an array
std::clock_t time_list_sort(int *array, int array_size) {
	std::cout << std::endl << "________ STD::LIST - insertion-merge sort ________"  << std::endl;
	
	// Display unsorted list first
	std::list<int> beforeList(array, array + array_size);
	std::cout << "Unsorted   (size " << beforeList.size() << "): " << intListToString(beforeList) << std::endl;
	
	PmergeMe listSorter(array, array_size, LIST);
	std::clock_t start = std::clock();
	listSorter.sort();
	std::clock_t listTime = std::clock() - start;

	std::list<int> &sortedList = listSorter.getSortedList();
	std::cout << "Sorted     (size " << sortedList.size() << "): " << intListToString(sortedList) << std::endl;

	return listTime;
}

// format and display container processing time with aligned output
void printTime(std::string containerType, std::clock_t time, int elements) {
	double clock_per_us = static_cast<double>(CLOCKS_PER_SEC) / 1000; // milliseconds
	double timeInUs = time / clock_per_us;

	std::ostringstream prefix;
	prefix << "Time to process a range of " << elements 
		<< " elements with std::" << containerType << ":";
	
	std::cout << std::left << std::setw(60) << prefix.str()
			<< std::right << std::setw(12) << std::fixed << std::setprecision(6) 
			<< timeInUs << " ms" << std::endl;
}

// COMPARISON

// compare sorting performance between vector and list
void compareSort(int ac, char **av) {
	int *array = NULL;
	try {
		int array_size = ac - 1;
		array = createArrayFromArgs(array_size, av);
		
		// Sort and measure time for both containers
		std::clock_t vectorTime = time_vector_sort(array, array_size);
		std::clock_t listTime = time_list_sort(array, array_size);
		
		std::cout << std::endl << "________ TIME: ________"  << std::endl;
		printTime("vector", vectorTime, ac - 1);
		printTime("list", listTime, ac - 1);
		std::cout << std::endl;
	}
	catch (...) {
		delete[] array;
		throw;
	}
	delete[] array;
}


// *** VERIFICATION (OPTIONAL) ***

// compare custom sorting implementation against std::sort

void verify_vector_sorting(int ac, char **av) {
	std::cout << "\n\033[36m" << "=== VECTOR SORTING VERIFICATION (comparing with std::sort) ===" << "\033[0m" << std::endl;
	
	int array_size = ac - 1;
	int *array = createArrayFromArgs(array_size, av);
	
	// Custom sorting
	PmergeMe vectorSorter(array, array_size, VECTOR);
	vectorSorter.sort();
	std::vector<int> &mySorted = vectorSorter.getSortedVector();
	
	// std::sort
	std::vector<int> stdSorted(array, array + array_size);
	std::sort(stdSorted.begin(), stdSorted.end());
	
	// Comparison
	bool vectorsMatch = (mySorted.size() == stdSorted.size()) && 
					std::equal(mySorted.begin(), mySorted.end(), stdSorted.begin());
	
	std::cout << "Vector: verification -> " 
			<< (vectorsMatch ? "✅ OK" : "❌ ERROR") << std::endl;
	
	if (!vectorsMatch) {
		std::cout << "Differences found!" << std::endl;
		std::cout << "My sort: ";
		for (size_t i = 0; i < mySorted.size() && i < 10; ++i)
			std::cout << mySorted[i] << " ";
		std::cout << std::endl << "std::sort: ";
		for (size_t i = 0; i < stdSorted.size() && i < 10; ++i)
			std::cout << stdSorted[i] << " ";
		std::cout << std::endl;
	}
	
	std::cout << "\033[36m" << "=== END OF VECTOR VERIFICATION ===\n" << "\033[0m" << std::endl;
	delete[] array;
}

void verify_list_sorting(int ac, char **av) {
	std::cout << "\n\033[36m" << "=== LIST SORTING VERIFICATION (comparing with std::list::sort) ===" << "\033[0m" << std::endl;
	
	int array_size = ac - 1;
	int *array = createArrayFromArgs(array_size, av);
	
	// Custom sorting
	PmergeMe listSorter(array, array_size, LIST);
	listSorter.sort();
	std::list<int> &myListSorted = listSorter.getSortedList();
	
	// std::list::sort
	std::list<int> stdListSorted(array, array + array_size);
	stdListSorted.sort();
	
	// Comparison
	bool listsMatch = (myListSorted.size() == stdListSorted.size());
	if (listsMatch) {
		std::list<int>::iterator it1 = myListSorted.begin();
		std::list<int>::iterator it2 = stdListSorted.begin();
		while (it1 != myListSorted.end() && it2 != stdListSorted.end()) {
			if (*it1 != *it2) {
				listsMatch = false;
				break;
			}
			++it1; ++it2;
		}
	}
	
	std::cout << "List:   verification -> " 
			<< (listsMatch ? "✅ OK" : "❌ ERROR") << std::endl;
	
	std::cout << "\033[36m" << "=== END OF LIST VERIFICATION ===\n" << "\033[0m" << std::endl;
	delete[] array;
}

void verify_sorting(int ac, char **av) {
	verify_vector_sorting(ac, av);
	verify_list_sorting(ac, av);
}
