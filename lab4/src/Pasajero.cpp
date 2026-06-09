#include "Pasajero.h"
#include "Reserva.h"
#include "Viaje.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}

Pasajero::~Pasajero() {}

std::set<DTListarViaje> Pasajero::getDTListarViajes() {
    std::set<DTListarViaje> ret;
    for(std::set<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it){
        Viaje* v = (*it)->getViaje();
        DTListarViaje dtv = v->getDTListarViaje();
        ret.insert(dtv);
    }
    return ret;
}