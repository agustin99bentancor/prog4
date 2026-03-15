#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include <iostream>
#include <string>
#include <set>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"
#include "../datatypes/TipoRegimen.h"
#include "./Experiencia.h"

class TourGuiado: public Experiencia{
private:
    std::string agencia;
    std::set<std::string> lugarVisitados;

public:
    TourGuiado(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string agencia, std::set<std::string> lugarVisitados);
    virtual ~TourGuiado();
    virtual float calcularCosto();
};

#endif