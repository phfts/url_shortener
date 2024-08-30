export LD_LIBRARY_PATH=/usr/local/lib

INCLUDE_TEST = -I./lib/Crow/include -I/usr/local/include/mongocxx/v_noabi/ -I/usr/local/include/bsoncxx/v_noabi/
LIBS_TEST = -lmongocxx -lbsoncxx
INCLUDE = -I./lib/Crow/include
CXX_STANDARD = c++17

clean:
	@echo "\nCleaning..."
	@rm -rf bin
	@mkdir bin

build-test:
	@echo "\nBuilding..."
	g++ -O3 -std=${CXX_STANDARD} tests/main.cpp -o bin/test -g ${INCLUDE_TEST} ${LIBS_TEST} -lgtest

build-main:
	@echo "\nBuilding..."
	g++ -O3 -std=${CXX_STANDARD} src/main.cpp -o bin/main ${INCLUDE} ${LIBS}

run: clean build-main
	@echo "\nRunning main program..."
	bin/main

test: clean build-test
	@echo "\nRunning tests..."
	bin/test

debug: clean build-test
	@echo "\nRunning tests in debug mode..."
	gdb bin/test