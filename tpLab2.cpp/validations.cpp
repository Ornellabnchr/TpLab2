#ifndef VALIDATIONS_CPP_INCLUDED
#define VALIDATIONS_CPP_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

#include "clsVendedor.h"
#include "clsVehiculo.h"
#include "clsCliente.h"
#include "clsOperacion.h"
#include "validations.h"
#include "rlutil.h"

using namespace rlutil;


// VALIDACIONES CLASE FECHA


int validateDia(int dia, int mes, int anio){
     int aux=dia;
     int auxM=mes;
     int auxA=anio;
     switch(mes){
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :  while(aux>31 || aux<1){
                    setBackgroundColor(RED);
                    cout<<endl<<"Error!";
                    setBackgroundColor(BLACK);
                    cout<<"Ingrese un dia valido: ";
                    cin>>aux;
                    }
                    return aux;
                    break;
        case  4 :
        case  6 :
        case  9 :
        case 11 :   while(aux>30 || aux<1){
                    setBackgroundColor(RED);
                    cout<<endl<<"Error!";
                    setBackgroundColor(BLACK);
                    cout<<"Ingrese un dia valido: ";
                    cin>>aux;
                    }
                    return aux;
                    break;
        case 2: {if((auxA % 4 == 0 && auxA % 100 != 0) || (auxA % 400 == 0)){
                        while(aux>29 || aux<1){
                    setBackgroundColor(RED);
                    cout<<endl<<"Error!";
                    setBackgroundColor(BLACK);
                    cout<<"Ingrese un dia valido: ";
                    cin>>aux;
                    }
                    return aux;
                    }
                    else{
                while(aux>28 || aux<1){
                    setBackgroundColor(RED);
                    cout<<endl<<"Error!";
                    setBackgroundColor(BLACK);
                    cout<<"Ingrese un dia valido: ";
                    cin>>aux;
                    }
                    return aux;}
                }
                break;
     }
     }
// TODO: Revisar esto. Creo que se puede hacer de una forma más eficiente


int validateMes(int mes,int dia){
     int aux=mes;

     while(aux>12 || aux<1){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ingrese un mes valido: ";
         cin>>aux;
     }
     return aux;
}

int validateAnio(int anio){
     int aux=anio;
     while(aux<1900){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ingrese un anio valido: ";
         cin>>aux;
     }
     return aux;

}

// VALIDACIONES DE LA CLASE PERSONA

Fecha validateEsMayor(Fecha fechaDeNacimiento){
     Fecha aux_fechaDeNacimiento = fechaDeNacimiento;
     time_t t;
     t = time(NULL);
     struct tm *fecha;
     fecha = localtime(&t);
     Fecha fechaDeHoy;
     fechaDeHoy.setDia(fecha->tm_mday);
     fechaDeHoy.setMes(fecha->tm_mon+1);
     fechaDeHoy.setAnio(fecha->tm_year+1900);
     int diferenciaAnio=fechaDeHoy.getAnio()-aux_fechaDeNacimiento.getAnio();
     int diferenciaMes=fechaDeHoy.getMes()-aux_fechaDeNacimiento.getMes();
     int diferenciaDia=fechaDeHoy.getDia()-aux_fechaDeNacimiento.getDia();
     while (diferenciaAnio<18||(diferenciaAnio==18 && diferenciaMes<0) || (diferenciaAnio==18 && diferenciaMes==0 && diferenciaDia<0)) {
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"En esta concesionaria solo entran mayores de edad. Ingrese una fecha de nacimiento valida:  \n";
         aux_fechaDeNacimiento.Cargar();
         diferenciaAnio=fechaDeHoy.getAnio()-aux_fechaDeNacimiento.getAnio();
         diferenciaMes=fechaDeHoy.getMes()-aux_fechaDeNacimiento.getMes();
         diferenciaDia=fechaDeHoy.getDia()-aux_fechaDeNacimiento.getDia();

     }
     if (diferenciaMes==0 && diferenciaDia==0){
        cout<<endl<<"Hoy es su cumpleanios! Deseale un feliz dia";
        return aux_fechaDeNacimiento;
     }
     return aux_fechaDeNacimiento;
}


