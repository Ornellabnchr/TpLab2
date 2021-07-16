#ifndef MENUREPORTES_CPP_INCLUDED
#define MENUREPORTES_CPP_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

#include "rlutil.h"
using namespace rlutil;

#include "funciones.h"
#include "clsOperacion.h"
#include "menuVendedores.h"
#include "menuVehiculos.h"
#include "menuReportes.h"
#include "validations.h"

enum MENU_REPORTES{
      OPCION_SALIR_DE_MENUREPORTES,
      OPCION_MOSTRAR_REPORTE_VENTAS,
      OPCION_RANKING_VENDEDORES,
      OPCION_RANKING_VEHICULOS,
      OPCION_ESTADISTICA_EDAD_Y_CREDITOS
};
int menuReportes(){
  int opc;
  while(true){
      cls();
      gotoxy(55,4);
      cout << "MENU REPORTES" << endl;
      LINEA_EN_X(40,86,6,7);
      LINEA_EN_X(40,86,16,7);
      LINEA_EN_Y(6,17,39,7);
      LINEA_EN_Y(6,17,86,7);
      gotoxy(45,8);
      cout << "1. Reporte de ventas mes a mes" << endl;
      gotoxy(45,9);
      cout << "2. Ranking de Vendedores" << endl;
      gotoxy(45,10);
      cout << "3. Ranking de Vehiculos mas vendidos" << endl;
      gotoxy(45,11);
      cout << "4. Estadistica entre edad y credito"<<endl;
      gotoxy(45,12);
      cout << "0. Volver al menu anterior" << endl;
      gotoxy(50,19);
      cout << "SELECCIONE UNA OPCION: " << endl;
      gotoxy(72,19);
      cin>>opc;
      cls();
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
        case OPCION_RANKING_VENDEDORES:
                {
                 cout<<"------------------------------------------------------------------------" <<endl;
                 cout<<"------------------RANKING MEJORES VENDEDORES -------------------------- "<<endl;
                 cout<<"------------------------------------------------------------------------" <<endl;
                 mostrarRankingVendedores();
                }
                break;
        case OPCION_RANKING_VEHICULOS:
                {
                 cout<<"------------------------------------------------------------------------" <<endl;
                 cout<<"------------------RANKING VEHICULOS MÁS VENDIDOS -----------------------"<<endl;
                 cout<<"------------------------------------------------------------------------" <<endl;
                 mostrarRankingVehiculos();
                }
                break;
        case OPCION_ESTADISTICA_EDAD_Y_CREDITOS:
                {
                 cout<<"------------------------------------------------------------------------" <<endl;
                 cout<<"------------------ESTADÍSTICAS DE CRÉDITOS SOLICITADOS------------------"<<endl;
                 cout<<"------------------------------------------------------------------------" <<endl;
                 mostrarEstadisticaCreditoEdad();
                }
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
 float calculateCantMontos(int dn){
   Operacion regOperacion;
   int cantVentas=0;
   int pos=0;
  while(regOperacion.leerDeDisco(pos++)){
        if(regOperacion.getDniVendedor()==dn && regOperacion.getVentaCompleta()==true){
            cantVentas+=regOperacion.getMonto();
        }
   }
   return cantVentas;
}


void mostrarMontosVendedores(Vendedor *vecV, int cant){
    Vendedor reg;
    int pos=0;
    for(int i=0;i<cant;i++){
           float montos=calculateCantMontos(vecV[i].getDni());
                   cout<<i+1<<"-"<<vecV[i].getNombre()<<" "<<vecV[i].getApellido()<<": "<< vecV[i].calculateCantVentasRealizadas()<<"   |   Monto Total Recaudado (Comisiones): "<< ((montos*vecV[i].getComisionPorcentaje())/ 100)<<endl;

    }
}
void mostrarRankingVendedores(){
    int cant = cantDeVendedores();
    FILE *p;
    p=fopen("Vendedores.dat","rb");
    if (p==NULL || cant==-1 ){
       cout<<endl<<"El archivo de vendedores no existe";
       return;
    }
    Vendedor *vecVendedores;
    vecVendedores = new Vendedor[cant];
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
/*    for (int k=0;k<cant;k++){
        cout<<k+1<<"-"<<vecVendedores[k].getNombre()<<" "<<vecVendedores[k].getApellido()<<": "<< vecVendedores[k].calculateCantVentasRealizadas()<<endl;

    }*/
      mostrarMontosVendedores(vecVendedores,cant);
    fclose(p);
    delete vecVendedores;
}

void mostrarRankingVehiculos(){
    int cant = cantDeVehiculos();
    FILE *p;
    p=fopen("Vehiculos.dat","rb");
    if (p==NULL || cant==-1){
      cout<<endl<<"El archivo de vehiculos no existe";
      return;
    }
    Vehiculo *vecVehiculos;
    vecVehiculos = new Vehiculo[cant];
    fread(vecVehiculos,sizeof (Vehiculo),cant,p);
    for (int i=0;i<cant;i++){
        for(int j=i+1;j<cant;j++){
            if (vecVehiculos[i].calculateCantVendidos()<vecVehiculos[j].calculateCantVendidos()){
                Vehiculo aux;
                aux = vecVehiculos[j];
                vecVehiculos[j]=vecVehiculos[i];
                vecVehiculos[i]=aux;
            }
        }
    }
    for (int k=0;k<cant;k++){
        cout<<k+1<<"-"<<vecVehiculos[k].getMarca()<<" "<<vecVehiculos[k].getModelo()<<": "<< vecVehiculos[k].calculateCantVendidos()<<endl;
    }
    fclose(p);
}


void mostrarEstadisticaCreditoEdad(){
    Cliente regCliente;
    Operacion regOperacion;
    int ventasJoven=0,ventasMedia=0, ventasMayor=0;
    int cantConCredito=0;
    float porcentajeJoven=0,porcentajeMedia=0,porcentajeMayor=0;
    FILE *p;
    p=fopen("Operaciones.dat","rb");
    if (p==NULL){
      cout<<"No se pudo leer el archivo"<<endl;
      return;
    }
    while (fread(&regOperacion,sizeof (Operacion),1,p)==1){
        int pos=regCliente.buscarPosEnDisco(regOperacion.getDniCliente());
        regCliente.leerDeDisco(pos);
        if(regCliente.getPidioCredito()==true){
            cantConCredito++;
            int edad=regCliente.calculateEdad();
            if(edad>45) ventasMayor++;
            else if (edad<=45 && edad>=31) ventasMedia++;
            else ventasJoven++;
        }
    }
    fclose(p);
    porcentajeJoven=float(ventasJoven)/float(cantConCredito);
    porcentajeMedia=float(ventasMedia)/float(cantConCredito);
    porcentajeMayor=float(ventasMayor)/float(cantConCredito);
    cout<<"Porcentaje de ventas con crédito: "<<endl;
    cout<<"Clientes jóvenes (entre 18 y 30 años inclusive): "<<porcentajeJoven << " ("<<ventasJoven<<" ventas)"<<endl;
    cout<<"Clientes de edad media (entre 30 y 45 años inclusive): "<<porcentajeMedia << " ("<<ventasMedia<<" ventas)"<<endl;
    cout<<"Clientes de mayores (más de 45 años): "<<porcentajeMayor << " ("<<ventasMayor<<" ventas)"<<endl;
}

#endif // MENUREPORTES_CPP_INCLUDED
