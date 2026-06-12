#include "Menu.h"
#include "Fabrica.h"
#include "IControladorFechaActual.h"
#include "IUsuario.h"
#include "CargaDatos.h"
#include "dtypes/DTFecha.h"
#include "dtypes/TipoVehiculo.h"
#include <iostream>
#include <limits>
#include <string>
#include <set>
#include <map>
#include "ViajeHandler.h"
#include "Viaje.h"
#include "dtypes/DTListarViaje.h"
#include "dtypes/DTDetalleViaje.h"
#include "dtypes/DTDetalleReserva.h"
#include "dtypes/DTDetalleVehiculo.h"

void Menu::altaUsuario() {
    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: "; std::getline(std::cin, email);


    bool usuarioOk = false;

    IUsuario* controlador = Fabrica::getInstance()->getIUsuario();

    if (tipoUsuario == 1) {
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        usuarioOk = controlador->altaPasajero(nickname, nombre, contrasena, email, ci);
    } else if (tipoUsuario == 2) {
        bool tieneMotoProfesional = false;
        bool tieneMotoAmateur = false;
        bool tieneAutoProfesional = false;
        bool tieneAutoAmateur = false;

        int cantLibretas = 0;
        int agregarLibreta = 1;

        while (agregarLibreta == 1 && cantLibretas < 4) {
            int tipoLibreta;
            std::cout << "\n=== Registrar Libreta ===\n";
            std::cout << "0. Moto (Profesional)\n";
            std::cout << "1. Moto (Amateur)\n";
            std::cout << "2. Auto (Profesional)\n";
            std::cout << "3. Auto (Amateur)\n";
            std::cout << "Seleccione el tipo de libreta: ";
            std::cin >> tipoLibreta;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool yaExiste = false;
            if (tipoLibreta == 0) {
                if (tieneMotoProfesional) {
                    yaExiste = true;
                } else {
                    tieneMotoProfesional = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 1) {
                if (tieneMotoAmateur) {
                    yaExiste = true;
                } else {
                    tieneMotoAmateur = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 2) {
                if (tieneAutoProfesional) {
                    yaExiste = true;
                } else {
                    tieneAutoProfesional = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 3) {
                if (tieneAutoAmateur) {
                    yaExiste = true;
                } else {
                    tieneAutoAmateur = true;
                    cantLibretas++;
                }
            } else {
                std::cout << "Opcion invalida.\n";
                continue;
            }

            if (yaExiste) {
                std::cout << "Esa libreta ya fue ingresada.\n";
            } else {
                std::cout << "Libreta agregada.\n";
            }

            if (cantLibretas < 4) {
                std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
                std::cin >> agregarLibreta;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cout << "Se ha alcanzado el limite maximo de libretas.\n";
            }
        }

        if (cantLibretas == 0) {
            std::cout << "Debe ingresar al menos una libreta para registrar un conductor.\n";
            return;
        }

        // Ejemplo de como armar el conjunto de libretas utilizando set
        std::set<TipoLibreta> libretas;
        if (tieneMotoProfesional) {
            libretas.insert(TipoLibreta::MotoProfesional);
        }
        if (tieneMotoAmateur) {
            libretas.insert(TipoLibreta::MotoAmateur);
        }
        if (tieneAutoProfesional) {
            libretas.insert(TipoLibreta::AutoProfesional);
        }
        if (tieneAutoAmateur) {
            libretas.insert(TipoLibreta::AutoAmateur);
        }

        usuarioOk = controlador->altaConductor(nickname, nombre, contrasena, email, libretas);

        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> tipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            TipoVehiculo tipoV;
            if (tipo == 0) {
                tipoV = Auto;
            } else if (tipo == 1) {
                tipoV = Moto;
            } else {
                std::cout << "Tipo invalido.\n";
                continue;
            }
            int resultadoRegistrarVehiculo = -3;
            resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipoV);
            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::altaViaje() {
    std::string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;

    std::cout << "Ingrese nickname del conductor: "; std::getline(std::cin, nickname);
    IReserva* controlador = Fabrica::getInstance()->getIReserva();
    std::vector<DTVehiculosConductor> vehiculosConductor = controlador->listarVehiculosConductor(nickname);

    for(DTVehiculosConductor vehiculoConductor: vehiculosConductor){
        std::cout << "> Matricula: " << vehiculoConductor.getMatricula() << ", Modelo: " << vehiculoConductor.getModelo() << ", Capacidad: " << vehiculoConductor.getCapacidad() << "\n";
    }

    std::cout << "Ingrese matricula del vehiculo a utilizar: "; std::getline(std::cin, matricula);
    bool matriculaValida = controlador->existeVehiculo(matricula);
    if (!matriculaValida) {
        std::cout << "Matricula invalida.\n";
        return;
    }

    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio);
    if (viajeOk) {
        std::cout << "Viaje registrado exitosamente.\n";
    } else {
        std::cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva() {
    //TODO: Colecion de String = controlador->listarPasajeros()
    //TODO: Recorrer la colección y mostrar "> xx"
    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: "; std::getline(std::cin, nickname);

    bool nicknameValido = false;
    //TODO: Validar nickname en listado
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //TODO: Coleccion de DTConsultaViaje = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos)
    //TODO: Recorrer la coleccion y mostrar: "> Codigo: xx, Marca: yy, Modelo: zzz, Conductor: aaa, CalificacionPromedio: qqq, PrecioTotal: eee"

    bool hayViajes = false;//TODO: Validar coleccion vacía
    if (!hayViajes) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    //TODO: Validar codigo en listado
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = false;
    //TODO: reservaOk = controlador->generarReserva(nickname, codigo, asientos)
    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario() {
    //TODO: Coleccion de DTUsuario = controlador->listarUsuarios()
    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Nombre: yyy"
    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    bool nicknameValido = false;
    //TODO: Validar nickname en listado
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    //TODO: Coleccion de DTListarViaje = controlador->listarViajes(nickname)
    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    int codigo;
    std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    //TODO: Validar codigo en listado
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    //TODO: Coleccion de DTUsuarioViaje = Controlador->listarUsuariosViaje(codigo)
    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Tipo: yyy"
    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool nicknameCalificadoValido = false;
    //TODO: Validar nickname en listado
    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = false;
    //TODO: calificacionOk = Controlador->calificarUsuario(nicknameCalificado, calificacion)
    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje() {

    IReserva* reserva = Fabrica::getInstance()->getIReserva();

    std::vector<DTListarViaje> viajes = reserva->listarViajes();

    if (viajes.empty()) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    for (DTListarViaje v : viajes) {
        std::cout
            << "Codigo: " << v.getCodigo()
            << ", Fecha: " << v.getFecha()
            << ", Origen: " << v.getOrigen()
            << ", Destino: " << v.getDestino()
            << ", Conductor: " << v.getConductor()
            << "\n";
    }

    int codigo;
    std::cout << "\nIngrese codigo del viaje: ";
    std::cin >> codigo;

    DTDetalleViaje detalle = reserva->obtenerDetalleViaje(codigo);

    std::cout << "\n>> Viaje <<\n";
    std::cout << "Codigo: " << detalle.getCodigo() << "\n";
    std::cout << "Fecha: " << detalle.getFecha() << "\n";
    std::cout << "Origen: " << detalle.getOrigen() << "\n";
    std::cout << "Destino: " << detalle.getDestino() << "\n";

    int confirmar;
    std::cout << "\n¿Confirmar eliminacion? (1: Si, 0: No): ";
    std::cin >> confirmar;

    if (confirmar == 1) {
    reserva->eliminarViaje(codigo);
    std::cout << "Eliminado correctamente\n";
    }
    else {
    std::cout << "Cancelado\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
