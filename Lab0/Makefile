compilar-correr:
	g++ -o ejecutable-entrega main.cpp ./datatypes/*.cpp ./clases/*.cpp
	echo "Compilo bien, corriendo el resultado:"
	./ejecutable-entrega
valgrind:
	clear
	valgrind -s --leak-check=full ./ejecutable-entrega
