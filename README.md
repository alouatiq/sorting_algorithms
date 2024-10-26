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
├── README.md                # Project description, objectives, and overview
├── sort.h                   # Header file with function prototypes and structure definitions
├── print_array.c            # Contains the print_array function
├── print_list.c             # Contains the print_list function
├── 0-bubble_sort.c          # Bubble Sort implementation
├── 0-O                      # Big O notations for Bubble Sort
├── 1-insertion_sort_list.c  # Insertion Sort (for doubly linked list) implementation
├── 1-O                      # Big O notations for Insertion Sort
├── 2-selection_sort.c       # Selection Sort implementation
├── 2-O                      # Big O notations for Selection Sort
├── 3-quick_sort.c           # Quick Sort implementation
├── 3-O                      # Big O notations for Quick Sort
└── main/                    # Optional: Folder for main test files (not submitted)
    ├── 0-main.c             # Test file for Bubble Sort
    ├── 1-main.c             # Test file for Insertion Sort
    ├── 2-main.c             # Test file for Selection Sort
    └── 3-main.c             # Test file for Quick Sort
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
