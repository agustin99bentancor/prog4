#ifndef VIAJE_HANDLER_H
#define VIAJE_HANDLER_H

#include <string>
#include <set>
#include <map>
#include <vector>

#include "dtypes/DTFecha.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTDetalleViaje.h"

class Viaje;
class Vehiculo;
class Conductor;

class ViajeHandler {
private:
    static ViajeHandler* instancia;
    std::map<int, Viaje*> viajes;

    ViajeHandler();

public:
    static ViajeHandler* getInstancia();

    Viaje* getViaje(int codigo);

    Viaje* crearViaje(Vehiculo* v, DTFecha fecha,
                      std::string origen, std::string destino,
                      int asientos, float precio);

    std::set<Viaje*> getViajes();

    std::vector<DTListarViaje> getDTListarViajes();

    DTDetalleViaje obtenerDetalleViaje(int codigo);

    void eliminarViaje(int codigo);
};

#endif