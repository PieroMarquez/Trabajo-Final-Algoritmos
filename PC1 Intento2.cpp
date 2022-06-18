// PC1 Intento2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Controladora.h"
void menu() {
    Controladora C;
    C.Cargar_Datos();
    int opc;
    do 
    {
        cout << "Gestion de Entregas" << endl;
        cout << "\n===================================================\n";
        cout << "Seleccione una opcion" << endl;
        cout << "1)Entregas Registradas" << endl;
        cout << "2)Entregas por Registrar" << endl;
        cout << "3)Ordenar los precios de los Usuarios" << endl;
        cout << "4)Ordenar los descuentos de los Usuarios" << endl;
        cout << "5) Ordenar los tiempos de los Usuarios" << endl;
        cout << "6)Cerrar" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            C.mostrarEntregas();
            system("pause");
            system("cls");
            break;
        case 2:
            C.agregarEntrega();
            system("cls");
            break;
        case 3:
            C.mostraPrecios();
            system("pause");
            system("cls");
            break;
        case 4:
            C.mostrarDescuentos();
            system("pause");
            system("cls");
            break;
        case 5:
            C.mostrarTiempos();
            system("pause");
            system("cls");
            break;
        case 6: 
            exit(0);
            break;
        }
    } while (opc<7&&opc>0);
}
int n = 0;
template <class T>void ordena_seleccion(vector<T>& v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        int min = i;
        for (int c = i + 1; c < v.size(); ++c) {
            if (v[min] > v[c]) min = c;
            ++n;
        }
        T aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}
void main()
{
    //menu();
    vector<int> v= {16, 10, 12, 5, 4, 20};
    ordena_seleccion(v);
    cout << n;
    system("pause>NULL");
}
