#include "Marca.h"

Marca::Marca(const std::string & nomeMarca) : nomeMarca(nomeMarca) {}

Marca::~Marca() {}



std::string Marca::getNomeMarca() const{
	return nomeMarca;
}

bool Marca::operator==(const Marca &otherMarca) const{
	return (this->nomeMarca == otherMarca.nomeMarca);
}

bool Marca::operator!=(const Marca &otherMarca) const{
	return (this->nomeMarca != otherMarca.nomeMarca);
}
