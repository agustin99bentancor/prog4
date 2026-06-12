#include "Calificacion.h"
#include "Reserva.h"
#include "Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->reserva = nullptr;
    this->califica = nullptr;
}

void Calificacion::setReserva(Reserva* r) {
    this->reserva = r;
}

void Calificacion::setUsuario(Usuario* u) {
    this->califica = u;
}

Reserva* Calificacion::getReserva() {
    return reserva;
}

Usuario* Calificacion::getUsuario() {
    return califica;
}

Calificacion::~Calificacion() {}
