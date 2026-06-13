#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <set>

#include "dtypes/DTFecha.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTUsuarioViaje.h"
#include "dtypes/DTDetalleReserva.h"

class Pasajero;
class Viaje;
class Calificacion;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

    Pasajero* pasajero;
    Viaje* viaje;
    std::set<Calificacion*> calificaciones;

public:
    Reserva(int asientosReservados, DTFecha fecha, Pasajero* p, Viaje* v);
    ~Reserva();

    DTListarViaje getDTListarViaje();
    DTUsuarioViaje getDatosPasajero();
    int getCodigoViaje();
    std::string getNickPasajero();
    int getAsientosReservados();
    DTFecha getFecha();
    DTDetalleReserva getDTDetalleReserva();
};

#endif
