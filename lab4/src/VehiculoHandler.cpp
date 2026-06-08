#include "VehiculoHandler.h"

VehiculoHandler* VehiculoHandler::instancia = nullptr;

VehiculoHandler::VehiculoHandler() {}

VehiculoHandler* VehiculoHandler::getInstancia(){
    if (instancia == nullptr) {
        instancia = new VehiculoHandler();
    }
    return instancia;
}

bool VehiculoHandler::existeVehiculo(std::string matricula){
    for(std::set<Vehiculo*>::iterator it = vehiculos.begin(); it != vehiculos.end(); ++it){
        if((*it)->getMatricula() == matricula){
            return true;
        }
    }
    return false;
}

Vehiculo* VehiculoHandler::getVehiculo(std::string matricula){
    for(std::set<Vehiculo*>::iterator it = vehiculos.begin(); it != vehiculos.end(); ++it){
        if((*it)->getMatricula() == matricula){
            return *it;
        }
    }
    return nullptr;
}

Vehiculo* VehiculoHandler::crearVehiculo(std::string matricula, int capacidad, std::string modelo, std::string marca, TipoVehiculo tipo, Conductor* c){
    Vehiculo* v = new Vehiculo(matricula, capacidad, modelo, marca, tipo, c);
    vehiculos.insert(v);
    return v;
}