#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <iostream>
#include <string>
#include <set>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"

using namespace std;

class Turista;

class Experiencia {
private:
    string codigoReserva;
    string descripcion;
    int precioBase;
    DTFecha fecha;
    set<Turista *> turistas;

public:
    Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha);
    virtual ~Experiencia();

    void linkTurista(Turista* t);
    void desvincularTurista(Turista* t);

    string getCodigoReserva();
    int getPrecioBase();
    set<Turista *> getTuristas();
    DTExpe getDT();
    virtual float calcularCosto() = 0;
};

#endif
