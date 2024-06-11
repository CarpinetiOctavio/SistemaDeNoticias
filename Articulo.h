//
// Created by Octavio Carpineti on 06/06/2024.
//

#ifndef SISTEMADENOTICIAS_ARTICULO_H
#define SISTEMADENOTICIAS_ARTICULO_H
#include "iostream"
#include "Autor.h"

class Articulo {
private:

    /*
     * Objeto autor, del tipo de clase Autor.
     * Empleado para trabajar con las listas de autores, a la hora de usar los articulos
     */
    Autor autor;
    std::string titulo;
    std::string detalle;
    int dia;
    int mes;
    int anio;


public:

    // Setters respectivos
    void setTitulo (std::string _titulo);
    void setDetalle (std::string _detalle);
    void setDia (int _dia);
    void setMes (int _mes);
    void setAnio (int _anio);
    void setAutor (Autor _autor);

    // Getters respectivos
    std::string getTitulo();
    std::string getDetalle ();
    int getDia ();
    int getMes ();
    int getAnio ();
    Autor getAutor();

    Articulo(std::string _titulo, std::string _detalle, int _dia, int _mes, int _anio, Autor _autor);
};


#endif //SISTEMADENOTICIAS_ARTICULO_H
