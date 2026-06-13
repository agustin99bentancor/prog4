#include "Vehiculo.h"
#include "Viaje.h"
#include "Conductor.h"

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

std::string Vehiculo::getMarca() {
    return marca;
}

std::string Vehiculo::getModelo() {
    return modelo;
}

std::string Vehiculo::getNicknameConductor() {
    return conductor->getNickname();
}

float Vehiculo::getCalificacionConductor() {
    return conductor->getCalificacionPromedio();
}

bool Vehiculo::hayViajesConductor(DTFecha fecha) {
    return conductor->hayViajesFechaConductor(fecha);
}

bool Vehiculo::hayViajesFecha(DTFecha fecha) {
    for(auto viaje : viajes){
        if(viaje->getFecha() == fecha){
            return true;
        }
    }
    return false;
}

void Vehiculo::asociarViaje(Viaje* cvi) {
    viajes.insert(cvi);
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor() {
    return DTVehiculosConductor(matricula, modelo, capacidad);
}

void Vehiculo::removerViaje(Viaje* v) {
    viajes.erase(v);
}

DTDetalleVehiculo Vehiculo::getDTDetalleVehiculo(){
    return DTDetalleVehiculo(matricula, capacidad, marca, modelo, tipo);
}

std::vector<DTListarViaje> Vehiculo::getDTListarViajes() {
    std::vector<DTListarViaje> ret;
    for(auto viaje : viajes){
        ret.push_back(viaje->getDTListarViaje());
    }
    return ret;
}

DTUsuarioViaje Vehiculo::getDatosConductor() {
    return DTUsuarioViaje(conductor->getNickname(), TipoUsuario::Conductor);
}

std::string Vehiculo::getNombreConductor() {
    return conductor->getNombre();
}
