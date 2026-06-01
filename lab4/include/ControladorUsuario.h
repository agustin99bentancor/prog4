#ifndef CONTROLADOR_USUARIO_H
#define CONTROLADOR_USUARIO_H

#include "IUsuario.h"

class ControladorUsuario : public IUsuario {
public:

    bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
    bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas);
    int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    std::set<DTUsuario> listarUsuarios();
    std::set<DTListarViaje> listarViajes(std::string nickname);
    std::set<DTUsuarioViaje> listarUsuariosViaje(int codigo);
    bool calificarUsuario(std::string nicknameCalificado, int calificacion);
};

#endif