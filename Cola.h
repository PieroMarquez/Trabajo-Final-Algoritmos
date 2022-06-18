#pragma once
#include "Librerias.h"
template <typename Tipo>
class Cola{
    Nodo<Tipo>* inicio;
    Nodo<Tipo>* fin;
    long cantidad;
 public:
    Cola(){
        fin=inicio=nullptr;        
        cantidad=0;
    }       
    void insertar(Tipo e){     
    Nodo<Tipo>* n=new Nodo<Tipo>(e);
        if(inicio==nullptr)
            inicio=fin=n;
        else {
          fin->siguiente=n;
          fin=n;
        }
        ++cantidad;
    }
    void eliminar() {
        Nodo<Tipo>* aux = inicio;
        if (inicio==fin)
        {
            inicio = fin = NULL;
        }
        else
        {
            inicio = inicio->siguiente;
        }
        delete aux;
        --cantidad;
    }
    int size(){ return cantidad; }
    //Retorna el primer elemento de la Cola
    Tipo primero() {
        return inicio->elemento;
    }
};