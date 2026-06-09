#include "Reserva.h"
#include "Pasajero.h"
#include "Viaje.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}

Reserva::~Reserva() {}

Viaje* Reserva::getViaje() {
    return this->viaje;
}

DTUsuarioViaje Reserva::getDatosPasajero() {
    return DTUsuarioViaje(pasajero->getNickname(), TipoUsuario::Pasajero);
}