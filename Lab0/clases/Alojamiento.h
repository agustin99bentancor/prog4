#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <iostream>
#include <string>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"
#include "../datatypes/TipoRegimen.h"
#include "./Experiencia.h"

class Alojamiento: public Experiencia{
private:
    std::string hotel;
    TipoRegimen regimen;
    int cantNoches;

public:
    Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string hotel, TipoRegimen regimen, int cantNoches);

    float calcularCosto();
};

#endif