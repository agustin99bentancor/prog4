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
    return new ControladorUsuario();
}

IReserva* Fabrica::getIReserva() {
    return nullptr; // falta implementar ControladorReserva
}
