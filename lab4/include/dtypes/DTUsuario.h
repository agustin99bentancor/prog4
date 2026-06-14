#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include <string>
#include <iostream>

class DTUsuario {
private:
    std::string nickname;
    std::string nombre;

public:
    DTUsuario(std::string nickname, std::string nombre);

    std::string getNickname() const;
    std::string getNombre() const;
};

std::ostream& operator<<(std::ostream& os, const DTUsuario& dtUsuario);

#endif
