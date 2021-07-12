#ifndef CLSVENDEDOR_CPP_INCLUDED
#define CLSVENDEDOR_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "clsVendedor.h"
#include "clsOperacion.h"
#include "validations.h"


void Vendedor::setComisionPorcentaje(const float comisionPorcentaje){this->comisionPorcentaje=comisionPorcentaje;}
void Vendedor::setSueldoBruto(const float sueldoBruto){this->sueldoBruto=sueldoBruto;}
float Vendedor::getComisionPorcentaje(){return comisionPorcentaje;}
float Vendedor::getSueldoBruto(){return sueldoBruto;}



void Vendedor::Cargar(){
    Persona::Cargar();
    cout <<"Ingrese el DNI: ";
    cin >> dni;"\n";
    dni= validateDniVendedor(dni);
    cout<<"Ingrese el sueldo bruto: ";
    cin >> sueldoBruto;"\n";
    sueldoBruto= validateSueldo(sueldoBruto);
    cout<<"Ingrese el porcentaje de comision que tiene este vendedor en cada operacion: ";
    cin >> comisionPorcentaje;"\n";
    comisionPorcentaje=validateComisionPorcentaje(comisionPorcentaje);
    cout<<endl<<"Perfil creado exitosamente";
    Vendedor::cargarEnArchivo();

}



void Vendedor::Mostrar(){
    if (estado==true){
            Persona::Mostrar();
            cout<<"Sueldo bruto: "<<sueldoBruto <<"$"<<endl;
            cout<<"Porcentaje de comision actual: "<<comisionPorcentaje <<"%"<<endl;
            cout<<"Cantidad de ventas realizadas: "<<Vendedor::calculateCantVentasRealizadas();
            cout<<endl;
    }
    else return;
}

void Vendedor::cargarEnArchivo(){
     FILE *p;
     p=fopen("Vendedores.dat","ab");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            return;
     }
     fwrite(this,sizeof (Vendedor),1,p);
     fclose(p);
     return;
}


int Vendedor::buscarPosEnDisco(const int dni){
      FILE *p;
      p=fopen("Vendedores.dat","rb");
      if (p==NULL){
                cout<<"No se pudo abrir el archivo";
                return -1;
      }
      int c=0,pos=-1;
      while(fread(this,sizeof (Vendedor),1,p)==1){
         if(this->dni==dni){
                pos=c;
         }
          c++;
      }
      fclose(p);
      return pos;
}


bool Vendedor::leerDeDisco(const int pos){
    FILE *p;
    p=fopen("Vendedores.dat","rb");
    if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            return false;
     }
    fseek(p, pos*sizeof *this, 0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}


bool Vendedor::grabarEnDisco(const int pos){
    FILE *p;
    p=fopen("Vendedores.dat","rb+");
    if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            return false;
     }
    else  fseek(p, (pos)*sizeof *this, 0);
    bool escribio=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return escribio;
}



int Vendedor::calculateCantVentasRealizadas(){
   Operacion regOperacion;
   int cantVentas=0;
   FILE *p;
   p=fopen("Operaciones.dat","rb");
   if (p==NULL) return 0;
   while(fread(&regOperacion,sizeof (Operacion),1,p)==1){
        if(regOperacion.getDniVendedor()==dni && regOperacion.getVentaCompleta()==true){
            cantVentas++;
        }
   }
   fclose(p);
   return cantVentas;
}

#endif // CLSVENDEDOR_CPP_INCLUDED
