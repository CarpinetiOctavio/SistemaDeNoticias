#ifndef USUARIO_H
#define USUARIO_H
#include "Persona.h"
#include <string>

class Usuario : public Persona {
private:
    int edad;

public:
    void setEdad (int _edad);

    int getEdad() const;

    Usuario();

    Usuario(int _dni, std::string _nombre, int _edad);

};

#endif // USUARIO_H
