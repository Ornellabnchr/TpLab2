#ifndef MENUREPORTES_CPP_INCLUDED
#define MENUREPORTES_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "clsOperacion.h"
#include "menuReportes.h"

enum MENU_REPORTES{
      OPCION_SALIR_DE_MENUREPORTES,
      OPCION_MOSTRAR_REPORTE_VENTAS
};
int menuReportes(){
  setlocale(LC_ALL, "Spanish");
  int opc;
  while(true){
      system("cls");
      cout << "-----MENU REPORTES-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. Reporte de ventas mes a mes" << endl;
      cout << "0. Volver al menu anterior" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case OPCION_MOSTRAR_REPORTE_VENTAS:
                {
                 cout<<"------------------------------------------------------------------------" <<endl;
                 cout<<"------------------VENTAS MES A MES (2019/2020/2021) -------------------- "<<endl;
                 cout<<"------------------------------------------------------------------------" <<endl;
                 int anio;
                 cout<<"Ingrese el anio que desea ver: ";
                 cin>>anio;"\n";
                 int indexAnio = getIndexAnio(anio);
                 while (indexAnio==-1){
                       cout<<"Error!!! Ingrese un anio de actividad de la concesionaria (2019/2020/2021): ";
                       cin>>anio; "\n";
                 }
                 ventasPorMes(anio, indexAnio);
                 break;
                }
        case OPCION_SALIR_DE_MENUREPORTES:
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

void ventasPorMes(int anio,int indexAnio){
    Operacion regOperacion;
    bool huboVentas=false;
    int ventasMeses[12][3]={0};
    FILE *p;
    p=fopen("Operaciones.dat","rb");
    if(p==NULL) return;
    while(fread(&regOperacion,sizeof (Operacion),1,p)==1){
        if (regOperacion.getVentaCompleta()==true && regOperacion.getFechaDeFin().getAnio()== anio){
               huboVentas=true;
               int mesDeOperacion = regOperacion.getFechaDeFin().getMes();
               ventasMeses[mesDeOperacion-1][indexAnio]++;
        }
    }
    if (huboVentas==false){
          cout<< endl<<"No hay registradas ventas ese anio";
          return;
    }
    for (int i=0;i<12;i++){
        cout<< getNombreDeMes(i+1) << ": "<<ventasMeses[i][indexAnio]<<endl;
    }


}

char* getNombreDeMes(int nroDeMes){
        switch(nroDeMes){
            case 1:
            return "Enero";
            case 2:
            return "Febrero";
            case 3:
            return "Marzo";
            case 4:
            return "Abril";
            case 5:
            return "Mayo";
            case 6:
            return "Junio";
            case 7:
            return "Julio";
            case 8:
            return "Agosto";
            case 9:
            return "Septiembre";
            case 10:
            return "Octubre";
            case 11:
            return "Noviembre";
            case 12:
            return "Diciembre";

        }
}

int getIndexAnio(int anio){
    switch(anio){
        case 2019:
        return 0;
        case 2020:
        return 1;
        case 2021:
        return 2;
   }
   return -1;
}

#endif // MENUREPORTES_CPP_INCLUDED