#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "funciones.h"

#include "clsFecha.h"
#include "clsPersona.h"
#include "clsVendedor.h"
#include "clsCliente.h"
#include "clsVehiculo.h"
#include "clsOperacion.h"

#include "menuVentas.h"
#include "menuClientes.h"
#include "menuVendedores.h"
#include "menuVehiculos.h"
#include "menuReportes.h"

//TODO: Cambiar estructuras de decision Si o No por una funcion
//TODO: Cambiar metodo buscarPosEnDisco de todas las clases
//TODO: Armar un archivo de operaciones de prueba

enum MENU_MAIN{
      OPCION_SALIR,
      OPCION_VENTAS,
      OPCION_CLIENTES,
      OPCION_VENDEDORES,
      OPCION_VEHICULOS,
      OPCION_REPORTES
};

int main(){
  setlocale(LC_ALL, "Spanish");
  int opc;
  while(true){
      system("cls");
      cout << "-----MENU PRINCIPAL-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. Gestionar ventas" << endl;
      cout << "2. Gestionar clientes" << endl;
      cout << "3. Gestionar vendedores" << endl;
      cout << "4. Gestionar vehiculos" << endl;
      cout << "5. Reportes" << endl;
      cout << "0. Cerrar" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case OPCION_VENTAS:
                menuVentas();
                break;
        case OPCION_CLIENTES:
                menuClientes();
                break;
        case OPCION_VENDEDORES:
                menuVendedores();
                break;
        case OPCION_VEHICULOS:
                menuVehiculos();
                break;
        case OPCION_REPORTES:
                menuReportes();
                break;
        case OPCION_SALIR:
                return 0;
                break;
        default: cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }


  return 0;
}
