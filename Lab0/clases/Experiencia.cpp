#include <iostream>
#include <string>
#include "./Experiencia.h"
#include "./Turista.h"


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

DTExpe Experiencia::getDT() {
    set<string> nombresTuristas;
    for (set<Turista *>::iterator it = this->turistas.begin(); it != this->turistas.end(); ++it) {
        if (*it != NULL) {
            nombresTuristas.insert((*it)->getNombre());
        }
    }
    DTExpe dt(codigoReserva, decripcion, fecha, nombresTuristas);
    return dt;
}

int Experiencia::getPrecioBase() {
    return this->precioBase;
}

set<Turista *> Experiencia::getTuristas() {
    return this->turistas;
}