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
    return usuarios.find(nickname) != usuarios.end();
}

Usuario* UsuarioHandler::getUsuario(std::string nickname){
    if (usuarios.find(nickname) != usuarios.end()) {
        return usuarios[nickname];
    }
    return nullptr;
}

void UsuarioHandler::crearPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci){
    Pasajero* u = new Pasajero(nickname, nombre, contrasena, email, ci);
    usuarios[nickname] = u;
}

void UsuarioHandler::crearConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas){
    Conductor* u = new Conductor(nickname, nombre, contrasena, email, libretas);
    usuarios[nickname] = u;
}

std::set<std::string> UsuarioHandler::getPasajeros() {
    std::set<std::string> ret;
    for(auto& [nickname, usuario] : usuarios){
        if(dynamic_cast<Pasajero*>(usuario) != nullptr){
            ret.insert(usuario->getNickname());
        }
    }
    return ret;
}