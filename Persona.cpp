//
// Created by Octavio Carpineti on 01/06/2024.
//

#include "Persona.h"

void Persona::setDni(int _dni)
{
    dni = _dni;
}

int Persona::getDni()
{
    return dni;
}

void Persona::setNombre(std::string _nombre)
{
    nombre = _nombre;
}

std::string Persona::getNombre()
{
    return nombre;
}

Persona::Persona() {};

// Constructor parametrizado
Persona::Persona(int _dni, std::string _nombre) : dni(_dni), nombre(_nombre) {}

