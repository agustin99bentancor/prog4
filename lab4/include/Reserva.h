#ifndef RESERVA_H
#define RESERVA_H

#include <string>

#include "dtypes/DTFecha.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTUsuarioViaje.h"
#include "Pasajero.h"
#include "Viaje.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

    Pasajero* pasajero;
    Viaje* viaje;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();

    DTListarViaje getDTListarViaje();
    DTUsuarioViaje getDatosPasajero();
    int getCodigoViaje();
    std::string getNickPasajero();
};

#endif
