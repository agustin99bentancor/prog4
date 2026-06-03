#include "../include/ControladorUsuario.h"
#include "../include/UsuarioHandler.h"
#include "../include/VehiculoHandler.h"
#include "../include/Conductor.h"

bool ControladorUsuario::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    bool existe = uh->existeUsuario(nickname);
    if(!existe){
        uh->crearPasajero(nickname, nombre, contrasena, email, ci);
    }
    return !existe;
}

bool ControladorUsuario::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    bool existe = uh->existeUsuario(nickname);
    if(!existe){
        uh->crearConductor(nickname, nombre, contrasena, email, libretas);
    }
    return !existe;
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo){
    VehiculoHandler* vh = VehiculoHandler::getInstancia();
    bool existe = vh->existeVehiculo(matricula);
    if(existe){
        return -1;
    }
    if(!existe){
        UsuarioHandler* uh = UsuarioHandler::getInstancia();
        Conductor* c = (Conductor*)uh->getUsuario(nickname);
        bool libreta = c->tieneLibretaCompatible(tipo);
        if(!libreta){
            return -2;
        }
        if(libreta){
            Vehiculo* v = vh->crearVehiculo(matricula, capacidad, modelo, marca, tipo, c);
            c->agregarVehiculo(v);
        }
    }
    return 0;
}