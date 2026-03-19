
#include <iostream>
#include <list>
#include <map>
#include <string>

#include "./clases/Experiencia.h"
#include "./clases/Turista.h"
#include "./clases/Alojamiento.h"
#include "./clases/TourGuiado.h"
#include "./clases/EventoCultural.h"
#include "./datatypes/DTFecha.h"
#include "./datatypes/DTExpe.h"

std::list<Experiencia*> experiencias;
std::map<std::string, Experiencia*> map_experiencias;

std::list<Turista*> turistas;
std::map<std::string, Turista*> map_turistas;

void coleccion_guardarExperiencia(Experiencia* exp){
	experiencias.push_back(exp);
	std::pair<std::string, Experiencia*> entry(exp->getCodigoReserva(), exp);
    map_experiencias.insert(entry);
}
void coleccion_eliminarExperiencia(Experiencia* exp){
	experiencias.remove(exp);
	map_experiencias.erase(exp->getCodigoReserva());
}

void printSeparador() {
	std::cout << "========================================" << std::endl;
}

void coleccion_guardarTurista(Turista* tur){
	turistas.push_back(tur);
	std::pair<std::string, Turista*> entry(tur->getCi(), tur);
    map_turistas.insert(entry);
}

Turista* coleccion_getTurista(std::string ci){
	return map_turistas[ci];
}

Experiencia* coleccion_getExperiencia(std::string codigoReserva){
	return map_experiencias[codigoReserva];
}

void parte_a(){
	Alojamiento* alojamiento1 = new Alojamiento("ALX5489", "Hotel moderno", 30, DTFecha(18, 5, 2020), "Hotel Lindorf", AllInclusive, 5);
	coleccion_guardarExperiencia(alojamiento1);

	Alojamiento* alojamiento2 = new Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100, DTFecha(10, 2, 2025), "Hotel SeaView", MediaPension, 15);
	coleccion_guardarExperiencia(alojamiento2);
}

void parte_b(){
	set<string> lugares1;
	lugares1.insert("Plaza Independencia");
	lugares1.insert("Plaza Matriz");
	TourGuiado* tour1 = new TourGuiado("TGO4657", "Plazas de Montevideo", 10, DTFecha(29, 8, 2024), "Paseos SA", lugares1);
	coleccion_guardarExperiencia(tour1);

	set<string> lugares2;
	lugares2.insert("Puerta de la ciudadela");
	lugares2.insert("Mausoleo");
	lugares2.insert("Cabildo");
	lugares2.insert("Palacio Salvo");
	TourGuiado* tour2 = new TourGuiado("TGR3257", "Puntos emblematicos", 5, DTFecha(29, 8, 2024), "Recorre", lugares2);
	coleccion_guardarExperiencia(tour2);
}

void parte_c(){
	EventoCultural* evento1 = new EventoCultural("ECP1346", "Danza en el Solis", 10, DTFecha(29, 10, 2025), "Teatro Solis", true);
	coleccion_guardarExperiencia(evento1);
}

void parte_d(){
	for (std::list<Experiencia*>::iterator it = experiencias.begin(); it != experiencias.end(); ++it) {
		Experiencia* exp = *it;
		std::cout << exp->getDT();
	}
}

void parte_e(){
	Turista* turista1 = new Turista("4.951.278-9", "Vanesa Castro", "vcastro.uy@servidor.net");
	Turista* turista2 = new Turista("1.535.442-0", "Karen Santos", "karen.s89@internet.uy");
	coleccion_guardarTurista(turista1);
	coleccion_guardarTurista(turista2);
}

void parte_f(){
	for(list<Turista*>::iterator it = turistas.begin(); it != turistas.end(); ++it){
		cout << (*it)->toString() << endl;
	}
}

