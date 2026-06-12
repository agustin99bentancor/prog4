#include "Reserva.h"
#include "Pasajero.h"
#include "Viaje.h"
#include "Calificacion.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha, Pasajero* p, Viaje* v) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = p;
    this->viaje = v;
    this->calificacion = nullptr;
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
void Reserva::setCalificacion(Calificacion* c) {
    this->calificacion = c;
}

Calificacion* Reserva::getCalificacion() {
    return calificacion;
}

DTDetalleReserva Reserva::getDetalleReserva() {
    return DTDetalleReserva(
        this->asientosReservados,
        this->fecha,
        this->pasajero->getNickname()
    );
}

Reserva::~Reserva() {
    if (calificacion != nullptr) {
        delete calificacion;
        calificacion = nullptr;
    }
}
