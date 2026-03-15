
#include "./EventoCultural.h"
#include "./Turista.h"
#include "../datatypes/DTFecha.h"


EventoCultural::EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string ubicacion, bool usoCupon)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->ubicacion = ubicacion;
    this->usoCupon = usoCupon;
}

EventoCultural::~EventoCultural() {}

float EventoCultural::calcularCosto() {
    int cant = Experiencia::getTuristas().size();
    int pbase = Experiencia::getPrecioBase();
    float resultado = pbase * cant;
    for (std::set<Turista*>::iterator it = listaTuristas.begin(); it != listaTuristas.end(); ++it) {
        if ((*it) != NULL && (*it)->usoCupon()) { 
            resultado -= 5.0f;
        }
    }
    return resultado;
}
