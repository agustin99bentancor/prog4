#include "dtypes/DTDetalleReserva.h"

DTDetalleReserva::DTDetalleReserva(int asientosReservados, DTFecha fecha, std::string pasajero) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = pasajero;
}

int DTDetalleReserva::getAsientosReservados() const { return asientosReservados; }
DTFecha DTDetalleReserva::getFecha() const { return fecha; }
std::string DTDetalleReserva::getPasajero() const { return pasajero; }

std::ostream& operator<<(std::ostream& os, const DTDetalleReserva& r) {
    os << "AsientosReservados: " << r.getAsientosReservados() << ", Fecha: " << r.getFecha() << ", Pasajero: " << r.getPasajero();
    return os;
}