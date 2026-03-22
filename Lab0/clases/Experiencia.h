#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <iostream>
#include <string>
#include <set>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"

class Turista;

class Experiencia {
private:
    std::string codigoReserva;
    std::string descripcion;
    int precioBase;
    DTFecha fecha;
    std::set<Turista *> turistas;

public:
    Experiencia(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fechaF);
    virtual ~Experiencia();

    void linkTurista(Turista* t);
    void desvincularTurista(Turista* t);

    std::string getCodigoReserva() const;
    int getPrecioBase() const;
    std::set<Turista *> getTuristas() const;
    DTExpe getDT() const;
    virtual float calcularCosto() = 0;
};

#endif