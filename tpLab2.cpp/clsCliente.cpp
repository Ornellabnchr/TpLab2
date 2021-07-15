#ifndef CLSCLIENTE_CPP_INCLUDED
#define CLSCLIENTE_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "clsCliente.h"
#include "validations.h"
#include "clsOperacion.h"


bool Cliente::getPidioCredito(){return pidioCredito;};
void Cliente::setPidioCredito(const bool pidioCredito){this->pidioCredito=pidioCredito;};

void Cliente::Mostrar(){
    // TODO: revisar metodo mostrar en el buscador por DNI
    if (estado==true){
            Persona::Mostrar();
            cout<<"Cantidad de compras realizadas: ";
            int cantCompras=Cliente::calcularCantComprasRealizadas(dni);
            cout<< cantCompras;
            if (cantCompras>0){
                cout<<endl<<"Patentes asociadas al cliente: ";
                Cliente::mostrarAutosAsociados(dni);
            }
            return;
    }
    cout<<endl;

}

void Cliente::Cargar(){
     Persona::Cargar();
     cout <<"Ingrese el DNI: ";
     cin >> dni;"\n";
     dni= validateDniCliente(dni);
     cout<<"\n Con fines estadisticos, responda: ¿Este cliente pidio un credito? 1- Si 2-No: ";
     int rta;
     cin>>rta;
     while (rta != 1 && rta != 2){
        cout<<endl<<"ERROR! Ingrese una opcion valida: ";
        cin>>rta;
     }
     if (rta==1){
        pidioCredito=true;
     }
     else pidioCredito=false;
     Cliente::cargarEnArchivo();
}

void Cliente::cargarEnArchivo(){
     FILE *p;
     p=fopen("Clientes.dat","ab");
     if (p==NULL)return;
     fwrite(this,sizeof (Cliente),1,p);
     fclose(p);
     return;
}

int Cliente::buscarPosEnDisco(const int dni){
      FILE *p;
      p=fopen("Clientes.dat","rb");
      if (p==NULL) return -1;
      int c=0,pos=-1;
      while(fread(this,sizeof (Cliente),1,p)==1){
         if(this->dni==dni){
                pos=c;
         }
          c++;
      }
      fclose(p);
      return pos;
}

bool Cliente::leerDeDisco(const int pos){
        FILE *p;
        p=fopen("Clientes.dat","rb");
        if (p==NULL) return false;
        fseek(p, pos*sizeof *this, 0);
        bool leyo=fread(this, sizeof *this, 1, p);
        fclose(p);
        return leyo;
}


bool Cliente::grabarEnDisco(const int pos){
    FILE *p;
    p=fopen("Clientes.dat","rb+");
    if (p==NULL){
            cout<<"No se pudo abrir el archivo";
            return false;
     }
    else  fseek(p, (pos)*sizeof *this, 0);
    bool escribio=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return escribio;
}


int Cliente::calcularCantComprasRealizadas(const int dni){
   Operacion regOperacion;
   int cantCompras=0;
   FILE *p;
   p=fopen("Operaciones.dat","rb");
   if (p==NULL) return 0;
   while(fread(&regOperacion,sizeof (Operacion),1,p)==1){
        if(regOperacion.getDniCliente()==dni && regOperacion.getVentaCompleta()==true){
            cantCompras++;
        }
   }
   fclose(p);
   return cantCompras;
}

void Cliente::mostrarAutosAsociados(const int dni){
   Operacion regOperacion;
   FILE *p;
   p=fopen("Operaciones.dat","rb");
   if (p==NULL) return;
   while(fread(&regOperacion,sizeof (Operacion),1,p)==1){
        if(regOperacion.getDniCliente()==dni){
            cout<<endl<< "Patente: "<<regOperacion.getDominioVehiculo();
        }
   }
   fclose(p);
};


#endif // CLSCLIENTE_CPP_INCLUDED
