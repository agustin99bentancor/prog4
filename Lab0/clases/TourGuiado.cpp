
#include "./TourGuiado.h"
#include "./Turista.h"
#include "../datatypes/DTFecha.h"


TourGuiado::TourGuiado(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string agencia, std::set<std::string> lugarVisitados)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->agencia = agencia;
    this->lugarVisitados= lugarVisitados;
}

TourGuiado::~TourGuiado() {}

float TourGuiado::calcularCosto() {
    int resultado = Experiencia::getPrecioBase() + (2 * this->lugarVisitados.size() * Experiencia::getTuristas().size());
    return resultado;
}