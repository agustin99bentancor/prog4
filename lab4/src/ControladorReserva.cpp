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

    for(std::set<Viaje*>::iterator it = viajes.begin(); it != viajes.end(); ++it){
        int reservados = (*it)->getAReservados();
        if((*it)->getFecha() == fecha && (*it)->getOrigen() == origen && (*it)->getDestino() == destino && reservados + asientos <= (*it)->getAsientosPublicados()){
            ret.insert((*it)->getDTcv(asientos));
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

bool ControladorReserva::existeVehiculo(std::string matricula){
    return VehiculoHandler::getInstancia()->getVehiculo(matricula) != nullptr;
}

void ControladorReserva::eliminarViaje(int codigo) {
    ViajeHandler::getInstancia()->eliminarViaje(codigo);
}

DTDetalleViaje ControladorReserva::obtenerDetalleViaje(int codigo) {
    return ViajeHandler::getInstancia()->obtenerDetalleViaje(codigo);
}

std::vector<DTListarViaje> ControladorReserva::listarViajes() {
    return ViajeHandler::getInstancia()->getDTListarViajes();
}