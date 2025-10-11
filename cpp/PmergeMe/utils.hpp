#ifndef UTILS_HPP
# define UTILS_HPP

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>			// for std::clock_t

// convert vector / list of integers to space-separated string
std::string intVectorToString(std::vector<int> &vector);
std::string intListToString(std::list<int> &list);
std::string intVectorToString(std::vector< std::pair<int, int> > &vector);
std::string intListToString(std::list< std::pair<int, int> > &list);
// ---------------

int *createArrayFromArgs(int ac, char **av);									// create and return an integer array from command line arguments
int convertStringToInt(char *nbStr, int *array, int array_size);				// convert string to integer with full validation:
// ***************

// print line
void printLine(std::string key);												// print the given string to standard output followed by a newline
void printLine(std::string key, std::string value);								// print a key-value pair with formatted alignment

// check if the given number exists in the array
bool isNumberInArray(const int *array, const int array_size, const int nb);

// *** TIME MEASUREMENT *** 

std::clock_t time_vector_sort(int *array, int array_size);						// measure and display the time taken to sort an array
std::clock_t time_list_sort(int *array, int array_size);						// measure and display the time taken to sort an array
void printTime(std::string containerType, std::clock_t time, int elements);		// format and display container processing time with aligned output

// COMPARISON VS STD::SORT()

void compareSort(int ac, char **av);											// test and compare sorting performance between vector and list

// *** VERIFICATION (OPTIONAL) ***

// compare custom sorting implementation against std::sort
void verify_list_sorting(int ac, char **av);
void verify_vector_sorting(int ac, char **av);
void verify_sorting (int ac, char **av);										// main verification function

#endif
