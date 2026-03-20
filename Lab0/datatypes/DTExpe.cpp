#include "DTExpe.h"

using std::string;
using std::set;
using std::ostream;

DTExpe::DTExpe() {
}

DTExpe::DTExpe(string codigoReserva, string descripcion, DTFecha fecha, set<string> turistas) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->fecha = fecha;
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