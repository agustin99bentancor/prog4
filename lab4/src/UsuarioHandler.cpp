#include "UsuarioHandler.h"
#include "Pasajero.h"
#include "Conductor.h"

UsuarioHandler* UsuarioHandler::instancia = nullptr;

UsuarioHandler::UsuarioHandler() {}

UsuarioHandler* UsuarioHandler::getInstancia(){
    if (instancia == nullptr) {
        instancia = new UsuarioHandler();
    }
    return instancia;
}

bool UsuarioHandler::existeUsuario(std::string nickname){
    for(std::set<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it){
        if((*it)->getNickname() == nickname){
            return true;
        }
    }
    return false;
}

Usuario* UsuarioHandler::getUsuario(std::string nickname){
    for(std::set<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it){
        if((*it)->getNickname() == nickname){
            return (*it);
        }
    }
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