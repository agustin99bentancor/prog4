#include "ControladorReserva.h"
#include "dtypes/DTVehiculosConductor.h"
#include "UsuarioHandler.h"
#include "ViajeHandler.h"
#include "VehiculoHandler.h"
#include "Conductor.h"

std::set<std::string> listarPasajeros() {
    std::set<std::string> ret;
    return ret;
}

std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {
    std::set<DTConsultaViaje> ret;
    return ret;
}

bool generarReserva(std::string nickname, int codigo, int asientos) {
    return false;
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