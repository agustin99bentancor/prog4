#ifndef TURISTA_H
#define TURISTA_H

#include <string>
using namespace std;

class Turista {
private:
    string ci;
    string nombre;

public:
    Turista(string ci, string nombre);
    string getCi();
};

#endif