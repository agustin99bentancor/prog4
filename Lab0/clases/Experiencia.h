#include <iostream>
#include <string>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"

using namespace std;

class Experiencia {
private:
    string codigoReserva;
    string decripcion;
    int precioBase;
    DTFecha fecha;

public:
    Experiencia(string codigoReserva, string decripcion, int precioBase, DTFecha fecha);
    virtual ~Experiencia();
    string getCodigoReserva();
    DTExpe getDT();
    virtual float calcularCosto();
};
