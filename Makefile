compilar-correr:
	g++ -o ejecutable-entrega main.cpp \
		./datatypes/*.cpp \
		./classes/*.cpp \
		./classes/informacion/*.cpp 
	echo "Compilo bien, corriendo el resultado:"
	./ejecutable-entrega

valgrind:
	clear
	valgrind -s --leak-check=full ./ejecutable-entrega
