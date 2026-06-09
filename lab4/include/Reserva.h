#ifndef RESERVA_H
#define RESERVA_H

#include <string>

#include "dtypes/DTFecha.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTUsuarioViaje.h"

class Pasajero;
class Viaje;

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
    Viaje* getViaje();
};

#endif
