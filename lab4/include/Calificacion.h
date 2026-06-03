#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "dtypes/DTFecha.h"

class Reserva;
class Usuario;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;

    Reserva* reserva;
    Usuario* califica;

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();
};

#endif
