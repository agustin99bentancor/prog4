#include "./TourGuiado.h"
#include "./Turista.h"
#include "../datatypes/DTFecha.h"

using std::string;
using std::set;

TourGuiado::TourGuiado(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, string agencia, set<string> lugaresVisitados)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->agencia = agencia;
    this->lugaresVisitados = lugaresVisitados;
}

float TourGuiado::calcularCosto() {
    int resultado = Experiencia::getPrecioBase() + (2 * this->lugaresVisitados.size() * Experiencia::getTuristas().size());
    return resultado;
}