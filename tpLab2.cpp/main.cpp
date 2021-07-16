#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "rlutil.h"
using namespace rlutil;

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
//TODO: Dar estilos a todos los menus

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
      cls();
      gotoxy(55,4);
      cout << "MENU PRINCIPAL" << endl;
      LINEA_EN_X(40,86,6,9);
      LINEA_EN_X(40,86,16,9);
      LINEA_EN_Y(6,17,39,9);
      LINEA_EN_Y(6,17,86,9);
      gotoxy(45,8);
      cout << "1. Gestionar ventas" << endl;
      gotoxy(45,9);
      cout << "2. Gestionar clientes" << endl;
      gotoxy(45,10);
      cout << "3. Gestionar vendedores" << endl;
      gotoxy(45,11);
      cout << "4. Gestionar vehiculos" << endl;
      gotoxy(45,12);
      cout << "5. Reportes" << endl;
      gotoxy(45,13);
      cout << "0. Cerrar" << endl;
      gotoxy(50,19);
      cout << "SELECCIONE UNA OPCION:  " << endl;
      gotoxy(72,19);
      cin>>opc;
      cls();
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
