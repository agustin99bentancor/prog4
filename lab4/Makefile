compilar-correr:
	g++ -I include -o ejecutable-entrega src/*.cpp src/dtypes/*.cpp
	echo "Compilo bien, corriendo el resultado:"
	./ejecutable-entrega
valgrind:
	valgrind -s --leak-check=full ./ejecutable-entrega
