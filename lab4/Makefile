compilar:
	g++ -I include -o main src/*.cpp src/dtypes/*.cpp
	@echo "Compilo bien"

compilar-correr:
	g++ -I include -o main src/*.cpp src/dtypes/*.cpp
	@echo "Compilo bien, corriendo el resultado:"
	./main

compilar-valgrind:
	g++ -I include -o main src/*.cpp src/dtypes/*.cpp
	@echo "Compilo bien, corriendo el resultado con valgrind:"
	valgrind -s --leak-check=full ./main

valgrind:
	valgrind -s --leak-check=full ./main
