#pragma once
#include"Librerias.h"
template <typename Tipo>
class ListaSimple {
    Nodo<Tipo>* inicio;
    Nodo<Tipo>* fin;
public:
    ListaSimple() {
        fin = inicio = nullptr;
    }
    void insertar(Tipo e) {
        Nodo<Tipo>* nuevo = new Nodo<Tipo>(e);
        if (inicio == nullptr)
            inicio = nuevo;
        else
        {
            Nodo<Tipo>* aux = inicio;
            while (aux->siguiente != nullptr)
                aux = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
    void mostrar() {
        Nodo<Tipo>* aux = inicio;
        while (aux != nullptr) {
            aux->elemento.show();
            aux = aux->siguiente;
        }
    }
};