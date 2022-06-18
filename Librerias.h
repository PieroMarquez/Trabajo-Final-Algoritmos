//Header de Librerias que se usaran en el proyecto
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
using namespace std;
template <typename Tipo>
struct Nodo {
    Tipo elemento;
    Nodo<Tipo>* siguiente;
    Nodo(Tipo e) { elemento = e; siguiente = nullptr; }
};
