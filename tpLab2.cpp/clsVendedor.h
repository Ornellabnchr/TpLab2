#ifndef CLSVENDEDOR_H_INCLUDED
#define CLSVENDEDOR_H_INCLUDED

#include "clsPersona.h"

class Vendedor:public Persona{
    private:
        float comisionPorcentaje;
        float sueldoBruto;
    public:
        void setComisionPorcentaje(const float);
        void setSueldoBruto(const float);
        float getComisionPorcentaje();
        float getSueldoBruto();
        void Mostrar();
        void Cargar();
        void cargarEnArchivo();
        int buscarPosEnDisco(const int);
        bool leerDeDisco(const int);
        bool grabarEnDisco(const int);
        int calculateCantVentasRealizadas();

};

#endif // CLSVENDEDOR_H_INCLUDED
