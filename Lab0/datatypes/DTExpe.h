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
    string getCodigoReserva() const;
    string getDescripcion() const;
    DTFecha getFecha() const;
    set<string> getTuristas() const;
};

ostream& operator<<(ostream& os, const DTExpe& dtexpe);

#endif