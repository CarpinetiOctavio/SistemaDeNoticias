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
    Publicacion publicacion;

public:

    //Funcion de registro de datos en archivos
    void registrarDatos(const std::string& nombreArchivo, const std::string& datos);
    // Menues
    void menuInicial();
    void menuLectorInicial();
    void menuAutorInicial();
    void menuRegistrosConsultas();

    void leerArticulos() const;
    void registroDeUsuarios();
    void registroDeAutores();
    void consultarArticulosPorAutor();
    void consultarComentariosPorUsuario();
    void listarNoticiasAnio(int anio);

    // Funciones de ingreso
    void registrarUsuario();
    void registrarAutor();
    void registrarArticulo();

    // Función para que un usuario comente un artículo
    void comentarArticulo();

    // Función para mostrar la lista de usuarios disponibles
    void mostrarUsuarios() const;

    void listarNoticiasUltimoMes(int mes);

    // Función para mostrar la lista de artículos disponibles
    void mostrarArticulos() const;

    void pedirFecha(int &mes, int &anio);


   
};

#endif // SISTEMADENOTICIAS_DESARROLLO_H