#include "Calificacion.h"
#include "Reserva.h"
#include "Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {
    calificador->eliminarRealiza(this);
    calificado->eliminarRecibe(this);
}

void Calificacion::setCalificador(Usuario* u) {
    calificador = u;
}

void Calificacion::setCalificado(Usuario* u) {
    calificado = u;
}

void Calificacion::setReserva(Reserva* r) {
    reserva = r;
}

Usuario* Calificacion::getCalificado() {
    return calificado;
}

Reserva* Calificacion::getReserva() {
    return reserva;
}

int Calificacion::getPuntaje() {
    return puntaje;
}