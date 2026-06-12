#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <set>

#include "dtypes/TipoVehiculo.h"
#include "dtypes/DTDetalleVehiculo.h"
#include "dtypes/DTVehiculosConductor.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTUsuarioViaje.h"

class Viaje;
class Conductor;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;

    Conductor* conductor;
    std::set<Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca,
             std::string modelo, TipoVehiculo tipo, Conductor* conductor);

    ~Vehiculo();

    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();

    std::string getNicknameConductor();
    float getCalificacionConductor();
    bool hayViajesFecha(DTFecha fecha);
    bool hayViajesConductor(DTFecha fecha);
    DTVehiculosConductor getDTVehiculoConductor();
    void asociarViaje(Viaje* v);
    void removerViaje(Viaje* v);

    DTDetalleVehiculo getDTDetalleVehiculo();
};

#endif