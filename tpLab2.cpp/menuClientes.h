#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED
#include "clsFecha.h"
#include "clsPersona.h"
#include "clsVendedor.h"
#include "clsCliente.h"
#include "clsVehiculo.h"
#include "clsOperacion.h"

void listarClientes();
void buscarCliente();
void eliminarCliente(int dni);
int cantDeClientes();
void changeClientePapelera(int pos);
int menuClientes();


#endif // MENUCLIENTES_H_INCLUDED
