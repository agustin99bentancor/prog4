#include "dtypes/DTUsuarioViaje.h"

DTUsuarioViaje::DTUsuarioViaje(std::string nickname, TipoUsuario tipo)
    {
    this->nickname = nickname;
    this->tipo = tipo;
}

std::string DTUsuarioViaje::getNickname() const { return nickname; }
TipoUsuario DTUsuarioViaje::getTipo() const { return tipo; }

std::ostream& operator<<(std::ostream& os, const DTUsuarioViaje& u) {
    os << "Nickname: " << u.getNickname() << ", Tipo: " << (u.getTipo() == TipoUsuario::Conductor ? "Conductor" : "Pasajero");
    return os;
}
