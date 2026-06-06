#include "../include/ControladorUsuario.h"
#include "../include/UsuarioHandler.h"
#include "../include/VehiculoHandler.h"
#include "../include/ViajeHandler.h"
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

std::set<DTUsuario> ControladorUsuario::listarUsuarios() {
    std::set<DTUsuario> ret;
    return ret;
}

std::set<DTListarViaje> ControladorUsuario::listarViajes(std::string nickname) {
    std::set<DTListarViaje> ret;
    return ret;
}

std::set<DTUsuarioViaje> ControladorUsuario::listarUsuariosViaje(int codigo) {
    std::set<DTUsuarioViaje> ret;
    return ret;
}

std::set<DTVehiculosConductor> ControladorUsuario::listarVehiculosConductor(std::string nickname) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Conductor* c = (Conductor*)uh->getUsuario(nickname);
    std::set<DTVehiculosConductor> vehiculos = c->listarVehiculos();
    return vehiculos;
}

bool ControladorUsuario::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
    VehiculoHandler* vh = VehiculoHandler::getInstancia();
    Vehiculo* v = vh->getVehiculo(matricula);
    int capacidad = v->getCapacidad();
    if(capacidad < asientos){
        return false;
    }
    bool hayViajesFecha = v->hayViajesConductor(fecha);
    if(hayViajesFecha){
        return false;
    }
    ViajeHandler* viajeHandler = ViajeHandler::getInstancia();
    Viaje* cvi = viajeHandler->crearViaje(v, fecha, origen, destino, asientos, precio);
    v->asociarViaje(cvi);
    return true;
}

bool ControladorUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    return false;
}