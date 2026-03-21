#ifndef DTEXPE_H
#define DTEXPE_H

#include <iostream>
#include <string>
#include <set>
#include "./DTFecha.h"

class DTExpe {
private:
    std::string codigoReserva;
    std::string descripcion;
    DTFecha fecha;
    std::set<std::string> turistas;
public:
    DTExpe();
    DTExpe(std::string codigoReserva,std::string descripcion,DTFecha fecha,std::set<std::string> turista);
    std::string getCodigoReserva() const;
    std::string getDescripcion() const;
    DTFecha getFecha() const;
    std::set<std::string> getTuristas() const;
};

std::ostream& operator<<(std::ostream& os, const DTExpe& dtexpe);

#endif