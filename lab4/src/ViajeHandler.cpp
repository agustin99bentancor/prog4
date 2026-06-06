#include "../include/ViajeHandler.h"

ViajeHandler* ViajeHandler::instancia = nullptr;

ViajeHandler::ViajeHandler() {}

ViajeHandler* ViajeHandler::getInstancia(){
    if (instancia == nullptr) {
        instancia = new ViajeHandler();
    }
    return instancia;
}

Viaje* ViajeHandler::crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    //TODO: tiene vehiculo y no se usa 
    //      tengo q conseguir el coigo nose como
    Viaje* viaje = new Viaje(0, fecha, origen, destino, asientos, precio);
    viajes.insert(viaje);
    return viaje;
}
