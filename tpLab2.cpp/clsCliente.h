#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED
#include "clsPersona.h"

class Cliente:public Persona{
    private:
        bool pidioCredito=false;
    public:
        bool getPidioCredito();
        void setPidioCredito(const bool pidioCredito);
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
