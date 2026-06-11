#include "Pasajero.h"
#include "Reserva.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}

Pasajero::~Pasajero() {}

void Pasajero::agregarReserva(Reserva* r) {
    reservas.insert(r);
}
