#include "ControladorUsuario.h"
#include "UsuarioHandler.h"
#include "VehiculoHandler.h"
#include "Conductor.h"
#include "Calificacion.h"

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
    std::set<DTListarViaje> ret;
    return ret;
}

std::set<DTUsuarioViaje> ControladorUsuario::listarUsuariosViaje(int codigo) {
    std::set<DTUsuarioViaje> ret;
    return ret;
}

bool ControladorUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();

    bool existe = uh->existeUsuario(nicknameCalificado);
    if (!existe) {
        return false;
    }

    Usuario* u = uh->getUsuario(nicknameCalificado);

    DTFecha fechaActual(9, 6, 2026); // Modifica según los parámetros de tu DTFecha (dia, mes, anio)
    Calificacion* nuevaCalificacion = new Calificacion(fechaActual, calificacion);

    u->agregarCalificacion(nuevaCalificacion);

    return true;
}
