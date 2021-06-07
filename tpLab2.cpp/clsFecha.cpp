#ifndef CLSFECHA_CPP_INCLUDED
#define CLSFECHA_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "validations.h"
#include "clsFecha.h"


void Fecha::setDia(int d){dia=d;}
void Fecha::setMes(int m){mes=m;}
void Fecha::setAnio(int a){anio=a;}
int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}



void Fecha::Cargar(){
    cout<<"Ingrese el anio: ";
    cin>>anio;
    anio=validateAnio(anio);
    cout<<"Ingrese el mes: ";
    cin>>mes;
    mes=validateMes(mes,dia);
    cout<<"Ingrese el dia: ";
    cin>>dia;
    dia=validateDia(dia,mes,anio);


}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}


#endif // CLSFECHA_CPP_INCLUDED
