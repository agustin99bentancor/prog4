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
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Conductor* c = (Conductor*)uh->getUsuario(nickname);
    bool libreta = c->tieneLibretaCompatible(tipo);
    if(!libreta){
        return -2;
    }
    Vehiculo* v = vh->crearVehiculo(matricula, capacidad, marca, modelo, tipo, c);
    c->agregarVehiculo(v);
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

bool ControladorUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    return false;
}

std::vector<DTListarViaje> ControladorUsuario::listarViajes() {
    ViajeHandler* vh = ViajeHandler::getInstancia();
    return vh->getDTListarViajes();
}

DTDetalleViaje ControladorUsuario::detalleViaje(int codigo) {
    //guarda en memoria el codigo
    codigoViajeAEliminar = codigo;
    ViajeHandler* vh = ViajeHandler::getInstancia();
    Viaje* v = vh->getViaje(codigo);
    DTDetalleViaje detalle = v->getDTDetalleViaje();
    DTDetalleViaje dtvi(v->getCodigo(), v->getFecha(), v->getOrigen(), v->getDestino(), v->getAsientosPublicados(), v->getPrecio(), detalle.getVehiculo(), detalle.getReservas());
    return dtvi;
}

void ControladorUsuario::eliminarViaje() {
    ViajeHandler* vh = ViajeHandler::getInstancia();
    vh->eliminarViaje(codigoViajeAEliminar);
}

void ControladorUsuario::cancelarEliminarViaje() {
    codigoViajeAEliminar = CODIGO_NULO;
}