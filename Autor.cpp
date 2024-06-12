//
// Created by Octavio Carpineti on 06/06/2024.
//

#include "Autor.h"

void Autor::setMedio(std::string _medio)
{
    medio = _medio;
}

std::string Autor::getMedio() const
{
    return medio;
}

Autor::Autor(int _dni, std::string _nombre, std::string _medio) : Persona(_dni, _nombre), medio(_medio){}

