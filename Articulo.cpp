#include "Articulo.h"

// Constructor que inicializa el artículo con los datos proporcionados
Articulo::Articulo(std::string _titulo, std::string _detalle, int _dia, int _mes, int _anio, Autor _autor)
        : titulo(_titulo), detalle(_detalle), dia(_dia), mes(_mes), anio(_anio), autor(_autor) {}

// Setters
void Articulo::setTitulo(std::string _titulo) {
    titulo = _titulo;
}

void Articulo::setDetalle(std::string _detalle) {
    detalle = _detalle;
}

void Articulo::setDia(int _dia) {
    dia = _dia;
}

void Articulo::setMes(int _mes) {
    mes = _mes;
}

void Articulo::setAnio(int _anio) {
    anio = _anio;
}

void Articulo::setAutor(Autor _autor) {
    autor = _autor;
}

// Getters
std::string Articulo::getTitulo() const {
    return titulo;
}

std::string Articulo::getDetalle() const {
    return detalle;
}

int Articulo::getDia() const {
    return dia;
}

int Articulo::getMes() const {
    return mes;
}

int Articulo::getAnio() const {
    return anio;
}

Autor Articulo::getAutor() const {
    return autor;
}

// Método para agregar un comentario al artículo
void Articulo::agregarComentario(const Comentario& comentario) {
    comentarios.push_back(comentario);
}

// Método para mostrar los comentarios asociados a este artículo
void Articulo::mostrarComentarios() const {
    for (const auto& comentario : comentarios) {
        std::cout << "- " << comentario.getTexto() << " (Usuario: " << comentario.getUsuario().getNombre() << ")" << std::endl;
    }
}

const std::vector<Comentario>& Articulo::getComentarios() const {
    return comentarios;
}