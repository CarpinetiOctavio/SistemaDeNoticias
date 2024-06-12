#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include "Usuario.h"

class Comentario {
private:
    int numero;
    std::string texto;
    Usuario usuario;

public:

    void setUsuario (Usuario _usuario);
    void setNumero (int _numero);
    void setTexto (std::string _texto);

    int getNumero();
    std::string getTexto() const;
    Usuario getUsuario () const;

    Comentario(int _numero, std::string _texto, Usuario _usuario);

};

#endif // COMENTARIO_H
