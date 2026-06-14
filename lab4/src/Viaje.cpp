#include "Viaje.h"
#include "Reserva.h"
#include "Vehiculo.h"

int Viaje::codigoGlobal = 1;

Viaje::Viaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = v;
    this->codigo = obtenerCodigo();
}

Viaje::~Viaje() {
    vehiculo->removerViaje(this);
    for (auto reserva : reservas) {
        delete reserva;
    }
}

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

DTListarViaje Viaje::getDTListarViaje() {
    return DTListarViaje(codigo, fecha, origen, destino, vehiculo->getNicknameConductor());
}

DTDetalleViaje Viaje::getDTDetalleViaje() {
    std::vector<DTDetalleReserva> res;
    for (Reserva* reserva : reservas) {
        res.push_back(reserva->getDTDetalleReserva());
    }
    return DTDetalleViaje(codigo, fecha, origen, destino, asientosPublicados, precio, vehiculo->getDTDetalleVehiculo(), res);
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
    std::string conductor = vehiculo->getNombreConductor();
    float calificacion = vehiculo->getCalificacionConductor();
    return DTConsultaViaje(codigo, marca, modelo, conductor, calificacion, precio * asientos);
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

DTUsuarioViaje Viaje::getDatosConductor() {
    return vehiculo->getDatosConductor();
}

std::vector<DTUsuarioViaje> Viaje::getDatosPasajeros() {
    std::vector<DTUsuarioViaje> ret;
    for (Reserva* reserva : reservas) {
        ret.push_back(reserva->getDatosPasajero());
    }
    return ret;
}

bool Viaje::pertenece(std::string nickname) {
    if (vehiculo->getNicknameConductor() == nickname) {
        return true;
    }
    for (Reserva* reserva : reservas) {
        if (reserva->getNickPasajero() == nickname) {
            return true;
        }
    }
    return false;
}

Reserva* Viaje::getReservaByNick(std::string nick) {
    for (Reserva* reserva : reservas) {
        if (reserva->getNickPasajero() == nick) {
            return reserva;
        }
    }
    return nullptr;
}