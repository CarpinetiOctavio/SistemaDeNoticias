//
// Created by Octavio Carpineti on 06/06/2024.
//

#include "Usuario.h"
#include "Persona.h"

void Usuario::setEdad(int _edad)
{
    edad = _edad;
}

int Usuario::getEdad() const
{
    return edad;
};

Usuario::Usuario() : edad(0){};

Usuario::Usuario(int _dni, std::string _nombre, int _edad) : Persona (_dni, _nombre), edad(_edad){};
