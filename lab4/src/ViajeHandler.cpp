#include "ViajeHandler.h"

ViajeHandler* ViajeHandler::instancia = nullptr;

ViajeHandler::ViajeHandler() {}

ViajeHandler* ViajeHandler::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ViajeHandler();
    }
    return instancia;
}

Viaje* ViajeHandler::getViaje(int codigo) {
    return nullptr;
}
