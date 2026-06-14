#include "VehiculoHandler.h"

VehiculoHandler* VehiculoHandler::instancia = nullptr;

VehiculoHandler::VehiculoHandler() {}

VehiculoHandler* VehiculoHandler::getInstancia(){
    if (instancia == nullptr) {
        instancia = new VehiculoHandler();
    }
    return instancia;
}

void VehiculoHandler::liberarMemoria() {
    delete instancia;
    instancia = nullptr;
}

VehiculoHandler::~VehiculoHandler() {
    for (auto& [matricula, vehiculo] : vehiculos) {
        delete vehiculo;
    }
}

bool VehiculoHandler::existeVehiculo(std::string matricula){
    return vehiculos.find(matricula) != vehiculos.end();
}

Vehiculo* VehiculoHandler::getVehiculo(std::string matricula){
    if (vehiculos.find(matricula) != vehiculos.end()) {
        return vehiculos[matricula];
    }
    return nullptr;
}

Vehiculo* VehiculoHandler::crearVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo, Conductor* c){
    Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo, c);
    vehiculos[matricula] = v;
    return v;
}