#include <iostream>
#include <string>
#include <set>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"

class Experiencia;  // Forward declaration

class Turista {
private:
    std::string ci;
    std::string nombre;
    std::string email;
    std::set<Experiencia *> experiencias;

public:
    Turista(std::string ci, std::string nombre, std::string email);
    virtual ~Turista();

    std::string getNombre();

    std::string toString();
    std::set<std::string> listarExperiencias(DTFecha desde, float min, float max);
};