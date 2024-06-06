cmake_minimum_required(VERSION 3.28)
project(SistemaDeNoticias)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SistemaDeNoticias
        Persona.cpp
        Persona.h
        Articulo.h
        Articulo.cpp
        Autor.h
        Usuario.h
        Usuario.cpp
        main.cpp
        Autor.cpp)
