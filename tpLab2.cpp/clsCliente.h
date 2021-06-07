#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED
#include "clsPersona.h"

class Cliente:public Persona{
    public:

    void setIdVehiculo(const int idVehiculo);
    void setPatenteVehiculo(const char* patenteVehiculo);
    int getIdVehiculo();
    char* getPatenteVehiculo();
    void Mostrar();
    void Cargar();
    void cargarEnArchivo();
    int buscarPosEnDisco(const int dni);
    bool leerDeDisco(const int pos);
    bool grabarEnDisco(const int pos);
    int calcularCantComprasRealizadas(const int dni);
    void mostrarAutosAsociados(const int dni);

};


#endif // CLSCLIENTE_H_INCLUDED
