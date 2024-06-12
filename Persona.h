
//
// Created by Octavio Carpineti on 01/06/2024.
//

#ifndef CODIGO_PERSONA_H
#define CODIGO_PERSONA_H
#include "iostream"

class Persona {
protected:
    int dni;
    std::string nombre;
    int edad;

public:
    // Setters respectivos
    void setDni (int _dni);
    void setNombre (std::string _nombre);

    // Getters respectivos
    std::string getNombre () const;
    int getDni() const;

    // Constructor parametrizado
    Persona(int _dni, std::string _nombre);

    Persona();
};



#endif //CODIGO_PERSONA_H

