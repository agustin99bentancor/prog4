
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
}

void parte_j(){
}

void parte_k(){
}

void cleanUp(){
}

int main() {
	std::cout << "parte_a" <<  std::endl;
	parte_a();
	std::cout << "parte_b" <<  std::endl;
	parte_b();
	std::cout << "parte_c" <<  std::endl;
	parte_c();
	std::cout << "parte_d" <<  std::endl;
	parte_d();
	std::cout << "parte_e" <<  std::endl;
	parte_e();
	std::cout << "parte_f" <<  std::endl;
	parte_f();
	std::cout << "parte_g" <<  std::endl;
	parte_g();
	std::cout << "parte_h" <<  std::endl;
	parte_h();
	std::cout << "parte_i" <<  std::endl;
	parte_i();
	std::cout << "parte_j" <<  std::endl;
	parte_j();
	std::cout << "parte_k" <<  std::endl;
	parte_k();
	std::cout << "cleanUp" <<  std::endl;
	cleanUp();
	std::cout << "fin" <<  std::endl;

	return 0;
}
