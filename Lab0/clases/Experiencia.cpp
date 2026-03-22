#include "./Experiencia.h"
#include "./Turista.h"

using std::string;
using std::set;

Experiencia::Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fechaF): fecha(fechaF) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
}

Experiencia::~Experiencia() {
    for (set<Turista *>::iterator it = this->turistas.begin(); it != this->turistas.end(); ++it) {
        Turista* turista = *it;
        if (turista != NULL) {
            turista->desvincularExperiencia(this);
        }
    }
    this->turistas.clear();
}

string Experiencia::getCodigoReserva() const {
    return this->codigoReserva;
}

DTExpe Experiencia::getDT() const {
    set<string> nombresTuristas;
    for (set<Turista *>::iterator it = this->turistas.begin(); it != this->turistas.end(); ++it) {
        if (*it != NULL) {
            nombresTuristas.insert((*it)->getNombre());
        }
    }
    DTExpe dt(codigoReserva, descripcion, fecha, nombresTuristas);
    return dt;
}

int Experiencia::getPrecioBase() const {
    return this->precioBase;
}

set<Turista *> Experiencia::getTuristas() const {
    return this->turistas;
}

void Experiencia::linkTurista(Turista* t) {
    if (t != NULL) {
        this->turistas.insert(t);
    }
}

void Experiencia::desvincularTurista(Turista* t) {
    if (t != NULL) {
        this->turistas.erase(t);
    }
}