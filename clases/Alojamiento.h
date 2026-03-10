


#include <iostream>
#include <string>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"
#include "./expreiencia.h"
using namespace std;

class Alojamiento: public Experiencia{
private:
    string hotel;
    string decripcion;
    int cantNoches;

public:
    Alojamiento(string codigoReserva, string decripcion, int precioBase, DTFecha fecha);
    virtual float calcularCosto();
};