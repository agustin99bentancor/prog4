#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include <set>

#include "Usuario.h"
#include "Vehiculo.h"
#include "dtypes/TipoLibreta.h"
#include "dtypes/TipoVehiculo.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTVehiculosConductor.h"
#include "dtypes/DTFecha.h"

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;

    std::set<Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();

    bool tieneLibretaCompatible(TipoVehiculo tipo);
    void agregarVehiculo(Vehiculo v);
    std::set<DTListarViaje> getDTListarViajes();
    std::set<DTVehiculosConductor> listarVehiculos();
    bool hayViajesFechaConductor(DTFecha fecha);
};

#endif
