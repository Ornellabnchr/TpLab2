#ifndef MENUCLIENTES_CPP_INCLUDED
#define MENUCLIENTES_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace rlutil;

#include "menuClientes.h"
#include "validations.h"

#include "clsFecha.h"
#include "clsPersona.h"
#include "clsVendedor.h"
#include "clsCliente.h"
#include "clsVehiculo.h"
#include "clsOperacion.h"

enum MENU_CLIENTES{
      OPCION_SALIR_DE_MENUCLIENTES,
      OPCION_CARGAR_CLIENTE,
      OPCION_LISTADO_CLIENTES,
      OPCION_BUSCAR_CLIENTE,
      OPCION_CAMBIAR_PAPELERA_CLIENTE,
      OPCION_BORRAR_CLIENTE
};

int menuClientes(){
   int opc;
  while(true){
      system("cls");
      cout << "-----MENU CLIENTES-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. Cargar cliente" << endl;
      cout << "2. Ver listado de clientes" << endl;
      cout << "3. Buscar cliente por DNI" << endl;
      cout << "4. Borrar/Recuperar cliente de Papelera de reciclaje"<< endl;
      cout << "5. Borrar un cliente de forma permanente"<< endl;
      cout << "0. Volver al menu anterior" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case OPCION_CARGAR_CLIENTE:
                {
                    cout<<"------------------------------------------------------------------------" <<endl;
                    cout<<"------------------INGRESE DATOS DE CLIENTE:  ---------------------------"<<endl;
                    cout<<"------------------------------------------------------------------------" <<endl;
                    Cliente regCliente;
                    regCliente.Cargar();
                    break;
                }
        case OPCION_LISTADO_CLIENTES:
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------CLIENTES ACTIVOS--------------------------------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                listarClientes();
                break;
        case OPCION_BUSCAR_CLIENTE:
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------BUSCADOR DE CLIENTES---------------------------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                buscarCliente();
                break;
        case OPCION_CAMBIAR_PAPELERA_CLIENTE:
                {
                     cout<<"------------------------------------------------------------------------" <<endl;
                     cout<<"------------------PAPELERA DE RECICLAJE---------------------------------"<<endl;
                    cout<<"------------------------------------------------------------------------" <<endl;
                     int dni,pos;
                     Cliente regCliente;
                     cout<< "Ingrese el dni del cliente: ";
                     cin>>dni;
                     cout<<endl;
                     pos=regCliente.buscarPosEnDisco(dni);
                     if (pos==-1){
                         cout<<"No se ha encontrado un cliente con ese DNI"<<endl;
                         break;
                     }
                     changeClientePapelera(pos);
                     break;

                }
        case OPCION_BORRAR_CLIENTE:
                cout<<"------------------------------------------------------------------------" <<endl;
                cout<<"------------------ELIMINAR UN VENDEDOR PERMANENTEMENTE-----------------"<<endl;
                cout<<"------------------------------------------------------------------------" <<endl;
                int dni;
                cout<<"Ingrese el DNI del cliente a eliminar: ";
                cin>>dni;
                eliminarCliente(dni);
                break;
        case OPCION_SALIR_DE_MENUCLIENTES: return 0;
                break;
        default: cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
      cout<<endl;
      system("pause");
    }
    return 0;
}



void listarClientes(){
     Cliente regCliente;
     int cantClientes= cantDeClientes();
     for(int i=0;i<cantClientes;i++){
        bool leyo=regCliente.leerDeDisco(i);
        if (leyo==false) {
                cout<<endl<< "No pudo leer el cliente";
                return;
        }
        regCliente.Mostrar();
        cout<<endl<<endl;
     }
     return;
}


void buscarCliente(){
     int dni,pos;
     Cliente regCliente;
     cout<< "Ingrese el dni del cliente: ";
     cin>>dni;
     cout<<endl;
     pos=regCliente.buscarPosEnDisco(dni);
     if (pos==-1){
         cout<<"No se ha encontrado un cliente con ese DNI"<<endl;
         return;
     }
     bool leyo=regCliente.leerDeDisco(pos);
     if (leyo==true){
          cout<<"CLIENTE ENCONTRADO:" <<endl;
          regCliente.Mostrar();
          return;
     }
     cout<<"No se pudo abrir el archivo de clientes"<<endl;
}



void changeClientePapelera(int pos){
     int tam = cantDeClientes();
     FILE *p;
     Cliente regCliente,*vecCliente;
     vecCliente= new Cliente[tam];
     p=fopen("Clientes.dat","rb+");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            return;
     }
     fread(vecCliente,sizeof (Cliente),tam,p);
     if (vecCliente[pos].getEstado()==true){
             cout<<"El cliente se encuentra en el registro."<<endl;
             cout<<"Esta seguro/a que desea enviar a la papelera al cliente "<< vecCliente[pos].getNombre();
             cout<<" "<< vecCliente[pos].getApellido()<<"?";
             cout<<endl<<"1-Si 2-No: ";"\n";
     }
     else if (vecCliente[pos].getEstado()==false){
             cout<<"El cliente se encuentra la papelera"<<endl;
             cout<<"Esta seguro/a que desea restaurar de la papelera al cliente "<< vecCliente[pos].getNombre();
             cout<<" "<< vecCliente[pos].getApellido()<<"?";
             cout<<endl<<"1-Si 2-No: ";"\n";
     }
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
     if (vecCliente[pos].getEstado()==true){
               vecCliente[pos].setEstado(false);
               cout<<"El cliente se ha enviado a la papelera"<<endl;
     }
     else if (vecCliente[pos].getEstado()==false){
               vecCliente[pos].setEstado(true);
               cout<<"El cliente se ha recuperado de la papelera"<<endl;
     }
     fseek(p,0,0);
     fwrite(vecCliente,sizeof (Cliente),tam,p);
     fclose(p);
     delete vecCliente;
     return;
}


void eliminarCliente(int dni){
     int tam = cantDeClientes(),pos;
     Cliente regCliente,*vecCliente;
     vecCliente= new Cliente[tam];
     pos=regCliente.buscarPosEnDisco(dni);
     if (pos==-1){
        cout<<"El cliente no existe."<<endl;
        return;
     }
     FILE *p;
     p=fopen("Clientes.dat","rb");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            fclose(p);
            delete vecCliente;
            return;
     }
     fread(vecCliente,sizeof (Cliente),tam,p);
     fclose(p);
     cout<<"Esta seguro/a que desea eliminar al cliente "<< vecCliente[pos].getNombre();
     cout<<" "<< vecCliente[pos].getApellido()<<"?";
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
     p=fopen("Clientes.dat","wb");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            fclose(p);
            delete vecCliente;
            return;
     }
     while(pos!=tam-1){
              vecCliente[pos]=vecCliente[pos+1];
              pos++;
     }
     fseek(p,0,0);
     fwrite(vecCliente,sizeof (Cliente),tam-1,p);
     cout<<"El cliente se ha eliminado correctamente"<<endl;
     fclose(p);
     delete vecCliente;

}



int cantDeClientes(){
      FILE *p;
      int cant;
      Cliente regCliente;
      p=fopen("Clientes.dat","rb");
      if (p==NULL)return -1;
      fseek(p,0,2);
      cant=ftell(p)/(sizeof (Cliente));
      return cant;
}




#endif // MENUCLIENTES_CPP_INCLUDED
