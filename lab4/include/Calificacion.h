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
    Usuario* calificador;
    Usuario* calificado;

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    void setCalificador(Usuario* u);
    void setCalificado(Usuario* u);
    void setReserva(Reserva* r);
    Usuario* getCalificado();
    Reserva* getReserva();
};

#endif
