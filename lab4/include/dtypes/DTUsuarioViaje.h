#ifndef DT_USUARIO_VIAJE_H
#define DT_USUARIO_VIAJE_H

#include <string>
#include "TipoUsuario.h" // Asegúrate de incluir tu enum correspondiente

class DTUsuarioViaje {
private:
    std::string nickname;
    TipoUsuario tipo;

public:
    DTUsuarioViaje(std::string nickname, TipoUsuario tipo);
    std::string getNickname() const;
    TipoUsuario getTipo() const;

    bool operator<(const DTUsuarioViaje& otro) const {
        return this->nickname < otro.nickname;
    }
};

#endif
