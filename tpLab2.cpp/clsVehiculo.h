#ifndef CLSVEHICULO_H_INCLUDED
#define CLSVEHICULO_H_INCLUDED




class Vehiculo{
    private:
        int idVehiculo;
        char modelo[20];
        char marca[15];
        char color[9];
        int cantPuertas;
        int anio;
        int stock;
        bool estado;

    public:
        Vehiculo();
        void setIdVehiculo(const int idVehiculo);
        void setModelo(const char *modelo);
        void setMarca(const char *marca);
        void setColor(const char *color);
        void setCantPuertas(const int cantPuertas);
        void setAnio(const int anio);
        void setStock(const int stock);
        void setEstado(const bool estado);
        int getIdVehiculo();
        const char *getModelo();
        const char *getMarca();
        const char *getColor();
        int getCantPuertas();
        int getAnio();
        int getStock();
        bool getEstado();
        void Cargar();
        void Mostrar();
        void cargarEnArchivo();
        int buscarPosEnDisco(const int idVehiculo);
        bool leerDeDisco(const int pos);
        bool grabarEnDisco(const int pos);
        int calculateCantVendidos();

};
#endif // CLSVEHICULO_H_INCLUDED
