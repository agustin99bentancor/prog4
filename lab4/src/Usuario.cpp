#include "Usuario.h"
#include "Calificacion.h"
#include "Reserva.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
    this->calificacionPromedio = 0.0;
}

Usuario::~Usuario() {}

std::string Usuario::getNickname() {
    return nickname;
}

std::string Usuario::getNombre() {
    return nombre;
}

float Usuario::getCalificacionPromedio() {
    return calificacionPromedio;
}

void Usuario::agregarRealiza(Calificacion* ca) {
    realiza.insert(ca);
}

void Usuario::agregarRecibe(Calificacion* ca) {
    recibe.insert(ca);
}

void Usuario::eliminarRealiza(Calificacion* ca) {
    realiza.erase(ca);
}

void Usuario::eliminarRecibe(Calificacion* ca) {
    recibe.erase(ca);
}

DTUsuario Usuario::getDT() {
    return DTUsuario(nickname, nombre);
}

bool Usuario::existeCalificacion(std::string nicknameCalificado, int codigo) {
    for (auto calificacion : realiza) {
        if (calificacion->getCalificado()->getNickname() == nicknameCalificado && calificacion->getReserva()->getCodigoViaje() == codigo) {
            return true;
        }
    }
    return false;
}
