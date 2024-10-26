# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89
INCLUDES = -I.

# Source files for sorting algorithms
SOURCES = 0-bubble_sort.c 1-insertion_sort_list.c 2-selection_sort.c 3-quick_sort.c \
          100-shell_sort.c 101-cocktail_sort_list.c 102-counting_sort.c \
          103-merge_sort.c 104-heap_sort.c 105-radix_sort.c 106-bitonic_sort.c \
          107-quick_sort_hoare.c 1000-sort_deck.c

# Source files for auxiliary functions
AUXILIARY = print_array.c print_list.c

# Main test files
MAIN_TESTS = main/0-main.c main/1-main.c main/2-main.c main/3-main.c main/100-main.c \
             main/101-main.c main/102-main.c main/103-main.c main/104-main.c main/105-main.c \
             main/106-main.c main/107-main.c main/1000-main.c

# Executable files for each test
EXECS = bubble_sort insertion_sort selection_sort quick_sort shell_sort cocktail_sort \
        counting_sort merge_sort heap_sort radix_sort bitonic_sort quick_sort_hoare deck_sort

# Targets for each individual test
all: $(EXECS)

bubble_sort: main/0-main.c 0-bubble_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/0-main.c 0-bubble_sort.c $(AUXILIARY)

insertion_sort: main/1-main.c 1-insertion_sort_list.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/1-main.c 1-insertion_sort_list.c $(AUXILIARY)

selection_sort: main/2-main.c 2-selection_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/2-main.c 2-selection_sort.c $(AUXILIARY)

quick_sort: main/3-main.c 3-quick_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/3-main.c 3-quick_sort.c $(AUXILIARY)

shell_sort: main/100-main.c 100-shell_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/100-main.c 100-shell_sort.c $(AUXILIARY)

cocktail_sort: main/101-main.c 101-cocktail_sort_list.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/101-main.c 101-cocktail_sort_list.c $(AUXILIARY)

counting_sort: main/102-main.c 102-counting_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/102-main.c 102-counting_sort.c $(AUXILIARY)

merge_sort: main/103-main.c 103-merge_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/103-main.c 103-merge_sort.c $(AUXILIARY)

heap_sort: main/104-main.c 104-heap_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/104-main.c 104-heap_sort.c $(AUXILIARY)

radix_sort: main/105-main.c 105-radix_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/105-main.c 105-radix_sort.c $(AUXILIARY)

bitonic_sort: main/106-main.c 106-bitonic_sort.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/106-main.c 106-bitonic_sort.c $(AUXILIARY)

quick_sort_hoare: main/107-main.c 107-quick_sort_hoare.c $(AUXILIARY) sort.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/107-main.c 107-quick_sort_hoare.c $(AUXILIARY)

deck_sort: main/1000-main.c 1000-sort_deck.c $(AUXILIARY) sort.h deck.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ main/1000-main.c 1000-sort_deck.c $(AUXILIARY)

# Target to test all executables
test: all
	@echo "Running tests..."
	@for exec in $(EXECS); do \
		echo "\nRunning $$exec:"; \
		./$$exec; \
	done

# Clean up generated files
clean:
	rm -f $(EXECS)
	rm -f *.o

.PHONY: all clean test
