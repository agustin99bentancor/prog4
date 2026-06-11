#include "dtypes/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string modelo, int capacidad) {
    this->matricula = matricula;
    this->modelo = modelo;
    this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() const { return matricula; }
std::string DTVehiculosConductor::getModelo() const { return modelo; }
int DTVehiculosConductor::getCapacidad() const { return capacidad; }

std::ostream& operator<<(std::ostream& os, const DTVehiculosConductor& dtvc) {
    os << "Matricula: " << dtvc.getMatricula() << ", Modelo: " << dtvc.getModelo() << ", Capacidad: " << dtvc.getCapacidad();
    return os;
}