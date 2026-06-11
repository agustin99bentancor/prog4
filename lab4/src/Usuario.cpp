#include "Usuario.h"
#include "Calificacion.h"

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

float Usuario::getCalificacionPromedio() {
    return calificacionPromedio;
}
