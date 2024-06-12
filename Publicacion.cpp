#include "Publicacion.h"
#include "Articulo.h"

bool Publicacion::comentarArticulo(const std::string &titulo, const Comentario &comentario, const Usuario &usuario)
{
    for (auto& a : articulos) {
        if (a.getTitulo() == titulo) { // Utilizar el parámetro titulo en lugar de articulo
            a.agregarComentario(comentario);
            return true; // Comentario agregado correctamente
        }
    }
    return false; // Artículo no encontrado
}

// Implementación del método para mostrar todos los artículos disponibles
void Publicacion::mostrarArticulos() const {
    std::cout << "Artículos disponibles:\n";
    for (const auto& articulo : articulos) {
        std::cout << "- Título: " << articulo.getTitulo() << "\n";
        std::cout << "  Autor: " << articulo.getAutor().getNombre() << "\n";
        std::cout << "  Fecha de publicación: " << articulo.getDia() << "/" << articulo.getMes() << "/" << articulo.getAnio() << "\n";
        std::cout << "  Detalle: " << articulo.getDetalle() << "\n\n";
    }
}