int digits(int nro){
    int c=1,aux=nro;
    while(aux/10>0){
        c++;
        aux=aux/10;
    }
    return c;
}





// VALIDACIONES CLASE CLIENTE

int validateDniCliente(int dni){
    int aux=dni;
    while(digits(aux)<8){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ingrese un Dni de al menos 8 digitos: ";
         cin>>aux;
    }
    Cliente regCliente;
    int pos=regCliente.buscarPosEnDisco(aux);
    while (pos!=-1){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ya hay un cliente registrado con ese DNI, ingrese un DNI que no haya sido registrado: ";
         cin>>aux;
         pos=regCliente.buscarPosEnDisco(aux);
    }
    return aux;
}


// VALIDACIONES CLASE Vendedor


int validateDniVendedor(int dni){
    int aux=dni;
    while(digits(aux)<8){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ingrese un Dni de al menos 8 digitos: ";
         cin>>aux;
    }
    Vendedor regVendedor;
    int pos=regVendedor.buscarPosEnDisco(aux);
    while (pos!=-1){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ya hay un vendedor registrado con ese DNI, ingrese un DNI que no haya sido registrado: ";
         cin>>aux;
         pos=regVendedor.buscarPosEnDisco(aux);
    }
    return aux;
}


float validateSueldo(float sueldoBruto){
   float aux= sueldoBruto;
   while (aux<40000){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"El sueldo minimo de la concesionaria es de 40000$. Ingrese un monto correcto: ";
         cin>>aux;
   }
   return aux;
}

float validateComisionPorcentaje(float comisionPorcentaje){
   float aux=comisionPorcentaje;
   while (aux>50 || aux<0){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"La comision de un vendedor onda entre el 0 y el 50% de cada operacion. Ingrese un porcentaje valido: ";
         cin>>aux;
   }
   return aux;
}

// VALIDACIONES CLASE OPERACION

int validateIdOperacion(int idOperacion){
    int aux=idOperacion;
    Operacion regOperacion;
    int pos=regOperacion.buscarPosEnDisco(aux);
    while (pos!=-1){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ya hay una operacion registrada con ese ID, ingrese un ID que no haya sido registrado: ";
         cin>>aux;
         pos=regOperacion.buscarPosEnDisco(aux);
    }
    while(idOperacion<0){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ingrese un número entero como ID: ";
         cin>>aux;
    }
    return aux;
}

float validateMonto(float monto){
   float aux=monto;
   while (aux<200000){
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"El precio minimo de un auto es de $200 mil pesos: ";
         cin>>aux;
         cout<<endl;
   }
   return aux;
}

Fecha validateFechaDeInicio(Fecha fechaDeInicio){
    Fecha aux=fechaDeInicio;
    while (aux.getAnio()<2019){
            setBackgroundColor(RED);
            cout<<endl<<"Error!";
            setBackgroundColor(BLACK);
            cout <<"Esta concesionaria solo estuvo activa entre el 2019 y el 2021. Ingrese una fecha válida: ";
            cout <<endl;
            aux.Cargar();"\n";
    }
    return aux;
}

