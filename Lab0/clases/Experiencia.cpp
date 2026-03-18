#include <iostream>
#include <string>
#include "./Experiencia.h"
#include "./Turista.h"


Experiencia::Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
}

Experiencia::~Experiencia() {
    for (set<Turista *>::iterator it = this->turistas.begin(); it != this->turistas.end(); ++it) {
        Turista* turista = *it;
        if (turista != NULL) {
            turista->desvincularExperiencia(this);
        }
    }
    this->turistas.clear();
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
    DTExpe dt(codigoReserva, descripcion, fecha, nombresTuristas);
    return dt;
}

int Experiencia::getPrecioBase() {
    return this->precioBase;
}

set<Turista *> Experiencia::getTuristas() {
    return this->turistas;
}

void Experiencia::linkTurista(Turista* t) {
    if (t != NULL) {
        this->turistas.insert(t);
    }
}

void Experiencia::desvincularTurista(Turista* t) {
    if (t != NULL) {
        this->turistas.erase(t);
    }
}
