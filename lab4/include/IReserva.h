#ifndef IRESERVA_H
#define IRESERVA_H

#include <string>
#include <set>
#include <vector>

#include "dtypes/DTConsultaViaje.h"
#include "dtypes/DTVehiculosConductor.h"

class IReserva {
public:

    virtual ~IReserva() {}
    virtual std::set<std::string> listarPasajeros() = 0;
    virtual std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) = 0;
    virtual bool generarReserva(std::string nickname, int codigo, int asientos) = 0;
    virtual std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname) = 0;
    virtual bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) = 0;
    virtual bool existeVehiculo(std::string matricula) = 0;
};

#endif