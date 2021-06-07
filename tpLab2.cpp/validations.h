#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

#include "clsFecha.h"

// Validaciones en clase Fecha
int validateDia(int,int,int);
int validateMes(int,int);
int validateAnio(int);

//validacion patente
int validateDominio(char *dominioVehiculo, int numcadena);

// Validaciones en clase Persona

Fecha validateEsMayor(Fecha);
int digits(int);

//Validaciones en clase Cliente

int validateDniCliente(int);


//Validaciones en clase Vendedor

int validateDniVendedor(int);
float validateSueldo(float);
float validateComisionPorcentaje(float);


// Validaciones en clase Operacion

int validateIdOperacion(int);
float validateMonto(float);
Fecha validateFechaDeInicio(Fecha);
Fecha validateFechaDeFin(Fecha, Fecha);
int validateVehiculoExiste(int);
int validateVehiculoStock(int);
int validateClienteExiste(int);
int validateVendedorExiste(int);


#endif // VALIDATIONS_H_INCLUDED
