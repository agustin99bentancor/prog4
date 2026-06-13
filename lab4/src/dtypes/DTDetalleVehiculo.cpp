#include "dtypes/DTDetalleVehiculo.h"
#include <iostream>

DTDetalleVehiculo::DTDetalleVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo)
    {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

std::string DTDetalleVehiculo::getMatricula() const { return matricula; }
int DTDetalleVehiculo::getCapacidad() const { return capacidad; }
std::string DTDetalleVehiculo::getMarca() const { return marca; }
std::string DTDetalleVehiculo::getModelo() const { return modelo; }
TipoVehiculo DTDetalleVehiculo::getTipo() const { return tipo; }

std::ostream& operator<<(std::ostream& os, const DTDetalleVehiculo& v) {
    os << "Matricula: " << v.getMatricula() << ", Capacidad: " << v.getCapacidad() << ", Marca: " << v.getMarca() << ", Modelo: " << v.getModelo() << ", Tipo: " << v.getTipo();
    return os;
}
