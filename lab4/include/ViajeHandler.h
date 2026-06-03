#ifndef VIAJE_HANDLER_H
#define VIAJE_HANDLER_H

#include <string>
#include <set>

#include "dtypes/TipoVehiculo.h"
#include "dtypes/DTFecha.h"

class Viaje;
class Conductor;
class Vehiculo;

class ViajeHandler {
private:

    static ViajeHandler* instancia;
    std::set<Viaje*> viajes;

    ViajeHandler();
public:

    static ViajeHandler* getInstance();

    Viaje* getViaje(int codigo);
    void crearVehiculo(std::string matricula, int capacidad, std::string modelo, std::string marca, TipoVehiculo tipo, Conductor* c);
    std::set<Viaje*> getViajes();
    Viaje* crearViaje(Vehiculo v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
};

#endif