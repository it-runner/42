# 🚀 PmergeMe - Ford-Johnson Merge-Insertion Sort Algorithm

A C++ program implementing the **Ford-Johnson Merge-Insertion Sort algorithm** for sorting sequences of positive integers. This project demonstrates the algorithm's application to both `std::vector` and `std::list` containers, providing insights into their performance characteristics for different dataset sizes.
The project was carried out as part of a series of projects at 42Warsaw in compliance with the C++98 standard.

## ✨ Features

-   **Ford-Johnson Merge-Insertion Sort**: Efficient sorting algorithm designed for optimal comparisons.
-   **Container Comparison**: Implements the algorithm for both `std::vector` and `std::list` to highlight performance differences.
-   **Jacobsthal Sequence**: Utilizes the Jacobsthal numbers for optimized insertion order in the merge-insertion process.
-   **Input Validation**: Robust handling of command-line arguments, ensuring only positive integers are processed.
-   **Performance Measurement**: Measures and displays the time taken for sorting using both `std::vector` and `std::list`.
-   **Detailed Algorithm Explanation**: Includes an in-depth explanation of the algorithm, including the Jacobsthal sequence generation and performance considerations for `std::list` vs `std::vector`.

## 📂 Project Structure

    ├── PmergeMe.hpp          # Class declaration for PmergeMe
    ├── PmergeMe.cpp          # Class implementation for PmergeMe
    ├── utils.hpp             # Utility functions (e.g., input parsing, printing)
    ├── utils.cpp
    ├── main.cpp              # Entry point of the program
    ├── Makefile              # Build configuration

## ⚙️ Compilation

To build the project, simply run:

``` bash
make
```

This will compile the program with: `-c++` - Flags: `-Wall -Wextra -Werror -std=c++98 -pedantic`

To clean up object files:

``` bash
make clean
```

To remove the executable:

``` bash
make fclean
```

To rebuild everything:

``` bash
make re
```

## ▶️ Usage

Run the compiled program with a sequence of positive integers as arguments:

``` bash
./PmergeMe 3 5 9 1 4 8 2 7 6
```

Example output:

```
________ STD::VECTOR - insertion-merge sort ________
Unsorted   (size 9): 3 5 9 1 4 8 2 7 6
Sorted     (size 9): 1 2 3 4 5 6 7 8 9

________ STD::LIST - insertion-merge sort ________
Unsorted   (size 9): 3 5 9 1 4 8 2 7 6
Sorted     (size 9): 1 2 3 4 5 6 7 8 9

________ TIME: ________
Time to process a range of 9 elements with std::vector:         0.048000 ms
Time to process a range of 9 elements with std::list:           0.025000 ms
```

For testing with 3000 randomly generated numbers, use the provided script:

``` bash
./run_3000.sh
```

This script will:
	Generate 3000 random positive integers
	Run the program with the generated sequence
	Display sorting results and timing information for both std::vector and std::list

## 🔒 Error Handling

-   **Invalid Arguments**: The program checks for non-positive integers, overflows or non-numeric inputs and exits with an error message.
-   **No Arguments**: If no integers are provided, the program displays a usage message.

## 📚 Algorithm Explanation

### Ford-Johnson Merge-Insertion Sort

The Ford-Johnson algorithm, also known as the merge-insertion sort, is an efficient comparison sort algorithm that minimizes the number of comparisons required to sort a list. It works by:

**1. Pairing and Sorting**  
Dividing the input into pairs, sorting each pair, and then recursively sorting these pairs based on their larger elements.

**2. Main Chain and Pending Elements**  
Constructing a main sorted chain and managing a set of pending elements to be inserted.

**3. Jacobsthal Insertion Sequence**  
Utilizing the Jacobsthal sequence to determine the optimal order for inserting pending elements into the main chain, minimizing comparisons. This strategy helps to minimize comparisons by inserting elements from their sorted positions, allowing for more efficient binary searches and fewer comparisons overall.

### Performance Comparison: `std::list` vs `std::vector`

The choice between `std::list` and `std::vector` for implementing sorting algorithms like Ford-Johnson can significantly impact performance, especially with varying dataset sizes:

| Feature                  | `std::vector`                                  | `std::list`                                     |
| :------------------------| :--------------------------------------------- | :---------------------------------------------- |
| **Data Structure**       | Dynamic array, contiguous memory               | Doubly linked list, non-contiguous memory       |
| **Access Time**          | `O(1)` for random access                       | `O(n)` for random access (sequential iteration) |
| **Insertion/Deletion**   | `O(n)` in the middle, `O(1)` at end            | `O(1)` anywhere (once position is found)        |
| **Cache Locality**       | Excellent, elements are stored contiguously    | Poor, elements can be scattered in memory       |
| **Reallocation**         | May incur overhead when resizing               | No reallocation overhead                        |

**For small datasets (e.g., 3-100 elements):**

-   `std::list` might have an advantage due to less reallocation overhead and faster pointer operations for a small number of elements.
-   Binary search in `std::vector` is `O(log n)` with constant time access, which is generally efficient.

**For large datasets (e.g., 1000+ elements):**

-   `std::vector` typically outperforms `std::list` due to better cache locality, allowing the processor to fetch multiple elements at once.
-   Binary search in `std::list` becomes `O(n)` because it requires sequential iteration to reach elements, making it less efficient for large collections.

This program provides a practical demonstration of these theoretical differences by measuring sorting times for both containers.
