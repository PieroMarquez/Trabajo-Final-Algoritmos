#pragma once
#include "Entrega.h"
class Controladora
{
private:
	ListaSimple<Entrega> ls;
	Entrega e;
public:
	Controladora(){}
	~Controladora(){}
	void Cargar_Datos() {
		e.Cola_de_Restaurantes();
		e.Pila_Distrito();
	}
	void agregarEntrega() {
		e.creaUsuario();
		e.archivo();
		e.crearRepartidor();
		e.archivo2();
		ls.insertar(e);
	}
	void mostrarEntregas() { 
		e.leer();
	}
	void mostraPrecios() {
		e.imprimir_Precios();
	}
	void mostrarTiempos() {
		e.imprimir_Tiempos();
	}
	void mostrarDescuentos() {
		e.imprimir_descuentos();
	}
};