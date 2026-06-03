#include "dtypes/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string marca, int capacidad) {
    this->matricula = matricula;
    this->modelo = marca;
    this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() { return matricula; }
std::string DTVehiculosConductor::getModelo() { return modelo; }
int DTVehiculosConductor::getCapacidad() { return capacidad; }