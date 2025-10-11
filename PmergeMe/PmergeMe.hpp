#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "utils.hpp"
#include <utility>		// for std::pair

enum ContainerType {
	VECTOR,
	LIST
};

class PmergeMe {

	private:

		// orthodox canonical form:
		PmergeMe();							// default constructor

		/* ----------------------------------------------------- BOTH CONTAINERS ----------------------------------------------------- */
		int	_containerType;
		int	_unpairedElement;

		int _getJacobstahlNumbers(const int n);	// return Jacobstahl sequence

		/* ---------------------------------------------------------- VECTOR --------------------------------------------------------- */

		std::vector<int> *_unsortedVector;
		std::vector<int> *_sortedVector;
		
		void _sortVector();																			// vector sorting using Ford-Johnson algorithm
		bool _isVectorSorted();																		// check if the vector is sorted in ascending order
		void _appendArrayToVector(int *array, int array_size);										// append all elements from the array to the vector

		// *********
		// PAIRS
		// *********
		std::vector< std::pair<int, int> > _createPairs(std::vector<int> &unsortedVector);			// split vector elements into pairs
		void _orderPairElements(std::vector< std::pair<int, int> > &pairedVector);					// sort each pair by swapping if a > b
		void _sortPairsBySecElem(std::vector< std::pair<int, int> > &pairedVector, const int n);	// sort pairs by their larger value
		void _mergeInsertSequence(std::vector< std::pair<int, int> > & pairedVector);				// build sorted sequence
		// *********

		// JACOBSTAHL
		std::vector<int> _buildInsertionOrder(const std::vector<int> &pending);						// generate Jacobstahl-based insertion index sequence
		std::vector<int> _buildJacobstahlInsertionSequence(const int size);							// generate Jacobsthal sequence for optimized insertion order

		// OTHER
		void _insertAtBisectedIndex(std::vector<int> &vector, int element);							// insert the element into the vector at its sorted position
		int _findInsertionPoint(std::vector<int> &vector, const int x);								// binary search to find insertion position
		void _separateLastElement(std::vector<int> &unsortedVector);								// extract and store the last element if odd vector size
		void _insertUnpairedElement(std::vector<int> &sortedVector);								// insert the unpaired element into the sorted list

		// print vector:
		void _printVector(std::vector<int> &vector, const std::string name);

		/* ---------------------------------------------------------- LIST ----------------------------------------------------------- */

		std::list<int> *_unsortedList;
		std::list<int> *_sortedList;
		
		void _sortList();																			// list sorting using Ford-Johnson algorithm
		bool _isListSorted();																		// check if list is already sorted
		void _appendArrayToList(int *array, int array_size);										// // append all elements from the array to the list

		// *********
		// PAIRS
		// *********
		std::list< std::pair<int, int> > _createPairs(std::list<int> &unsortedList);				// split list elements into pairs
		void _orderPairElements(std::list< std::pair<int, int> > &pairedList);						// sort each pair by swapping if a > b
		void _sortPairsBySecElem(std::list< std::pair<int, int> > &pairedList);						// sort pairs by their larger value
		void _mergeInsertSequence(std::list< std::pair<int, int> > & pairedList);					// build sorted sequence
		// *********

		// JACOBSTAHL
		std::list<int> _buildInsertionOrder(const std::list<int> &pending);							// generate Jacobstahl-based insertion index sequence
		std::list<int> _buildJacobstahlInsertionSequence(const std::list<int> pending);				// generate Jacobsthal sequence for optimized insertion order

		// OTHER
		void _insertAtBisectedIndex(std::list<int> &list, int element);								// insert the element into the vector at its sorted position
		int _findInsertionPoint(std::list<int> &list, const int x);									// binary search to find insertion position
		void _separateLastElement(std::list<int> &unsortedList);									// extract and store the last element if odd list size
		void _insertUnpairedElement(std::list<int> &sortedList);									// insert the unpaired element into the sorted list

		// print list:
		void _printList(std::list<int> &list, const std::string name);

	public:
		// orthodox canonical form:
		PmergeMe(int* array, int array_size, int container);										// constructor
		PmergeMe(PmergeMe &src);																	// copy constructor
		PmergeMe & operator=( PmergeMe & src);														// copy assignment operator
		~PmergeMe();																				// destructor

		// methods:
		void sort();																				// main sort function with choice of container

		// getters:
		std::vector<int> &getSortedVector();														// getter (sorted vector)
		std::list<int> &getSortedList();															// getter (sorted list)

};

#endif
