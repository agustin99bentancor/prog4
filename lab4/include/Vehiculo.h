#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <set>

#include "dtypes/TipoVehiculo.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTUsuarioViaje.h"
#include "dtypes/DTVehiculosConductor.h"

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
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo, Conductor* conductor);
    ~Vehiculo();

    std::set<DTListarViaje> getDTListarViajes();
    std::string getNicknameConductor();
    DTUsuarioViaje getDatosConductor();
    std::string getNombreConductor();
    float getCalificacionConductor();
    DTVehiculosConductor getDTVehiculoConductor();
    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
    void asociarViaje(Viaje* cvi);
    int getCapacidad();

    std::string getMatricula();
    std::string getMarca();
    std::string getModelo();
};

#endif
