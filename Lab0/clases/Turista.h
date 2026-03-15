#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include "../datatypes/DTFecha.h"
using namespace std;

class Experiencia;

class Turista {
private:
    string ci;
    string nombre;
    string email;
    set<Experiencia *> participa;

public:
    Turista(string ci, string nombre, string email);

    string getCi();
    string getNombre();
    string getEmail();

    string toString();
    set<string> listarExperiencias(DTFecha desde, float min, float max);
};

#endif