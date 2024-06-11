//
// Created by Octavio Carpineti on 06/06/2024.
//

#include "Articulo.h"

void Articulo::setTitulo(std::string _titulo)
{
    titulo = _titulo;
}

std::string Articulo::getTitulo()
{
    return titulo;
}

void Articulo::setDetalle(std::string _detalle)
{
    detalle = _detalle;
}

std::string Articulo::getDetalle()
{
    return detalle;
}

void Articulo::setDia(int _dia)
{
    dia = _dia;
}

int Articulo::getDia()
{
    return dia;
}

void Articulo::setMes(int _mes)
{
    mes = _mes;
}

int Articulo::getMes()
{
    return mes;
}

void Articulo::setAnio(int _anio)
{
    anio = _anio;
}

int Articulo::getAnio()
{
    return anio;
}

void Articulo::setAutor(Autor _autor)
{
    autor = _autor;
}

Autor Articulo::getAutor()
{
    return autor;
}

Articulo::Articulo(std::string _titulo, std::string _detalle, int _dia, int _mes, int _anio, Autor _autor)
: titulo(_titulo), detalle(_detalle), dia(_dia), mes(_mes), anio(_anio), autor(_autor){};
