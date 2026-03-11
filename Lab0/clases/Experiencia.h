#include <iostream>
#include <string>
#include <set>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"

class Turista;  // Forward declaration

class Experiencia {
private:
    std::string codigoReserva;
    std::string decripcion;
    int precioBase;
    DTFecha fecha;
    std::set<Turista *> turistas;

public:
    Experiencia();
    Experiencia(std::string codigoReserva, std::string decripcion, int precioBase, DTFecha fecha);
    virtual ~Experiencia();
    DTExpe getDT();
    virtual float calcularCosto() = 0;
};