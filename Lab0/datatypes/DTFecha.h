#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
#include <string>

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    std::string toString() const;
};

#endif