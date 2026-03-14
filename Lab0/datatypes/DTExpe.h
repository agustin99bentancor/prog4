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
    set<string> turista;

public:
    DTExpe();
    DTExpe(string codigoReserva,string descripcion,DTFecha fecha,set<string> turista);
    string getCodigoReserva();
    string getDescripcion();
    DTFecha getfecha();
    set<string> getTurista();
    
    std::ostream operator<<(const DTExpe& dtexpe) const;
};
