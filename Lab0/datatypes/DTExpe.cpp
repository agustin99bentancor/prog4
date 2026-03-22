#include "DTExpe.h"

using std::string;
using std::set;
using std::ostream;

DTExpe::DTExpe(string codigoReserva, string descripcion, DTFecha fechaF, set<string> turistas): fecha(fechaF) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->turistas = turistas;
}

string DTExpe::getCodigoReserva() const {
    return this->codigoReserva;
}

string DTExpe::getDescripcion() const {
    return this->descripcion;
}

DTFecha DTExpe::getFecha() const {
    return this->fecha;
}

set<string> DTExpe::getTuristas() const {
    return this->turistas;
}

ostream& operator<<(ostream& os, const DTExpe& dtexpe) {
    os << dtexpe.getCodigoReserva() << "->" << dtexpe.getDescripcion() << "(" << dtexpe.getFecha().toString() << ")/";
    set<string> turistas = dtexpe.getTuristas();
    for (set<string>::iterator it = turistas.begin(); it != turistas.end(); ++it) {
        if (it != turistas.begin()) {
            os << ",";
        }
        os << *it;
    }
    os << '\n';
    return os;
}