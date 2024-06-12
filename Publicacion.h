#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <vector>
#include "Articulo.h"
#include "Comentario.h"
#include "Usuario.h"

class Publicacion {
private:
    std::vector<Articulo> articulos;

public:
    void agregarArticulo(const Articulo& articulo);

    // Método para obtener todos los artículos
    const std::vector<Articulo>& getArticulos() const
    {
        return articulos;
    }

    // Método para asociar un comentario con un artículo específico
    bool comentarArticulo(const std::string& titulo, const Comentario& comentario, const Usuario& usuario);

    void mostrarArticulos() const;
};

#endif // PUBLICACION_H
