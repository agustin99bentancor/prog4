#include "DTFecha.h"
#include <sstream>

DTFecha::DTFecha() {
}

DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DTFecha::get_dia() {
    return this->dia;
}

int DTFecha::get_mes() {
    return this->mes;
}

int DTFecha::get_anio() {
    return this->anio;
}

string DTFecha::toString() const {
    stringstream ss;
    ss << dia << "/" << mes << "/" << anio;
    return ss.str();
}
