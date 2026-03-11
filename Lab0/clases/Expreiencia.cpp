#include "./Experiencia.h"
#include "../datatypes/DTExpe.h"

Experiencia::Experiencia(string codigoReserva, string decripcion, int precioBase, DTFecha fecha) {
    this->codigoReserva = codigoReserva;
    this->decripcion = decripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
}

DTExpe Experiencia::getDT() {
    std::set<std::string> turistas;
    for (std::set<Turista *>::iterator it = this->turistas.begin(); it != this->turistas.end(); ++it) {
        turistas.insert((*it)->getNombre());
    }
    return DTExpe(this->codigoReserva, this->decripcion, this->precioBase, this->fecha, turistas);
}