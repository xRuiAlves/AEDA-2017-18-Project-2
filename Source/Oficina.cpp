#include "Oficina.h"

Oficina::Oficina(unsigned int id , unsigned int disponibilidade , const std::vector<Marca> & marcasRepresentadas) :
	id(id),
	disponibilidade(disponibilidade) ,
	marcasRepresentadas(marcasRepresentadas) {}

Oficina::~Oficina() {}



unsigned int Oficina::getID() const{
	return id;
}

unsigned int Oficina::getDisponibilidade() const{
	return disponibilidade;
}

std::vector<Marca> Oficina::getMarcasRepresentadas() const{
	return marcasRepresentadas;
}



void Oficina::adicionarVeiculo(){
	disponibilidade++;
}
