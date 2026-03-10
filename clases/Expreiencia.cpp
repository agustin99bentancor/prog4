#include "./Expreiencia.h"

Experiencia::Experiencia(string codigoReserva, string decripcion, int precioBase, DTFecha fecha) {
    this->codigoReserva = codigoReserva;
    this->decripcion = decripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
}

DTExpe Experiencia::getDT() {
    return;
}