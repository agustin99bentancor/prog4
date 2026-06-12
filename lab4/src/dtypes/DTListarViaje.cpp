#include "dtypes/DTListarViaje.h"

DTListarViaje::DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string conductor) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->conductor = conductor;
}

int DTListarViaje::getCodigo() const { return codigo; }
DTFecha DTListarViaje::getFecha() const { return fecha; }
std::string DTListarViaje::getOrigen() const { return origen; }
std::string DTListarViaje::getDestino() const { return destino; }
std::string DTListarViaje::getConductor() const { return conductor; }

std::ostream& operator<<(std::ostream& os, const DTListarViaje& v) {
    std::ostream& ret = os;
    ret << "Codigo: " << v.getCodigo() << ", Fecha: " << v.getFecha() << ", Origen: " << v.getOrigen() << ", Destino: " << v.getDestino() << ", Conductor: " << v.getConductor();
    return ret;
}
