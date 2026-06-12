#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <set>

#include "dtypes/TipoLibreta.h"
#include "dtypes/TipoVehiculo.h"
#include "dtypes/DTUsuario.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTUsuarioViaje.h"
#include "dtypes/DTDetalleViaje.h"


class IUsuario {
public:

    virtual ~IUsuario() {}
    virtual bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) = 0;
    virtual bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) = 0;
    virtual int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) = 0;
    virtual std::set<DTUsuario> listarUsuarios() = 0;
    virtual std::set<DTListarViaje> listarViajes(std::string nickname) = 0;
    virtual std::set<DTUsuarioViaje> listarUsuariosViaje(int codigo) = 0;
    virtual bool calificarUsuario(std::string nicknameCalificado, int calificacion) = 0;
    virtual void eliminarViaje(int codigo) = 0;
    virtual DTDetalleViaje obtenerDetalleViaje(int codigo) = 0;
    virtual std::vector<DTListarViaje> listarViajes() = 0;
};


#endif