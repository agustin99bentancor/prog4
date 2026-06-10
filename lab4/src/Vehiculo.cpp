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

std::string Vehiculo::getNicknameConductor() {
    return this->conductor->getNickname();
}

void Vehiculo::removerViaje(Viaje* v) {
    viajes.erase(v);
}

DTDetalleVehiculo Vehiculo::getDTDetalleVehiculo(){
    return DTDetalleVehiculo(
        this->matricula,
        this->capacidad,
        this->marca,
        this->modelo,
        this->tipo
    );
}
