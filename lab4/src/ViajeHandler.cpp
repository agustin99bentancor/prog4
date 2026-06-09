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
    Viaje* viaje = new Viaje(fecha, origen, destino, asientos, precio, v);
    viajes[viaje->getCodigo()] = viaje;
    return viaje;
}
