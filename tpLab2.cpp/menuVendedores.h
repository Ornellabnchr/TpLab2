#ifndef MENUVENDEDORES_H_INCLUDED
#define MENUVENDEDORES_H_INCLUDED


#include "clsFecha.h"
#include "clsPersona.h"
#include "clsVendedor.h"
#include "clsCliente.h"
#include "clsVehiculo.h"
#include "clsOperacion.h"

void listarVendedores();
void buscarVendedor();
void eliminarVendedor(int dni);
void actualizarSueldoVendedor(int dni);
int cantDeVendedores();
void changeVendedorPapelera(int pos);
int menuVendedores();



#endif // MENUVENDEDORES_H_INCLUDED
