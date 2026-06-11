#include "dtypes/DTConsultaViaje.h"

DTConsultaViaje::DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal) {
    this->codigo = codigo;
    this->marca = marca;
    this->modelo = modelo;
    this->conductor = conductor;
    this->calificacionProm = calificacionProm;
    this->precioTotal = precioTotal;
}

int DTConsultaViaje::getCodigo() const { return codigo; }
std::string DTConsultaViaje::getMarca() const { return marca; }
std::string DTConsultaViaje::getModelo() const { return modelo; }
std::string DTConsultaViaje::getConductor() const { return conductor; }
float DTConsultaViaje::getCalificacionProm() const { return calificacionProm; }
float DTConsultaViaje::getPrecioTotal() const { return precioTotal; }

bool DTConsultaViaje::operator<(const DTConsultaViaje& otro) const {
    if (precioTotal != otro.precioTotal){
        return precioTotal < otro.precioTotal;
    }
    return calificacionProm > otro.calificacionProm;
}

std::ostream& operator<<(std::ostream& os, const DTConsultaViaje& dtcv) {
    os << "Codigo: " << dtcv.getCodigo() << ", Marca: " << dtcv.getMarca() << ", Modelo: " << dtcv.getModelo() << ", Conductor: " << dtcv.getConductor() << ", CalificacionPromedio: " << dtcv.getCalificacionProm() << ", PrecioTotal: " << dtcv.getPrecioTotal();
    return os;
}