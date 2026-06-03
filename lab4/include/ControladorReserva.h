#ifndef CONTROLADOR_RESERVA_H
#define CONTROLADOR_RESERVA_H

#include "IReserva.h"

class ControladorReserva : public IReserva {
public:

    std::set<std::string> listarPasajeros();
    std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
    bool generarReserva(std::string nickname, int codigo, int asientos);
    std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
};

#endif