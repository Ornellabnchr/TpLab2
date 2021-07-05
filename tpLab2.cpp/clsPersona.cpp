#ifndef CLSPERSONA_CPP_INCLUDED
#define CLSPERSONA_CPP_INCLUDED


#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

#include "clsPersona.h"
#include "funciones.h"
#include "validations.h"

Persona::Persona(){
           estado=true;
}
void Persona::setDni(const int dni){this->dni=dni;};
void Persona::setEstado(const bool estado){this->estado=estado;}
void Persona::setTelefono(const int telefono){this->telefono=telefono;};
void Persona::setFechaDeNacimiento(){this->fechaDeNacimiento.Cargar();};
void Persona::setNombre(const char *nombre){strcpy(this->nombre,nombre);};
void Persona::setApellido(const char *apellido){strcpy(this->apellido,apellido);};
void Persona::setDomicilio(const char *domicilio){strcpy(this->domicilio,domicilio);};
void Persona::setLocalidad(const char *localidad){strcpy(this->localidad,localidad);};
void Persona::setEmail(const char *email){strcpy(this->email,email);};
int Persona::getDni(){return dni;}
bool Persona::getEstado(){return estado;}
int Persona::getTelefono(){return telefono;}
Fecha Persona::getFechaDeNacimiento(){return fechaDeNacimiento;}
char* Persona::getNombre(){return nombre;}
char* Persona::getApellido(){return apellido;}
char* Persona::getDomicilio(){return domicilio;}
char* Persona::getLocalidad(){return localidad;}
char* Persona::getEmail(){return email;}


void Persona::Cargar(){
    cout<<"Ingrese nombres: ";
    cargarCadena(nombre,30);"\n";
    cout<<"Ingrese el apellido: ";
    cargarCadena(apellido,30);"\n";
    cout<<"Ingrese el domicilio: ";
    cargarCadena(domicilio,30);"\n";
    cout<<"Ingrese el localidad: ";
    cargarCadena(localidad,20);"\n";
    cout<<"Ingrese el email: ";
    cin >> email;"\n";
    cout<<"Ingrese el telefono: ";
    cin >> telefono;"\n";
    cout<<"Fecha de nacimiento \n\n";
    fechaDeNacimiento.Cargar();"\n";
    fechaDeNacimiento= validateEsMayor(fechaDeNacimiento);
    cout<<endl;

}

void Persona::Mostrar(){
   cout<<"Nombre completo: "<<nombre << " "<< apellido <<endl;
   cout<<"DNI: "<<dni <<endl;
   cout<<"Fecha de nacimiento: ";
   fechaDeNacimiento.Mostrar();
   cout<<"Telefono: "<<telefono <<endl;
   cout<<"Email: "<<email <<endl;
   cout<<"Domicilio: "<<domicilio <<endl;
   cout<<"Localidad: "<<localidad <<endl;


}

int Persona::calculateEdad(){
     time_t t;
     t = time(NULL);
     struct tm *fecha;
     fecha = localtime(&t);
     Fecha fechaDeHoy;
     fechaDeHoy.setDia(fecha->tm_mday);
     fechaDeHoy.setMes(fecha->tm_mon+1);
     fechaDeHoy.setAnio(fecha->tm_year+1900);
     int edad = fechaDeHoy.getAnio() - fechaDeNacimiento.getAnio();
     if (fechaDeHoy.getMes()<fechaDeNacimiento.getMes() || (fechaDeHoy.getMes()==fechaDeNacimiento.getMes() && fechaDeHoy.getDia()<fechaDeNacimiento.getDia())) edad=edad-1;
     return edad;
}

#endif // CLSPERSONA_CPP_INCLUDED
