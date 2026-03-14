#include "./Experiencia.h"

Experiencia::Experiencia(string codigoReserva, string decripcion, int precioBase, DTFecha fecha) {
    this->codigoReserva = codigoReserva;
    this->decripcion = decripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
}

Experiencia::~Experiencia() {
}

string Experiencia::getCodigoReserva() {
    return this->codigoReserva;
}

float Experiencia::calcularCosto() {
    return precioBase;
}

DTExpe Experiencia::getDT() {
    set<string> turistas;
    DTExpe dt(codigoReserva, decripcion, fecha, turistas);
    return dt;
}