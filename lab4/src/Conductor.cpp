#include "Conductor.h"
#include "Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {}

bool Conductor::tieneLibretaCompatible(TipoVehiculo tipo){
    return false;
}

void Conductor::agregarVehiculo(Vehiculo* v){
    vehiculos.insert(v);
}
