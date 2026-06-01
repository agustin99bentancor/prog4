#ifndef VIAJE_H
#define VIAJE_H

#include <string>
#include <set>

#include "dtypes/DTFecha.h"
#include "Reserva.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTUsuarioViaje.h"
#include "dtypes/DTConsultaViaje.h"
#include "Vehiculo.h"

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;

    std::set<Reserva*> reservas;
    Vehiculo* vehiculo;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();

    DTListarViaje getDTListarViaje();
    DTUsuarioViaje getDatosConductor();
    std::set<DTUsuarioViaje> getDatosPasajeros();
    bool pertenece(std::string nickname);
    Reserva* getReservaByNick(std::string nick);
    int getAReservados();
    DTConsultaViaje getDTcv();
    bool puedeReservar(std::string nickname, int asientos);
    void agregarReserva(Reserva* r);
    int getCodigo();
};

#endif
