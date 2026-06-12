#ifndef RESERVA_H
#define RESERVA_H

#include <string>

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
    Calificacion* calificacion;

public:
    Reserva(int asientosReservados, DTFecha fecha, Pasajero* p, Viaje* v);
    ~Reserva();

    DTListarViaje getDTListarViaje();
    DTUsuarioViaje getDatosPasajero();
    int getCodigoViaje();
    std::string getNickPasajero();
    DTFecha getFecha();
    int getAsientosReservados();
    DTDetalleReserva getDetalleReserva();
    void setCalificacion(Calificacion* c);
    Calificacion* getCalificacion();

};

#endif
