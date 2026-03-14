
#include <iostream>
#include <string>
#include <set>
#include "Turista.h"
#include "Experiencia.h"
#include "../datatypes/DTFecha.h"


Turista::Turista(string ci, string nombre, string email) {
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
}

string Turista::getCi() {
    return this->ci;
}

string Turista::getNombre() {
    return this->nombre;
}

string Turista::getEmail() {
    return this->email;
}

string Turista::to_string() {
    return this->ci + "->" + this->nombre + "/" + this->email;
}

bool esPosterior(DTFecha fecha, DTFecha desde) {
    if (fecha.get_anio() != desde.get_anio()) {
        return fecha.get_anio() > desde.get_anio();
    }
    if (fecha.get_mes() != desde.get_mes()) {
        return fecha.get_mes() > desde.get_mes();
    }
    return fecha.get_dia() > desde.get_dia();
}

set<string> Turista::listarExperiencias(DTFecha desde, float min, float max) {
    set<string> experiencias;
    for (Experiencia* experiencia : this->participa) {
        DTFecha fechaExperiencia = experiencia->getDT().getfecha();
        float costo = experiencia->calcularCosto();

        if (esPosterior(fechaExperiencia, desde) && costo >= min && costo <= max) {
            experiencias.insert(experiencia->getCodigoReserva());
        }
    }
    return experiencias;
}
