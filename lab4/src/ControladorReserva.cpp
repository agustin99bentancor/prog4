#include "ControladorReserva.h"
#include "dtypes/DTVehiculosConductor.h"
#include "UsuarioHandler.h"
#include "ViajeHandler.h"
#include "VehiculoHandler.h"
#include "Conductor.h"
#include "Viaje.h"
#include "Pasajero.h"
#include "Reserva.h"

std::set<std::string> ControladorReserva::listarPasajeros() {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    std::set<std::string> ret = uh->getPasajeros();
    return ret;
}

std::multiset<DTConsultaViaje> ControladorReserva::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {
    std::multiset<DTConsultaViaje> ret;
    ViajeHandler* vih = ViajeHandler::getInstancia();
    std::set<Viaje*> viajes = vih->getViajes();

    for(auto viaje : viajes){
        int reservados = viaje->getAReservados();
        if(viaje->getFecha() == fecha && viaje->getOrigen() == origen && viaje->getDestino() == destino && reservados + asientos <= viaje->getAsientosPublicados()){
            ret.insert(viaje->getDTcv(asientos));
        }
    }
    
    return ret;
}

bool ControladorReserva::generarReserva(std::string nickname, int codigo, int asientos) {
    ViajeHandler* vih = ViajeHandler::getInstancia();
    Viaje* vi = vih->getViaje(codigo);
    if (!vi->puedeReservar(nickname, asientos)) {
        return false;
    }
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Pasajero* p = (Pasajero*)uh->getUsuario(nickname);
    Reserva* r = new Reserva(asientos, vi->getFecha(), p, vi);
    vi->agregarReserva(r);
    p->agregarReserva(r);
    return true;
}

std::vector<DTVehiculosConductor> ControladorReserva::listarVehiculosConductor(std::string nickname) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Conductor* c = (Conductor*)uh->getUsuario(nickname);
    std::vector<DTVehiculosConductor> vehiculos = c->listarVehiculos();
    return vehiculos;
}

bool ControladorReserva::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
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
    ViajeHandler* vih = ViajeHandler::getInstancia();
    Viaje* cvi = vih->crearViaje(v, fecha, origen, destino, asientos, precio);
    v->asociarViaje(cvi);
    return true;
}

std::vector<DTListarViaje> ControladorReserva::listarViajes() {
    ViajeHandler* vh = ViajeHandler::getInstancia();
    return vh->getDTListarViajes();
}

DTDetalleViaje ControladorReserva::detalleViaje(int codigo) {
    codigoViajeAEliminar = codigo;
    ViajeHandler* vh = ViajeHandler::getInstancia();
    Viaje* v = vh->getViaje(codigo);
    DTDetalleViaje dtvi = v->getDTDetalleViaje();
    return dtvi;
}

void ControladorReserva::eliminarViaje() {
    ViajeHandler* vh = ViajeHandler::getInstancia();
    vh->eliminarViaje(codigoViajeAEliminar);
    codigoViajeAEliminar = CODIGO_NULO;
}

void ControladorReserva::cancelarEliminarViaje() {
    codigoViajeAEliminar = CODIGO_NULO;
}