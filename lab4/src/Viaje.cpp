#include "Viaje.h"
#include "Reserva.h"
#include "Vehiculo.h"
#include "dtypes/DTUsuarioViaje.h"
#include "dtypes/TipoUsuario.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

Viaje::~Viaje() {}

DTUsuarioViaje Viaje::getDatosConductor() {

    return DTUsuarioViaje("stub_conductor", TipoUsuario::Conductor);
}

std::set<DTUsuarioViaje> Viaje::getDatosPasajeros() {
    std::set<DTUsuarioViaje> res;
    return res;
}

bool Viaje::pertenece(std::string nick) {
    return false;
}
