#include "ControladorUsuario.h"
#include "UsuarioHandler.h"
#include "VehiculoHandler.h"
#include "ViajeHandler.h"
#include "Conductor.h"
#include "Viaje.h"

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
        Vehiculo* v = vh->crearVehiculo(matricula, capacidad, modelo, marca, tipo, c);
        c->agregarVehiculo(v);
    }
    return 0;
}

std::set<DTUsuario> ControladorUsuario::listarUsuarios() {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    return  uh->getDTUsuarios();
}

std::set<DTListarViaje> ControladorUsuario::listarViajes(std::string nickname) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Usuario* u = uh->getUsuario(nickname);
    std::set<DTListarViaje> ret = u->getDTListarViajes();
    return ret;
}

std::set<DTUsuarioViaje> ControladorUsuario::listarUsuariosViaje(int codigo) {
    //TODO: Nose esta funcion si quedo bien
    //std::set<DTUsuarioViaje> ret;
    ViajeHandler* vih = ViajeHandler::getInstancia();
    Viaje* v = vih->getViaje(codigo);
    DTUsuarioViaje conductor = v->getDatosConductor();
    std::set<DTUsuarioViaje> pasajeros = v->getDatosPasajeros();
    pasajeros.insert(conductor);
    return pasajeros;
}

bool ControladorUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    return false;
}