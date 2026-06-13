#ifndef PASAJERO_H
#define PASAJERO_H

#include <string>

#include "Usuario.h"
#include "dtypes/DTListarViaje.h"

class Reserva;

class Pasajero : public Usuario {
private:
    std::string ci;

    std::set<Reserva*> reservas;

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();

    std::set<DTListarViaje> getDTListarViajes();
    void agregarReserva(Reserva* r);
    void eliminarReserva(Reserva* r);
};

#endif
