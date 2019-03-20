CC=g++ -std=c++11

all: clean build run

clean:
	rm -rf *.o huffencode

build:
	$(CC) driver.cpp -o huffencode

run:
	./huffencode test.txt output.txt
