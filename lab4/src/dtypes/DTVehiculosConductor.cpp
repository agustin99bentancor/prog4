#include "dtypes/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string modelo, int capacidad) {
    this->matricula = matricula;
    this->modelo = modelo;
    this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() { return matricula; }
std::string DTVehiculosConductor::getMarca() { return marca; }
int DTVehiculosConductor::getCapacidad() { return capacidad; }