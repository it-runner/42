	________________________________________________     PERFORMANCE COMPARISON:     ________________________________________________

	std::list vs std::vector for different dataset sizes

	For small datasets (3-100 elements):
		1. std::list has an advantage because it doesn't have reallocation overhead
		2. Pointer operations are fast for a small number of elements
		3. Binary search in vector is O(log n) with constant time access

	For large datasets (1000+ elements):
		1. std::vector has better cache locality - the processor can fetch multiple elements at once
		2. Binary search in list is O(n) due to the necessity of iteration


	________________________________________________     JAKOBSTHAL EXPLANATION (EN):     ________________________________________________

	***** SUMMARY OF THE ENTIRE PROCESS: *****

	INPUT: [1, 7, 2, 5, 6, 4, 3]

	STEPS:
	Creating pairs: [1,7], [2,5], [6,4] + 3 (odd)
	Sorting within pairs: [1,7], [2,5], [4,6]
	Sorting pairs: [2,5], [4,6], [1,7] (by second elements)
	Split: Main=[5,6,7], Pending=[2,4,1]
	Jacobsthal sequence: [1,3,2] (optimal insertion order)
	Insertion:
		Index 1: 2 → [2,5,6,7]
		Index 3: 1 → [1,2,5,6,7]
		Index 2: 4 → [1,2,4,5,6,7]
		Odd element: 3 → [1,2,3,4,5,6,7]
	OUTPUT: [1, 2, 3, 4, 5, 6, 7] ✅

	*********************************************************
	***** DETAILED JACOBSTHAL SEQUENCE GENERATION: *****
	*********************************************************

	from pairs: [2,5], [4,6], [1,7] pending 3:

	STEP 5: GENERATING THE INSERTION SEQUENCE - SIMPLIFIED
		We have 3 elements in the pending group: pending = [2, 4, 1]

	WHAT DO THE INDICES MEAN?
		Index 1 = first element = 2
		Index 2 = second element = 4
		Index 3 = third element = 1

	HOW WE BUILD THE SEQUENCE:

	STEP 5.1: Always start with index 1
	Sequence: [1]

	STEP 5.2: Take Jacobsthal numbers
		Look for numbers greater than 1, but smaller than the size (3)
		J(2)=1 (too small), J(3)=3 (perfect), J(4)=5 (too big)
		Take 3 from Jacobsthal
		Sequence: [1, 3]

	STEP 5.3: Fill in missing indices in natural order
		Check sequentially: 2, 3, 4...
		2 is not yet in the sequence → add it
		Sequence: [1, 3, 2]

	WHY THIS ORDER?
		Sequence [1, 3, 2] means we will insert elements in the order:
		Index 1 = element 2
		Index 3 = element 1
		Index 2 = element 4


	________________________________________________     JAKOBSTHAL EXPLANATION (PL):     ________________________________________________

	***** PODSUMOWANIE CAŁEGO PROCESU: *****

	WEJŚCIE: [1, 7, 2, 5, 6, 4, 3]

	KROKI:
		Tworzenie par: [1,7], [2,5], [6,4] + 3 (nieparzysty)
		Sortowanie w parach: [1,7], [2,5], [4,6]
		Sortowanie par: [2,5], [4,6], [1,7] (według drugich elementów)
		Podział: Główna=[5,6,7], Oczekująca=[2,4,1]
		Sekwencja Jacobsthala: [1,3,2] (optymalna kolejność wstawiania)
		Wstawianie:
			Indeks 1: 2 → [2,5,6,7]
			Indeks 3: 1 → [1,2,5,6,7]
			Indeks 2: 4 → [1,2,4,5,6,7]
			Element nieparzysty: 3 → [1,2,3,4,5,6,7]
			WYJŚCIE: [1, 2, 3, 4, 5, 6, 7] ✅

	*********************************************************
	***** GENEROWANIE SEKWENCJI JACOBSTHALA SZCZEGŁOWO: *****
	*********************************************************

	z par: [2,5], [4,6], [1,7] pending 3:

	KROK 5: GENEROWANIE SEKWENCJI WSTAWIANIA - PROŚCIEJ
		Mamy 3 elementy w grupie oczekującej: pending = [2, 4, 1]

	CO OZNACZAJĄ INDEKSY?
		Indeks 1 = pierwszy element = 2
		Indeks 2 = drugi element = 4
		Indeks 3 = trzeci element = 1

	JAK BUDUJEMY SEKWENCJĘ:

	KROK 5.1: Zawsze zaczynamy od indeksu 1
	Sekwencja: [1]

	KROK 5.2: Bierzemy liczby Jacobsthala
		Szukamy liczb większych niż 1, ale mniejszych niż rozmiar (3)
		J(2)=1 (za małe), J(3)=3 (idealne), J(4)=5 (za duże)
		Bierzemy 3 z Jacobsthala
		Sekwencja: [1, 3]
	
	KROK 5.3: Uzupełniamy brakujące indeksy w kolejności naturalnej
		Sprawdzamy kolejno: 2, 3, 4...
		2 nie ma jeszcze w sekwencji → dodajemy
		Sekwencja: [1, 3, 2]

	DLACZEGO TAKA KOLEJNOŚĆ?
		Sekwencja [1, 3, 2} oznacza, że będziemy wstawiać elementy w kolejności:
		Indeks 1 = element 2
		Indeks 3 = element 1
		Indeks 2 = element 4
