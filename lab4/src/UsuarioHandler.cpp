#include "ControladorUsuario.h"
#include "UsuarioHandler.h"
#include "VehiculoHandler.h"
#include "Conductor.h"

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

    // Recorremos el conjunto 'usuarios' interno del Handler usando tu mismo estilo de iteradores
    for (std::set<Usuario*>::iterator it = uh->usuarios.begin(); it != uh->usuarios.end(); ++it) {
        // Extraemos los datos de cada objeto Usuario real del dominio
        std::string nick = (*it)->getNickname();
        std::string nom = (*it)->getNombre();

        // Creamos el Data Transfer Object y lo metemos en el conjunto de retorno
        DTUsuario dt(nick, nom);
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

    // 1. Validamos si el usuario existe usando tu método del Handler
    bool existe = uh->existeUsuario(nicknameCalificado);
    if (!existe) {
        return false;
    }

    // 2. Traemos el puntero del objeto real
    Usuario* u = uh->getUsuario(nicknameCalificado);

    // 3. Le asignamos la calificación al objeto de negocio
    u->agregarCalificacion(calificacion);

    return true;
}
