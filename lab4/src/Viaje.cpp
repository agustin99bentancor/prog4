#include "Viaje.h"
#include "Reserva.h"
#include "Vehiculo.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* v) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = v;
}

Viaje::~Viaje() {}

DTFecha Viaje::getFecha() {
    return this->fecha;
}

int Viaje::getCodigo() {
    return this->codigo;
}

void Viaje::setVehiculo(Vehiculo* v) {
    this->vehiculo = v;
}

DTUsuarioViaje Viaje::getDatosConductor() {
    return vehiculo->getDatosConductor();
}

std::set<DTUsuarioViaje> Viaje::getDatosPasajeros() {
    std::set<DTUsuarioViaje> ret;
    for(std::set<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it){
        ret.insert((*it)->getDatosPasajero());
    }
    return ret;
}
