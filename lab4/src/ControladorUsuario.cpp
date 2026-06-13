#include "ControladorUsuario.h"
#include "UsuarioHandler.h"
#include "VehiculoHandler.h"
#include "ViajeHandler.h"
#include "Viaje.h"
#include "Conductor.h"
#include "Calificacion.h"
#include "ControladorFechaActual.h"
#include "Pasajero.h"
#include "Reserva.h"

const std::string ControladorUsuario::NICKNAME_NULO = "";

bool ControladorUsuario::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    bool existe = uh->existeUsuario(nickname);
    if(!existe){
        uh->crearPasajero(nickname, nombre, contrasena, email, ci);
    }
    return !existe;
}

bool ControladorUsuario::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    bool existe = uh->existeUsuario(nickname);
    if(!existe){
        uh->crearConductor(nickname, nombre, contrasena, email, libretas);
    }
    return !existe;
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo){
    VehiculoHandler* vh = VehiculoHandler::getInstancia();
    bool existe = vh->existeVehiculo(matricula);
    if(existe){
        return -1;
    }
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Conductor* c = (Conductor*)uh->getUsuario(nickname);
    bool libreta = c->tieneLibretaCompatible(tipo);
    if(!libreta){
        return -2;
    }
    Vehiculo* v = vh->crearVehiculo(matricula, capacidad, marca, modelo, tipo, c);
    c->agregarVehiculo(v);
    return 0;
}

std::vector<DTUsuario> ControladorUsuario::listarUsuarios() {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    std::vector<DTUsuario> dtUsuarios = uh->getDTUsuarios();
    return dtUsuarios;
}

std::vector<DTListarViaje> ControladorUsuario::listarViajes(std::string nickname) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Usuario* u = uh->getUsuario(nickname);
    std::vector<DTListarViaje> dtlvs = u->getDTListarViajes();
    nicknameCalificador = nickname;
    return dtlvs;
}

std::vector<DTUsuarioViaje> ControladorUsuario::listarUsuariosViaje(int codigo) {
    ViajeHandler* vih = ViajeHandler::getInstancia();
    Viaje* v = vih->getViaje(codigo);
    std::vector<DTUsuarioViaje> ret;

    DTUsuarioViaje conductor = v->getDatosConductor();
    if (conductor.getNickname() != nicknameCalificador) {
        ret.push_back(conductor);
    }

    std::vector<DTUsuarioViaje> pasajeros = v->getDatosPasajeros();
    for (DTUsuarioViaje pasajero : pasajeros) {
        if (pasajero.getNickname() != nicknameCalificador) {
            ret.push_back(pasajero);
        }
    }

    codigoViajeCalificacion = codigo;
    return ret;
}

bool ControladorUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Usuario* calificador = uh->getUsuario(nicknameCalificador);
    Usuario* calificado = uh->getUsuario(nicknameCalificado);

    ViajeHandler* vih = ViajeHandler::getInstancia();
    Viaje* viaje = vih->getViaje(codigoViajeCalificacion);

    bool existe = calificador->existeCalificacion(nicknameCalificado, codigoViajeCalificacion);
    if (existe) {
        return false;
    }

    bool cadoOK = viaje->pertenece(nicknameCalificado);
    bool cdorOK = viaje->pertenece(nicknameCalificador);

    if (!cadoOK || !cdorOK) {
        return false;
    }

    Calificacion* ca = new Calificacion(ControladorFechaActual::getInstance()->getFecha(), calificacion);

    Reserva* reserva = nullptr;

    if (dynamic_cast<Pasajero*>(calificador) != nullptr) {
        reserva = viaje->getReservaByNick(nicknameCalificador);
    } else {
        reserva = viaje->getReservaByNick(nicknameCalificado);
    }

    ca->setCalificador(calificador);
    ca->setCalificado(calificado);
    ca->setReserva(reserva);

    reserva->agregarCalificacion(ca);
    calificador->agregarRealiza(ca);
    calificado->agregarRecibe(ca);

    nicknameCalificador = NICKNAME_NULO;
    codigoViajeCalificacion = CODIGO_NULO;
    return true;
}