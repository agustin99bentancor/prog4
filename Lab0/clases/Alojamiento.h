


#include <iostream>
#include <string>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"
#include "../datatypes/TipoRegimen.h"
#include "./Experiencia.h"

class Alojamiento: public Experiencia{
private:
    std::string hotel;
    TipoRegimen regimen;
    int cantNoches;

public:
    Alojamiento();
    Alojamiento(std::string codigoReserva, std::string decripcion, int precioBase, DTFecha fecha, std::string hotel, int cantNoches);
    
    ~Alojamiento();
    float calcularCosto();
};