Fecha validateFechaDeFin(Fecha fechaDeFin,Fecha fechaDeInicio){
    Fecha auxInicio=fechaDeInicio;
    Fecha auxFin=fechaDeFin;
    while (auxFin.getAnio()<2019){
            setBackgroundColor(RED);
            cout<<endl<<"Error!";
            setBackgroundColor(BLACK);
            cout <<"Esta concesionaria solo estuvo activa entre el 2019 y el 2021. Ingrese una fecha válida: ";
            cout <<endl;
            auxFin.Cargar();"\n";
    }
    int diferenciaAnio=auxFin.getAnio()-auxInicio.getAnio();
    int diferenciaMes=auxFin.getMes()-auxInicio.getMes();
    int diferenciaDia=auxFin.getDia()-auxInicio.getDia();
    while (diferenciaAnio<0||(diferenciaAnio==0 && diferenciaMes<0) || (diferenciaAnio==0 && diferenciaMes==0 && diferenciaDia<0)) {
         setBackgroundColor(RED);
         cout<<endl<<"Error!";
         setBackgroundColor(BLACK);
         cout<<"Ingrese una fecha de finalizacion valida de acuerdo a la fecha de inicio ingresada:  \n";
         auxFin.Cargar();
         diferenciaAnio=auxFin.getAnio()-auxInicio.getAnio();
         diferenciaMes=auxFin.getMes()-auxInicio.getMes();
         diferenciaDia=auxFin.getDia()-auxInicio.getDia();

    }

    return auxFin;
}

int validateVehiculoExiste(int idVehiculo){
    Vehiculo regVehiculo;
    int pos=regVehiculo.buscarPosEnDisco(idVehiculo);
    if (pos==-1){
            cout<<endl<<endl<<"El vehiculo no existe.";
            setBackgroundColor(LIGHTGREEN);
            cout<<"Inicializando creacion...";
            setBackgroundColor(BLACK);
            cout<<endl<<"------------------------------------------------";
            regVehiculo.Cargar();
            return regVehiculo.getIdVehiculo();
    }
    return idVehiculo;
}


int validateVehiculoStock(int idVehiculo){
    Vehiculo regVehiculo;
    int pos=regVehiculo.buscarPosEnDisco(idVehiculo);
    regVehiculo.leerDeDisco(pos);
    if(regVehiculo.getEstado()==false){
         cout<<endl<<endl<<"El vehiculo no tiene stock.";
         cout<<endl<<"Agregue stock en la seccion de 'Gestionar Vehiculos' si es que ingreso a sucursal.";
         return 0;
    }
    return idVehiculo;
}

int validateClienteExiste(int dniCliente){
    Cliente regCliente;
    int pos=regCliente.buscarPosEnDisco(dniCliente);
    if (pos==-1){
            cout<<endl<<endl<<"El cliente no existe.";
            setBackgroundColor(LIGHTGREEN);
            cout<<"Inicializando creacion...";
            setBackgroundColor(BLACK);
            cout<<endl<<"------------------------------------------------";
            regCliente.Cargar();
            return regCliente.getDni();
    }
    return dniCliente;
}

int validateVendedorExiste(int dniVendedor){
    Vendedor regVendedor;
    int pos=regVendedor.buscarPosEnDisco(dniVendedor);
    if (pos==-1){
            cout<<endl<<endl<<"El vendedor no existe.";
            setBackgroundColor(LIGHTGREEN);
            cout<<"Inicializando creacion...";
            setBackgroundColor(BLACK);
            cout<<endl<<"------------------------------------------------";
            regVendedor.Cargar();
            return regVendedor.getDni();
    }
    return dniVendedor;
}


int validateDominio(char *dominioVehiculo, int numcadena){
int i;
for(i=0;i<numcadena;i++){
        if(i==0 || i==1){
            if(isalpha(dominioVehiculo[i])==false){
                cout<<"ERROR EN LOS PRIMEROS DOS DIGITOS, LOS CUALES DEBERIAN SER LETRAS"<<endl;
                return 1;
            }
        }
        if(i==2 || i==3 || i==4){
            if(isdigit(dominioVehiculo[i])==false){
                cout<<" ERROR LOS TRES DIGITOS DEL MEDIO, LOS CUALES DEBERIAN SER NUMEROS"<<endl;
                return 1;
            }
        }
        if(i==5 || i==6){
            if(isalpha(dominioVehiculo[i])==false){
                cout<<" ERROR EN LOS ULTIMOS DOS DIGITOS, LOS CUALES DEBERIAN SER LETRAS"<<endl;
                return 1;
            }
        }
}
return 0;
}

#endif // VALIDATIONS_CPP_INCLUDED
