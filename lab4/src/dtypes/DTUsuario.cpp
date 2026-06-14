#include "dtypes/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre)
    {
    this->nickname = nickname;
    this->nombre = nombre;
}

std::string DTUsuario::getNickname() const { return nickname; }
std::string DTUsuario::getNombre() const { return nombre; }

std::ostream& operator<<(std::ostream& os, const DTUsuario& u) {
    os << "Nickname: " << u.getNickname() << ", Nombre: " << u.getNombre();
    return os;
}
