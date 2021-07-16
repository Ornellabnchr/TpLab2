#ifndef MENUVENDEDORES_CPP_INCLUDED
#define MENUVENDEDORES_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "rlutil.h"
using namespace rlutil;

#include "funciones.h"
#include "menuVendedores.h"

enum MENU_VENDEDORES{
      OPCION_SALIR_DE_MENUVENDEDORES,
      OPCION_CARGAR_VENDEDOR,
      OPCION_LISTADO_VENDEDORES,
      OPCION_BUSCAR_VENDEDOR,
      OPCION_ACTUALIZAR_SUELDO,
      OPCION_CAMBIAR_PAPELERA_VENDEDOR,
      OPCION_BORRAR_VENDEDOR
};


int menuVendedores(){
  int opc;
  while(true){
      cls();
      gotoxy(55,4);
      cout << "MENU VENDEDORES" << endl;
      LINEA_EN_X(40,86,6,8);
      LINEA_EN_X(40,86,16,8);
      LINEA_EN_Y(6,17,39,8);
      LINEA_EN_Y(6,17,86,8);
      gotoxy(45,8);
      cout << "1. Cargar vendedor" << endl;
      gotoxy(45,9);
      cout << "2. Ver listado de vendedores" << endl;
      gotoxy(45,10);
      cout << "3. Buscar vendedor por DNI" << endl;
      gotoxy(45,11);
      cout << "4. Actualizar sueldo de vendedores" << endl;
      gotoxy(45,12);
      cout << "5. Borrar/Recuperar vendedor de Papelera"<< endl;
      gotoxy(45,13);
      cout << "6. Borrar un vendedor de forma permanente"<< endl;
      gotoxy(45,14);
      cout << "0. Volver al menu anterior" << endl;
      gotoxy(50,19);
      cout << "SELECCIONE UNA OPCION: " << endl;
      gotoxy(72,19);
      cin>>opc;
      cls();
      switch(opc){
        case OPCION_CARGAR_VENDEDOR:
                {
                    cout<<"------------------------------------------------------------------------" <<endl;
                    cout<<"------------------INGRESE DATOS DE VENDEDOR:  --------------------------"<<endl;
                    cout<<"------------------------------------------------------------------------" <<endl;
                    Vendedor regVendedor;
                    regVendedor.Cargar();
                    break;
                }
        case OPCION_LISTADO_VENDEDORES:
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------VENDEDORES ACTIVOS-------------------------------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                listarVendedores();
                break;
        case OPCION_BUSCAR_VENDEDOR:
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------BUSCADOR DE VENDEDORES---------------------------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                buscarVendedor();
                break;
        case OPCION_ACTUALIZAR_SUELDO:
               {
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------ACTUALIZAR SUELDO -------------------------------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                int dni;
                cout<< "Ingrese el dni del vendedor: ";
                cin>>dni;
                cout<<endl;
                actualizarSueldoVendedor(dni);
               }
        break;
        case OPCION_CAMBIAR_PAPELERA_VENDEDOR:
                {
                     cout<<"------------------------------------------------------------------------" <<endl;
                     cout<<"------------------PAPELERA DE RECICLAJE---------------------------------"<<endl;
                    cout<<"------------------------------------------------------------------------" <<endl;
                     int dni,pos;
                     Vendedor regVendedor;
                     cout<< "Ingrese el dni del vendedor: ";
                     cin>>dni;
                     cout<<endl;
                     pos=regVendedor.buscarPosEnDisco(dni);
                     if (pos==-1){
                         cout<<"No se ha encontrado un vendedor con ese DNI"<<endl;
                         break;
                     }
                     changeVendedorPapelera(pos);
                     break;

                }
        case OPCION_BORRAR_VENDEDOR:
                 {
                    cout<<"------------------------------------------------------------------------" <<endl;
                    cout<<"------------------ELIMINAR UN VENDEDOR PERMANENTEMENTE-----------------"<<endl;
                    cout<<"------------------------------------------------------------------------" <<endl;
                    int dni;
                    cout<<"Ingrese el DNI del vendedor a eliminar: ";
                    cin>>dni;
                    eliminarVendedor(dni);
                    break;
                }
        case OPCION_SALIR_DE_MENUVENDEDORES:
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



void listarVendedores(){
     Vendedor regVendedor;
     int cantVendedores= cantDeVendedores();
     for(int i=0;i<cantVendedores;i++){
        bool leyo=regVendedor.leerDeDisco(i);
        if (leyo==false) {
                cout<<endl<< "No pudo leer el vendedor";
                return;
        }
        regVendedor.Mostrar();
        cout<<endl;
     }
     return;
}



void buscarVendedor(){
     int dni,pos;
     Vendedor regVendedor;
     cout<< "Ingrese el dni del vendedor: ";
     cin>>dni;
     cout<<endl;
     pos=regVendedor.buscarPosEnDisco(dni);
     if (pos==-1){
         cout<<"No se ha encontrado un vendedor con ese DNI"<<endl;
         return;
     }
     bool leyo=regVendedor.leerDeDisco(pos);
     if (leyo==true){
          cout<<"VENDEDOR ENCONTRADO:" <<endl;
          regVendedor.Mostrar();
          return;
     }
     cout<<"No se pudo abrir el archivo de vendedores"<<endl;
}


void changeVendedorPapelera(int pos){
     Vendedor regVendedor;
     bool leyo = regVendedor.leerDeDisco(pos);
     if (leyo == false) return;
     if (regVendedor.getEstado()==true){
             cout<<"El vendedor se encuentra en el registro."<<endl;
             cout<<"Esta seguro/a que desea enviar a la papelera al vendededor/a "<< regVendedor.getNombre();
             cout<<" "<< regVendedor.getApellido()<<"?";
     }
     else if (regVendedor.getEstado()==false){
             cout<<"El vendedor se encuentra la papelera"<<endl;
             cout<<"Esta seguro/a que desea restaurar de la papelera al vendededor/a "<< regVendedor.getNombre();
             cout<<" "<< regVendedor.getApellido()<<"?";
     }
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
     if (regVendedor.getEstado()==true){
               regVendedor.setEstado(false);
               cout<<endl<<"El vendedor se enviara a la papelera..."<<endl;
     }
     else if (regVendedor.getEstado()==false){
               regVendedor.setEstado(true);
               cout<<endl<<"El vendedor se restaurara de la papelera..."<<endl;
     }
     bool escribio=regVendedor.grabarEnDisco(pos);
     if (escribio==false) {
            cout<<"Proceso fallido";
            return;
     }
     cout<<"Proceso exitoso";

}



void eliminarVendedor(int dni){
     int tam = cantDeVendedores(),pos;
     Vendedor regVendedor,*vecVendedor;
     vecVendedor= new Vendedor[tam];
     pos=regVendedor.buscarPosEnDisco(dni);
     if (pos==-1){
        cout<<"El vendedor no existe."<<endl;
        return;
     }
     FILE *p;
     p=fopen("Vendedores.dat","rb");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            fclose(p);
            delete vecVendedor;
            return;
     }
     fread(vecVendedor,sizeof (Vendedor),tam,p);
     fclose(p);
     cout<<"Esta seguro/a que desea eliminar al vendedor "<< vecVendedor[pos].getNombre();
     cout<<" "<< vecVendedor[pos].getApellido()<<"?";
     cout<<endl<<"1-S� 2-No: ";"\n";
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
     p=fopen("Vendedores.dat","wb");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            fclose(p);
            delete vecVendedor;
            return;
     }
     while(pos!=tam-1){
              vecVendedor[pos]=vecVendedor[pos+1];
              pos++;
     }
     fseek(p,0,0);
     fwrite(vecVendedor,sizeof (Vendedor),tam-1,p);
     cout<<"El vendedor se ha eliminado correctamente"<<endl;
     fclose(p);
     delete vecVendedor;

}


int cantDeVendedores(){
      FILE *p;
      int cant;
      Vendedor regVendedor;
      p=fopen("Vendedores.dat","rb");
      if (p==NULL){
            return -1;
      }
      fseek(p,0,2);
      cant=ftell(p)/(sizeof (Vendedor));
      return cant;
}


void actualizarSueldoVendedor(int dni){
     int pos;
     float porcentajeAumento,nuevoSueldo;
     Vendedor regVendedor;
     pos=regVendedor.buscarPosEnDisco(dni);
     bool leyo = regVendedor.leerDeDisco(pos);
     if (leyo == false) return;
     cout<<"\n\n"<<"El/la vendedor/a "<< regVendedor.getNombre() << regVendedor.getApellido() << " actualmente gana $"<<regVendedor.getSueldoBruto();
     cout<<endl<<"Ingrese el porcentaje de sueldo que desea aumentarle: ";
     cin>>porcentajeAumento;
     nuevoSueldo= regVendedor.getSueldoBruto()+(porcentajeAumento*regVendedor.getSueldoBruto()/float(100));
     regVendedor.setSueldoBruto(nuevoSueldo);
     bool escribio=regVendedor.grabarEnDisco(pos);
     if (escribio==false) return;
     cout<<endl<<"Ingresado con exito. Nuevo sueldo $"<<nuevoSueldo;

};


#endif // MENUVENDEDORES_CPP_INCLUDED
