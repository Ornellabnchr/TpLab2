#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

int menuReportes();
void ventasPorMes(int,int);
void mostrarVentasPorMes(int,int);
char* getNombreDeMes(int);
int getIndexAnio(int);
void mostrarRankingVendedores();
void mostrarRankingVehiculos();
void mostrarEstadisticaCreditoEdad();
void mostrarMontosVendedores(Vendedor *vecV, int cant);
 float calculateCantMontos(int dn);

#endif // MENUREPORTES_H_INCLUDED
