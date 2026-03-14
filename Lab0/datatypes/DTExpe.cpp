#include "DTExpe.h"
#include "../clases/Turista.h"

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

std::ostream DTExpe::operator<<(const DTExpe& dtexpe) const {
    std::cout << "Codigo Reserva: " << dtexpe.codigoReserva << std::endl;
    std::cout << "Descripcion: " << dtexpe.descripcion << std::endl;
    std::cout << "Fecha: " << dtexpe.fecha.toString() << std::endl;
    std::cout << "Turistas: ";

    for (std::string turista : dtexpe.turista) {
        std::cout << turista;
        std::cout << ",";
    }

    std::cout << std::endl;
}
