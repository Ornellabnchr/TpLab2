#ifndef MENUVEHICULOS_CPP_INCLUDED
#define MENUVEHICULOS_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "rlutil.h"
using namespace rlutil;

#include "funciones.h"
#include "menuVehiculos.h"

enum MENU_VEHICULOS{
      OPCION_SALIR_MENUVEHICULOS,
      OPCION_CARGAR_VEHICULO,
      OPCION_LISTADO_VEHICULOS,
      OPCION_BUSCAR_VEHICULO,
      OPCION_ELIMINAR_VEHICULO,
      OPCION_AGREGAR_STOCK_VEHICULOS

};
int menuVehiculos(){
  int opc;
  while(true){
      cls();
      gotoxy(55,4);
      cout << "MENU VEHICULOS" << endl;
      LINEA_EN_X(40,86,6,6);
      LINEA_EN_X(40,86,16,6);
      LINEA_EN_Y(6,17,39,6);
      LINEA_EN_Y(6,17,86,6);
      gotoxy(45,8);
      cout << "1. Cargar nuevo vehiculo" << endl;
      gotoxy(45,9);
      cout << "2. Ver lista de vehiculos disponibles" << endl;
      gotoxy(45,10);
      cout << "3. Revisar stock por ID" << endl;
      gotoxy(45,11);
      cout << "4. Borrar un vehiculo"<< endl;
      gotoxy(45,12);
      cout << "5. Agregar stock a un vehiculo"<< endl;
      gotoxy(45,13);
      cout << "0. Volver al menu anterior" << endl;
      gotoxy(50,19);
      cout << "SELECCIONE UNA OPCION: " << endl;
      gotoxy(72,19);
      cin>>opc;
      cls();
      switch(opc){
        case OPCION_CARGAR_VEHICULO:
                {
                 cout<<"------------------------------------------------------------------------" <<endl;
                 cout<<"------------------INGRESE DATOS DE VEHICULO:  --------------------------"<<endl;
                 cout<<"------------------------------------------------------------------------" <<endl;
                 Vehiculo regVehiculo;
                 regVehiculo.Cargar();
                 break;
                }
        case OPCION_LISTADO_VEHICULOS:
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------VEHICULOS EN STOCK-------------------------------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                listarVehiculos();
                break;
        case OPCION_BUSCAR_VEHICULO:
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------BUSCADOR DE VEHICULOS---------------------------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                buscarVehiculo();
                break;
        case OPCION_ELIMINAR_VEHICULO:

                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------ELIMINAR UN VEHICULO PERMANENTEMENTE-----------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                int idVehiculo;
                cout<<"Ingrese el ID del vehiculo que desea eliminar: ";
                cin>>idVehiculo;
                eliminarVehiculo(idVehiculo);
                break;
        case OPCION_AGREGAR_STOCK_VEHICULOS:
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------AGREGAR STOCK A UN VEHICULO EXISTENTE-----------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                int id,stock;
                cout<<"Ingrese el ID del vehiculo para sumar stock: ";
                cin>>id;
                cout<<endl<<"Ingrese el numero de stock que ingreso a la sucursal: ";
                cin>>stock;
                agregarStockVehiculo(id,stock);
                break;
        case OPCION_SALIR_MENUVEHICULOS:
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


void listarVehiculos(){
     Vehiculo regVehiculo;
     int cantVehiculos= cantDeVehiculos();
     for(int i=0;i<cantVehiculos;i++){
        bool leyo=regVehiculo.leerDeDisco(i);
        if (leyo==false) {
                cout<<endl<< "No pudo leer el vehiculo";
                return;
        }
        regVehiculo.Mostrar();
        cout<<endl;
     }
     return;
}


void buscarVehiculo(){
     int idVehiculo,pos;
     Vehiculo regVehiculo;
     cout<< "Ingrese el ID del vehiculo: ";
     cin>>idVehiculo;
     cout<<endl;
     pos=regVehiculo.buscarPosEnDisco(idVehiculo);
     if (pos==-1){
         cout<<"No se ha encontrado un vehiculo con ese ID"<<endl;
         return;
     }
     bool leyo=regVehiculo.leerDeDisco(pos);
     if (leyo==true){
          cout<<"VEHICULO ENCONTRADO:" <<endl;
          regVehiculo.Mostrar();
          return;
     }
     cout<<"No se pudo abrir el archivo de vehiculos"<<endl;
}


void eliminarVehiculo(int idVehiculo){
     int tam = cantDeVehiculos(),pos;
     Vehiculo regVehiculo,*vecVehiculo;
     vecVehiculo= new Vehiculo[tam];
     pos=regVehiculo.buscarPosEnDisco(idVehiculo);
     if (pos==-1){
        cout<<"El vehiculo no existe."<<endl;
        return;
     }
     FILE *p;
     p=fopen("Vehiculos.dat","rb");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            fclose(p);
            delete vecVehiculo;
            return;
     }
     fread(vecVehiculo,sizeof (Vehiculo),tam,p);
     fclose(p);
     cout<<"Esta seguro/a que desea eliminar al vehiculo "<< vecVehiculo[pos].getMarca()<<" ";
     cout<<vecVehiculo[pos].getModelo()<<"?";

     cout<<endl<<"1-Si 2-No: ";"\n";
     int rta;
     cin>>rta;
     while (rta!=1 && rta!=2){
                cout<<endl<<"Ingrese una opcion valida: ";
                cin>>rta;
     }
     if(rta==2){
                cout<<endl<<"Operacion cancelada.";
                return;
     }
     p=fopen("Vehiculos.dat","wb");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            fclose(p);
            delete vecVehiculo;
            return;
     }
     while(pos!=tam-1){
              vecVehiculo[pos]=vecVehiculo[pos+1];
              pos++;
     }
     fseek(p,0,0);
     fwrite(vecVehiculo,sizeof (Vehiculo),tam-1,p);
     cout<<"El vehiculo se ha eliminado correctamente"<<endl;
     fclose(p);
     delete vecVehiculo;

}

void agregarStockVehiculo(int idVehiculo,int stock){
      int tam = cantDeVehiculos(),stockActual,aux=stock;
      Vehiculo regVehiculo,*vecVehiculo;
      vecVehiculo= new Vehiculo[tam];
      int pos=regVehiculo.buscarPosEnDisco(idVehiculo);
      if(pos==-1){
            cout<<endl<<"El vehiculo no existe en el archivo.";
            delete vecVehiculo;
            return;
      }
      FILE *p;
      p=fopen("Vehiculos.dat","rb+");
      if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            delete vecVehiculo;
            return;
      }
      fread(vecVehiculo,sizeof (Vehiculo),tam,p);
      stockActual=vecVehiculo[pos].getStock();
      aux+=stockActual;
      if(aux>0 && vecVehiculo[pos].getEstado()==false) vecVehiculo[pos].setEstado(true);
      vecVehiculo[pos].setStock(aux);
      cout<<"Stock actualizado. Stock actual de " << vecVehiculo[pos].getMarca() << " "<<vecVehiculo[pos].getModelo()<<": "<<aux;
      fseek(p,0,0);
      fwrite(vecVehiculo,sizeof (Vehiculo),tam,p);
      fclose(p);
      delete vecVehiculo;
      return;
}

int cantDeVehiculos(){
      FILE *p;
      int cant;
      Vehiculo regVehiculo;
      p=fopen("Vehiculos.dat","rb");
      if (p==NULL){
            return -1;
      }
      fseek(p,0,2);
      cant=ftell(p)/(sizeof (Vehiculo));
      return cant;
}



#endif // MENUVEHICULOS_CPP_INCLUDED
