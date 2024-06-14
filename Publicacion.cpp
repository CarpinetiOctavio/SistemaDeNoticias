#include "Publicacion.h"
#include "Articulo.h"

void Publicacion::agregarArticulo(const Articulo &articulo)
{
    articulos.push_back(articulo);
}

bool Publicacion::comentarArticulo(const std::string &titulo, const Comentario &comentario, const Usuario &usuario)
{
    for (size_t i = 0; i < articulos.size(); ++i)
    {
        Articulo &articulo = articulos[i];
        if (articulo.getTitulo() == titulo)
        {
            articulo.agregarComentario(comentario);
            return true; // Comentario agregado correctamente
        }
    }
    return false; // Artículo no encontrado
}

void Publicacion::mostrarArticulos() const
{
    std::cout << "Artículos disponibles:\n";
    for (size_t i = 0; i < articulos.size(); ++i)
    {
        const Articulo &articulo = articulos[i];
        std::cout << "- Título: " << articulo.getTitulo() << "\n";
        std::cout << "  Autor: " << articulo.getAutor().getNombre() << "\n";
        std::cout << "  Fecha de publicación: " << articulo.getDia() << "/" << articulo.getMes() << "/" << articulo.getAnio() << "\n";
        std::cout << "  Detalle: " << articulo.getDetalle() << "\n\n";
    }
}