#ifndef CONTROLADOR_RESERVA_H
#define CONTROLADOR_RESERVA_H

#include "IReserva.h"

class ControladorReserva : public IReserva {
private:
    static const int CODIGO_NULO = -1;
    int codigoViajeAEliminar;

public:

    std::set<std::string> listarPasajeros();
    std::multiset<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
    bool generarReserva(std::string nickname, int codigo, int asientos);
    std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
    std::vector<DTListarViaje> listarViajes();
    DTDetalleViaje detalleViaje(int codigo);
    void eliminarViaje();
    void cancelarEliminarViaje();
};

#endif