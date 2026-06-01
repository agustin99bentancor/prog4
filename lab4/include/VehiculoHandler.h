#ifndef VEHICULO_HANDLER_H
#define VEHICULO_HANDLER_H

#include <string>
#include <set>

#include "Vehiculo.h"
#include "dtypes/TipoVehiculo.h"
#include "Conductor.h"

class VehiculoHandler {
private:

    static VehiculoHandler* instancia;
    std::set<Vehiculo*> vehiculos;

    VehiculoHandler();
public:

    static VehiculoHandler* getInstance();

    bool existeVehiculo(std::string matricula);
    void crearVehiculo(std::string matricula, int capacidad, std::string modelo, std::string marca, TipoVehiculo tipo, Conductor* c);
    Vehiculo getVehiculo(std::string matricula);
};

#endif