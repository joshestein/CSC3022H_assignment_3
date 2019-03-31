CC=g++ -std=c++11
OBJECTS=HuffmanNode.o HuffmanTree.o utilities.o
TEST_FILES=utility_tests.cpp HuffmanNode_tests.cpp HuffmanTree_tests.cpp 

all: clean build run

clean:
	rm -rf *.o huffencode tests

build: $(OBJECTS)
	$(CC) driver.cpp $(OBJECTS) -o huffencode

%.o : %.cpp
	$(CC) -c $<

run:
	./huffencode test.txt output

tests: clean_tests build_tests run_tests

clean_tests:
	rm -f tests

build_tests: $(OBJECTS) tests_main.o
	$(CC) tests_main.o $(OBJECTS) $(TEST_FILES) -o tests

tests_main.o:
	$(CC) tests_main.cpp -c

run_tests:
	./tests
