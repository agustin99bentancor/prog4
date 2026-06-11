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