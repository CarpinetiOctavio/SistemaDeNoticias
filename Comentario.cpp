//
// Created by Octavio Carpineti on 11/06/2024.
//

#include "Comentario.h"

void Comentario::setUsuario(Usuario _usuario)
{
    usuario = _usuario;
}

void Comentario::setNumero(int _numero)
{
    numero = _numero;
}

void Comentario::setTexto(std::string _texto)
{
    texto = _texto;
}

Usuario Comentario::getUsuario() const
{
    return usuario;
}

int Comentario::getNumero()
{
    return numero;
}

std::string Comentario::getTexto () const
{
    return texto;
}



Comentario::Comentario(int _numero, std::string _texto, Usuario _usuario)
: numero(_numero), texto(_texto), usuario(_usuario){};
