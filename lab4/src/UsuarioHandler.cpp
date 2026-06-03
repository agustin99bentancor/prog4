#include "../include/UsuarioHandler.h"
#include "../include/Pasajero.h"
#include "../include/Conductor.h"

UsuarioHandler* UsuarioHandler::instancia = nullptr;

UsuarioHandler::UsuarioHandler() {}

UsuarioHandler* UsuarioHandler::getInstancia(){
    if (instancia == nullptr) {
        instancia = new UsuarioHandler();
    }
    return instancia;
}

//ver si usar map en lugar de set, asi podemos usar clave para buscar
bool UsuarioHandler::existeUsuario(std::string nickname){
    return true;
}

//ver si usar map en lugar de set, asi podemos usar clave para buscar
Usuario* UsuarioHandler::getUsuario(std::string nickname){
    return nullptr;
}

void UsuarioHandler::crearPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci){
    Pasajero* u = new Pasajero(nickname, nombre, contrasena, email, ci);
    usuarios.insert(u);
}

void UsuarioHandler::crearConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas){
    Conductor* u = new Conductor(nickname, nombre, contrasena, email, libretas);
    usuarios.insert(u);
}