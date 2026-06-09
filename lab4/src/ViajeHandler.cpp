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
    int codigo = obtenerCodigo();
    Viaje* viaje = new Viaje(codigo, fecha, origen, destino, asientos, precio, v);
    viaje->setVehiculo(v);
    viajes[codigo] = viaje;
    return viaje;
}

int ViajeHandler::obtenerCodigo() {
    if (viajes.empty())
        return 1;
    return viajes.rbegin()->first + 1;
}
