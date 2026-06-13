#include "Calificacion.h"
#include "Reserva.h"
#include "Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->realiza = realiza;
    this->califica = califica;
    this->reserva = reserva;

}

Calificacion::~Calificacion() {
    realiza->eliminarRealiza(this);
    califica->eliminarRecibe(this);
}

void Calificacion::setCalificador(Usuario* u) {
    califica = u;
}

void Calificacion::setCalificado(Usuario* u) {
    realiza = u;
}

void Calificacion::setReserva(Reserva* r) {
    reserva = r;
}

Usuario* Calificacion::getCalificado() {
    return califica;
}

Reserva* Calificacion::getReserva() {
    return reserva;
}
