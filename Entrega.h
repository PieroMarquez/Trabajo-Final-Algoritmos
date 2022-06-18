#pragma once
#include "Usuario.h"
#include "Repartidor.h"
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
class Entrega
{
private:
    Usuario* u;
    vector<Usuario*> usuarios;
    Repartidor rappi;
    vector<Repartidor> r;
    Cola<string> cl;
    Pila<string> pl;
    vector<int> precios;
    vector<int> tiempos;
    vector<int> descuentos;
    int codigo;
    int tiempo;
    int precio;
    int descuento;
    int cantidad;
    string linea;
    string texto;
public:
    Entrega() {}
    ~Entrega() {}
   //Carga de Datos en Cola y Pila
    void Cola_de_Restaurantes() {
        cl.insertar("PizzaHut");
        cl.insertar("Bembos");
        cl.insertar("KFC");
        cl.insertar("McDonalds");
        cl.insertar("Rockys");
        cl.insertar("ISushi");
        cl.insertar("MadameTusan");
    }
    void Pila_Distrito() {
        pl.insertar("SanMiguel");
        pl.insertar("PuebloLibre");
        pl.insertar("Magdanela");
        pl.insertar("Bellavista");
        pl.insertar("JesusMaria");
        pl.insertar("Breña");
        pl.insertar("SanIsidro");
        pl.insertar("Miraflores");
        pl.insertar("Lince");
        pl.insertar("SanBorja");
        pl.insertar("Surco");
        pl.insertar("LaVictoria");
    }
    //Asignacion de valores a Usuario 
    void creaUsuario() {
        string n, d, m, r;
        cout << "Escriba el nombre del Usuario" << endl;
        cin >> n;
        if (pl.size() == 0) {
            Pila_Distrito();
        }
        d = pl.ultimo();
        cout << "Escriba su metodo de pago(Efectivo, POS)" << endl;
        cin >> m;
        if (cl.size() == 0)
        {
            Cola_de_Restaurantes();
        }
        r = cl.primero();
        u = new Usuario(n, d, m, r);
        usuarios.push_back(u);
        cl.eliminar();
        pl.eliminar();
        ++cantidad;
    }
    //Asignacion de Datos Randoms al Repartidor
    void randoms(int n) {
        rappi = r.at(n);
        auto random1 = [](int c) {return c = 100 + rand() % (1000 - 1); };
        auto random2 = [](int t) { return t = 20 + rand() % (61 - 1); };
        auto random3 = [](int precio) {return precio = 10 + rand() % (60 - 1); };
        auto random4 = [](int descuento) {return descuento = 10 + rand() % (16 - 1); };
        
        rappi.setCodigo(random1(codigo));
        rappi.setTiempo(random2(tiempo));
        tiempos.push_back(rappi.getTiempo());
        rappi.setPrecio(random3(precio));
        precios.push_back(rappi.getPrecio());
        rappi.setdescuento(random4(descuento));
        descuentos.push_back(rappi.getDescuento());
        //Asignacion de datos para Usuarios que se usara para el ordenamiento
        u->setTiempo(rappi.getTiempo());
        u->setPrecio(rappi.getPrecio());
        u->setDescuento(rappi.getDescuento());
    }
    //Asigna de Datos para el Repartidor
    void crearRepartidor() {
        srand(time(NULL));
        int op = 1 + rand() % (5 - 1);
        r.push_back(Repartidor{ "Diego",codigo = 100 + rand() % (1000 - 1) , tiempo = 20 + rand() % (61 - 1),precio = 10 + rand() % (60 - 1),descuento = 10 + rand() % (16 - 1) });
        r.push_back(Repartidor{ "Juan", codigo = 100 + rand() % (1000 - 1) , tiempo = 20 + rand() % (61 - 1),precio = 10 + rand() % (60 - 1),descuento = 10 + rand() % (16 - 1) });
        r.push_back(Repartidor{ "Pedro", codigo = 100 + rand() % (1000 - 1) ,tiempo = 20 + rand() % (61 - 1),precio = 10 + rand() % (60 - 1),descuento = 10 + rand() % (16 - 1) });
        r.push_back(Repartidor{ "Jaime", codigo = 100 + rand() % (1000 - 1) , tiempo = 20 + rand() % (61 - 1),precio = 10 + rand() % (60 - 1),descuento = 10 + rand() % (16 - 1) });
        randoms(op);
    }
    //Archivos para guardar Usuario y Repartidor
    void archivo() {
        u->guardar();
    }
    void archivo2() {
        rappi.guardar2();
        u->setPrecioDesc(rappi.getPrecioDesc());
    }
    void leer() {
        ifstream registro2("Registro.txt", fstream::in);
        while (getline(registro2, linea)) {
            texto = texto + linea + "\n";
        }
        registro2.close();
        cout << texto << endl;
    }
    //Ordenamientos
    //Funcion swap que sirvera intercambiar datos 
    template<typename T>
    void swap(T* a, T* b) {
        T t = *a;
        *a = *b;
        *b = t;
    }
    //Ordenamiento Burbuja para los precios
    void printprecios() {
            int aux;
            for (int i = 0; i < precios.size(); i++)
            {
                for (int j = 0; j < precios.size(); j++)
                {
                    if (precios[i] > precios[j])
                    {
                        aux = precios[i];
                        precios[i] = precios[j];
                        precios[j] = aux;
                    }
                }
            }
        }
    //Impresion de Precios Ordenados de Mayor a Menor
    void imprimir_Precios() {
        printprecios();
        cout << "Con los precios ordenados de mayor a menor tenemos la siguiente lista" << endl;
        for (int i = 0; i < precios.size(); i++)
        {
            for (int j = 0; j < usuarios.size(); j++)
            {
                if (usuarios[j]->getPrecio() == precios[i])
                {
                    cout << "El Usuario/a " << usuarios[j]->getNombre() << " tiene el monto de: " << precios[i] << " soles." << endl;
                }
            }
        }
    }
    //Ordenamiento por Insercion para el Tiempo
    void ordenar_por_Insercion() {
        for (auto it = tiempos.begin() + 1; it != tiempos.end(); ++it) {
            auto key = it;
            for (auto i = it - 1; i >= tiempos.begin(); --i) {
                if (*i > *key) {
                    std::swap(*i, *key);
                    key--;
                }
                else {
                    break;
                }
            }
        }
    }
    //Impresion de Tiempos ordenados de Menor a Mayor 
    void imprimir_Tiempos() {
        ordenar_por_Insercion();
        cout << "Con los tiempos de espera ordenados de menor a mayor tenemos la siguiente lista" << endl;
        for (int i = 0; i < tiempos.size(); i++)
        {
            for (int j = 0; j < usuarios.size(); j++)
            {
                if (usuarios[j]->getTiempo() == tiempos[i])
                {
                    cout << "El Usuario/a " << usuarios[j]->getNombre() << " tendra que esperar su pedido: " << tiempos[i] << " minutos." << endl;
                }
            }
        }
    }
    //Ordenamiento por Seleccion para el Descuento
    void seleccionsort()
    {
        int min, i, j, aux;
        for (i = 0; i < descuentos.size() - 1; i++)
        {
            min = i;
            for (j = i + 1; j < descuentos.size(); j++)
                if (descuentos[min] > descuentos[j])
                    min = j;
            aux = descuentos[min];
            descuentos[min] = descuentos[i];
            descuentos[i] = aux;
        }
    }
    //Impresion de los Descuentos de Mayor a Menor 
    void imprimir_descuentos() {
        seleccionsort();
        cout << "Con los descuentos ordenados de menor a mayor tenemos la siguiente lista" << endl;
        for (int i = 0; i < descuentos.size(); i++)
        {
            for (int j = 0; j < usuarios.size(); j++)
            {
                if (usuarios[j]->getDescuento() == descuentos[i])
                {
                    cout << "El Usuario/a " << usuarios[j]->getNombre() << " tendra " << descuentos[i] << "% de descuento en su compra y pagara:"<<usuarios[j]->getPrecioDesc() << endl;
                }
            }
        }
    }
};
