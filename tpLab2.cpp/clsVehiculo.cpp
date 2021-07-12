#ifndef CLSVEHICULO_CPP_INCLUDED
#define CLSVEHICULO_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "clsVehiculo.h"
#include "clsOperacion.h"
#include "funciones.h"


Vehiculo::Vehiculo(){
            estado=false;
}
void Vehiculo::setIdVehiculo(const int idVehiculo){this->idVehiculo=idVehiculo;}
void Vehiculo::setModelo(const char *modelo){strcpy(this->modelo, modelo);}
void Vehiculo::setMarca(const char *marca){strcpy(this->marca, marca);}
void Vehiculo::setColor(const char *color){strcpy(this->color, color);}
void Vehiculo::setCantPuertas(const int cantPuertas){this->cantPuertas=cantPuertas;}
void Vehiculo::setAnio(const int anio){this->anio=anio;}
void Vehiculo::setStock(const int stock){this->stock=stock;}
void Vehiculo::setEstado(const bool estado){this->estado=estado;}
int Vehiculo::getIdVehiculo(){return idVehiculo;}
const char* Vehiculo::getModelo(){return modelo;}
const char* Vehiculo::getMarca(){return marca;}
const char* Vehiculo::getColor(){return color;}
int Vehiculo::getCantPuertas(){return cantPuertas;}
int Vehiculo::getAnio(){return anio;}
int Vehiculo::getStock(){return stock;}
bool Vehiculo::getEstado(){return estado;}

//TODO: Agregar validacion a la cantidad de puertas, año del modelo, Id del vehiculo


void Vehiculo::Cargar(){
    cout <<"Ingrese el ID del vehiculo: ";
    cin >> idVehiculo;"\n";
    cout<<"Ingrese el nombre del modelo: ";
    cargarCadena(modelo,20);"\n";
    cout<<"Ingrese la marca: ";
    cargarCadena(marca,15);"\n";
    cout<<"Ingrese el color : ";
    cin >> color;"\n";
    cout<<"Ingrese el anio del modelo: ";
    cin >> anio;"\n";
    cout<<"Ingrese la cantidad de puertas del modelo: ";
    cin >> cantPuertas;"\n";
    cout<<"Ingrese el stock: ";
    cin >> stock;"\n";
    if (stock>0) this->setEstado(true);
    Vehiculo::cargarEnArchivo();

}

void Vehiculo::Mostrar(){
   cout<<"ID del vehiculo: "<<idVehiculo<<endl;
   cout<<"Modelo: "<<modelo <<endl;
   cout<<"Marca: "<<marca<<endl;
   cout<<"Color: "<<color <<endl;
   cout<<"Anio: "<<anio <<endl;
   cout<<"Cantidad de Puertas: "<<cantPuertas <<endl;
   cout<<"Stock: "<<stock << " disponibles"<<endl;
}

void Vehiculo::cargarEnArchivo(){
     FILE *p;
     p=fopen("Vehiculos.dat","ab");
     if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            return;
     }
     fwrite(this,sizeof (Vehiculo),1,p);
     fclose(p);
     return;
}

int Vehiculo::buscarPosEnDisco(const int idVehiculo){
      FILE *p;
      p=fopen("Vehiculos.dat","rb");
      if (p==NULL){
                cout<<"No se pudo abrir el archivo";
                return -1;
      }
      int c=0,pos=-1;
      while(fread(this,sizeof (Vehiculo),1,p)==1){
         if(this->idVehiculo==idVehiculo){
                pos=c;
         }
          c++;
      }
      fclose(p);
      return pos;
}

bool Vehiculo::leerDeDisco(const int pos){
        FILE *p;
        p=fopen("Vehiculos.dat","rb");
        if (p==NULL){
                cout<<"No se pudo abrir el archivo";
                return false;
         }
        fseek(p, pos*sizeof *this, 0);
        bool leyo=fread(this, sizeof *this, 1, p);
        fclose(p);
        return leyo;
}

bool Vehiculo::grabarEnDisco(const int pos){
    FILE *p;
    p=fopen("Vehiculos.dat","rb+");
    if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            return false;
     }
    fseek(p, pos*sizeof *this, 0);
    bool escribio=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return escribio;
}


int Vehiculo::calculateCantVendidos(){
   Operacion regOperacion;
   int cantVentas=0;
   FILE *p;
   p=fopen("Operaciones.dat","rb");
   if (p==NULL) return 0;
   while(fread(&regOperacion,sizeof (Operacion),1,p)==1){
        if(regOperacion.getIdVehiculo()==idVehiculo && regOperacion.getVentaCompleta()==true){
            cantVentas++;
        }
   }
   fclose(p);
   return cantVentas;
}

#endif // CLSVEHICULO_CPP_INCLUDED
