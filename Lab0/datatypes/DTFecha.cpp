#include "DTFecha.h"

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
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}
