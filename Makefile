CC=g++ -std=c++11
OBJECTS=HuffmanNode.o HuffmanTree.o

all: clean build run

clean:
	rm -rf *.o huffencode

build: $(OBJECTS)
	$(CC) driver.cpp $(OBJECTS) -o huffencode

%.o : %.cpp
	$(CC) -c $<

run:
	./huffencode test.txt output.txt
