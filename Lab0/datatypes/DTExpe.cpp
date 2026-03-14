#include "DTExpe.h"

DTExpe::DTExpe() {
}

DTExpe::DTExpe(string codigoReserva, string descripcion, DTFecha fecha, set<string> turista) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->fecha = fecha;
    this->turista = turista;
}

string DTExpe::getCodigoReserva() {
    return this->codigoReserva;
}

string DTExpe::getDescripcion() {
    return this->descripcion;
}

DTFecha DTExpe::getfecha() {
    return this->fecha;
}

set<string> DTExpe::getTurista() {
    return this->turista;
}
