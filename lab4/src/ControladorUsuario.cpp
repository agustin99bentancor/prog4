#include "ControladorUsuario.h"
#include "UsuarioHandler.h"
#include "VehiculoHandler.h"
#include "Conductor.h"
#include "Calificacion.h"
#include "ViajeHandler.h"
#include "Viaje.h"
#include "dtypes/DTUsuarioViaje.h"

bool ControladorUsuario::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    bool existe = uh->existeUsuario(nickname);
    if (!existe) {
        uh->crearPasajero(nickname, nombre, contrasena, email, ci);
    }
    return !existe;
}

bool ControladorUsuario::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    bool existe = uh->existeUsuario(nickname);
    if (!existe) {
        uh->crearConductor(nickname, nombre, contrasena, email, libretas);
    }
    return !existe;
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    VehiculoHandler* vh = VehiculoHandler::getInstancia();
    bool existe = vh->existeVehiculo(matricula);
    if (existe) {
        return -1;
    }
    if (!existe) {
        UsuarioHandler* uh = UsuarioHandler::getInstancia();
        Conductor* c = (Conductor*)uh->getUsuario(nickname);
        bool libreta = c->tieneLibretaCompatible(tipo);
        if (!libreta) {
            return -2;
        }
        Vehiculo* v = vh->crearVehiculo(matricula, capacidad, modelo, marca, tipo, c);
        c->agregarVehiculo(v);
    }
    return 0;
}

std::set<DTUsuario> ControladorUsuario::listarUsuarios() {
    std::set<DTUsuario> ret;
    UsuarioHandler* uh = UsuarioHandler::getInstancia();

    // 1. Obtenemos el set del Handler (recuerda agregar getUsuarios() en include/UsuarioHandler.h)
    std::set<Usuario*> copiaUsuarios = uh->getUsuarios();

    // 2. Iteramos delegando la creación del DT a la función nativa de tu clase Usuario
    for (std::set<Usuario*>::iterator it = copiaUsuarios.begin(); it != copiaUsuarios.end(); ++it) {
        DTUsuario dt = (*it)->getDT(); // 🚀 Reemplaza la extracción manual y es 100% seguro
        ret.insert(dt);
    }
    return ret;
}

std::set<DTListarViaje> ControladorUsuario::listarViajes(std::string nickname) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();

    Usuario* u = uh->getUsuario(nickname);

    if (u == nullptr) {
        return std::set<DTListarViaje>(); // Si no existe el usuario, retorna conjunto vacío
    }

    return u->getDTListarViajes();
}

std::set<DTUsuarioViaje> ControladorUsuario::listarUsuariosViaje(int codigo) {
    std::set<DTUsuarioViaje> ret;

    ViajeHandler* vh = ViajeHandler::getInstancia();

    Viaje* vi = vh->getViaje(codigo);

    if (vi == nullptr) {
        return ret;
    }

    DTUsuarioViaje cond = vi->getDatosConductor();
    ret.insert(cond);

    std::set<DTUsuarioViaje> pasajeros = vi->getDatosPasajeros();

    for (std::set<DTUsuarioViaje>::iterator it = pasajeros.begin(); it != pasajeros.end(); ++it) {
        ret.insert(*it);
    }

    return ret;
}

bool ControladorUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
   
    UsuarioHandler* uh = UsuarioHandler::getInstancia();

    std::string nicknameRecordado = this->nicknameRecordado;
    int codigoViajeRecordado = this->codigoViajeRecordado;

    Usuario* cdor = uh->getUsuario(nicknameRecordado);

    Usuario* cdorCalificado = uh->getUsuario(nicknameCalificado);
    if (cdor == nullptr || cdorCalificado == nullptr) {
        return false;
    }

    ViajeHandler* vh = ViajeHandler::getInstancia();

    // 5: vi := getViaje(codigoViajeRecordado): Viaje
    Viaje* vi = vh->getViaje(codigoViajeRecordado);
    if (vi == nullptr) {
        return false;
    }

    bool existe = cdor->existeCalificacion(nicknameCalificado, codigoViajeRecordado);

    bool c1 = vi->pertenece(nicknameCalificado);

    bool c2 = vi->pertenece(nicknameRecordado);

    if (!existe && c1 && c2) {
        DTFecha fechaActual(10, 6, 2026);
        Calificacion* nuevaCalificacion = new Calificacion(fechaActual, calificacion);

        cdorCalificado->agregarCalificacion(nuevaCalificacion);

        return true;
    }

    return false;
}
