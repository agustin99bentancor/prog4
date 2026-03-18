
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

Turista::~Turista() {
    for (set<Experiencia *>::iterator it = this->participa.begin(); it != this->participa.end(); ++it) {
        Experiencia* exp = *it;
        if (exp != NULL) {
            exp->desvincularTurista(this);
        }
    }
    this->participa.clear();
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

string Turista::toString() {
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
    set<Experiencia*> participa = this->participa;
    for (set<Experiencia*>::iterator it = participa.begin(); it != participa.end(); ++it) {
        Experiencia* experiencia = *it;
        DTFecha fechaExperiencia = experiencia->getDT().getFecha();
        float costo = experiencia->calcularCosto();

        if (esPosterior(fechaExperiencia, desde) && costo >= min && costo <= max) {
            experiencias.insert(experiencia->getCodigoReserva());
        }
    }
    return experiencias;
}

void Turista::linkExperiencia(Experiencia* exp) {
    this->participa.insert(exp);
}

void Turista::desvincularExperiencia(Experiencia* exp) {
    this->participa.erase(exp);
}
