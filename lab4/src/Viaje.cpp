#include "Viaje.h"
#include "Reserva.h"
#include "Vehiculo.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTDetalleVehiculo.h"

int Viaje::codigoGlobal = 0;

Viaje::Viaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = v;
    this->codigo = obtenerCodigo();
}

Viaje::~Viaje() {}

DTFecha Viaje::getFecha() {
    return fecha;
}

int Viaje::getCodigo() {
    return codigo;
}

std::string Viaje::getOrigen() {
    return origen;
}

std::string Viaje::getDestino() {
    return destino;
}

int Viaje::getAsientosPublicados() {
    return asientosPublicados;
}

int Viaje::obtenerCodigo() {
    int cod = codigoGlobal;
    codigoGlobal++;
    return cod;
}

int Viaje::getAReservados() {
    int reservados = 0;
    for(std::set<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it){
        reservados += (*it)->getAsientosReservados();
    }
    return reservados;
}

DTConsultaViaje Viaje::getDTcv(int asientos) {
    std::string marca = vehiculo->getMarca();
    std::string modelo = vehiculo->getModelo();
    std::string conductor = vehiculo->getNicknameConductor();
    float calificacion = vehiculo->getCalificacionConductor();
    return DTConsultaViaje(codigo, marca, modelo, conductor, calificacion, precio * asientos);
}

void Viaje::agregarReserva(Reserva* r) {
    reservas.insert(r);
}

bool Viaje::puedeReservar(std::string nickname, int asientos) {
    int reservados = 0;
    for(std::set<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it){
        int acc = (*it)->getAsientosReservados();
        reservados += acc;
        if (reservados + asientos > asientosPublicados) {
            return false;
        }
        std::string nick = (*it)->getNickPasajero();
        if (nick == nickname) {
            return false;
        }
    }
    return true;
}