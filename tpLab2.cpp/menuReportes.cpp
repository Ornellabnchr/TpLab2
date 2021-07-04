#ifndef MENUREPORTES_CPP_INCLUDED
#define MENUREPORTES_CPP_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

#include "clsOperacion.h"
#include "menuVendedores.h"
#include "menuReportes.h"
#include "validations.h"

enum MENU_REPORTES{
      OPCION_SALIR_DE_MENUREPORTES,
      OPCION_MOSTRAR_REPORTE_VENTAS,
      OPCION_RANKING_VENDEDORES,
};
int menuReportes(){
  setlocale(LC_ALL, "Spanish");
  int opc;
  while(true){
      system("cls");
      cout << "-----MENU REPORTES-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. Reporte de ventas mes a mes" << endl;
      cout << "2. Ranking de Vendedores" << endl;
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
                 // TODO: Falta Funci�n exportar como CSV
                 break;
                }
        case OPCION_RANKING_VENDEDORES:
                {
                 cout<<"------------------------------------------------------------------------" <<endl;
                 cout<<"------------------RANKING MEJORES VENDEDORES -------------------------- "<<endl;
                 cout<<"------------------------------------------------------------------------" <<endl;
                 mostrarRankingVendedores();
                }
                // TODO: Agregar los montos que gan� por comisiones
                break;
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
    fclose(p);
    cout<<endl<<endl;
    cout<<"Ingrese numero de mes para ver el detalle o 0 (cero) para salir: ";
    int rta;
    cin >> rta;
    if (rta==0) return;
    rta = validateMes(rta,anio);
    system("cls");
    mostrarVentasPorMes(rta,anio);
}


void mostrarVentasPorMes(int mes,int anio){
    Operacion regOperacion;
    Cliente regCliente;
    Vendedor regVendedor;
    Vehiculo regVehiculo;
    FILE *p;
    p=fopen("Operaciones.dat","rb");
    cout<<setw(5)<<"ID"<<setw(31)<<"Apellido del cliente"<<setw(31)<<"Apellido del vendedor"<<setw(10)<<"Monto"<<setw(15)<<"Marca"<<setw(20)<<"Modelo"<<endl;
    while (fread(&regOperacion, sizeof (Operacion),1,p) == 1){
        if (regOperacion.getFechaDeFin().getAnio()==anio && regOperacion.getFechaDeFin().getMes() == mes){
           cout<<setw(5)<<regOperacion.getIdOperacion();
           int pos;
           pos=regCliente.buscarPosEnDisco(regOperacion.getDniCliente());
           regCliente.leerDeDisco(pos);
           cout<<setw(31)<<regCliente.getApellido();
           pos=regVendedor.buscarPosEnDisco(regOperacion.getDniVendedor());
           regVendedor.leerDeDisco(pos);
           cout<<setw(31)<<regVendedor.getApellido();
           cout<<setw(10)<<"$"<<regOperacion.getMonto();
           pos=regVehiculo.buscarPosEnDisco(regOperacion.getIdVehiculo());
           regVehiculo.leerDeDisco(pos);
           cout<<setw(15)<<regVehiculo.getMarca();
           cout<<setw(20)<<regVehiculo.getModelo();
        }
    }
    fclose(p);
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

void mostrarRankingVendedores(){
    int cant = cantDeVendedores();
    Vendedor *vecVendedores;
    vecVendedores = new Vendedor[cant];
    FILE *p;
    p=fopen("Vendedores.dat","rb");
    if (p==NULL) return;
    fread(vecVendedores,sizeof (Vendedor),cant,p);
    for (int i=0;i<cant;i++){
        for(int j=i+1;j<cant;j++){
            if (vecVendedores[i].calculateCantVentasRealizadas()<vecVendedores[j].calculateCantVentasRealizadas()){
                Vendedor aux;
                aux = vecVendedores[j];
                vecVendedores[j]=vecVendedores[i];
                vecVendedores[i]=aux;
            }
        }
    }
    for (int k=0;k<cant;k++){
        cout<<k+1<<"-"<<vecVendedores[k].getNombre()<<" "<<vecVendedores[k].getApellido()<<": "<< vecVendedores[k].calculateCantVentasRealizadas()<<endl;

    }
    fclose(p);
}

#endif // MENUREPORTES_CPP_INCLUDED
