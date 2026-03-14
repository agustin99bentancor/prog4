#include "DTExpe.h"
#include "../clases/Turista.h"

DTExpe::DTExpe() {
}

DTExpe::DTExpe(string codigoReserva, string descripcion, DTFecha fecha, set<string> turistas) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->fecha = fecha;
    this->turistas = turistas;
}

string DTExpe::getCodigoReserva() {
    return this->codigoReserva;
}

string DTExpe::getDescripcion() {
    return this->descripcion;
}

DTFecha DTExpe::getFecha() {
    return this->fecha;
}

set<string> DTExpe::getTuristas() {
    return this->turistas;
}

ostream& operator<<(ostream& os, DTExpe& dtexpe) {
    os << dtexpe.getCodigoReserva() << "->" << dtexpe.getDescripcion() << "(" << dtexpe.getFecha().toString() << ")/";
    for (auto tur : dtexpe.getTuristas()) {
        os << tur << ",";
    }
    return os;
}