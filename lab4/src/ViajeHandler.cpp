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

void ViajeHandler::liberarMemoria() {
    delete instancia;
    instancia = nullptr;
}

ViajeHandler::~ViajeHandler() {
    for (auto& [codigo, viaje] : viajes) {
        delete viaje;
    }
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

std::vector<DTListarViaje> ViajeHandler::getDTListarViajes() {
    std::vector<DTListarViaje> ret;
    for (auto& [codigo, viaje] : viajes) {
        ret.push_back(viaje->getDTListarViaje());
    }
    return ret;
}

void ViajeHandler::eliminarViaje(int codigo) {
    Viaje* v = viajes[codigo];
    viajes.erase(codigo);
    delete v;
}

std::set<Viaje*> ViajeHandler::getViajes() {
    std::set<Viaje*> ret;
    for (auto& [codigo, viaje] : viajes) {
        ret.insert(viaje);
    }
    return ret;
}
