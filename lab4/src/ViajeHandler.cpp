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
    if (viajes.find(codigo) != viajes.end()) {
        return viajes[codigo];
    }
    return nullptr;
}

std::set<Viaje*> ViajeHandler::getViajes() {
    std::set<Viaje*> ret;
    for (auto& [codigo, viaje] : viajes) {
        ret.insert(viaje);
    }
    return ret;
}


DTDetalleViaje ViajeHandler::obtenerDetalleViaje(int codigo) {
    auto it = viajes.find(codigo);

    if (it == viajes.end()) {
        throw std::invalid_argument("Viaje no existe");
    }

    return it->second->getDTDetalleViaje();
}

std::vector<DTListarViaje> ViajeHandler::getDTListarViajes() {
    std::vector<DTListarViaje> ret;

    for (auto it = viajes.begin(); it != viajes.end(); ++it) {
        ret.push_back(it->second->getDTListarViaje());
    }

    return ret;
}

void ViajeHandler::eliminarViaje(int codigo) {

    auto it = viajes.find(codigo);

    if (it == viajes.end()) {
        return;
    }

    Viaje* v = it->second;

    v->eliminarReservas();         

    v->getVehiculo()->removerViaje(v);

    delete v;

    viajes.erase(it);
}