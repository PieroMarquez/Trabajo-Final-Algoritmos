#pragma once
#include"Librerias.h"
class Repartidor
{
private:
	string nombre;
	int codigo;
	int tiempo;
	int precio;
	int descuento;
	int precioDesc;
public:
	Repartidor(string nombre, int codigo, int tiempo, int precio, int descuento) :nombre(nombre), codigo(codigo), tiempo(tiempo), precio(precio),descuento(descuento) {}
	Repartidor(){}
	~Repartidor(){}
	//Setters y Getters de parametros de Repartidor
	void setCodigo(int c) {
		codigo = c;
	}
	void setTiempo(int c) {
		tiempo = c;
	}
	void setPrecio(int c) {
		precio = c;
	}
	void setdescuento(int c) {
		descuento = c;
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
	//Archivos para guardar los datos Principales del Repartidor
	void guardar2() {
		auto desc = [](int descuento, int precio) {return (descuento * precio) / 100; }(descuento, precio);
		auto desc2 = [](int descuento, int precio) {return precio - ((descuento * precio) / 100); }(descuento, precio);
		precioDesc = desc2;
		ofstream registro("Registro.txt", fstream::in | fstream::out | fstream::app);
		registro << "Repartidor: " << nombre << endl;
		registro << "Codigo: " << codigo << endl;
		registro << "Tiempo de llegada: " << tiempo << " minutos." << endl;
		registro << "Precio: " << precio << " soles." << endl;
		registro << "Descuento a realizar: " << descuento << "%" << endl;
		registro<< "Total del descuento: " << desc << endl;
		registro<< "Total a pagar con descuento: " << desc2 << endl;
		registro.close();
	}
	//Getter del precio con el descuento aplicado que se usara en ordenamiento
	int getPrecioDesc() {
		return precioDesc;
	}
};
