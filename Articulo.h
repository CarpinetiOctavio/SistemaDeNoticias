//
// Created by Octavio Carpineti on 06/06/2024.
//

#ifndef SISTEMADENOTICIAS_ARTICULO_H
#define SISTEMADENOTICIAS_ARTICULO_H
#include "iostream"

class Articulo {
private:
    std::string titulo;
    std::string detalle;
    int dia;
    int mes;
    int anio;

public:
    void setTitulo (std::string _titulo);
    void setDetalle (std::string _detalle);
    void setDia (int _dia);
    void setMes (int _mes);
    void setAnio (int _anio);

    std::string getTitulo();
    std::string getDetalle ();
    int getDia ();
    int getMes ();
    int getAnio ();

    Articulo(std::string _titulo, std::string _detalle, int _dia, int _mes, int _anio);
};


#endif //SISTEMADENOTICIAS_ARTICULO_H
