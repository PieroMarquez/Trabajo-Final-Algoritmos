//Libreria de la clase Pila 
#pragma once
#include"Librerias.h"
template <typename Tipo>
class Pila {
    Nodo<Tipo>* inicio;
    Nodo<Tipo>* fin;
    long cantidad;
public:
    Pila() {
        fin = inicio = nullptr;
        cantidad = 0;
    }
    void insertar(Tipo e) {
        Nodo<Tipo>* n = new Nodo<Tipo>(e);
        n->elemento = e;
        n->siguiente = fin;
        fin = n;
        ++cantidad;
    }
    void eliminar() {
        Nodo<Tipo>* aux = fin;
        Tipo anterior;
        if (inicio == fin) {
            inicio = fin = NULL;
        }
        else {
            anterior = aux->elemento;
            fin = fin->siguiente;
        }
        delete aux;
        --cantidad;
    }
    int size() {
        return cantidad;
    }
    //Retorna el ultimo elemento de la Pila
    Tipo ultimo() {
        return fin->elemento;
    }
};