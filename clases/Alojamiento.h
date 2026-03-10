


#include <iostream>
#include <string>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"
#include "../datatypes/TipoRegimen.h"
#include "./expreiencia.h"
using namespace std;

class Alojamiento: public Experiencia{
private:
    string hotel;
    TipoRegimen regimen;
    int cantNoches;

public:
    Alojamiento(string codigoReserva, string decripcion, int precioBase, DTFecha fecha, string hotel, int cantNoches);
    virtual float calcularCosto();
};