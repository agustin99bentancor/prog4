#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>

#include "dtypes/DTUsuario.h"
#include "dtypes/DTListarViaje.h"

class Calificacion;

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    float calificacionPromedio;

    std::set<Calificacion*> realiza;
    
public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    DTUsuario getDT();
    std::set<DTListarViaje> getDTListarViajes();
    bool existeCalificacion(std::string nicknameCalificado, int codigo);
    void agregarCalificacion(Calificacion* ca);

    std::string getNickname();
    float getCalificacionPromedio();
};

#endif
