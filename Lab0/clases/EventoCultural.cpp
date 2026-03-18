
#include "./EventoCultural.h"
#include "./Turista.h"
#include "../datatypes/DTFecha.h"


EventoCultural::EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string ubicacion, bool usoCupon)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->ubicacion = ubicacion;
    this->usoCupon = usoCupon;
}

float EventoCultural::calcularCosto() {
    int cant = Experiencia::getTuristas().size();
    int pbase = Experiencia::getPrecioBase();
    float resultado = pbase * cant;
    // El cupon es uno por Evento y no por turista, si se usa cupon se resta 5 unidades por turista en el evento
    if (this->usoCupon) {
        resultado -= (5.0f * cant);
    }
    return resultado;
}
