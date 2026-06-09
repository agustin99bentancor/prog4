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

std::vector<DTVehiculosConductor> Conductor::listarVehiculos() {
    std::vector<DTVehiculosConductor> ret;
    for(std::set<Vehiculo*>::iterator it = vehiculos.begin(); it != vehiculos.end(); ++it){
        ret.push_back((*it)->getDTVehiculoConductor());
    }
    return ret;
}

std::vector<DTListarViaje> Conductor::getDTListarViajes() {
    std::vector<DTListarViaje> ret;
    for(std::set<Vehiculo*>::iterator it = vehiculos.begin(); it != vehiculos.end(); ++it){
        std::set<DTListarViaje> viajes = (*it)->getDTListarViajes();
        ret.insert(ret.end(), viajes.begin(), viajes.end());
    }
    return ret;
}