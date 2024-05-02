CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++17	# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.

all: test3
SRCS = sorting_basic.cpp sorting_ll.cpp sorting_hybrid.cpp test_3.cpp print_array.cpp
DEPS = $(SRCS:.cpp=.d)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

test3: test3.o linkedlist.o sorting_hybrid.o sorting_basic.o print_array.o
	$(CC) test3.o linkedlist.o sorting_hybrid.o sorting_basic.o print_array.o -o test3

clean:
	rm *.o test3
