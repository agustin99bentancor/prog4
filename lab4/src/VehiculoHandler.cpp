#include "../include/VehiculoHandler.h"

VehiculoHandler* VehiculoHandler::instancia = nullptr;

VehiculoHandler::VehiculoHandler() {}

VehiculoHandler* VehiculoHandler::getInstancia(){
    if (instancia == nullptr) {
        instancia = new VehiculoHandler();
    }
    return instancia;
}

//ver si usar map en lugar de set, asi podemos usar clave para buscar
bool VehiculoHandler::existeVehiculo(std::string matricula){
    return true;
}

Vehiculo* VehiculoHandler::crearVehiculo(std::string matricula, int capacidad, std::string modelo, std::string marca, TipoVehiculo tipo, Conductor* c){
    Vehiculo* v = new Vehiculo(matricula, capacidad, modelo, marca, tipo, c);
    vehiculos.insert(v);
    return v;
}