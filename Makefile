export LD_LIBRARY_PATH=/usr/local/lib

INCLUDE = -I./lib/Crow/include -I/usr/local/include/mongocxx/v_noabi/ -I/usr/local/include/bsoncxx/v_noabi/
LIBS = -lmongocxx -lbsoncxx
CXX_STANDARD = c++17

clean:
	@echo "\nCleaning..."
	@rm -rf bin
	@mkdir bin

build-test:
	@echo "\nBuilding..."
	g++ -O3 -std=${CXX_STANDARD} tests/main.cpp -o bin/test -g ${INCLUDE} ${LIBS} -lgtest

build-main:
	@echo "\nBuilding..."
	g++ -O3 -std=${CXX_STANDARD} src/main.cpp -o bin/main ${INCLUDE} ${LIBS}

run: clean build-main
	@echo "\nRunning main program..."
	bin/main

test: clean build-test
	@echo "\nRunning tests..."
	bin/test

load-test:
	ab -n 50000 -c 1000 -p tests/files/post_data.txt localhost:8080/api/v1/

debug: clean build-test
	@echo "\nRunning tests in debug mode..."
	gdb bin/test