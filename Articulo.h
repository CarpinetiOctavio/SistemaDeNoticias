#ifndef SISTEMADENOTICIAS_ARTICULO_H
#define SISTEMADENOTICIAS_ARTICULO_H

#include <vector>
#include <string>
#include "Autor.h"
#include "Comentario.h"

class Articulo {
private:
    Autor autor;
    std::string titulo;
    std::string detalle;
    int dia, mes, anio;
    std::vector<Comentario> comentarios;

public:
    // Constructor del artículo
    Articulo(std::string _titulo, std::string _detalle, int _dia, int _mes, int _anio, Autor _autor);

    // Setters
    void setTitulo(std::string _titulo);
    void setDetalle(std::string _detalle);
    void setDia(int _dia);
    void setMes(int _mes);
    void setAnio(int _anio);
    void setAutor(Autor _autor);

    // Getters
    std::string getTitulo() const;
    std::string getDetalle() const;
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    Autor getAutor() const;

    // Método para agregar un comentario al artículo
    void agregarComentario(const Comentario& comentario);

    // Método para mostrar los comentarios asociados a este artículo
    void mostrarComentarios() const;

    const std::vector<Comentario>& getComentarios() const;

};

#endif // SISTEMADENOTICIAS_ARTICULO_H
