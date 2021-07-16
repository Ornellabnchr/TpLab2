#ifndef FUNCIONES_CPP_INCLUDED
#define FUNCIONES_CPP_INCLUDED
#include <windows.h>
#include "funciones.h"
#include "rlutil.h"
using namespace rlutil;

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}



void LINEA_EN_Y(int yInicial, int yFinal, int x, int color){
   void gotoxy(int x,int y);
   for (int i=yInicial;i<yFinal;i++){
         gotoxy(x,i);
         setBackgroundColor(color);
         cout << "  ";
   }
   setBackgroundColor(0);
}
void LINEA_EN_X(int xInicial, int xFinal, int y,int color){
   void gotoxy(int x,int y);
   for (int i=xInicial;i<xFinal;i++){
         gotoxy(i,y);
         setBackgroundColor(color);
         cout << " ";
   }
   setBackgroundColor(0);
}


#endif // FUNCIONES_CPP_INCLUDED
