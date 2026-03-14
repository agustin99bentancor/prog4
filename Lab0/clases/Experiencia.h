#include <iostream>
#include <string>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"

using namespace std;

class Turista;

class Experiencia {
private:
    string codigoReserva;
    string decripcion;
    int precioBase;
    DTFecha fecha;
    set<Turista *> turistas;

public:
    Experiencia(string codigoReserva, string decripcion, int precioBase, DTFecha fecha);
    virtual ~Experiencia();

    string getCodigoReserva();
    int getPrecioBase();
    set<Turista *> getTuristas();
    DTExpe getDT();
    virtual float calcularCosto();
};