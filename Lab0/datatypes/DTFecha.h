#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
#include <string>
using namespace std;

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);
    int get_dia();
    int get_mes();
    int get_anio();
    string toString() const;
};

#endif
