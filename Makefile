run:
	rm -rf bin
	mkdir bin
	@echo "\nCompiling..."
	g++ -O3 -std=c++17 main.cpp -o bin/main  -I./lib/Crow/include

	@echo "\nRunning..."
	bin/main