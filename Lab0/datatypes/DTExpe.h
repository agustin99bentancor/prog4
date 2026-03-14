#ifndef DTEXPE_H
#define DTEXPE_H

#include <iostream>
#include <string>
#include <set>

#include "./DTFecha.h"

using namespace std;

class DTExpe {
private:
    string codigoReserva;
    string descripcion;
    DTFecha fecha;
    set<string> turistas;
public:
    DTExpe();
    DTExpe(string codigoReserva,string descripcion,DTFecha fecha,set<string> turista);
    string getCodigoReserva();
    string getDescripcion();
    DTFecha getFecha();
    set<string> getTuristas();
};

ostream& operator<<(ostream& os, DTExpe& dtexpe);

#endif