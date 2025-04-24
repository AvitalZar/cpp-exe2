CXX = g++ -g
CXXFLAGS = -std=c++2a -Wall -Wextra -pedantic -Werror



all: test main

main: main.o squareMat.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	./main

test: squareMat.o test.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	./test

valgrind: main
	valgrind --leak-check=full ./main

%.o: %.cpp squareMat.hpp
	$(CXX) $(CXXFLAGS) -c $<

main.o: main.cpp squareMat.hpp
	$(CXX) $(CXXFLAGS) -c $<



clean:
	rm -f test *.o main
