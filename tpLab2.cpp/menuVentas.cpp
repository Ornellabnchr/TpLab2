#ifndef MENUVENTAS_CPP_INCLUDED
#define MENUVENTAS_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "clsFecha.h"
#include "clsOperacion.h"
#include "menuVentas.h"

enum MENU_VENTAS{
      OPCION_SALIR_MENUVENTAS,
      OPCION_CARGAR_VENTA,
      OPCION_LISTADO_VENTAS,
};


int menuVentas(){
  int opc;
  while(true){
      system("cls");
      cout << "-----MENU VENTAS-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. Cargar venta" << endl;
      cout << "2. Ver listado de operaciones" << endl;
      cout << "0. Volver al menu anterior" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case OPCION_CARGAR_VENTA:
                   {
                    cout<<"------------------------------------------------------------------------" <<endl;
                    cout<<"------------------INGRESE DATOS DE VENTA:  --------------------------"<<endl;
                    cout<<"------------------------------------------------------------------------" <<endl;
                    Operacion regOperacion;
                    regOperacion.Cargar();
                    break;
                   }

        case OPCION_LISTADO_VENTAS:
                  listarOperaciones();
                   break;

        case OPCION_SALIR_MENUVENTAS:
                return 0;
                break;
        default: cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
      cout<<endl;
      system("pause");
    }
    return 0;
}


void listarOperaciones(){
     Operacion regOperacion;
     int cantOperaciones= cantDeOperaciones();
     for(int i=0;i<cantOperaciones;i++){
        bool leyo=regOperacion.leerDeDisco(i);
        if (leyo==false) {
                cout<<endl<< "No pudo leer la operacion";
                return;
        }
        regOperacion.Mostrar();
        cout<<endl;
     }
     return;
}


int cantDeOperaciones(){
      FILE *p;
      int cant;
      Operacion regOperacion;
      p=fopen("Operaciones.dat","rb");
      if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            return -1;
      }
      fseek(p,0,2);
      cant=ftell(p)/(sizeof (Operacion));
      return cant;
}

#endif // MENUVENTAS_CPP_INCLUDED
