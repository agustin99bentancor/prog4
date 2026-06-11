#include "Reserva.h"
#include "Pasajero.h"
#include "Viaje.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha, Pasajero* p, Viaje* v) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = p;
    this->viaje = v;
}

Reserva::~Reserva() {}

int Reserva::getAsientosReservados() {
    return asientosReservados;
}

std::string Reserva::getNickPasajero() {
    return pasajero->getNickname();
}
