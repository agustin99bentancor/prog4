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
    return this->fecha;
}

int Viaje::getCodigo() {
    return this->codigo;
}

int Viaje::obtenerCodigo() {
    int cod = codigoGlobal;
    codigoGlobal++;
    return cod;
}


DTListarViaje Viaje::getDTListarViaje() {
    return DTListarViaje(
        this->codigo,
        this->fecha,
        this->origen,
        this->destino,
        this->vehiculo->getNicknameConductor()
    );
}

Vehiculo* Viaje::getVehiculo() {
    return this->vehiculo;
}

void Viaje::eliminarReservas() {
    for (std::set<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it) {
        delete *it;
    }
    reservas.clear();
}

DTDetalleViaje Viaje::getDTDetalleViaje() {

    std::vector<DTDetalleReserva> res;

    for (Reserva* r : reservas) {
        res.push_back(
            DTDetalleReserva(
                r->getAsientosReservados(),
                r->getFecha(),
                r->getNickPasajero()
            )
        );
    }

    return DTDetalleViaje(
        codigo,
        fecha,
        origen,
        destino,
        asientosPublicados,
        precio,
        vehiculo->getDTDetalleVehiculo(),
        res
    );
}