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

Vehiculo* Viaje::getVehiculo() {
    return vehiculo;
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
    for(auto reserva : reservas){
        reservados += reserva->getAsientosReservados();
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

DTListarViaje Viaje::getDTListarViaje() {
    return DTListarViaje(
        codigo,
        fecha,
        origen,
        destino,
        vehiculo->getNicknameConductor()
    );
}

void Viaje::agregarReserva(Reserva* r) {
    reservas.insert(r);
}

bool Viaje::puedeReservar(std::string nickname, int asientos) {
    int reservados = 0;
    for(auto reserva : reservas){
        int acc = reserva->getAsientosReservados();
        reservados += acc;
        if (reservados + asientos > asientosPublicados) {
            return false;
        }
        std::string nick = reserva->getNickPasajero();
        if (nick == nickname) {
            return false;
        }
    }
    return true;
}


void Viaje::eliminarReservas() {
    for (std::set<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it) {
        delete *it;
    }
    reservas.clear();
}

DTDetalleViaje Viaje::getDTDetalleViaje() {

    std::vector<DTDetalleReserva> datosReservas;

    for (Reserva* r : reservas) {
        datosReservas.push_back(r->getDetalleReserva());
    }

    return DTDetalleViaje(
        codigo,
        fecha,
        origen,
        destino,
        asientosPublicados,
        precio,
        vehiculo->getDTDetalleVehiculo(),
        datosReservas
    );
}

void Viaje::desasociarVehiculo() {
    if (vehiculo != nullptr) {
        vehiculo->removerViaje(this);
        vehiculo = nullptr;
    }
}