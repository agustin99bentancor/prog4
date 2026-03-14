
#include "./EventoCultural.h"
#include "./Turista.h"
#include "../datatypes/DTFecha.h"


EventoCultural::EventoCultural(std::string codigoReserva, std::string decripcion, int precioBase, DTFecha fecha, std::string ubicacion, bool useCupo)
    : Experiencia(codigoReserva, decripcion, precioBase, fecha) {
    this->ubicacion = ubicacion;
    this->useCupo = useCupo;
}

EventoCultural::~EventoCultural() {}

float EventoCultural::calcularCosto() {
    int cant = Experiencia::getTuristas().size();
    int resultado = Experiencia::getPrecioBase();

    return resultado;
}