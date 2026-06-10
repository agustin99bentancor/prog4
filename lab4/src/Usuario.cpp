#include "Usuario.h"
#include "Calificacion.h"
#include "dtypes/DTUsuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
    this->calificacionPromedio = 0.0f; // Inicializamos el promedio
}

Usuario::~Usuario() {}

std::string Usuario::getNickname() const {
    return nickname;
}

std::string Usuario::getNombre() const {
    return nombre;
}

DTUsuario Usuario::getDT() const {
    return DTUsuario(this->nickname, this->nombre);
}

void Usuario::agregarCalificacion(Calificacion* ca) {
    this->realiza.insert(ca);
}

std::set<DTListarViaje> Usuario::getDTListarViajes() {
    std::set<DTListarViaje> res;
    return res;
}

bool Usuario::existeCalificacion(std::string nicknameCalificado, int codigo) {
    return false;
}
