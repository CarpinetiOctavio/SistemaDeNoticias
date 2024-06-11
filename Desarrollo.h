#ifndef SISTEMADENOTICIAS_DESARROLLO_H
#define SISTEMADENOTICIAS_DESARROLLO_H

#include <iostream>
#include <vector>
#include "Persona.h"
#include "Autor.h"
#include "Usuario.h"
#include "Articulo.h"
#include "Publicacion.h"
#include "Comentario.h"

class Desarrollo {
private:
    std::vector<Usuario> usuarios;
    std::vector<Autor> autores;
    std::vector<Articulo> articulos;

public:
    // Menues
    void menuInicial();
    void menuLectorInicial();
    void menuAutorInicial();

    // Funciones de ingreso
    void registrarUsuario();
    void registrarAutor();
    void registrarArticulo();
};

#endif //SISTEMADENOTICIAS_DESARROLLO_H
