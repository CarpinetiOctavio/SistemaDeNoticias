//
// Created by Octavio Carpineti on 06/06/2024.
//

#ifndef SISTEMADENOTICIAS_USUARIO_H
#define SISTEMADENOTICIAS_USUARIO_H
#include "iostream"
#include "Persona.h"

class Usuario : public Persona{
private:
    int edad;

public:
    void setEdad (int _edad);

    int getEdad();

    Usuario();
    Usuario(int _dni, std::string _nombre, int _edad);
};


#endif //SISTEMADENOTICIAS_USUARIO_H
