# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89 -I.

# Source files
SRCS = print_array.c print_list.c sort.h
BUBBLE_SORT = 0-bubble_sort.c
INSERTION_SORT = 1-insertion_sort_list.c
SELECTION_SORT = 2-selection_sort.c
QUICK_SORT = 3-quick_sort.c

# Main test files
MAIN_BUBBLE = main/0-main.c
MAIN_INSERTION = main/1-main.c
MAIN_SELECTION = main/2-main.c
MAIN_QUICK = main/3-main.c

# Executable names
BUBBLE_EXEC = bubble_sort
INSERTION_EXEC = insertion_sort
SELECTION_EXEC = selection_sort
QUICK_EXEC = quick_sort

# All target - Builds all executables
all: $(BUBBLE_EXEC) $(INSERTION_EXEC) $(SELECTION_EXEC) $(QUICK_EXEC)

# Compile each sorting algorithm with its main file and helper functions
$(BUBBLE_EXEC): $(BUBBLE_SORT) $(SRCS) $(MAIN_BUBBLE)
	$(CC) $(CFLAGS) $(MAIN_BUBBLE) $(BUBBLE_SORT) print_array.c -o $(BUBBLE_EXEC)

$(INSERTION_EXEC): $(INSERTION_SORT) $(SRCS) $(MAIN_INSERTION)
	$(CC) $(CFLAGS) $(MAIN_INSERTION) $(INSERTION_SORT) print_list.c -o $(INSERTION_EXEC)

$(SELECTION_EXEC): $(SELECTION_SORT) $(SRCS) $(MAIN_SELECTION)
	$(CC) $(CFLAGS) $(MAIN_SELECTION) $(SELECTION_SORT) print_array.c -o $(SELECTION_EXEC)

$(QUICK_EXEC): $(QUICK_SORT) $(SRCS) $(MAIN_QUICK)
	$(CC) $(CFLAGS) $(MAIN_QUICK) $(QUICK_SORT) print_array.c -o $(QUICK_EXEC)

# Test target - Runs each executable in sequence
test: all
	@echo "\nTesting Bubble Sort:"
	@./$(BUBBLE_EXEC)
	@echo "\nTesting Insertion Sort:"
	@./$(INSERTION_EXEC)
	@echo "\nTesting Selection Sort:"
	@./$(SELECTION_EXEC)
	@echo "\nTesting Quick Sort:"
	@./$(QUICK_EXEC)

# Clean target - Removes all executables
clean:
	rm -f $(BUBBLE_EXEC) $(INSERTION_EXEC) $(SELECTION_EXEC) $(QUICK_EXEC)

# Phony targets
.PHONY: all test clean
