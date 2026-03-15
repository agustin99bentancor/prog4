#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include <iostream>
#include <string>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"
#include "../datatypes/TipoRegimen.h"
#include "./Experiencia.h"

class EventoCultural: public Experiencia{
private:
    std::string ubicacion;
    bool usoCupon;

public:
    EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string ubicacion, bool usoCupon);
    EventoCultural();

    virtual ~EventoCultural();
    float calcularCosto();
};

#endif