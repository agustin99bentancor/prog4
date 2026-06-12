#ifndef DT_DETALLE_RESERVA_H
#define DT_DETALLE_RESERVA_H

#include "DTFecha.h"
#include <string>

class DTDetalleReserva {
private:
    int asientosReservados;
    DTFecha fecha;
    std::string pasajero;

public:
    DTDetalleReserva(int asientosReservados, DTFecha fecha, std::string pasajero);

    int getAsientosReservados() const;
    DTFecha getFecha() const;
    std::string getPasajero() const;
};

std::ostream& operator<<(std::ostream& os, const DTDetalleReserva& v);

#endif
