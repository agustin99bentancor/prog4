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
    for(auto vehiculo : vehiculos){
        if(vehiculo->hayViajesFecha(fecha)){
            return true;
        }
    }
    return false;
}

std::vector<DTVehiculosConductor> Conductor::listarVehiculos() {
    std::vector<DTVehiculosConductor> ret;
    for(auto vehiculo : vehiculos){
        ret.push_back(vehiculo->getDTVehiculoConductor());
    }
    return ret;
}

std::vector<DTListarViaje> Conductor::getDTListarViajes() {
    std::vector<DTListarViaje> ret;
    for(auto vehiculo : vehiculos){
        std::vector<DTListarViaje> dtlvs = vehiculo->getDTListarViajes();
        ret.insert(ret.end(), dtlvs.begin(), dtlvs.end());
    }
    return ret;
}