#ifndef MENUVEHICULOS_H_INCLUDED
#define MENUVEHICULOS_H_INCLUDED

#include "clsFecha.h"
#include "clsPersona.h"
#include "clsVendedor.h"
#include "clsCliente.h"
#include "clsVehiculo.h"
#include "clsOperacion.h"

void listarVehiculos();
int cantDeVehiculos();
void buscarVehiculo();
void eliminarVehiculo(int);
void agregarStockVehiculo(int, int);
int menuVehiculos();

#endif // MENUVEHICULOS_H_INCLUDED
