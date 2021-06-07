#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        void Cargar();
        void Mostrar();
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);
        int getDia();
        int getMes();
        int getAnio();
};

#endif // CLSFECHA_H_INCLUDED
