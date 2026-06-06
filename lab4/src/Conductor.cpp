#include "Conductor.h"
#include "Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {}

bool Conductor::tieneLibretaCompatible(TipoVehiculo tipo){
    return (tipo == Auto && (libretas.find(AutoProfesional) != libretas.end() || libretas.find(AutoAmateur) != libretas.end())) ||
           (tipo == Moto && (libretas.find(MotoProfesional) != libretas.end() || libretas.find(MotoAmateur) != libretas.end()));
}

void Conductor::agregarVehiculo(Vehiculo* v){
    vehiculos.insert(v);
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    for(std::set<Vehiculo*>::iterator it = vehiculos.begin(); it != vehiculos.end(); ++it){
        if((*it)->hayViajesFecha(fecha)){
            return true;
        }
    }
    return false;
}