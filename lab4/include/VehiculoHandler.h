#ifndef VEHICULO_HANDLER_H
#define VEHICULO_HANDLER_H

#include <string>
#include <map>

#include "dtypes/TipoVehiculo.h"
#include "../include/Vehiculo.h"

class Vehiculo;
class Conductor;

class VehiculoHandler {
private:

    static VehiculoHandler* instancia;
    std::map<std::string, Vehiculo*> vehiculos;

    VehiculoHandler();
public:

    static VehiculoHandler* getInstancia();
    static void liberarMemoria();
    ~VehiculoHandler();

    bool existeVehiculo(std::string matricula);
    Vehiculo* crearVehiculo(std::string matricula, int capacidad, std::string modelo, std::string marca, TipoVehiculo tipo, Conductor* c);
    Vehiculo* getVehiculo(std::string matricula);
};

#endif