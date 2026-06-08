#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include <set>
#include <vector>

#include "Usuario.h"
#include "dtypes/TipoLibreta.h"
#include "dtypes/TipoVehiculo.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTVehiculosConductor.h"
#include "dtypes/DTFecha.h"

class Vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;

    std::set<Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();

    bool tieneLibretaCompatible(TipoVehiculo tipo);
    void agregarVehiculo(Vehiculo* v);
    std::vector<DTListarViaje> getDTListarViajes();
    std::vector<DTVehiculosConductor> listarVehiculos();
    bool hayViajesFechaConductor(DTFecha fecha);
};

#endif
