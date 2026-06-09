#include "Vehiculo.h"
#include "Viaje.h"
#include "Conductor.h"
#include "dtypes/TipoUsuario.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo, Conductor* conductor) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->conductor = conductor;
}

Vehiculo::~Vehiculo() {}

std::string Vehiculo::getMatricula() {
    return matricula;
}

int Vehiculo::getCapacidad() {
    return capacidad;
}

bool Vehiculo::hayViajesConductor(DTFecha fecha) {
    return conductor->hayViajesFechaConductor(fecha);
}

bool Vehiculo::hayViajesFecha(DTFecha fecha) {
    for(std::set<Viaje*>::iterator it = viajes.begin(); it != viajes.end(); ++it){
        if((*it)->getFecha() == fecha){
            return true;
        }
    }
    return false;
}

void Vehiculo::asociarViaje(Viaje* cvi) {
    this->viajes.insert(cvi);
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor() {
    return DTVehiculosConductor(matricula, modelo, capacidad);
}

std::set<Viaje*> Vehiculo::getViajes() {
    return this->viajes;
}

std::set<DTListarViaje> Vehiculo::getDTListarViajes() {
    std::set<DTListarViaje> ret;
    for(std::set<Viaje*>::iterator it = viajes.begin(); it != viajes.end(); ++it){
        ret.insert((*it)->getDTListarViaje());
    }
    return ret;
}

DTUsuarioViaje Vehiculo::getDatosConductor() {
    DTUsuarioViaje res = DTUsuarioViaje(conductor->getNickname(), TipoUsuario::Conductor);
    return res;
}