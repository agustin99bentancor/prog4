#include "DTFecha.h"
#include <sstream>

using std::string;
using std::stringstream;

DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DTFecha::getDia() const {
    return this->dia;
}

int DTFecha::getMes() const {
    return this->mes;
}

int DTFecha::getAnio() const {
    return this->anio;
}

string DTFecha::toString() const {
    stringstream ss;
    ss << dia << "/" << mes << "/" << anio;
    return ss.str();
}