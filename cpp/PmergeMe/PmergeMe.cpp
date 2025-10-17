	#include "PmergeMe.hpp"
	#include <iterator>
	#include <list>
	#include <vector>
	#include <stdexcept>
	#include <algorithm>		// for std::sort
	#include <climits>			// for INT_MAX
	#include <sstream>			// for std::stringstream

	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// 															PRIVATE:
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	// ====================================================================
	// orthodox canonical form
	// ====================================================================

	PmergeMe::PmergeMe() {}															// default constructor

	/* ----------------------------------------------------- BOTH CONTAINERS ----------------------------------------------------- */

	/* 
		return Jacobstahl sequence
			J(0)=0,
			J(1)=1,
			J(n)=J(n−1)+2⋅J(n−2)
		result:	0 1 1 3 5 11 21 43 85 171 341 683 1365 2731 5461 10923 21845 43691 87381 174763 349525 699051 1398101 2796203 5592405 
				11184811 22369621 44739243 89478485 178956971 357913941 715827883 1431655765
	*/
	int PmergeMe::_getJacobstahlNumbers(const int n) {
		if (n <= 0) return 0;
		if (n == 1) return 1;

		long a = 0;  // J(0)
		long b = 1;  // J(1)

		for (int i = 2; i <= n; ++i) {
			long next = b + 2 * a;			// Iterative Jacobsthal sequence: J(n) = J(n-1) + 2*J(n-2)
			if (next > INT_MAX)				// overflow protection
				return -1;
			a = b;
			b = next;
		}
		return static_cast<int>(b);
	}

	/* ================================================================================================================== */
	/* ----------------------------------------------------- VECTOR ----------------------------------------------------- */
	/* ================================================================================================================== */

	// vector sorting using Ford-Johnson algorithm
	void PmergeMe::_sortVector() {
		if (_isVectorSorted()) {
			std::vector<int>::iterator it = _unsortedVector->begin();
			for ( ; it != _unsortedVector->end(); ++it)
				_sortedVector->push_back(*it);
			return;
		}
		bool hasUnpairedElement = _unsortedVector->size() % 2 != 0;
		if (hasUnpairedElement)
			_separateLastElement(*_unsortedVector);
		std::vector< std::pair<int, int> > pairedVector = _createPairs(*_unsortedVector);
		_orderPairElements(pairedVector);
		_sortPairsBySecElem(pairedVector, pairedVector.size() - 1);
		_mergeInsertSequence(pairedVector);
		if (hasUnpairedElement)
			_insertUnpairedElement(*_sortedVector);
	}

	// append all elements from the array to the vector
	void PmergeMe::_appendArrayToVector(int *array, int array_size) {
		for (int i = 0; i < array_size; ++i)
			_unsortedVector->push_back( array[i]);
	}

	// check if the vector is sorted in ascending order
	bool PmergeMe::_isVectorSorted() {
		std::vector<int>::iterator it = _unsortedVector->begin();
		for (; it != _unsortedVector->end(); ++it) {
			std::vector<int>::iterator next = it + 1;
			if (next != _unsortedVector->end() && *it > *next)
				return false;
		}
		return true;
	}

	// *********
	// PAIRS
	// *********

	// split vector elements into pairs, leaving last element unpaired if count is odd
	/* 	--- Iterates through the vector, grouping elements into pairs (first, second). 
		--- If the vector has an odd number of elements, the last element is ignored/discarded */
	std::vector< std::pair<int, int> > PmergeMe::_createPairs(std::vector<int> &unsortedVector) {
		std::vector< std::pair<int, int> > pairedVector;
		int first = 0;
		std::vector<int>::iterator it = unsortedVector.begin();
		for (; it != unsortedVector.end(); it++)
		{
			if (first == 0)
				first = *it;
			else {
				pairedVector.push_back(std::make_pair(first, *it));
				first = 0;
			}
		}
		return (pairedVector);
	}

	// sort each pair by swapping if first element is greater than second
	/*	--- Iterates through the vector, sorting each pair by swapping 
		--- if first element is greater than second */
	void PmergeMe::_orderPairElements(std::vector< std::pair<int, int> > &pairedVector) {
		std::vector< std::pair<int, int> >::iterator it = pairedVector.begin();
		for (; it != pairedVector.end(); ++it) {
			if(it->first > it->second) {
				int tmp = it->first;
				it->first = it->second;
				it->second = tmp;
			}
		}
	}

	// sort pairs by their larger value using insertion sort on the entire vector.
	void PmergeMe::_sortPairsBySecElem(std::vector< std::pair<int, int> > &pairedVector, const int n) {
		if (n <= 0)
			return;
		_sortPairsBySecElem(pairedVector, n - 1);
		std::pair<int, int> key = pairedVector[n];
		int j = n - 1;
		while (j >= 0 && pairedVector[j].second > key.second) {
			pairedVector[j + 1] = pairedVector[j];
			--j;
		}
		pairedVector[j + 1] = key;
	}

	// build sorted sequence by inserting pending elements in optimal order using binary search insertion
	/*	--- 1. Initialize _sortedVector with smaller elements, larger ones go to pending
		--- 2. Generate optimal insertion sequence for pending elements
		--- 3.Insert pending elements using binary search for optimal positioning */
	void PmergeMe::_mergeInsertSequence(std::vector< std::pair<int, int> > &pairedVector) {
		std::vector<int> pending;
		std::vector< std::pair<int, int> >::iterator it = pairedVector.begin();
		for (; it != pairedVector.end(); ++it) {
			_sortedVector->push_back(it->second);
			pending.push_back(it->first);
		}
		std::vector<int> indexSequence = _buildInsertionOrder(pending);
		std::vector<int>::iterator isit = indexSequence.begin();
		for (; isit != indexSequence.end(); ++isit) {
			int numberToInsert = pending[*isit - 1];
			_insertAtBisectedIndex(*_sortedVector, numberToInsert);
		}
	}

	// *********

	// ############################################
	// ###############  Jacobstahl  ###############
	// ############################################

	// generate Jacobstahl-based insertion index sequence for merge-insert sort
	std::vector<int> PmergeMe::_buildInsertionOrder(const std::vector<int> &pending)
	{
		int pendingSize = pending.size();
		std::vector<int> indexSequence;

		// always start with index 1
		indexSequence.push_back(1);
		if (pendingSize == 1)
			return indexSequence;

		std::vector<int> jacobSequence = _buildJacobstahlInsertionSequence(pendingSize);
		bool useJacobNumber = false;
		int i = 2;
		int safetyCounter = 0;	// safety counter to prevent infinite loop

		while (indexSequence.size() < (size_t)pendingSize) {

			// insert Jacobstahl number if possible and not already inserted
			if (!useJacobNumber && !jacobSequence.empty()) {
				int jacobIndex = jacobSequence.front();
				jacobSequence.erase(jacobSequence.begin());

				// check if Jacobstahl number is already inserted or out of range
				if (jacobIndex >= 1 && jacobIndex <= pendingSize
						&& std::find(indexSequence.begin(), indexSequence.end(), jacobIndex) == indexSequence.end()) {
					indexSequence.push_back(jacobIndex);
				}
				useJacobNumber = true;
				continue;
			}

			// insert next index if not already inserted
			if (i <= pendingSize && std::find(indexSequence.begin(), indexSequence.end(), i) == indexSequence.end()) {
				indexSequence.push_back(i);
				useJacobNumber = false;
			}

			++i;
			++safetyCounter;

			// protect against infinite loop
			if (safetyCounter > pendingSize * 3) {
				// add remaining numbers to index sequence if not already inserted
				for (int k = 1; k <= pendingSize; ++k) {
					if (std::find(indexSequence.begin(), indexSequence.end(), k) == indexSequence.end())
						indexSequence.push_back(k);
				}
				break;
			}
		}

		return indexSequence;
	}

	// generate Jacobsthal sequence for optimized insertion order in merge-insert sort
	std::vector<int> PmergeMe::_buildJacobstahlInsertionSequence(const int size) {
		std::vector<int> jacobSequence;
		int jacobIndex = 3;

		while (true) {
			int result = _getJacobstahlNumbers(jacobIndex);
			// overflow protection
			if (result == -1) {
				std::cerr << "[WARN] Overflow Jacobsthal at n = " << jacobIndex << std::endl;
				break;
			}
			// stop if Jacobstahl number is out of range
			if (result >= size - 1)
				break;
			jacobSequence.push_back(result);
			++jacobIndex;
		}
		return jacobSequence;
	}

	// ############################################
	// #################  other  ##################
	// ############################################

	// insert the element into the vector at its sorted position using binary search
	void PmergeMe::_insertAtBisectedIndex( std::vector<int> &vector, int element) {
		int index = _findInsertionPoint(vector, element);
		vector.insert(vector.begin() + index, element);
	}

	// binary search on a vector to find insertion position for x in sorted order
	int PmergeMe::_findInsertionPoint(std::vector<int> &vector, const int x) {
		int lo = 0;
		int hi = vector.size();

		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (x < vector[mid])
				hi = mid;
			else
				lo = mid + 1;
		}
		return lo;
	}

	// extract and store the last element if the vector has an odd number of elements
	void PmergeMe::_separateLastElement(std::vector<int> &unsortedVector) {
		_unpairedElement = unsortedVector.back();
		unsortedVector.pop_back();
	}

	// insert the unpaired element into the sorted list using binary search
	void PmergeMe::_insertUnpairedElement(std::vector<int> &sortedVector) {
		_insertAtBisectedIndex( sortedVector, _unpairedElement );
	}

	void PmergeMe::_printVector(std::vector<int> &vector, const std::string name) {
		std::stringstream ss;
		ss << name << " (size " << vector.size() << "): " 
		<< intVectorToString(vector);
		printLine(ss.str());
	}

	/* ================================================================================================================ */
	/* ----------------------------------------------------- LIST ----------------------------------------------------- */
	/* ================================================================================================================ */

	// append all elements from the array to the list
	void PmergeMe::_appendArrayToList(int *array, int array_size) {
		for (int i = 0; i < array_size; ++i)
			_unsortedList->push_back( array[i]);
	}

	// list sorting using Ford-Johnson algorithm
	void PmergeMe::_sortList() {
		if (_isListSorted()) {
			std::list<int>::iterator it = _unsortedList->begin();
			for (; it != _unsortedList->end(); ++it)
				_sortedList->push_back(*it);
			return;
		}
		bool hasUnpairedElement = _unsortedList->size() % 2 != 0;
		if (hasUnpairedElement)
			_separateLastElement(*_unsortedList);
		std::list< std::pair<int, int> > pairedList = _createPairs(*_unsortedList);
		_orderPairElements(pairedList);
		_sortPairsBySecElem(pairedList);
		_mergeInsertSequence(pairedList);
		if (hasUnpairedElement)
			_insertUnpairedElement(*_sortedList);
	}

	// check if the vector is sorted in ascending order
	bool PmergeMe::_isListSorted() {
		std::list<int>::iterator it = _unsortedList->begin();
		for (; it != _unsortedList->end(); ++it) {
			std::list<int>::iterator next = it;
			std::advance(next, 1);
			if (next != _unsortedList->end() && *it > *next)
				return false;
		}
		return true;
	}

	// *********
	// PAIRS
	// *********

	// split list elements into pairs, leaving last element unpaired if count is odd
	/* 	--- Iterates through the list, grouping elements into pairs (first, second). 
		--- If the list has an odd number of elements, the last element is ignored/discarded */
	std::list< std::pair<int, int> > PmergeMe::_createPairs(std::list<int> &unsortedList)
	{
		std::list< std::pair<int, int> > pairedList;
		int first = 0;
		std::list<int>::iterator it = unsortedList.begin();
		for (; it != unsortedList.end(); ++it) {
			if (first == 0)
				first = *it;
			else {
				pairedList.push_back( std::make_pair(first, *it));
				first = 0;
			}
		}
		return (pairedList);
	}

	// sort each pair by swapping if first element is greater than second
	/*	--- Iterates through the list, sorting each pair by swapping 
		--- if first element is greater than second */
	void PmergeMe::_orderPairElements(std::list< std::pair<int, int> > &pairedList) {
		std::list< std::pair<int, int> >::iterator it = pairedList.begin();
		for (; it != pairedList.end(); ++it) {
			if(it->first > it->second) {
				int tmp = it->first;
				it->first = it->second;
				it->second = tmp;
			}
		}
	}

	// sort pairs by largest value using insertion sort on the entire list (using vector - list doesn't work with indexing)
	void PmergeMe::_sortPairsBySecElem(std::list< std::pair<int, int> > &pairedList) {
		std::vector< std::pair<int, int> > temp(pairedList.begin(), pairedList.end());
		// use vector to sort
		_sortPairsBySecElem(temp, temp.size() - 1);
		pairedList.assign(temp.begin(), temp.end());
	}

	// build sorted sequence by inserting pending elements in optimal order using binary search insertion
	/*	--- 1. Initialize _sortedList with smaller elements, larger ones go to pending
		--- 2. Generate optimal insertion sequence for pending elements
		--- 3.Insert pending elements using binary search for optimal positioning */
	void PmergeMe::_mergeInsertSequence(std::list< std::pair<int, int> > &pairedList) {
		std::list<int> pending;
		std::list< std::pair<int, int> >::iterator it = pairedList.begin();
		for (; it != pairedList.end(); ++it) {
			_sortedList->push_back(it->second);
			pending.push_back(it->first);
		}
		std::list<int> indexSequence = _buildInsertionOrder(pending);
		std::list<int>::iterator isit = indexSequence.begin();
		for (; isit != indexSequence.end(); ++isit) {
			int index = *isit;
			std::list<int>::iterator pit = pending.begin();
			std::advance(pit, index - 1);
			int numberToInsert = *pit;
			_insertAtBisectedIndex(*_sortedList, numberToInsert);
		}
	}

	// *********

	// ############################################
	// ###############  Jacobstahl  ###############
	// ############################################

	// generate Jacobstahl-based insertion index sequence for merge-insert sort
	std::list<int> PmergeMe::_buildInsertionOrder(const std::list<int>& pending) {
		int pendingSize = pending.size();
		std::list<int> indexSequence;

		indexSequence.push_back(1);
		if (pendingSize == 1)
			return indexSequence;

		// convert Jacobstahl sequence to list
		std::vector<int> jacobVector = _buildJacobstahlInsertionSequence(pendingSize);
		std::list<int> jacobSequence(jacobVector.begin(), jacobVector.end());
		
		bool useJacobNumber = false;
		int i = 2;
		int safetyCounter = 0;

		while (indexSequence.size() < (size_t)pendingSize) {
			if (!useJacobNumber && !jacobSequence.empty()) {
				int jacobIndex = jacobSequence.front();
				jacobSequence.pop_front();

				if (jacobIndex >= 1 && jacobIndex <= pendingSize) {
					bool exists = false;
					for (std::list<int>::const_iterator it = indexSequence.begin(); 
						it != indexSequence.end(); ++it) {
						if (*it == jacobIndex) {
							exists = true;
							break;
						}
					}
					
					if (!exists)
						indexSequence.push_back(jacobIndex);
				}

				useJacobNumber = true;
				continue;
			}

			if (i <= pendingSize) {
				bool exists = false;
				for (std::list<int>::const_iterator it = indexSequence.begin(); it != indexSequence.end(); ++it) {
					if (*it == i) {
						exists = true;
						break;
					}
				}
				
				if (!exists) {
					indexSequence.push_back(i);
					useJacobNumber = false;
				}
			}

			++i;
			++safetyCounter;

			if (safetyCounter > pendingSize * 3) {
				for (int k = 1; k <= pendingSize; ++k) {
					bool exists = false;
					for (std::list<int>::const_iterator it = indexSequence.begin(); it != indexSequence.end(); ++it) {
						if (*it == k) {
							exists = true;
							break;
						}
					}

					if (!exists)
						indexSequence.push_back(k);
				}
				break;
			}
		}

		return indexSequence;
	}

	// generate Jacobsthal sequence for optimized insertion order in merge-insert sort
	std::list<int> PmergeMe::_buildJacobstahlInsertionSequence(const std::list<int> pending) {
		std::list<int> jacobSequence;
		int size = pending.size();
		int jacobIndex = 3;
		while (true) {
			int result = _getJacobstahlNumbers(jacobIndex);
			// overflow protection
			if (result == -1) {
				std::cerr << "[WARN] Overflow Jacobsthal at n = " << jacobIndex << std::endl;
				break;
			}
		// stop if Jacobstahl number is out of range
		if (result >= size - 1)
			break;
		jacobSequence.push_back(result);
		++jacobIndex;
		}
		return jacobSequence;
	}

	// ############################################
	// #################  other  ##################
	// ############################################

	// insert the element into the vector at its sorted position using binary search
	void PmergeMe::_insertAtBisectedIndex(std::list<int> &list, int element) {
		int pos = _findInsertionPoint( list, element );
		std::list<int>::iterator it = list.begin();
		std::advance(it, pos);
		list.insert( it, element );
	}

	// binary search on a list to find insertion position for x in sorted order
	int PmergeMe::_findInsertionPoint(std::list<int> &list, const int x) {
		if (list.empty())
			return 0;

		std::list<int>::iterator lo = list.begin();
		std::list<int>::iterator hi = list.end();

		while (lo != hi) {
			std::list<int>::iterator mid = lo;
			int distance = std::distance(lo, hi);

			// move mid to the middle of the range
			for (int i = 0; i < distance / 2; ++i)
				++mid;

			if (x < *mid)
				hi = mid;
			else
				lo = ++mid;
		}

		return std::distance(list.begin(), lo);
	}

	// extract and store the last element if the list has an odd number of elements
	void PmergeMe::_separateLastElement(std::list<int> &unsortedList) {
		_unpairedElement = unsortedList.back();
		unsortedList.pop_back();
	}

	// insert the unpaired element into the sorted list using binary search
	void PmergeMe::_insertUnpairedElement(std::list<int> &sortedList) {
		_insertAtBisectedIndex(sortedList, _unpairedElement);
	}

	void PmergeMe::_printList(std::list<int> &list, std::string name) {
		std::stringstream ss;
		ss << name << " (size " << list.size() << "): " 
		<< intListToString(list);
		printLine(ss.str());
	}

	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// 															PRIVATE:
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	// ====================================================================
	// orthodox canonical form
	// ====================================================================

	// constructor
	PmergeMe::PmergeMe(int* array, int array_size, int container) 
	: _containerType(container),
	_unpairedElement(0),
	_unsortedVector(new std::vector<int>()),
	_sortedVector(new std::vector<int>()),
	_unsortedList(new std::list<int>()),
	_sortedList(new std::list<int>())
	{
		if (container == VECTOR)
			_appendArrayToVector(array, array_size);
		else if (container == LIST)
			_appendArrayToList(array, array_size);
	}

	// copy constructor
	PmergeMe::PmergeMe(PmergeMe &src) {(void)src;}

	// copy assignment operator
	PmergeMe &PmergeMe::operator=(PmergeMe &src) {
		(void)src;
		return *this;
	}

	// destructor
	PmergeMe::~PmergeMe() {
		delete _unsortedVector;
		delete _sortedVector;
		delete _unsortedList;	
		delete _sortedList;
	}

	// ====================================================================
	// methods
	// ====================================================================

	// main sort function with choice of container
	void PmergeMe::sort() {
		if (_containerType == VECTOR)
			_sortVector();
		else if (_containerType == LIST)
			_sortList();
	}

	// getter (sorted vector)
	std::vector<int> &PmergeMe::getSortedVector() {
		if (!_sortedVector)
			throw std::runtime_error("Sorted vector is not initialized");
		return *_sortedVector;
	}

	// getter (sorted list)
	std::list<int> &PmergeMe::getSortedList() {
		if (!_sortedList)
			throw std::runtime_error("Sorted list is not initialized");
		return *_sortedList;
	}
