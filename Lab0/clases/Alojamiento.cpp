#include "./Alojamiento.h"
#include "./Turista.h"
#include "../datatypes/DTFecha.h"

using std::string;

Alojamiento::Alojamiento(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, string hotel, TipoRegimen regimen, int cantNoches)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->hotel = hotel;
    this->regimen = regimen;
    this->cantNoches = cantNoches;
}

float Alojamiento::calcularCosto() {
    float resultado = getPrecioBase() * this->cantNoches;
    if(this->regimen == AllInclusive) {
        resultado += 10*this->cantNoches;
    }
    return resultado;
}