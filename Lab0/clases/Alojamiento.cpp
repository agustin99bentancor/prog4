
#include "./Alojamiento.h"
#include "./Turista.h"
#include "../datatypes/DTFecha.h"

Alojamiento::Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string hotel, TipoRegimen regimen, int cantNoches)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->hotel = hotel;
    this->regimen = regimen;
    this->cantNoches = cantNoches;
}

Alojamiento::~Alojamiento() {}

float Alojamiento::calcularCosto() {
    float resultado = getPrecioBase() * this->cantNoches;
    if(this->regimen == AllInclusive) {
        resultado += 10*this->cantNoches;
    }
    return resultado;
}