#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <vector>

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
    std::set<Calificacion*> recibe;
    
public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    DTUsuario getDT();
    virtual std::vector<DTListarViaje> getDTListarViajes() = 0;
    bool existeCalificacion(std::string nicknameCalificado, int codigo);
    void agregarRealiza(Calificacion* ca);
    void agregarRecibe(Calificacion* ca);
    void eliminarRealiza(Calificacion* ca);
    void eliminarRecibe(Calificacion* ca);

    std::string getNickname();
    float getCalificacionPromedio();
    std::string getNombre();
};

#endif
