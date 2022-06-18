#pragma once
#include"Librerias.h"
class Usuario {
private:
    string nombre;
    string direccion;
    string metododepago;
    string restaurante;
    int precio;
    int tiempo;
    int descuento;
    int precioDesc;
public:
    Usuario(string nombre,string direccion,string metododepago,string restaurante): nombre(nombre),direccion(direccion),metododepago(metododepago),restaurante(restaurante) {
    }
    //Setters y Getters de los parametros de Usuario
    void setNombre(string n) {
        nombre = n;
    }
    void setDireccion(string d) {
        direccion = d;
    }
    void setMetodo(string m) {
        metododepago = m;
    }
    void setRestaurante(string r) {
        restaurante = r;
    }
    string getNombre() {
        return nombre;
    }
    string getDireccion() {
        return direccion;
    }
    string getPago() {
        return metododepago;
    }
    string getRestaurante() {
        return restaurante;
    }
    //Setters y Getters de Parametros de Repartidos usados para el ordenamiento
    void setPrecio(int p) {
        precio = p;
    }
    void setTiempo(int t) {
        tiempo = t;
    }
    void setDescuento(int d) {
        descuento = d;
    }
    void setPrecioDesc(int pd) {
        precioDesc = pd;
    }
    int getPrecio() {
        return precio;
    }
    int getTiempo() {
        return tiempo;
    }
    int getDescuento() {
        return descuento;
    }
    int getPrecioDesc() {
        return precioDesc;
    }
    //Funcion de Archivos para guardar los datos Principales del Usuario
    void guardar() {
        ofstream registro("Registro.txt", fstream::in | fstream::out | fstream::app);
        registro << "=============================" << endl;
        registro << "Nombre: " << nombre << endl;
        registro << "Distrito: " << direccion << endl;
        registro << "Metodo de Pago: " << metododepago << endl;
        registro << "Restaurante: " << restaurante << endl;
        registro << "=============================" << endl;
        registro.close();
    }
};