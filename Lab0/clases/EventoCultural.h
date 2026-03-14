

#include <iostream>
#include <string>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTExpe.h"
#include "../datatypes/TipoRegimen.h"
#include "./Experiencia.h"

class EventoCultural: public Experiencia{
private:
    std::string ubicacion;
    bool useCupo;

public:
    EventoCultural(std::string codigoReserva, std::string decripcion, int precioBase, DTFecha fecha, std::string ubicacion, bool useCupo);
    EventoCultural();

    virtual ~EventoCultural();
    float calcularCosto();
};