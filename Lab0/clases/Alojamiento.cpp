
#include "./Alojamiento.h"
#include "./Turista.h"
#include "../datatypes/DTFecha.h"

Alojamiento::Alojamiento(std::string codigoReserva, std::string decripcion, int precioBase, DTFecha fecha, std::string hotel, int cantNoches)
    : Experiencia(codigoReserva, decripcion, precioBase, fecha) {
    this->hotel = hotel;
    this->regimen = regimen;
    this->cantNoches = cantNoches;
}

Alojamiento::~Alojamiento() {}

float Alojamiento::calcularCosto() {
    float resultado = Experiencia::getPrecioBase() * this->cantNoches;
    if(this->regimen == AllInclusive) {
        resultado += 10*this->cantNoches;
    }
    return resultado;
}