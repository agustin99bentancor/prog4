#include "Turista.h"

Turista::Turista(string ci, string nombre) {
    this->ci = ci;
    this->nombre = nombre;
}

string Turista::getCi() {
    return this->ci;
}
