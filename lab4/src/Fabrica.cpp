#include "Fabrica.h"
#include "ControladorFechaActual.h"
#include "ControladorUsuario.h"
#include "ControladorReserva.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

IUsuario* Fabrica::getIUsuario() {
    static ControladorUsuario instancia;
    return &instancia;
}

IReserva* Fabrica::getIReserva() {
    static ControladorReserva instancia;
    return &instancia;
}
