#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

#include "clsFecha.h"

class Persona
{

    protected:
        int dni;
        char nombre[30];
        char apellido[30];
        Fecha fechaDeNacimiento;
        char domicilio[30];
        char email[40];
        int telefono;
        char localidad[20];
        bool estado;

    public:
        Persona();
        void setDni(const int dni);
        void setEstado(const bool estado);
        void setTelefono(const int telefono);
        void setFechaDeNacimiento();
        void setNombre(const char *nombre);
        void setApellido(const char *apellido);
        void setDomicilio(const char *domicilio);
        void setLocalidad(const char *localidad);
        void setEmail(const char *email);
        int getDni();
        bool getEstado();
        int getTelefono();
        Fecha getFechaDeNacimiento();
        char* getNombre();
        char* getApellido();
        char* getDomicilio();
        char* getLocalidad();
        char* getEmail();
        void Mostrar();
        void Cargar();
        int calculateEdad();
};

#endif // CLSPERSONA_H_INCLUDED
