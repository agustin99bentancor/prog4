#ifndef USUARIO_HANDLER_H
#define USUARIO_HANDLER_H

#include <string>
#include <set>
#include <map>
#include <vector>

#include "dtypes/TipoLibreta.h"
#include "dtypes/DTUsuario.h"

class Usuario;

class UsuarioHandler {
private:

    static UsuarioHandler* instancia;
    std::map<std::string, Usuario*> usuarios;

    UsuarioHandler();
public:

    static UsuarioHandler* getInstancia();

    bool existeUsuario(std::string nickname);
    void crearPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
    void crearConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas);
    Usuario* getUsuario(std::string nickname);
    std::vector<DTUsuario> getDTUsuarios();
    std::set<std::string> getPasajeros();
};

#endif