void parte_g(){
    Turista* vanesa = coleccion_getTurista("4.951.278-9");
    Turista* karen = coleccion_getTurista("1.535.442-0");
	
    Experiencia* hotelMod = coleccion_getExperiencia("ALX5489");
    Experiencia* hotelVista = coleccion_getExperiencia("ALJ4789");
    Experiencia* puntosEmblem = coleccion_getExperiencia("TGR3257");
    Experiencia* danzaSolis = coleccion_getExperiencia("ECP1346");
    Experiencia* plazasMdeo = coleccion_getExperiencia("TGO4657");

    hotelMod->linkTurista(vanesa); vanesa->linkExperiencia(hotelMod);
    hotelVista->linkTurista(vanesa); vanesa->linkExperiencia(hotelVista);
    puntosEmblem->linkTurista(vanesa); vanesa->linkExperiencia(puntosEmblem);
    danzaSolis->linkTurista(vanesa); vanesa->linkExperiencia(danzaSolis);
    plazasMdeo->linkTurista(karen); karen->linkExperiencia(plazasMdeo);
    puntosEmblem->linkTurista(karen); karen->linkExperiencia(puntosEmblem);
}

void parte_h(){
	Turista* vanesa = coleccion_getTurista("4.951.278-9");

    if (vanesa != NULL) {
        std::set<std::string> resultado = vanesa->listarExperiencias(DTFecha(10, 12, 2023), 0, 1000);
        for (std::set<std::string>::iterator it = resultado.begin(); it != resultado.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
}

void parte_i(){
    Experiencia* exp = coleccion_getExperiencia("TGR3257");
	coleccion_eliminarExperiencia(exp);
	delete exp; 
	std::cout << "Eliminacion de TGR3257 completada." << std::endl;
}

void parte_j(){
    Turista* karen = coleccion_getTurista("1.535.442-0");

    if (karen != NULL) {
        std::set<std::string> resultado = karen->listarExperiencias(DTFecha(10, 10, 2020), 0, 1000);
        for (std::set<std::string>::iterator it = resultado.begin(); it != resultado.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
}

void parte_k(){
	    for (std::list<Experiencia*>::iterator it = experiencias.begin(); it != experiencias.end(); ++it) {
        Experiencia* exp = *it;        std::cout << exp->getDT() << std::endl;
    }
}

void cleanUp(){
    for (std::map<std::string, Experiencia*>::iterator it = map_experiencias.begin(); it != map_experiencias.end(); ++it) {
        delete it->second;
    }
    map_experiencias.clear();
    experiencias.clear();

    for (std::map<std::string, Turista*>::iterator it = map_turistas.begin(); it != map_turistas.end(); ++it) {
        delete it->second;
    }
    map_turistas.clear();
    turistas.clear();
}

int main() {
	printSeparador();
	std::cout << "Parte-A (Agrego Alojamientos ALX5489 y ALJ4789 )" <<  std::endl;
	parte_a();
	printSeparador();

	std::cout << "Parte-B (Agrego TourGuiado TGO4657 y TGR3257)" << std::endl;
	parte_b();
	printSeparador();

	std::cout << "Parte-C (Agrego EventoCultural ECP1346)" << std::endl;
	parte_c();
	printSeparador();

	std::cout << "Parte-D (ejecutar operador << getDT())" <<  std::endl;
	parte_d();
	printSeparador();

	std::cout << "Parte-E (Agrego Turistas 4.951.278-9 y 1.535.442-0)" <<  std::endl;
	parte_e();
	printSeparador();

	std::cout << "Parte-F (Ejecutar operador << toString())" <<  std::endl;
	parte_f();
	printSeparador();

	std::cout << "Parte-G (Link Turistas y Experiencias)" <<  std::endl;
	parte_g();
	printSeparador();

	std::cout << "Parte-H (Ejecutar listarExperiencias(10/12/2023, 0, 1000))" <<  std::endl;
	parte_h();
	printSeparador();
	std::cout << "Parte-I (Eliminar Experiencia TGR3257)" <<  std::endl;
	parte_i();
	printSeparador();

	std::cout << "Parte-J (Ejecutar listarExperiencias(10/10/2020, 0, 1000))" <<  std::endl;
	parte_j();
	printSeparador();

	std::cout << "Parte-K (Ejecutar operador << getDT())" <<  std::endl;
	parte_k();
	printSeparador();

	std::cout << "cleanUp" <<  std::endl;
	cleanUp();
	std::cout << "fin" <<  std::endl;

	return 0;
}
