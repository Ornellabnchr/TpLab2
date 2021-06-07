#ifndef CLSOPERACION_H_INCLUDED
#define CLSOPERACION_H_INCLUDED


#include "clsFecha.h"
#include "clsPersona.h"
#include "clsVendedor.h"
#include "clsCliente.h"
#include "clsVehiculo.h"
class Operacion
{
    private:
    int idOperacion;
    float monto;
    int idVehiculo;
    int dniVendedor;
    int dniCliente;
    char dominioVehiculo[7];
    Fecha fechaDeInicio;
    Fecha fechaDeFin;
    bool ventaCompleta;
    float gananciasAVendedor;
    float gananciasAConcesionaria;

    public:
    void setIdOperacion(const float idOperacion);
    void setMonto(const float monto);
    void setIdVehiculo(const int idVehiculo);
    void setDniVendedor(const int dniVendedor);
    void setDniCliente(const int dniCliente);
    void setDominioVehiculo(const char *dominioVehiculo);
    void setFechadeInicio(const Fecha fechaDeInicio);
    void setFechadeFin(const Fecha fechaDeFin);
    void setVentaCompleta(const bool ventaCompleta);
    void setGananciasAVendedor(const float gananciasAVendedor);
    void setGananciasAConcesionaria(const float gananciasAConcesionaria);
    int getIdOperacion();
    float getMonto();
    int getIdVehiculo();
    int getDniVendedor();
    int getDniCliente();
    char* getDominioVehiculo();
    Fecha getFechaDeInicio();
    Fecha getFechaDeFin();
    bool getVentaCompleta();
    float getGananciasAVendedor();
    float getGananciasAConcesionaria();
    void Cargar();
    void Mostrar();
    void cargarEnArchivo();
    bool leerDeDisco(const int pos);
    int  buscarPosEnDisco(const int idOperacion);
    int calculateGananciasAVendedor();
};


#endif // CLSOPERACION_H_INCLUDED
