# Sorting Algorithms Project

The sorting_algorithms repository is a C project implementing and analyzing four fundamental sorting algorithms: Bubble Sort, Insertion Sort, Selection Sort, and Quick Sort. Each algorithm is implemented in its own file and includes code to print the array or list after each swap, aiding in visualization and debugging.

The project also explores the Big O notation for each algorithm's time complexity across best, average, and worst-case scenarios, documented in separate files. Additional files include helper functions (print_array and print_list) for displaying arrays and doubly linked lists, respectively.

The project aims to deepen understanding of sorting mechanics, efficiency, and stability while reinforcing C programming skills and knowledge of algorithm analysis.

## Files
- `0-bubble_sort.c`: Implements the Bubble Sort algorithm for an array of integers.
- `1-insertion_sort_list.c`: Implements the Insertion Sort algorithm for a doubly linked list.
- `2-selection_sort.c`: Implements the Selection Sort algorithm for an array of integers.
- `3-quick_sort.c`: Implements the Quick Sort algorithm using the Lomuto partition scheme.
- `print_array.c`: Helper function to print arrays.
- `print_list.c`: Helper function to print doubly linked lists.

```
sorting_algorithms/
├── README.md                   # Project description, objectives, and overview
├── sort.h                      # Header file with function prototypes and structure definitions
├── print_array.c               # Contains the print_array function
├── print_list.c                # Contains the print_list function
├── 0-bubble_sort.c             # Bubble Sort implementation
├── 0-O                         # Big O notations for Bubble Sort
├── 1-insertion_sort_list.c     # Insertion Sort (for doubly linked list) implementation
├── 1-O                         # Big O notations for Insertion Sort
├── 2-selection_sort.c          # Selection Sort implementation
├── 2-O                         # Big O notations for Selection Sort
├── 3-quick_sort.c              # Quick Sort (Lomuto partition scheme) implementation
├── 3-O                         # Big O notations for Quick Sort
├── 100-shell_sort.c            # Shell Sort (Knuth sequence) implementation
├── 101-cocktail_sort_list.c    # Cocktail Shaker Sort implementation
├── 101-O                       # Big O notations for Cocktail Shaker Sort
├── 102-counting_sort.c         # Counting Sort implementation
├── 102-O                       # Big O notations for Counting Sort
├── 103-merge_sort.c            # Merge Sort (top-down) implementation
├── 103-O                       # Big O notations for Merge Sort
├── 104-heap_sort.c             # Heap Sort (sift-down) implementation
├── 104-O                       # Big O notations for Heap Sort
├── 105-radix_sort.c            # Radix Sort (LSD) implementation
├── 106-bitonic_sort.c          # Bitonic Sort implementation
├── 106-O                       # Big O notations for Bitonic Sort
├── 107-quick_sort_hoare.c      # Quick Sort (Hoare partition scheme) implementation
├── 107-O                       # Big O notations for Quick Sort (Hoare)
├── 1000-sort_deck.c            # Sort Deck (cards) implementation
├── deck.h                      # Header file with deck structure definitions
└── main/                       # Folder for main test files (not submitted)
    ├── 0-main.c                # Test file for Bubble Sort
    ├── 1-main.c                # Test file for Insertion Sort
    ├── 2-main.c                # Test file for Selection Sort
    ├── 3-main.c                # Test file for Quick Sort
    ├── 100-main.c              # Test file for Shell Sort (Knuth sequence)
    ├── 101-main.c              # Test file for Cocktail Shaker Sort
    ├── 102-main.c              # Test file for Counting Sort
    ├── 103-main.c              # Test file for Merge Sort
    ├── 104-main.c              # Test file for Heap Sort
    ├── 105-main.c              # Test file for Radix Sort
    ├── 106-main.c              # Test file for Bitonic Sort
    ├── 107-main.c              # Test file for Quick Sort (Hoare partition)
    └── 1000-main.c             # Test file for Sort Deck (cards)

```

## Big O Notations
Big O notation files:
- `0-O`: Bubble Sort complexities.
- `1-O`: Insertion Sort complexities.
- `2-O`: Selection Sort complexities.
- `3-O`: Quick Sort complexities.

## Compilation
To compile each algorithm:
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 <task-main.c> <task-sort.c> print_array.c -o <output-file>
