clean:
	@echo "\nCleaning..."
	rm -rf bin
	mkdir bin

run: clean
	@echo "\nCompiling..."
	g++ -O3 -std=c++17 src/main.cpp -o bin/main  -I./lib/Crow/include

	@echo "\nRunning main program..."
	bin/main

test: clean
	@echo "\nCompiling..."
	g++ -O3 -std=c++17 tests/main.cpp -o bin/test  -I./lib/Crow/include -lgtest

	@echo "\nRunning tests..."
	bin/test