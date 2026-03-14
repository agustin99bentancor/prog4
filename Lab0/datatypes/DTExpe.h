#ifndef DTEXPE_H
#define DTEXPE_H

#include <iostream>
#include <string>
#include <set>
using namespace std;
#include "./DTFecha.h"

class DTExpe {
private:
    string codigoReserva;
    string descripcion;
    DTFecha fecha;
    set<string> turista;

public:
    DTExpe();
    DTExpe(string codigoReserva,string descripcion,DTFecha fecha,set<string> turista);
    string getCodigoReserva();
    string getDescripcion();
    DTFecha getfecha();
    set<string> getTurista();
};

#endif