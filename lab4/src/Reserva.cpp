#include "Reserva.h"
#include "Pasajero.h"
#include "Viaje.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}
int Reserva::getAsientosReservados() {
    return asientosReservados;
}

DTFecha Reserva::getFecha() {
    return fecha;
}

std::string Reserva::getNickPasajero() {
    return pasajero->getNickname();
}

Reserva::~Reserva() {}
