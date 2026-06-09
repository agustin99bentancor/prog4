#include "Usuario.h"
#include "Calificacion.h"
#include "dtypes/DTUsuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

Usuario::~Usuario() {}

std::string Usuario::getNickname() const {
    return nickname;
}

DTUsuario Usuario::getDT() const {
    return DTUsuario(this->nickname, this->nombre);
}

void Usuario::agregarCalificacion(Calificacion* ca) {
    this->realiza.insert(ca);
}
