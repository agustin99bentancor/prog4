#include "../include/ViajeHandler.h"
#include "Viaje.h"
#include "Vehiculo.h"
#include "Conductor.h"


ViajeHandler* ViajeHandler::instancia = nullptr;

ViajeHandler::ViajeHandler() {}

ViajeHandler* ViajeHandler::getInstancia(){
    if (instancia == nullptr) {
        instancia = new ViajeHandler();
    }
    return instancia;
}

Viaje* ViajeHandler::crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    Viaje* viaje = new Viaje(v, fecha, origen, destino, asientos, precio);
    viajes[viaje->getCodigo()] = viaje;
    return viaje;
}

Viaje* ViajeHandler::getViaje(int codigo){
    auto it = viajes.find(codigo);

    if (it != viajes.end()) {
        return it->second;
    }

    return nullptr;
}

std::vector<DTListarViaje> ViajeHandler::getDTListarViajes() {
    std::vector<DTListarViaje> ret;

    for (auto it = viajes.begin(); it != viajes.end(); ++it) {
        ret.push_back(it->second->getDTListarViaje());
    }

    return ret;
}
void ViajeHandler::eliminarViaje(int codigo) {

    Viaje* v = viajes.at(codigo);

    v->eliminarReservas();

    v->getVehiculo()->removerViaje(v);

    viajes.erase(codigo);

    delete v;
}