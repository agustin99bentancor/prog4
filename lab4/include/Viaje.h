#ifndef VIAJE_H
#define VIAJE_H

#include <string>
#include <set>

#include "dtypes/DTFecha.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTUsuarioViaje.h"
#include "dtypes/DTConsultaViaje.h"
#include "dtypes/DTDetalleViaje.h"

class Reserva;
class Vehiculo;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;

    static int codigoGlobal;

    std::set<Reserva*> reservas;
    Vehiculo* vehiculo;

public:
    Viaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
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
    DTFecha getFecha();
    int getCodigo();
    static int obtenerCodigo();
    Vehiculo* getVehiculo();
    void eliminarReservas();
    DTDetalleViaje getDTDetalleViaje();

    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();
};

#endif
