#ifndef VIAJE_HANDLER_H
#define VIAJE_HANDLER_H

#include <string>
#include <set>
#include <map>
#include <vector>

#include "dtypes/TipoVehiculo.h"
#include "dtypes/DTFecha.h"
#include "dtypes/DTListarViaje.h"

class Viaje;
class Conductor;
class Vehiculo;

class ViajeHandler {
private:

    static ViajeHandler* instancia;
    std::map<int, Viaje*> viajes;

    ViajeHandler();
public:

    static ViajeHandler* getInstancia();
    static void liberarMemoria();
    ~ViajeHandler();

    Viaje* getViaje(int codigo);
    std::set<Viaje*> getViajes();
    Viaje* crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
    std::vector<DTListarViaje> getDTListarViajes();
    void eliminarViaje(int codigo);
};

#endif