//
// Created by Octavio Carpineti on 06/06/2024.
//

#ifndef SISTEMADENOTICIAS_AUTOR_H
#define SISTEMADENOTICIAS_AUTOR_H
#include "iostream"
#include "Persona.h"

class Autor : public Persona {
private:
    std::string medio;

public:
    void setMedio (std::string _medio);

    std::string getMedio ();

    Autor(int _dni, std::string _nombre, std::string _medio);
};


#endif //SISTEMADENOTICIAS_AUTOR_H
