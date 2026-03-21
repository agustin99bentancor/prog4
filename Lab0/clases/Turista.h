#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include "../datatypes/DTFecha.h"

class Experiencia;

class Turista {
private:
    std::string ci;
    std::string nombre;
    std::string email;
    std::set<Experiencia *> participa;

public:
    Turista(std::string ci, std::string nombre, std::string email);
    ~Turista();
    
    void linkExperiencia(Experiencia* exp);
    void desvincularExperiencia(Experiencia* exp);
    
    std::string getCi() const;
    std::string getNombre() const;
    std::string getEmail() const;
    
    std::string toString() const;
    std::set<std::string> listarExperiencias(DTFecha desde, float min, float max);
};

#endif
